#include"CodeGen.hpp"
#include"AST.hpp"
using namespace llvm;

//构造函数，建立一些llvm需要的变量
 Gen::Gen() {
     g_llvm_context = new LLVMContext();
     g_ir_builder = new IRBuilder<>(*g_llvm_context);
     g_module = new Module("testCode", *g_llvm_context);

     // Create a new pass manager attached to it.
     TheFPM = std::make_unique<legacy::FunctionPassManager>(g_module);

     // Do simple "peephole" optimizations and bit-twiddling optzns.
     TheFPM->add(createInstructionCombiningPass());
     // Reassociate expressions.
     TheFPM->add(createReassociatePass());
     // Eliminate Common SubExpressions.
     TheFPM->add(createGVNPass());
     // Simplify the control flow graph (deleting unreachable blocks, etc).
     TheFPM->add(createCFGSimplificationPass());
     // Loop unroll.
     TheFPM->add(createLoopUnrollPass(3));

     TheFPM->doInitialization();
}

void Gen::CompUnitGen(AST::CompUnit*& ast) {
    InitExternalFunction();
    for (auto& Unit : ast->units) {
        if (Unit->unitType == Fun)FuncGen(Unit);
        else GlobalVarGen(Unit);
    }
    g_module->print(outs(), nullptr);
    OutputGen();
}


void Gen::InitExternalFunction() {
    // scanf
    FunctionType* scanfTy = FunctionType::get(GetType(Int), { Type::getInt8PtrTy(*g_llvm_context) }, true);
    Function* scanf = Function::Create(scanfTy, Function::ExternalLinkage, "scanf", g_module);
    scanf->setCallingConv(CallingConv::C);
    // printf
    FunctionType* printfTY = FunctionType::get(GetType(Int), { Type::getInt8PtrTy(*g_llvm_context) }, true);
    Function* printf = Function::Create(printfTY, Function::ExternalLinkage, "printf", g_module);
    printf->setCallingConv(CallingConv::C);
}

void Gen::OutputGen() {
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    g_module->setTargetTriple(TargetTriple);

    string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        exit(0);
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = llvm::Optional<Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    g_module->setDataLayout(TheTargetMachine->createDataLayout());

    auto Filename = "output.o";
    error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    if (EC) {
        errs() << "Could not open file: " << EC.message();
        exit(0);
    }

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        exit(0);
    }

    pass.run(*g_module);
    dest.flush();

    outs() << "Wrote " << Filename << "\n";
}

void Gen::GlobalVarGen(AST::Unit*& unit) {
    AST::Variable* var = static_cast<AST::Variable*>(unit);
    if (g_values.find(*var->varName) == g_values.end()) {
        if (!var->is_array) {
            GlobalVariable* gVar = new GlobalVariable(*g_module,
                GetType(var->bType), false,  // 只在当前模块内可见
                GlobalValue::ExternalLinkage,
                ConstantInt::get(*g_llvm_context, APInt(32, 0)),  // 初始值为nullptr
                *(var->varName)  // 全局变量的名称
            );
            if (var->initValList != nullptr) {
                gVar->setInitializer(dyn_cast<Constant>(ValueGen(var->initValList->valList[0])));//varList是容器,容器元素的类型是Exp*
            }
            g_values.emplace(*var->varName, gVar);
            NamedValues.insert(var->varName, nullptr, nullptr);
        }
        else {
            //这里默认全局数组不会有int a[][]={}的赋值
            Value* arraySize = GetArraySize(var);//len也是容器,每个里面是Exp*
            auto arrayType = ArrayType::get(GetType(var->bType), (dyn_cast<Constant>(arraySize)->getUniqueInteger().getSExtValue()));
            auto* gVar = new GlobalVariable(*g_module, arrayType, false, GlobalValue::ExternalLinkage, ConstantArray::get(arrayType, ConstantInt::get(*g_llvm_context, APInt(32, 0))), *(var->varName));
            g_values.emplace(*var->varName, gVar);
            NamedValues.insert(var->varName, nullptr, &var->arr->len);
        }
        
    }
    else std::cout << "error: variable redefinition" << std::endl;
}

