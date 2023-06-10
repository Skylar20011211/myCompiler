#include "AST.hpp"
#include <string>
#include <fstream>
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
std::fstream ofs;

void AST::CompUnit::Dump()const {
    ofs.open("visual.json", ios::out);
	ofs << "{\"name\":\"Program\"," <<endl;
	ofs << "\"children\":[" <<endl;
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
	ofs << "]}" <<endl;
	ofs.close();
}

void AST::Variable::Dump()const {
	ofs << "{\"name\":\"Variable:" << typeNames[bType] << "\"," << endl;
	ofs << "\"children\":[" <<endl;
	if (!is_array) {
		ofs << "{\"name\":\"Ident:" << *varName << "\"";
		if (initValList) {
			ofs <<","<<endl;
			ofs << "\"children\":[";
			ofs << "{\"name\":\"= InitVal\"," <<endl;
			ofs << "\"children\":[" <<endl;
			std::vector<AST::Exp*>::iterator it = initValList->valList.begin();
			(*it)->Dump();
			ofs << "]";
			ofs << "}" <<endl;
			ofs << "]";
		}
		ofs << "}" <<endl;
	}
	else {
		ofs << "{\"name\":\"ArrayIdent:" << *varName << "\"," <<endl;
		ofs << "\"children\":[" <<endl;
		for (std::size_t i = 0; i < arr->len.size(); ++i) {
				arr->len[i]->Dump();
		}
		ofs << "]";
		ofs << "}," << endl;
		if (initValList) {
			ofs << "{\"name\":\"= InitVal\"," << endl;
			ofs << "\"children\":[" <<endl;
			for (const auto& initVal : initValList->valList) {
					ofs << static_cast<AST::ConstNumber*>(initVal)->val;
			}
			ofs << "]";
			ofs << "},"  <<endl;
		}
	}	
	ofs << "]}," <<endl;
}

void AST::Func::Dump() const {
	ofs << "{"<<endl;
	ofs << "\"name\":\"FuncDef\"," << endl;
	ofs <<"\"children\":["<<endl;
	ofs << "{\"name\":\""<< typeNames[funcType] <<"\"},"<< endl;
	ofs << "{\"name\":\""<< *funcName <<"\"},"<< endl;
	if (argList) {
		ofs << "{\"name\":\"FuncFParams\","<<endl;
		ofs<<"\"children\":["<<endl;
		for (std::size_t i = 0; i < argList->args.size(); ++i) {
			ofs<<"{\"name\":\"";
			argList->args[i]->Dump();
			ofs<<"\"},";
			ofs << endl;
		}
		ofs<<"{\"name\":\"void\"}"<<endl;
		ofs<<"]";
		ofs<<"},"<<endl;
	}
	ofs <<"{\"name\":\"Block\"," << endl;
	ofs<<"\"children\":["<<endl;
	for (const auto& item : funcBody->itemList) {
		ofs << space2;
		item->Dump();
		ofs << endl;
	}
	ofs<<"]";
	ofs<<"}"<<endl;
	ofs<< "]";
	ofs << "},"<<endl;
}

void AST::Arg::Dump()const {
	if (is_pointer) {
		ofs<<typeNames[bType];
	}
	else ofs <<typeNames[bType];
}

void AST::BlockItem::Dump()const {
	if (itemType == DECL) {
		Variable* ptr = static_cast<AST::Variable*>(const_cast<AST::BlockItem*>(this));
		ptr->Dump();
	}
	else {
		Stmt*ptr = static_cast<AST::Stmt*>(const_cast<AST::BlockItem*>(this));
		ptr->Dump();
	}
}

void AST::Stmt::Dump()const {
	ofs << "{\"name\":\"StmtType:" << stmtTypeNames[stmtType] <<"\"},"<<endl;
	switch (this->stmtType) {
	case assignStmt: static_cast<AssignStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case ifStmt:  static_cast<IfStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case whileStmt:   static_cast<WhileStmt*>(const_cast<Stmt*>(this))->Dump(); break;
	case returnStmt:  static_cast<ReturnStmt*>(const_cast<Stmt*>(this)) ->Dump(); break;
	case blockStmt:
		for (const auto& item : static_cast<Block*>(const_cast<Stmt*>(this))->itemList) {
			ofs << space2;
			item->Dump();
			ofs << endl;
		}
	}
}

