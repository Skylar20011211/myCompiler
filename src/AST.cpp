#include "AST.hpp"
#include <string>
using namespace std;
const char* typeNames[]{
	"Int",
	"Float",
	"Void"
};

const char* stmtTypeNames[]{
	 "assignStmt",
	 "expStmt","blockStmt","ifStmt","whileStmt","breakStmt","continueStmt","returnStmt"
};

const char* expTypeNames[]{
	"finalExp","lValExp","constNumExp", "funcCall", "mulExp", "divExp","modExp","addExp","subExp","LTexp","GTexp","LEexp","GEexp","EQexp","NEexp","lAndExp","lOrExp"
};


std::string space1(4, ' ');
std::string space2(8, ' ');
std::string space3(12, ' ');



void AST::CompUnit::Dump()const {
	for (const auto& Unit :units) {
		if (Unit->unitType == VarDeclare) {
			Variable* ptr = static_cast<Variable*>(Unit);
			ptr->Dump();
		}
	    else {
			Func* ptr = static_cast<Func*>(Unit);
			ptr->Dump();
		}
	}
}

void AST::Variable::Dump()const {
	cout << "Variable: "<<typeNames[bType];
	if (!is_array) {
		cout << " Ident:" << *varName;
		if (initValList) {
			cout << "= InitVal:";
			std::vector<AST::Exp*>::iterator it = initValList->valList.begin();
			(*it)->Dump();
		}
	}
	else {
		cout << " Ident:" << *varName;
		for (std::size_t i = 0; i < arr->len.size(); ++i) {
			cout << '[';
				arr->len[i]->Dump();
				cout << ']';
		}
		if (initValList) {
			cout << "= InitVal:{";
			for (const auto& initVal : initValList->valList) {
					cout << static_cast<AST::ConstNumber*>(initVal)->val;
			}
			cout << "}";
		}
	}	
}

void AST::Func::Dump() const {
	cout << "FuncDef:{" << endl;
	cout << space1<<"FuncType:" << typeNames[funcType] << endl;
	cout << space1<<"Ident:" << *funcName << endl;
	cout << space1<<"FuncFParams:" << endl;
	if (argList) {
		for (std::size_t i = 0; i < argList->args.size(); ++i) {
			cout << space2 << "FuncFParam: ";
			argList->args[i]->Dump();
			cout << endl;
		}
	}
	cout << space1<<"Block:" << endl;
	for (const auto& item : funcBody->itemList) {
		cout << space2;
		item->Dump();
		cout << endl;
	}
	cout << "}"<<endl;
}

void AST::Arg::Dump()const {
	if (is_pointer) {
		cout << "ArgType:"<<typeNames[bType] << " Ident:" << *(this->argName) << "[]";
	}
	else cout << "ArgType:"<<typeNames[bType] << " Ident:" << *argName;
}

void AST::BlockItem::Dump()const {
	if (itemType == Decl) {
		Variable* ptr = static_cast<AST::Variable*>(const_cast<AST::BlockItem*>(this));
		ptr->Dump();
	}
	else {
		Stmt*ptr = static_cast<AST::Stmt*>(const_cast<AST::BlockItem*>(this));
		ptr->Dump();
	}
}

void AST::Stmt::Dump()const {
	cout << "StmtType:"<<stmtTypeNames[stmtType]<<endl;
	switch (this->stmtType) {
	case assignStmt: static_cast<AssignStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case ifStmt:  static_cast<IfStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case whileStmt:   static_cast<WhileStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case returnStmt:  static_cast<ReturnStmt*>(const_cast<Stmt*>(this)) ->Dump(); break;
	case blockStmt:
		for (const auto& item : static_cast<Block*>(const_cast<Stmt*>(this))->itemList) {
			cout << space2;
			item->Dump();
			cout << endl;
		}
	}
}

void AST::AssignStmt::Dump()const {
	cout << "LVal: ";
	lVal->Dump();
	cout << endl;
	cout << "Exp: " << endl;
	cout << space1;
	rVal->Dump();
	cout << endl;
}

void AST::IfStmt::Dump()const {
	cout << "Cond:" << endl;
	cout << space1;
	condition->Dump();
	cout << "IfBlock:"<<endl;
	cout << space1;
	ifBlock->Dump();
	if (elseBlock) {
		cout << "ElseBlock:" << endl;
		cout << space1;
		elseBlock->Dump();
	}
	cout << endl;
}

void AST::WhileStmt::Dump()const {
	cout << "Cond:" << endl;
	cout << space1;
	condition->Dump();
	cout << "LoopStmt:"<<endl;
	cout << space1;
	loopBlock->Dump();
	cout << endl;
}

void AST::ReturnStmt::Dump()const {
	cout << "StmtType:" << stmtTypeNames[stmtType] << endl;
	cout << space2<<"RetVal:" << endl;
	retVal->Dump();
	cout << endl;
}

void AST::Exp::Dump()const {
	cout << expTypeNames[expType] << endl;
	switch (this->expType) {
	case finalExp:static_cast<FinalExp*>(const_cast<Exp*>(this))->Dump(); break;
	case lValExp: static_cast<Variable*>(const_cast<Exp*>(this))->Dump(); break;
	case constNumExp:static_cast<ConstNumber*>(const_cast<Exp*>(this))->Dump(); break;
	case mulExp: case divExp:case modExp:case addExp:case subExp:case LTexp:case GTexp:case LEexp:case GEexp:case EQexp:case NEexp:case lAndExp:case lOrExp:
		static_cast<BinaryExp*>(const_cast<Exp*>(this)) ->Dump(); break;
	case funcCall:static_cast<FuncCall*>(const_cast<Exp*>(this))->Dump(); break;
	}
}

void AST::ConstNumber::Dump()const {
	cout << "BType:" << typeNames[constType] << endl;
	cout << "Val:" << val << endl;
	cout << endl;
}

void AST::FinalExp::Dump()const {
	cout << "IExp:" << endl;
	cout << space1;
	iExp->Dump();
	cout << endl;
}

void AST::BinaryExp::Dump()const {
	cout << "LExp:" << endl;
	cout << space1;
	lExp->Dump();
	cout << "RExp:" << endl;
	cout << space1;
	rExp->Dump();
	cout << endl;
}


void AST::FuncCall::Dump()const {
	cout << "Ident:";
	cout << *funcName << endl;
	cout << "FuncRParams:" << endl;
	for (const auto& arg : realArgList->realArgs) {
		cout << space1 << "FuncRParam:";
		arg->Dump();
	}
	cout << endl;
}