Value* Gen::GetArraySize(AST::Variable*& ast) {
    Value* arraySize = ValueGen(ast->arr->len[0]);
    for (int i = 1; i < ast->arr->len.size(); ++i)
        arraySize = g_ir_builder->CreateMul(arraySize, ValueGen(ast->arr->len[i]));
    return arraySize;
}

void Gen::FuncGen(AST::Unit* &unit){
    AST::Func* fun=static_cast<AST::Func*>(unit);
    std::vector<Type*> arg_types;
    for (auto& arg : fun->argList->args) {
        if (arg->is_pointer) {
            arg_types.push_back(GetPtrType(arg->bType));
        }
        else {
            arg_types.push_back(GetType(arg->bType));
        }
    }
    FunctionType* function_type = FunctionType::get(GetType(fun->funcType), arg_types, false);
    Function* func= llvm::Function::Create(function_type, Function::ExternalLinkage, *(fun->funcName), g_module);
    // 设置function的argument name
    int index = 0;
    for (auto&  arg: func->args()) {
        arg.setName(*(fun->argList->args[index]->argName));
    }
    BasicBlock* block =BasicBlock::Create(*g_llvm_context, "entry", func);
    g_ir_builder->SetInsertPoint(block);

    //符号表要插入函数的形参
    auto* cur_block = g_ir_builder->GetInsertBlock();//cur是block的指针
    int i = 0;
    for (auto& arg : func->args()) {
        Value* val = &arg;
        AllocaInst* Alloca;
        AST::Arg* cur_arg = fun->argList->args[i];
        if (!cur_arg->is_pointer) Alloca = createBlockAlloca(*cur_block,cur_arg->argName,cur_arg->bType);
        else Alloca = createBlockPtrAlloca(*cur_block, cur_arg->argName, cur_arg->bType);
        NamedValues.insert(cur_arg->argName, Alloca, nullptr);//注意这里形参是指针的话，写到符号表里并没有指明维度,和tcn不一样
        g_ir_builder->CreateStore(val, Alloca);
        ++i;
        //Q:这里不用把形参在函数部分结束之后也弹出来吗？
    }

    //DeclGen会出现新的变量，存在removeList里，函数程序段结束后从符号表删除
    std::vector<std::string*> removeList;
    bool no_use_sign;
    for (auto& item : fun->funcBody->itemList) {
        if (item->itemType == STMT) StmtGen(func, item,nullptr,nullptr,no_use_sign);
        else if (item->itemType == DECL)  DeclGen(item, removeList);
    }
    NamedValues.remove(removeList);
    if(fun->funcType==Void)g_ir_builder->CreateRetVoid();
 }

//堆栈上的内存分配，在一个独立的IR_builder里，之后可以插入到指定的基本块
AllocaInst* Gen::createBlockPtrAlloca(BasicBlock& block, const string* VarName,basType VarType) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetPtrType(VarType), nullptr, *VarName);
}

AllocaInst* Gen::createBlockAlloca(BasicBlock& block, const string* VarName, basType VarType) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetType(VarType), nullptr, *VarName);
}

AllocaInst* Gen::createBlockArrayAlloca(BasicBlock& block, const string* VarName, basType VarType, Value* ArraySize) {
    IRBuilder<> TmpB(&block, block.begin());
    return TmpB.CreateAlloca(GetType(VarType), ArraySize, *VarName);
}

