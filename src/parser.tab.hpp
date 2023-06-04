/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_SKYLAR_MYCOMPILER_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_HOME_SKYLAR_MYCOMPILER_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include <memory>
  #include <string>
  #include "AST.hpp"
  #include <vector>
  #include "myFlexer.hpp"

#line 57 "/home/skylar/myCompiler/src/parser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    RETURN = 261,                  /* RETURN  */
    CONST = 262,                   /* CONST  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    BREAK = 266,                   /* BREAK  */
    CONTINUE = 267,                /* CONTINUE  */
    NE = 268,                      /* NE  */
    EQ = 269,                      /* EQ  */
    LE = 270,                      /* LE  */
    GE = 271,                      /* GE  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    PRINTF = 274,                  /* PRINTF  */
    SCANF = 275,                   /* SCANF  */
    IDENT = 276,                   /* IDENT  */
    STRING = 277,                  /* STRING  */
    INT_CONST = 278,               /* INT_CONST  */
    FLOAT_CONST = 279              /* FLOAT_CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "src/parser.y"

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
  basType type_val;

#line 117 "/home/skylar/myCompiler/src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (AST::CompUnit* &Ast, myFlexer &Flexer);


#endif /* !YY_YY_HOME_SKYLAR_MYCOMPILER_SRC_PARSER_TAB_HPP_INCLUDED  */
