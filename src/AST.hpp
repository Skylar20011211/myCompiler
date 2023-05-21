#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <exception>

enum Type { Int, Float, Void};
enum BlockItemType {Decl,Stmt};
enum ExpType {finalExp,lValExp,constNumExp, funcCall, mulExp, divExp,modExp,addExp,subExp,LTexp,GTexp,LEexp,GEexp,EQexp,NEexp,lAndExp,lOrExp};
enum StmtType{ assignStmt, expStmt,blockStmt,ifStmt,whileStmt,breakStmt,continueStmt,returnStmt};
enum UnitType{VarDeclare,Func};

namespace AST {

	//Forward declarations

	class BaseAST;

	/*** Root ***/
	class CompUnit;
	class Unit;
	class BlockItem;
	class Stmt;

	/*** Function ***/
	class Func;
	class ArgList;
	class Arg;
	class Block;

	/*** Declarations ***/
	class VarDecl;
	class VarDefList;
	class Variable;


	/*** Variable Types ***/
	class ArrayType;

	class InitValList;


	/*** Statements ***/
	
	class AssignStmt;
	class IfStmt;
	class WhileStmt;
	class ReturnStmt;

	/*** Expressions ***/
	class Exp;
	class ConstNumber;
	class FuncCall;
	class RealArgList;
	class BinaryExp;
	class FinalExp;
}

namespace AST {
	class BaseAST {
	public:
		virtual ~BaseAST() = default;
		virtual void Dump() const = 0;
	};

	class CompUnit : public BaseAST {
	public:
		std::vector<Unit*> units;
		void Dump() const override;
	};

	class Unit :public BaseAST {
	public:
		UnitType unitType;
	};

	class BlockItem :public BaseAST {
	public:
		BlockItemType itemType;
		void Dump() const override;
	};

	class Stmt : public BlockItem {
	public:
		StmtType stmtType;
		void Dump() const override;
	};

	class Exp :public Stmt {
	public:
		ExpType expType;
		void Dump() const override;
	};

	class Block :public Stmt {
	public:
		std::vector<BlockItem*>itemList;
	};


	class Variable :public Exp, public Unit {
	public:
		std::string* varName;
		bool is_array;
		Type bType;
		ArrayType* arr;
		InitValList* initValList;
		void Dump() const override;
	};

	class ConstNumber :public Exp {
	public:
		Type constType;
		float val;
		void Dump() const override;
	};

	class ArrayType : public ConstNumber {
	public:
		std::vector<Exp*> len;
	};

	class InitValList :public Exp {
	public:
		std::vector<Exp*> valList;
	};

	class Func : public Unit{
	public:
		Type funcType;
		std::string* funcName;
		ArgList* argList;
		Block* funcBody;
		void Dump() const override;
	};

	class Arg :public BaseAST {
	public:
		std::string* argName;
		Type bType;
		bool is_pointer;
		void Dump() const override;
	};
	
	class ArgList :public Arg {
	public:
		std::vector<Arg*> args;
	};

	class AssignStmt : public Stmt {
	public:
		Variable* lVal;
		Exp* rVal;
		void Dump() const override;
	};

	class IfStmt : public Stmt {
	public:
		Exp* condition;
		Stmt* ifBlock;
		Stmt* elseBlock;
		void Dump() const override;
	};

	class WhileStmt : public Stmt {
	public:
		Exp* condition;
		Stmt* loopBlock;
		void Dump() const override;
	};

	class ReturnStmt :public Stmt {
	public:
		Exp* retVal;
		void Dump() const;
	};
	
	class FinalExp :public Exp {
	public:
		Exp* iExp;
		void Dump() const override;
	};

	

	class BinaryExp: public Exp {
	public:
		Exp* lExp;
		Exp* rExp;
		void Dump() const override;
	};
	
	class FuncCall :public Exp {
	public:
		std::string* funcName;
		RealArgList* realArgList;
		std::string*IO;
		void Dump() const override;
	};

	class RealArgList :public Exp {
	public:
		std::vector<Exp*> realArgs;
	};
	

}
// ...