void Gen::DeclGen(AST::BlockItem*& item, vector<std::string*>& removeList) {
    AST::Variable* var=static_cast<AST::Variable*>(item);
    auto* cur = g_ir_builder->GetInsertBlock();
    // check redefinition
    auto check_sym = find(removeList.begin(), removeList.end(), var->varName);
    if (check_sym != removeList.end()) {
        cout << "error: redefinition of '" << *(var->varName) << "'" << endl;
        exit(0);
    }
    AllocaInst* Alloca;
    if (var->is_array) {
        Value* arraySize = GetArraySize(var);
        Alloca = createBlockArrayAlloca(*cur, var->varName, var->bType, arraySize);
    }
    else Alloca=createBlockAlloca(*cur, var->varName, var->bType);

    Value* InitVal = nullptr;
    //只支持单变量的initValList
    if (var->initValList!= nullptr) {
        InitVal = ValueGen(var->initValList->valList[0]);
    }
    if (InitVal != nullptr) g_ir_builder->CreateStore(InitVal, Alloca);
    // add to symbol table
    NamedValues.insert(var->varName, Alloca, &var->arr->len);
    removeList.push_back(var->varName);
}

//finalExp,lValExp,constNumExp, funcCall, mulExp, divExp,modExp,addExp,subExp,LTexp,GTexp,LEexp,GEexp,EQexp,NEexp,lAndExp,lOrExp
Value* Gen::ValueGen(AST::Exp* ast) {
    if (ast->expType == constNumExp) {
        AST::ConstNumber* num = static_cast<AST::ConstNumber*>(ast);
        if (num->constType == Int)return ConstantInt::get(*g_llvm_context, APInt(32, int(num->val)));
        else return ConstantFP::get(*g_llvm_context, APFloat(num->val));
    }
    else if (ast->expType == lValExp) {
        AST::Variable* lexp = static_cast<AST::Variable*>(ast);
        AllocaInst* var = NamedValues.find(lexp->varName);
        if (var == nullptr) {//var==nullptr的原因是全局变量插入时没有AllocaInst*，证明这是个全局变量
            auto g_var = g_values.find(*lexp->varName);
            if (g_var == g_values.end()) {
                cout << "error:Undefined Variable" << endl;
                exit(1);
            }
            if (g_var->second->getValueType()->isArrayTy()) {
                auto index = GetArrayIndex(lexp);
                Value* gep = g_ir_builder->CreateInBoundsGEP(g_var->second->getValueType()->getScalarType(), g_var->second, { index });
                return g_ir_builder->CreateLoad(g_var->second->getValueType()->getScalarType(), gep);
            }
            else return g_ir_builder->CreateLoad(g_var->second->getValueType(), g_var->second);
        }
        else {
            if (!lexp->is_array)return g_ir_builder->CreateLoad(var->getAllocatedType(), var, var->getName().data());
            else {
                Value* location = GetLocation(lexp, var);
                return g_ir_builder->CreateLoad(GetType(lexp->bType), location, var->getName().data());
            }
        }
    }
    else if (ast->expType == funcCall)  return FuncCallGen(static_cast<AST::FuncCall*>(ast));
    else if (ast->expType == finalExp) return ValueGen(static_cast<AST::FinalExp*>(ast)->iExp);
    else return BinaryExpGen(static_cast<AST::BinaryExp*>(ast));
   
}

Value* Gen::GetLocation(AST::Variable*&VarUnit, AllocaInst* var) {
    Value* index = GetArrayIndex(VarUnit);
    Value* location;
    //是指针类型的情况就是函数形参有指针
    if (var->getAllocatedType()->isPointerTy()) {
        Value* st = g_ir_builder->CreateLoad(var->getAllocatedType(), var, var->getName().data());
        if (var->getAllocatedType() == Type::getInt32PtrTy(*g_llvm_context)) {
            location = g_ir_builder->CreateInBoundsGEP(GetType(Int), st, index);
        }
        else location = g_ir_builder->CreateInBoundsGEP(GetType(Float), st, index);
    }
    else location = g_ir_builder->CreateInBoundsGEP(var->getAllocatedType(), var, index);
    return location;
}

