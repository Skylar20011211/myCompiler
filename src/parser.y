%code requires {
  #include <memory>
  #include <string>
  #include "AST.hpp"
  #include <vector>
}

%{
#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

int yylex();
void yyerror(AST::CompUnit* &Ast, const char *s);
using namespace std;
%}

%parse-param { AST::CompUnit* &Ast }

%union {
  std::string* str_val;
  int int_val;
  float float_val;
  AST::CompUnit* comp_unit_val;
  AST::Variable* var_val;
  AST::ArrayType* arr_val;
  AST::InitValList* init_val_list_val;
  AST::Func* func_val;
  AST::ArgList* arg_list_val;
  AST::Arg* arg_val;
  AST::Block* block_val;
  AST::BlockItem* block_item_val;
  AST::Stmt* stmt_val;
  AST::RealArgList* real_arg_list_val;
  AST::Exp* exp_val;
  Type type_val;
}

%token INT FLOAT VOID RETURN CONST IF ELSE WHILE BREAK CONTINUE NE EQ LE GE AND OR PRINTF SCANF
%token <str_val> IDENT STRING
%token <int_val> INT_CONST
%token<float_val>FLOAT_CONST
%type<comp_unit_val> CompUnit
%type<var_val>VarDef LVal  VarDecl
%type<arr_val>Exp_Wrap
%type<init_val_list_val>InitVal InitValList
%type<func_val>FuncDef
%type<arg_list_val>FuncFParams
%type<arg_val>FuncFParam
%type<block_val>Block BlockItemList
%type<block_item_val>BlockItem
%type<stmt_val>Stmt
%type<exp_val>Exp Cond PrimaryExp  FinalExp Number UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp
%type <real_arg_list_val>FuncRParams
%type<type_val>BType 

%%

CompUnit
	: FuncDef {
    auto comp_unit = new AST::CompUnit();
	$1->unitType=Func;
    comp_unit->units.push_back($1);
    Ast =comp_unit;
	$$=comp_unit;
    }
	|VarDecl{
	auto comp_unit=new AST::CompUnit();
	$1->unitType=VarDeclare;
	comp_unit->units.push_back($1);
	Ast =comp_unit;
	$$=comp_unit;
	}
	|CompUnit FuncDef{
	$2->unitType=Func;
	$1->units.push_back($2);
	Ast =$1;
	$$=$1;
	}
	|CompUnit VarDecl{
	$2->unitType=VarDeclare;
	$1->units.push_back($2);
	Ast =$1;
	$$=$1;
	}
	;

BType
	:INT{
	    Type var_type=Int;
		$$=var_type;
	}
	|FLOAT{
		Type var_type=Float;
		$$=var_type;
	}
	|VOID{
		Type var_type=Void;
		$$=var_type;  
	}
	;

VarDecl
	:VarDef ';'{
		$$=$1;
	}
	;

VarDef
	:BType IDENT{
		auto ast=new AST::Variable();
		ast->bType=$1;
		ast->varName=$2;
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		$$=ast;
	}
	|BType IDENT Exp_Wrap{
		auto ast=new AST::Variable();
		ast->bType=$1;
		ast->varName=$2;
		ast->is_array=true;
		ast->arr=$3;
		ast->initValList=nullptr;
		$$=ast;
	}
	|BType IDENT'='InitVal{
		auto ast=new AST::Variable();
		ast->bType=$1;
		ast->varName=$2;
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=$4;
		$$=ast;
	}
	|BType IDENT Exp_Wrap '='InitVal{
		auto ast=new AST::Variable();
		ast->bType=$1;
		ast->varName=$2;
		ast->is_array=true;
		ast->arr=$3;
		ast->initValList=$5;
		$$=ast;
	}
	;

Exp_Wrap
	:'[' Exp ']'{
		auto ast=new AST::ArrayType();
		ast->len.push_back($2);
		$$=ast;
	}
	|'[' Exp ']' Exp_Wrap{
		$4->len.insert($4->len.begin(),$2);
		$$=$4;
	}
	;

