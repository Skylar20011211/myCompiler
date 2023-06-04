#ifndef CODE_GEN_HPP
#define CODE_GEN_HPP

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/ValueSymbolTable.h"
#include "llvm/IR/SymbolTableListTraits.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/LoopUnrollPass.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Vectorize/LoopVectorize.h"
#include"llvm/ADT/Optional.h"

#include"AST.hpp"
#include"symbolTable.hpp"
using namespace llvm;

class Gen {
public:
	// ��¼��LLVM�ĺ������ݽṹ���������ͺͳ��������������ǲ�̫��Ҫ���������ڲ�
	LLVMContext* g_llvm_context;
	// ���ڴ���LLVMָ��
	IRBuilder<>* g_ir_builder;
	// ���ڹ���������ȫ�ֱ��������Դ�ǳ������Ϊ��c++�ı��뵥Ԫ(����cpp�ļ�)
	Module* g_module;
	SymbolTable NamedValues;
	std::unique_ptr<legacy::FunctionPassManager> TheFPM;
	// ���ڼ�¼�����ı�������
	std::map<std::string, GlobalVariable*> g_values;
	Gen();
	void CompUnitGen(AST::CompUnit*& ast);
	void FuncGen(AST::Unit* & unit);
	Type* GetType(basType FuncType);
	Type* GetPtrType(basType FuncType);
	void GlobalVarGen(AST::Unit*& unit);
	Value* ValueGen(AST::Exp* ast);
	Value* GetArraySize(AST::Variable*& ast);
	AllocaInst* createBlockPtrAlloca(BasicBlock& block, const string* VarName, basType VarType);
	AllocaInst* createBlockAlloca(BasicBlock& block, const string* VarName, basType VarType);
	AllocaInst* createBlockArrayAlloca(BasicBlock& block, const string* VarName, basType VarType, Value* ArraySize);
	void DeclGen(AST::BlockItem*& item, vector<std::string*>& removeList);
    vector<AST::Exp*>* find_dim(const string* name);
	Value* GetArrayIndex(const AST::Variable* VarUnit);
	Value* GetLocation(AST::Variable*& VarUnit, AllocaInst* var);
	void StmtGen(Function* func, AST::BlockItem* item, BasicBlock* loopBB, BasicBlock* endLoopBB, bool& break_sign);
	void IfGen(Function* func, AST::IfStmt* item);
	void WhileGen(Function* func, AST::WhileStmt* item);
	void AssignGen(Function* func, AST::AssignStmt* item);
	Value* BinaryExpGen(AST::BinaryExp* ast);
	bool FloatGen(Value*& L, Value*& R);
	Value* IntToFloat(Value* InitVal);
	Value* FloatToInt(Value* InitVal);
	Value* FuncCallGen(AST::FuncCall* ast);
	basType GetBType(GlobalVariable* var);
	basType GetBType(Value* var);
	basType GetBType(const AllocaInst* var);
	void IfGen(Function* F, AST::IfStmt* ifStmt, BasicBlock* loopBB, BasicBlock* endLoopBB);
	Value* PrintfGen(AST::FuncCall* ast);
	Value* ScanfGen(AST::FuncCall* ast);
	void InitExternalFunction();
	void OutputGen();
};
#endif // !CODE_GEN_HPP