Value* Gen::GetArrayIndex(const AST::Variable* VarUnit) {
    Value* index = ValueGen(VarUnit->arr->len [(VarUnit->arr->len).size() - 1] );//这里能找到inde
    vector<AST::Exp*>* arrayLen = NamedValues.find_dim(VarUnit->varName);//这里能查到原数组的size
    for (int i = 0; i < (VarUnit->arr->len).size() - 1; ++i) {
        Value* arrayIndex = ValueGen((VarUnit->arr->len)[i]);
        for (int j = i + 1; j < (*arrayLen).size(); ++j) {
            arrayIndex = g_ir_builder->CreateMul(arrayIndex, ValueGen((*arrayLen)[j]));
        }
        index = g_ir_builder->CreateAdd(index, arrayIndex);
    }
    return index;
}

Type* Gen::GetType(basType FuncType) {
    switch (FuncType) {
    case Int:
        return Type::getInt32Ty(*g_llvm_context);
    case Float:
        return Type::getFloatTy(*g_llvm_context);
    case Void:
        return Type::getVoidTy(*g_llvm_context);
    }
}

Type* Gen::GetPtrType(basType FuncType) {
    switch (FuncType) {
    case Int:
        return Type::getInt32PtrTy(*g_llvm_context);
    case Float:
        return Type::getFloatPtrTy(*g_llvm_context);
    }
}

void Gen::StmtGen(Function* func, AST::BlockItem* item,BasicBlock*loopBB, BasicBlock* endLoopBB,bool&break_sign) {
    AST::Stmt* stmt = static_cast<AST::Stmt*>(item);
    if (stmt->stmtType == ifStmt) IfGen(func, static_cast<AST::IfStmt*>(stmt), loopBB, endLoopBB);
    else if (stmt->stmtType == whileStmt)WhileGen(func, static_cast<AST::WhileStmt*>(stmt));
    else if (stmt->stmtType == assignStmt)AssignGen(func, static_cast<AST::AssignStmt*>(stmt));
    else if (stmt->stmtType == returnStmt) {
        AST::ReturnStmt* ret = static_cast<AST::ReturnStmt*>(stmt);
        if (ret->retVal)
            g_ir_builder->CreateRet(ValueGen(ret->retVal));
        else g_ir_builder->CreateRetVoid();

    }
    else if (stmt->stmtType == breakStmt) break_sign = true;
    else if (stmt->stmtType == expStmt) {
       ValueGen(static_cast<AST::Exp*>(stmt));
        
    }
}

//IfGen used in While
void Gen::IfGen(Function* func, AST::IfStmt* ifStmt, BasicBlock* loopBB, BasicBlock* endLoopBB) {
    BasicBlock* ThenBB = BasicBlock::Create(*g_llvm_context, "if", func);
    BasicBlock* ElseBB = BasicBlock::Create(*g_llvm_context, "else", func);
    BasicBlock* MergeBB = BasicBlock::Create(*g_llvm_context, "merge", func);

    Value* cond = ValueGen(ifStmt->condition);
    g_ir_builder->CreateCondBr(cond, ThenBB, ElseBB);

    g_ir_builder->SetInsertPoint(ThenBB);
    std::vector<std::string*>removeList;
    bool break_sign = false;
    for (auto& blockItem : static_cast<AST::Block*>(ifStmt->ifBlock)->itemList) {
        if (blockItem->itemType == DECL) DeclGen(blockItem, removeList);
        else if (blockItem->itemType == STMT) StmtGen(func, blockItem,loopBB,endLoopBB,break_sign);
    }
    NamedValues.remove(removeList);
    if (!break_sign) g_ir_builder->CreateBr(MergeBB);
    
    break_sign = false;
    g_ir_builder->SetInsertPoint(ElseBB);
    if (ifStmt->elseBlock) {
        for (auto& blockItem : static_cast<AST::Block*>(ifStmt->elseBlock)->itemList) {
            if (blockItem->itemType == DECL) DeclGen(blockItem, removeList);
            else if (blockItem->itemType == STMT) StmtGen(func, blockItem,loopBB, endLoopBB,break_sign);
        }
        NamedValues.remove(removeList);
    }
    if (!break_sign) g_ir_builder->CreateBr(MergeBB);
    g_ir_builder->SetInsertPoint(MergeBB);
}

