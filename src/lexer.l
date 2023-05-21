%option noyywrap
%option nounput
%option noinput

%{

#include <cstdlib>
#include <string>

// 因为 Flex 会用到 Bison 中关于 token 的定义
// 所以需要 include Bison 生成的头文件
#include "parser.tab.hpp"
using namespace std;

%}

/* 空白符和注释 */
WhiteSpace    [ \t\n\r]*
LineComment   "//".*
MultiLineComment    "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" 

/* 标识符 */

/* 整数字面量 */
Decimal       [1-9][0-9]*
Octal         0[0-7]*
Hexadecimal   0[xX][0-9a-fA-F]+
Float         [0-9]+\.[0-9]*

Identifier    [a-zA-Z_][a-zA-Z0-9_]*
String        \"(\\.|[^"\\])*\"

%%

{WhiteSpace}    {  }
{LineComment}   {  }
{MultiLineComment} { }

"int"           { return INT; }
"return"        { return RETURN; }
"float"         { return FLOAT; }
"const"         { return CONST; }
"void"          { return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"printf"        { return PRINTF; }
"scanf"         { return SCANF; }
"!="            { return NE; }
"=="            { return EQ; }
"<="            { return LE; }
">="            { return GE; }
"&&"			{return AND;}
"||"			{return OR;}

{Identifier}    { yylval.str_val = new string(yytext); return IDENT; }
{String}        { char* tmp = new char[yyleng - 1]; strcpy(tmp, yytext + 1); tmp[yyleng-2] = '\0'; yylval.str_val = new string(tmp); return STRING; }


{Decimal}       { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Octal}         { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Hexadecimal}   { yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{Float}         { yylval.float_val = strtod(yytext, nullptr); return FLOAT_CONST; }

.               { return yytext[0]; }

%%
