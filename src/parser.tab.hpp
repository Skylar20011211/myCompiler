
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "src/parser.y"

  #include <memory>
  #include <string>
  #include "AST.hpp"
  #include <vector>



/* Line 1676 of yacc.c  */
#line 49 "C:/course/Compiler/myCompiler/src/parser.tab.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     VOID = 260,
     RETURN = 261,
     CONST = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     BREAK = 266,
     CONTINUE = 267,
     NE = 268,
     EQ = 269,
     LE = 270,
     GE = 271,
     AND = 272,
     OR = 273,
     IDENT = 274,
     PRINTF = 275,
     SCANF = 276,
     STRING = 277,
     INT_CONST = 278,
     FLOAT_CONST = 279
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "src/parser.y"

  std::string* str_val;
  int int_val;
  float float_val;
  AST::CompUnit* comp_unit_val;
  AST::VarDecl* var_decl_val;
  AST::VarDefList* var_def_list_val;
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



/* Line 1676 of yacc.c  */
#line 113 "C:/course/Compiler/myCompiler/src/parser.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