void Gen::WhileGen(Function* func, AST::WhileStmt* whileStmt) {
    BasicBlock* loopBB = BasicBlock::Create(*g_llvm_context, "loop", func);
    BasicBlock* endLoopBB = BasicBlock::Create(*g_llvm_context, "endLoop", func);

    Value* EndCond = ValueGen(whileStmt->condition);
    g_ir_builder->CreateCondBr(EndCond, loopBB, endLoopBB);

    g_ir_builder->SetInsertPoint(loopBB);
    vector<string*>removeList;
    bool no_use_sign;
    for (auto& item : static_cast<AST::Block*>(whileStmt->loopBlock)->itemList) {
        if (item->itemType == DECL) DeclGen(item, removeList);
        else if (item->itemType == STMT) StmtGen(func, item, loopBB, endLoopBB, no_use_sign);
    }
    NamedValues.remove(removeList);
    EndCond = ValueGen(whileStmt->condition);
    g_ir_builder->CreateCondBr(EndCond, loopBB, endLoopBB);
    g_ir_builder->SetInsertPoint(endLoopBB);
}

void Gen::AssignGen(Function* func, AST::AssignStmt* assginStmt) {
    AllocaInst* var = NamedValues.find(assginStmt->lVal->varName);
    Value* r = ValueGen(assginStmt->rVal);
    // 被赋值的是全局变量
    if (var == nullptr) {
        auto g_var = g_values.find(*assginStmt->lVal->varName);
        if (g_var == g_values.end()) {
            cout << "error:undefined variable" << endl;
            exit(1);
        }
        if (GetBType(g_var->second) != GetBType(r)) {
            if (GetBType(g_var->second) == Int) r = FloatToInt(r);
            else r = IntToFloat(r);

        }
        if (g_var->second->getValueType()->isArrayTy()) {
            auto index = GetArrayIndex(assginStmt->lVal);
            g_ir_builder->CreateStore(r, g_ir_builder->CreateInBoundsGEP(g_var->second->getValueType()->getScalarType(), g_var->second, index));
        }
        else g_ir_builder->CreateStore(r, g_var->second);
    }
    else {
        if (var->getAllocatedType()!=r->getType()) {
            if (var->getAllocatedType()->isIntegerTy())r = FloatToInt(r);
            else r = IntToFloat(r);
        }
        if (assginStmt->lVal->is_array) {
            Value* location = GetLocation(assginStmt->lVal, var);
            g_ir_builder->CreateStore(r, location);
        }
        else g_ir_builder->CreateStore(r, var);
    }
}

basType Gen::GetBType(GlobalVariable* var) {
    basType ret;
    auto tmp = var->getValueType();
    if (tmp->isArrayTy()) {
        if (tmp->getArrayElementType()->isIntegerTy()) ret = Int;
        else ret = Float;
    }
    else {
        if (tmp->isIntegerTy()) ret = Int;
        else ret = Float;
    }
    return ret;
}

basType Gen::GetBType(Value* var) {
    basType ret;
    if (var->getType()->isPointerTy()) {
        if (var->getType() == GetPtrType(Int))
            ret = Int;
        else ret = Float;
    }
    else {
        if (var->getType() == GetType(Int))
            ret = Int;
        else ret = Float;
    }
    return ret;
}

basType Gen::GetBType(const AllocaInst* var) {
    basType ret;
    if (var->getAllocatedType()->isPointerTy()) {
        if (var->getAllocatedType() == GetPtrType(Int))
            ret = Int;
        else ret = Float;
    }
    else {
        if (var->getAllocatedType() == GetType(Int))
            ret = Int;
        else ret = Float;
    }
    return ret;
}