InitVal
	:Exp{
		auto ast=new AST::InitValList();
		ast->valList.push_back($1);
		$$=ast;
	}
	|'{' InitValList '}'{$$=$2;}
	;


InitValList 
	:Exp{
		auto ast=new AST::InitValList();
		ast->valList.push_back($1);
		$$=ast;
	}
	|InitValList ',' Exp{
		$1->valList.push_back($3);
		$$=$1;
	}
	;

FuncDef
  : BType IDENT '(' ')' Block {
    auto func = new AST::Func();
    func->funcType = $1;
	func->funcName=$2;
	func->argList=nullptr;
	func->funcBody = $5;
    $$ = func;
  }
  |BType IDENT '('FuncFParams ')' Block{
	auto func = new AST::Func();
    func->funcType = $1;
	func->funcName=$2;
	func->argList=$4;
	func->funcBody = $6;
    $$ = func;
  }
  ;

FuncFParams
	:FuncFParam{
		auto ast= new AST::ArgList();
	    ast->args.push_back($1);
		$$=ast;
	}
	|FuncFParams ',' FuncFParam{
		$1->args.push_back($3);
		$$=$1;
	}
	;
	
FuncFParam
	:BType IDENT {
		auto ast=new AST::Arg();
		ast->argName=$2;
		ast->bType=$1;
		ast->is_pointer=false;
		$$=ast;
	}
	|BType IDENT '[' ']'{
		auto ast=new AST::Arg();
		ast->argName=$2;
		ast->bType=$1;
		ast->is_pointer=true;
		$$=ast;
	}
	|BType IDENT '[' ']' Exp_Wrap{}
	;

Block
  : '{' BlockItemList '}' {
    $$=$2;
  }
  ;
  
BlockItemList
	:BlockItem{
		auto ast=new AST::Block();
		ast->itemList.push_back($1);
		$$=ast;
	}
	|BlockItemList BlockItem{
		$1->itemList.push_back($2);
		$$=$1;
	}
	;
	
BlockItem
	:VarDecl{$1->itemType=Decl;$$=$1;}
	|Stmt{$1->itemType=Stmt;$$=$1;}
	;
	
Stmt
	:LVal '=' Exp ';'{
		auto ast=new AST::AssignStmt();
		ast->stmtType=assignStmt;
		ast->lVal=$1;
		ast->rVal=$3;
		$$=ast;
	}
	|Exp ';'{$1->stmtType=expStmt;$$=$1;}
	|Block{$1->stmtType=blockStmt;$$=$1;}
	|IF '(' Cond ')' Stmt{
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=$3;
		ast->ifBlock=$5;
		ast->elseBlock=nullptr;
		$$=ast;
	}
	|IF '(' Cond ')' Stmt ELSE Stmt{
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=$3;
		ast->ifBlock=$5;
		ast->elseBlock=$7;
		$$=ast;
	}
	|WHILE '(' Cond ')' Stmt{
		auto ast=new AST::WhileStmt();
		ast->stmtType=whileStmt;
		ast->condition=$3;
		ast->loopBlock=$5;
		$$=ast;
	}
	|BREAK ';'{
		auto ast=new AST::Stmt();
		ast->stmtType=breakStmt;
		$$=ast;
	}
	|CONTINUE ';'{
		auto ast=new AST::Stmt();
		ast->stmtType=continueStmt;
		$$=ast;
	}
	|RETURN Exp ';'{
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=$2;
		$$=ast;
	}
	|RETURN ';' {
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=nullptr;
		$$=ast;
	}
  ;
  
Exp:AddExp{$$=$1;};

Cond:LOrExp{$$=$1;};

LVal
	:IDENT{
		auto ast=new AST::Variable();
		ast->varName=$1;
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		$$=ast;
	}
	|IDENT Exp_Wrap{
		auto ast=new AST::Variable();
		ast->varName=$1;
		ast->is_array=true;
		ast->arr=$2;
		ast->initValList=nullptr;
		$$=ast;
	}
	;
	