void AST::AssignStmt::Dump()const {
	ofs << "{\"name\":\"AssignStmt\"," <<endl;
	ofs << "\"children\":[" << endl;
	ofs << "{\"name\":\"LVal\"," << endl;
	ofs << "\"children\":[" << endl;
	lVal->Dump();
	ofs << "]";
	ofs << "}," << endl; 
	ofs << "{\"name\":\"Exp\"," << endl;
	ofs << "\"children\":[" << endl;
	rVal->Dump();
	ofs << "]";
	ofs << "}" << endl;
	ofs << "]";
	ofs << "}," << endl; 
}

void AST::IfStmt::Dump()const {
	ofs << "{\"name\":\"IfStmt\"," << endl;
	ofs << "\"children\":[" <<endl;
	ofs << "{\"name\":\"IfCond\"," <<endl;
	ofs << "\"children\":[" <<endl;
	condition->Dump();
	ofs << "]";
	ofs << "}," <<endl;
	ofs << "{\"name\":\"IfBlock\"," <<endl;
	ofs << "\"children\":[" <<endl;
	ifBlock->Dump();
	ofs << "]";
	ofs << "}," <<endl;

	if (elseBlock) {
		ofs << "{\"name\":\"elseBlock\"," <<endl;
		ofs << "\"children\":[" <<endl;
		elseBlock->Dump();
		ofs << "]";
		ofs << "}" <<endl;
	}
	ofs << "]}," <<endl;
}

void AST::WhileStmt::Dump()const {
	ofs << "{\"name\":\"WhileStmt\","<<endl;
	ofs << "\"children\":[" <<endl;
	ofs << "{\"name\":\"WhileCond\"," <<endl;
	ofs << "\"children\":[" <<endl;
	condition->Dump();
	ofs << "]";
	ofs << "}," <<endl;
	ofs << "{\"name\":\"LoopStmt\"," <<endl;
	ofs << "\"children\":[" <<endl;
	loopBlock->Dump();
	ofs << "]";
	ofs << "}" <<endl;
	ofs << "]}," <<endl;
}

void AST::ReturnStmt::Dump()const {
	ofs << "{\"name\":\"StmtType:" << stmtTypeNames[stmtType] <<"\"},"<<endl;
	ofs << "{\"name\":\"RetVal\"," << endl;
	ofs << "\"children\":[" <<endl;
	retVal->Dump();
	ofs << "]";
	ofs << "}"<<endl;
}

void AST::Exp::Dump()const {
	ofs << expTypeNames[expType] << endl;
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
	ofs << "{\"name\":\"BType:" << typeNames[constType] << "\"," << endl;
	ofs << "\"children\":[" <<endl;
	ofs << "{\"name\":\"Val:" << val << "\"}" << endl;
	ofs << "]";
	ofs << "},"<<endl;
}

void AST::FinalExp::Dump()const {
	ofs << "{\"name\":\"IExp\"," <<endl;
	ofs << "\"children\":[" <<endl;
	iExp->Dump();
	ofs << "]";
	ofs << "}," <<endl;
}

void AST::BinaryExp::Dump()const {
	ofs << "{\"name\":\"LExp\"," <<endl;
	ofs << "\"children\":[" <<endl;
	lExp->Dump();
	ofs << "]";
	ofs << "}," <<endl;

	ofs << "{\"name\":\"RExp\"," <<endl;
	ofs << "\"children\":[" <<endl;
	rExp->Dump();
	ofs << "]";
	ofs << "}," <<endl;
}

void AST::FuncCall::Dump()const {
	ofs <<"{\"name\":\"Ident:"<<*funcName<<"\"},"<<endl;
	if (realArgList) {
		ofs<<"{\"name\":\"FuncRParams\","<<endl;
		ofs<<"\"children\":["<<endl;
		for (const auto& arg : realArgList->realArgs) {
			arg->Dump();
		}
        ofs<<"]},"<<endl;
	}
	ofs << endl;
}