//finalExp, lValExp, constNumExp, funcCall, mulExp, divExp, modExp, addExp, subExp, LTexp, GTexp, LEexp, GEexp, EQexp, NEexp, lAndExp, lOrExp
Value* Gen::BinaryExpGen(AST::BinaryExp* ast) {
    llvm::Value* lhs = ValueGen(ast->lExp);
    llvm::Value* rhs = ValueGen(ast->rExp);
    bool is_float = FloatGen(lhs, rhs);
    switch (ast->expType) {
    case addExp:
        if (is_float) return g_ir_builder->CreateFAdd(lhs, rhs);
        else return g_ir_builder->CreateAdd(lhs, rhs);
    case subExp:
        if (is_float) return g_ir_builder->CreateFSub(lhs, rhs);
        else return g_ir_builder->CreateSub(lhs, rhs);
    case mulExp:
        if (is_float) return g_ir_builder->CreateFMul(lhs, rhs);
        else return g_ir_builder->CreateMul(lhs, rhs);
    case divExp:
        if (lhs->getType()->isIntegerTy()) lhs = g_ir_builder->CreateSIToFP(lhs, Type::getFloatTy(*g_llvm_context));
        if (rhs->getType()->isIntegerTy()) rhs = g_ir_builder->CreateSIToFP(rhs, Type::getFloatTy(*g_llvm_context));
        return g_ir_builder->CreateFDiv(lhs, rhs);
    case modExp:
        if (lhs->getType()->isFloatTy()) lhs = FloatToInt(lhs);
        if (rhs->getType()->isFloatTy()) rhs = FloatToInt(rhs);
        return g_ir_builder->CreateSRem(lhs, rhs);
    case LTexp:
        if (is_float) return g_ir_builder->CreateFCmpOLT(lhs, rhs);
        else return g_ir_builder->CreateICmpSLT(lhs, rhs);
    case GTexp:
        if (is_float) return g_ir_builder->CreateFCmpOGT(lhs, rhs);
        else return g_ir_builder->CreateICmpSGT(lhs, rhs);
    case LEexp:
        if (is_float) return g_ir_builder->CreateFCmpOLE(lhs, rhs);
        else return g_ir_builder->CreateICmpSLE(lhs, rhs);
    case GEexp:
        if (is_float) return g_ir_builder->CreateFCmpOGE(lhs, rhs);
        else return g_ir_builder->CreateICmpSGE(lhs, rhs);
    case EQexp:
        if (is_float) return g_ir_builder->CreateFCmpOEQ(lhs, rhs);
        else return g_ir_builder->CreateICmpEQ(lhs, rhs);
    case NEexp:
        if (is_float) return g_ir_builder->CreateFCmpONE(lhs, rhs);
        else return g_ir_builder->CreateICmpNE(lhs, rhs);
    case lAndExp:
        return g_ir_builder->CreateAnd(lhs, rhs);
    case lOrExp:
        return g_ir_builder->CreateOr(lhs, rhs);
    }
}


bool Gen::FloatGen(Value*& L, Value*& R) {
    bool is_float = !(L->getType()->isIntegerTy() && R->getType()->isIntegerTy());
    if (is_float) {
        if (L->getType()->isIntegerTy()) L = IntToFloat(L);
        if (R->getType()->isIntegerTy()) R = IntToFloat(R);
    }
    return is_float;
}

Value* Gen::IntToFloat(Value* InitVal) {
    InitVal = g_ir_builder->CreateSIToFP(InitVal, Type::getFloatTy(*g_llvm_context));
    return InitVal;
}

Value* Gen::FloatToInt(Value* InitVal) {
    InitVal = g_ir_builder->CreateFPToSI(InitVal, Type::getInt32Ty(*g_llvm_context));
    return InitVal;
}