PrimaryExp
	:FinalExp{$1->expType=finalExp;$$=$1;}
	|LVal{$1->expType=lValExp;$$=$1;}
	|Number{$1->expType=constNumExp;$$=$1;}
	;

FinalExp
	:'(' Exp ')'{
		auto ast=new AST::FinalExp();
		ast->iExp=$2;
		$$=ast;
	}
	;

Number
  : INT_CONST {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Int;
	  ast->val=$1;
	  $$=ast;
  }
  | FLOAT_CONST {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Float;
	  ast->val=$1;
	  $$=ast;
  }
  ;

UnaryExp
	:PrimaryExp{$$=$1;}

	|IDENT '(' ')'{
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=$1;
		ast->realArgList=nullptr;
		ast->IO=nullptr;
		$$=ast;
		
	}
	|IDENT '(' FuncRParams ')'{
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=$1;
		ast->realArgList=$3;
		ast->IO=nullptr;
		$$=ast;
	}
	|PRINTF '(' STRING ')' {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=nullptr;
		ast->IO=$3;
		$$=ast;
	
	}
	|PRINTF '(' STRING ',' FuncRParams ')'{
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=$5;
		ast->IO=$3;
		$$=ast;
	}
	|SCANF '(' STRING ')' {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=nullptr;
		ast->IO=$3;
		$$=ast;
	}
	|SCANF '(' STRING ',' FuncRParams ')'{
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=$5;
		ast->IO=$3;
		$$=ast;
		
	}
	|UnaryOp UnaryExp {}
	;

UnaryOp
	:'-'{}
	|'+'{}
	|'!'{}
	;
	
FuncRParams
	:Exp{
		auto ast=new AST::RealArgList();
		ast->realArgs.push_back($1);
		$$=ast;
	}
	|FuncRParams ',' Exp{
		$1->realArgs.push_back($3);
		$$=$1;
	}
	;

MulExp
	:UnaryExp{$$=$1;}
	|MulExp '*' UnaryExp{
		auto ast=new AST::BinaryExp();
		ast->expType=mulExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|MulExp '/' UnaryExp{
		auto ast=new AST::BinaryExp();
		ast->expType=divExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|MulExp '%' UnaryExp{
		auto ast=new AST::BinaryExp();
		ast->expType=modExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
	
AddExp
	:MulExp{$$=$1;}
	|AddExp '+' MulExp{
		auto ast=new AST::BinaryExp();
		ast->expType=addExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|AddExp '-' MulExp{
		auto ast=new AST::BinaryExp();
		ast->expType=subExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
	
RelExp
	:AddExp{$$=$1;}
	|RelExp '<' AddExp{
		auto ast=new AST::BinaryExp();
		ast->expType=LTexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|RelExp '>' AddExp{
		auto ast=new AST::BinaryExp();
		ast->expType=GTexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|RelExp LE AddExp{
		auto ast=new AST::BinaryExp();
		ast->expType=LEexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|RelExp GE AddExp{
		auto ast=new AST::BinaryExp();
		ast->expType=GEexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
	
EqExp
	:RelExp{$$=$1;}
	|EqExp EQ RelExp{
		auto ast=new AST::BinaryExp();
		ast->expType=EQexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	|EqExp NE RelExp{
		auto ast=new AST::BinaryExp();
		ast->expType=NEexp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
	
LAndExp
	:EqExp{$$=$1;}
	| LAndExp AND EqExp{
		auto ast=new AST::BinaryExp();
		ast->expType=lAndExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
	
LOrExp
	:LAndExp{$$=$1;}
	|LOrExp OR LAndExp{
		auto ast=new AST::BinaryExp();
		ast->expType=lOrExp;
		ast->lExp=$1;
		ast->rExp=$3;
		$$=ast;
	}
	;
%%

void yyerror(AST::CompUnit* &Ast , const char *s) {
  cerr << "error: " << s << endl;
}