Value* Gen::FuncCallGen(AST::FuncCall* ast) {
    if (*(ast->funcName) == "printf") return PrintfGen(ast);
    if (*(ast->funcName) == "scanf") return ScanfGen(ast);
    llvm::Function* callee = g_module->getFunction(*(ast->funcName));
    std::vector<llvm::Value*> args{};
    if (ast->realArgList) {
        //注意传实参的时候数组类型会长成单变量的样子,lexp会被解读成单变量，所以不能那么简单每一个参数直接ValueGen
        for (auto& arg : ast->realArgList->realArgs) {
            if (arg->expType == lValExp) {
                AST::Variable* ast = static_cast<AST::Variable*>(arg);
                AllocaInst* var = NamedValues.find(ast->varName);
                if (var == nullptr) {
                    cout << "Error:Undefined Variable" << endl;
                    exit(1);
                }
                auto dim = NamedValues.find_dim(ast->varName);
                if (var->getAllocatedType()->isPointerTy()) {//这里的处理是为了funccall的实参是外层函数形参，并且形参指针的情况下，quicksort里调用quicksort
                    args.push_back(g_ir_builder->CreateLoad(var->getAllocatedType(), var, var->getName().data()));
                }
                else if (dim && ast->arr->len.empty()) {
                    args.push_back(g_ir_builder->CreateInBoundsGEP(var->getAllocatedType(), var, ConstantInt::get(*g_llvm_context, APInt(32, 0))));//对应main里面调用quicksort情况
                }
                else args.push_back(ValueGen(arg));
            }
            else  args.push_back(ValueGen(arg));
        }
    }
    return g_ir_builder->CreateCall(callee, args, "calltmp");
}

Value* Gen::PrintfGen(AST::FuncCall* ast) {
    Function* CalleeF = g_module->getFunction("printf");
    vector<Value*> ArgValues;
    // replace \n with ascii 10
    while ((*ast->IO).find("\\n") != string::npos)
       (*ast->IO).replace((*ast->IO).find("\\n"), 2, string(1, toascii(10)));
    auto* FormatStrInst = g_ir_builder->CreateGlobalStringPtr(*ast->IO, "printf_format_str");
    ArgValues.push_back(FormatStrInst);
    if (!ast->realArgList->realArgs.empty()) {
        for (auto& i : ast->realArgList->realArgs) {
            Value* Val = ValueGen(i);
            if (Val->getType()->isFloatTy())
                Val = g_ir_builder->CreateFPExt(Val, Type::getDoubleTy(*g_llvm_context));
            ArgValues.push_back(Val);
        }
    }
    return g_ir_builder->CreateCall(CalleeF, ArgValues, "c_printf");
}

Value* Gen::ScanfGen(AST::FuncCall* ast) {
    Function* CalleeF = g_module->getFunction("scanf");
    vector<Value*> ArgValues;
    auto* FormatStrInst = g_ir_builder->CreateGlobalStringPtr(*ast->IO, "scanf_format_str");
    ArgValues.push_back(FormatStrInst);
    if (!ast->realArgList->realArgs.empty()) {
        for (auto& Param : ast->realArgList->realArgs) {
                AST::Variable* VarUnit = static_cast<AST::Variable*>(Param);
                AllocaInst* var = NamedValues.find(VarUnit->varName);
                if (var == nullptr) {
                    auto global =g_values.find(*VarUnit->varName);
                    if (global == g_values.end()) {
                        cout << "error: undefined variable '" << *VarUnit->varName << "'" << endl;
                        exit(1);
                    }
                    auto global_var = global->second;
                    if (global_var->getValueType()->isArrayTy()) {
                        auto index = GetArrayIndex(VarUnit);
                        Value* ptr = g_ir_builder->CreateInBoundsGEP(global_var->getValueType()->getScalarType(), global_var, index);
                        ArgValues.push_back(ptr);
                    }
                    else
                        ArgValues.push_back(g_ir_builder->CreateInBoundsGEP(global_var->getValueType(), global_var,
                            ConstantInt::get(*g_llvm_context, APInt(32, 0))));
                }
                else {
                    if (!VarUnit->is_array)
                        ArgValues.push_back(g_ir_builder->CreateInBoundsGEP(var->getAllocatedType(), var,
                            ConstantInt::get(*g_llvm_context, APInt(32, 0))));
                    else {
                        Value* index = GetArrayIndex(VarUnit);
                        ArgValues.push_back(g_ir_builder->CreateInBoundsGEP(var->getAllocatedType(), var, index));
                    }
                }
            
        }
    }
    return g_ir_builder->CreateCall(CalleeF, ArgValues, "c_scanf");
}
