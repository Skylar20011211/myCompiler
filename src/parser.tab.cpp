
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 8 "src/parser.y"

#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

int yylex();
void yyerror(AST::CompUnit* &Ast, const char *s);
using namespace std;


/* Line 189 of yacc.c  */
#line 85 "C:/course/Compiler/myCompiler/src/parser.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 "src/parser.y"

  #include <memory>
  #include <string>
  #include "AST.hpp"
  #include <vector>



/* Line 209 of yacc.c  */
#line 118 "C:/course/Compiler/myCompiler/src/parser.tab.cpp"

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
     PRINTF = 274,
     SCANF = 275,
     IDENT = 276,
     STRING = 277,
     INT_CONST = 278,
     FLOAT_CONST = 279
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "src/parser.y"

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



/* Line 214 of yacc.c  */
#line 180 "C:/course/Compiler/myCompiler/src/parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "C:/course/Compiler/myCompiler/src/parser.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    39,     2,     2,
      32,    33,    37,    35,    31,    34,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      40,    26,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      22,    25,    29,    34,    40,    44,    49,    51,    55,    57,
      61,    67,    74,    76,    80,    83,    88,    94,    98,   100,
     103,   105,   107,   112,   115,   117,   123,   131,   137,   140,
     143,   147,   150,   152,   154,   156,   159,   161,   163,   165,
     169,   171,   173,   175,   179,   184,   189,   196,   201,   208,
     211,   213,   215,   217,   219,   223,   225,   229,   233,   237,
     239,   243,   247,   249,   253,   257,   261,   265,   267,   271,
     275,   277,   281,   283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    50,    -1,    45,    -1,    43,    50,    -1,
      43,    45,    -1,     3,    -1,     4,    -1,     5,    -1,    46,
      25,    -1,    44,    21,    -1,    44,    21,    47,    -1,    44,
      21,    26,    48,    -1,    44,    21,    47,    26,    48,    -1,
      27,    57,    28,    -1,    27,    57,    28,    47,    -1,    57,
      -1,    29,    49,    30,    -1,    57,    -1,    49,    31,    57,
      -1,    44,    21,    32,    33,    53,    -1,    44,    21,    32,
      51,    33,    53,    -1,    52,    -1,    51,    31,    52,    -1,
      44,    21,    -1,    44,    21,    27,    28,    -1,    44,    21,
      27,    28,    47,    -1,    29,    54,    30,    -1,    55,    -1,
      54,    55,    -1,    45,    -1,    56,    -1,    59,    26,    57,
      25,    -1,    57,    25,    -1,    53,    -1,     8,    32,    58,
      33,    56,    -1,     8,    32,    58,    33,    56,     9,    56,
      -1,    10,    32,    58,    33,    56,    -1,    11,    25,    -1,
      12,    25,    -1,     6,    57,    25,    -1,     6,    25,    -1,
      67,    -1,    71,    -1,    21,    -1,    21,    47,    -1,    61,
      -1,    59,    -1,    62,    -1,    32,    57,    33,    -1,    23,
      -1,    24,    -1,    60,    -1,    21,    32,    33,    -1,    21,
      32,    65,    33,    -1,    19,    32,    22,    33,    -1,    19,
      32,    22,    31,    65,    33,    -1,    20,    32,    22,    33,
      -1,    20,    32,    22,    31,    65,    33,    -1,    64,    63,
      -1,    34,    -1,    35,    -1,    36,    -1,    57,    -1,    65,
      31,    57,    -1,    63,    -1,    66,    37,    63,    -1,    66,
      38,    63,    -1,    66,    39,    63,    -1,    66,    -1,    67,
      35,    66,    -1,    67,    34,    66,    -1,    67,    -1,    68,
      40,    67,    -1,    68,    41,    67,    -1,    68,    15,    67,
      -1,    68,    16,    67,    -1,    68,    -1,    69,    14,    68,
      -1,    69,    13,    68,    -1,    69,    -1,    70,    17,    69,
      -1,    70,    -1,    71,    18,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    69,    76,    82,    91,    95,    99,   106,
     112,   121,   130,   139,   151,   156,   163,   168,   173,   178,
     185,   193,   204,   209,   216,   223,   230,   234,   240,   245,
     252,   253,   257,   264,   265,   266,   274,   282,   289,   294,
     299,   305,   313,   315,   318,   326,   337,   338,   339,   343,
     351,   357,   366,   368,   377,   385,   394,   402,   410,   419,
     423,   424,   425,   429,   434,   441,   442,   449,   456,   466,
     467,   474,   484,   485,   492,   499,   506,   516,   517,   524,
     534,   535,   545,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "RETURN",
  "CONST", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "NE", "EQ", "LE",
  "GE", "AND", "OR", "PRINTF", "SCANF", "IDENT", "STRING", "INT_CONST",
  "FLOAT_CONST", "';'", "'='", "'['", "']'", "'{'", "'}'", "','", "'('",
  "')'", "'-'", "'+'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "$accept",
  "CompUnit", "BType", "VarDecl", "VarDef", "Exp_Wrap", "InitVal",
  "InitValList", "FuncDef", "FuncFParams", "FuncFParam", "Block",
  "BlockItemList", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "PrimaryExp", "FinalExp", "Number", "UnaryExp", "UnaryOp", "FuncRParams",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    61,    91,    93,   123,
     125,    44,    40,    41,    45,    43,    33,    42,    47,    37,
      60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    44,    44,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    58,    59,    59,    60,    60,    60,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     3,     4,     5,     3,     4,     1,     3,     1,     3,
       5,     6,     1,     3,     2,     4,     5,     3,     1,     2,
       1,     1,     4,     2,     1,     5,     7,     5,     2,     2,
       3,     2,     1,     1,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     3,     4,     4,     6,     4,     6,     2,
       1,     1,     1,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     7,     8,     0,     0,     3,     0,     2,     1,
       5,     4,    10,     9,     0,     0,     0,    11,     0,     0,
      44,    50,    51,     0,     0,    60,    61,    62,    12,    16,
      47,    52,    46,    48,    65,     0,    69,    42,     0,     0,
       0,     0,    22,     0,     0,     0,     0,    45,     0,    18,
       0,    59,     0,     0,     0,     0,     0,    14,     0,    20,
      24,     0,     0,    13,     0,     0,    53,    63,     0,    17,
       0,    49,    66,    67,    68,    71,    70,    15,     0,     0,
       0,     0,     0,     0,    30,    34,     0,    28,    31,     0,
      47,     0,    23,    21,     0,    55,     0,    57,     0,    54,
      19,    41,     0,     0,     0,    38,    39,    10,    27,    29,
      33,     0,    25,     0,     0,    64,    40,     0,    72,    77,
      80,    82,    43,     0,     0,    26,    56,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    35,
      75,    76,    73,    74,    79,    78,    81,    83,    37,     0,
      36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    84,     7,    17,    28,    48,     8,    41,
      42,    85,    86,    87,    88,    89,   117,    30,    31,    32,
      33,    34,    35,    68,    36,    37,   119,   120,   121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
      54,  -112,  -112,  -112,   109,    12,  -112,    18,  -112,  -112,
    -112,  -112,   -11,  -112,    31,   196,     1,    42,   -19,    21,
      -8,  -112,  -112,   196,   196,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   196,    32,    27,    44,    56,
      71,    -6,  -112,    31,    74,    81,    55,  -112,    80,  -112,
      72,  -112,   196,   196,   196,   196,   196,    91,   130,  -112,
     100,    54,    56,  -112,    -3,    13,  -112,  -112,    16,  -112,
     196,  -112,  -112,  -112,  -112,    32,    32,  -112,   189,    97,
     105,   114,   122,   127,  -112,  -112,    96,  -112,  -112,   132,
     126,   133,  -112,  -112,   196,  -112,   196,  -112,   196,  -112,
    -112,  -112,   135,   196,   196,  -112,  -112,    95,  -112,  -112,
    -112,   196,    91,    50,    62,  -112,  -112,   125,    27,    -4,
     110,   146,   149,   145,   143,  -112,  -112,  -112,   171,   196,
     196,   196,   196,   196,   196,   196,   196,   171,  -112,   175,
      27,    27,    27,    27,    -4,    -4,   110,   146,  -112,   171,
    -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   -13,    14,  -112,   -18,   137,  -112,   181,  -112,
     128,   -31,  -112,   101,  -111,   -14,    82,   -51,  -112,  -112,
    -112,   -12,  -112,   -74,    90,    40,    22,    53,    57,  -112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    38,    47,    40,     1,     2,     3,    90,    59,    49,
      50,   129,   130,    44,     6,    14,    15,   139,    10,    15,
     113,    16,   114,    51,    46,    61,   148,    62,    94,    29,
      95,    93,    67,    12,    39,    90,   131,   132,   150,    77,
      72,    73,    74,    13,    96,    83,    97,    98,    40,    99,
      18,    19,    20,    45,    21,    22,   100,     1,     2,     3,
      23,    55,    56,    24,   102,    25,    26,    27,    43,    52,
      53,    54,    57,    83,    18,    19,    20,    90,    21,    22,
      67,    98,    67,   126,   115,    58,    90,    24,    66,    25,
      26,    27,    60,    98,   125,   127,    64,   124,    90,     1,
       2,     3,    78,    65,    79,    71,    80,    81,    82,     9,
      69,    70,     1,     2,     3,    18,    19,    20,    15,    21,
      22,    14,    15,   133,   134,    58,   108,    91,    24,   103,
      25,    26,    27,     1,     2,     3,    78,   104,    79,   105,
      80,    81,    82,   118,   118,    75,    76,   106,   107,    18,
      19,    20,   111,    21,    22,   144,   145,   110,   128,    58,
     116,   112,    24,   135,    25,    26,    27,   136,   138,   140,
     141,   142,   143,   118,   118,   118,   118,    78,   137,    79,
      63,    80,    81,    82,   149,    11,   123,   109,   146,    92,
      18,    19,    20,   147,    21,    22,     0,     0,     0,     0,
      58,     0,     0,    24,     0,    25,    26,    27,    18,    19,
      20,     0,    21,    22,   101,    18,    19,    20,     0,    21,
      22,    24,     0,    25,    26,    27,     0,     0,    24,     0,
      25,    26,    27
};

static const yytype_int16 yycheck[] =
{
      14,    15,    20,    16,     3,     4,     5,    58,    39,    23,
      24,    15,    16,    32,     0,    26,    27,   128,     4,    27,
      94,    32,    96,    35,    32,    31,   137,    33,    31,    43,
      33,    62,    46,    21,    33,    86,    40,    41,   149,    57,
      52,    53,    54,    25,    31,    58,    33,    31,    61,    33,
      19,    20,    21,    32,    23,    24,    70,     3,     4,     5,
      29,    34,    35,    32,    78,    34,    35,    36,    26,    37,
      38,    39,    28,    86,    19,    20,    21,   128,    23,    24,
      94,    31,    96,    33,    98,    29,   137,    32,    33,    34,
      35,    36,    21,    31,   112,    33,    22,   111,   149,     3,
       4,     5,     6,    22,     8,    33,    10,    11,    12,     0,
      30,    31,     3,     4,     5,    19,    20,    21,    27,    23,
      24,    26,    27,    13,    14,    29,    30,    27,    32,    32,
      34,    35,    36,     3,     4,     5,     6,    32,     8,    25,
      10,    11,    12,   103,   104,    55,    56,    25,    21,    19,
      20,    21,    26,    23,    24,   133,   134,    25,    33,    29,
      25,    28,    32,    17,    34,    35,    36,    18,    25,   129,
     130,   131,   132,   133,   134,   135,   136,     6,    33,     8,
      43,    10,    11,    12,     9,     4,   104,    86,   135,    61,
      19,    20,    21,   136,    23,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    19,    20,
      21,    -1,    23,    24,    25,    19,    20,    21,    -1,    23,
      24,    32,    -1,    34,    35,    36,    -1,    -1,    32,    -1,
      34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    43,    44,    45,    46,    50,     0,
      45,    50,    21,    25,    26,    27,    32,    47,    19,    20,
      21,    23,    24,    29,    32,    34,    35,    36,    48,    57,
      59,    60,    61,    62,    63,    64,    66,    67,    57,    33,
      44,    51,    52,    26,    32,    32,    32,    47,    49,    57,
      57,    63,    37,    38,    39,    34,    35,    28,    29,    53,
      21,    31,    33,    48,    22,    22,    33,    57,    65,    30,
      31,    33,    63,    63,    63,    66,    66,    47,     6,     8,
      10,    11,    12,    44,    45,    53,    54,    55,    56,    57,
      59,    27,    52,    53,    31,    33,    31,    33,    31,    33,
      57,    25,    57,    32,    32,    25,    25,    21,    30,    55,
      25,    26,    28,    65,    65,    57,    25,    58,    67,    68,
      69,    70,    71,    58,    57,    47,    33,    33,    33,    15,
      16,    40,    41,    13,    14,    17,    18,    33,    25,    56,
      67,    67,    67,    67,    68,    68,    69,    70,    56,     9,
      56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (Ast, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Ast); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, AST::CompUnit* &Ast)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, Ast)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    AST::CompUnit* &Ast;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (Ast);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, AST::CompUnit* &Ast)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, Ast)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    AST::CompUnit* &Ast;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, Ast);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, AST::CompUnit* &Ast)
#else
static void
yy_reduce_print (yyvsp, yyrule, Ast)
    YYSTYPE *yyvsp;
    int yyrule;
    AST::CompUnit* &Ast;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , Ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, Ast); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, AST::CompUnit* &Ast)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, Ast)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    AST::CompUnit* &Ast;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (Ast);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (AST::CompUnit* &Ast);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (AST::CompUnit* &Ast)
#else
int
yyparse (Ast)
    AST::CompUnit* &Ast;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 61 "src/parser.y"
    {
    auto comp_unit = new AST::CompUnit();
	(yyvsp[(1) - (1)].func_val)->unitType=Fun
	;
    comp_unit->units.push_back((yyvsp[(1) - (1)].func_val));
    Ast =comp_unit;
	(yyval.comp_unit_val)=comp_unit;
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 69 "src/parser.y"
    {
	auto comp_unit=new AST::CompUnit();
	(yyvsp[(1) - (1)].var_val)->unitType=VarDeclare;
	comp_unit->units.push_back((yyvsp[(1) - (1)].var_val));
	Ast =comp_unit;
	(yyval.comp_unit_val)=comp_unit;
	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 76 "src/parser.y"
    {
	(yyvsp[(2) - (2)].func_val)->unitType=Fun;
	(yyvsp[(1) - (2)].comp_unit_val)->units.push_back((yyvsp[(2) - (2)].func_val));
	Ast =(yyvsp[(1) - (2)].comp_unit_val);
	(yyval.comp_unit_val)=(yyvsp[(1) - (2)].comp_unit_val);
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "src/parser.y"
    {
	(yyvsp[(2) - (2)].var_val)->unitType=VarDeclare;
	(yyvsp[(1) - (2)].comp_unit_val)->units.push_back((yyvsp[(2) - (2)].var_val));
	Ast =(yyvsp[(1) - (2)].comp_unit_val);
	(yyval.comp_unit_val)=(yyvsp[(1) - (2)].comp_unit_val);
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 91 "src/parser.y"
    {
	    basType var_type=Int;
		(yyval.type_val)=var_type;
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 95 "src/parser.y"
    {
		basType var_type=Float;
		(yyval.type_val)=var_type;
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 99 "src/parser.y"
    {
		basType var_type=Void;
		(yyval.type_val)=var_type;  
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 106 "src/parser.y"
    {
		(yyval.var_val)=(yyvsp[(1) - (2)].var_val);
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 112 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[(1) - (2)].type_val);
		ast->varName=(yyvsp[(2) - (2)].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 121 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[(1) - (3)].type_val);
		ast->varName=(yyvsp[(2) - (3)].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[(3) - (3)].arr_val);
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 130 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[(1) - (4)].type_val);
		ast->varName=(yyvsp[(2) - (4)].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=(yyvsp[(4) - (4)].init_val_list_val);
		(yyval.var_val)=ast;
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 139 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[(1) - (5)].type_val);
		ast->varName=(yyvsp[(2) - (5)].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[(3) - (5)].arr_val);
		ast->initValList=(yyvsp[(5) - (5)].init_val_list_val);
		(yyval.var_val)=ast;
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 151 "src/parser.y"
    {
		auto ast=new AST::ArrayType();
		ast->len.push_back((yyvsp[(2) - (3)].exp_val));
		(yyval.arr_val)=ast;
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 156 "src/parser.y"
    {
		(yyvsp[(4) - (4)].arr_val)->len.insert((yyvsp[(4) - (4)].arr_val)->len.begin(),(yyvsp[(2) - (4)].exp_val));
		(yyval.arr_val)=(yyvsp[(4) - (4)].arr_val);
	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 163 "src/parser.y"
    {
		auto ast=new AST::InitValList();
		ast->valList.push_back((yyvsp[(1) - (1)].exp_val));
		(yyval.init_val_list_val)=ast;
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 168 "src/parser.y"
    {(yyval.init_val_list_val)=(yyvsp[(2) - (3)].init_val_list_val);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 173 "src/parser.y"
    {
		auto ast=new AST::InitValList();
		ast->valList.push_back((yyvsp[(1) - (1)].exp_val));
		(yyval.init_val_list_val)=ast;
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 178 "src/parser.y"
    {
		(yyvsp[(1) - (3)].init_val_list_val)->valList.push_back((yyvsp[(3) - (3)].exp_val));
		(yyval.init_val_list_val)=(yyvsp[(1) - (3)].init_val_list_val);
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 185 "src/parser.y"
    {
    auto func = new AST::Func();
    func->funcType = (yyvsp[(1) - (5)].type_val);
	func->funcName=(yyvsp[(2) - (5)].str_val);
	func->argList=nullptr;
	func->funcBody = (yyvsp[(5) - (5)].block_val);
    (yyval.func_val) = func;
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 193 "src/parser.y"
    {
	auto func = new AST::Func();
    func->funcType = (yyvsp[(1) - (6)].type_val);
	func->funcName=(yyvsp[(2) - (6)].str_val);
	func->argList=(yyvsp[(4) - (6)].arg_list_val);
	func->funcBody = (yyvsp[(6) - (6)].block_val);
    (yyval.func_val) = func;
  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 204 "src/parser.y"
    {
		auto ast= new AST::ArgList();
	    ast->args.push_back((yyvsp[(1) - (1)].arg_val));
		(yyval.arg_list_val)=ast;
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 209 "src/parser.y"
    {
		(yyvsp[(1) - (3)].arg_list_val)->args.push_back((yyvsp[(3) - (3)].arg_val));
		(yyval.arg_list_val)=(yyvsp[(1) - (3)].arg_list_val);
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 216 "src/parser.y"
    {
		auto ast=new AST::Arg();
		ast->argName=(yyvsp[(2) - (2)].str_val);
		ast->bType=(yyvsp[(1) - (2)].type_val);
		ast->is_pointer=false;
		(yyval.arg_val)=ast;
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 223 "src/parser.y"
    {
		auto ast=new AST::Arg();
		ast->argName=(yyvsp[(2) - (4)].str_val);
		ast->bType=(yyvsp[(1) - (4)].type_val);
		ast->is_pointer=true;
		(yyval.arg_val)=ast;
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 230 "src/parser.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 234 "src/parser.y"
    {
    (yyval.block_val)=(yyvsp[(2) - (3)].block_val);
  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 240 "src/parser.y"
    {
		auto ast=new AST::Block();
		ast->itemList.push_back((yyvsp[(1) - (1)].block_item_val));
		(yyval.block_val)=ast;
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 245 "src/parser.y"
    {
		(yyvsp[(1) - (2)].block_val)->itemList.push_back((yyvsp[(2) - (2)].block_item_val));
		(yyval.block_val)=(yyvsp[(1) - (2)].block_val);
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 252 "src/parser.y"
    {(yyvsp[(1) - (1)].var_val)->itemType=DECL;(yyval.block_item_val)=(yyvsp[(1) - (1)].var_val);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 253 "src/parser.y"
    {(yyvsp[(1) - (1)].stmt_val)->itemType=STMT;(yyval.block_item_val)=(yyvsp[(1) - (1)].stmt_val);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 257 "src/parser.y"
    {
		auto ast=new AST::AssignStmt();
		ast->stmtType=assignStmt;
		ast->lVal=(yyvsp[(1) - (4)].var_val);
		ast->rVal=(yyvsp[(3) - (4)].exp_val);
		(yyval.stmt_val)=ast;
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 264 "src/parser.y"
    {(yyvsp[(1) - (2)].exp_val)->stmtType=expStmt;(yyval.stmt_val)=(yyvsp[(1) - (2)].exp_val);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 265 "src/parser.y"
    {(yyvsp[(1) - (1)].block_val)->stmtType=blockStmt;(yyval.stmt_val)=(yyvsp[(1) - (1)].block_val);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 266 "src/parser.y"
    {
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=(yyvsp[(3) - (5)].exp_val);
		ast->ifBlock=(yyvsp[(5) - (5)].stmt_val);
		ast->elseBlock=nullptr;
		(yyval.stmt_val)=ast;
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 274 "src/parser.y"
    {
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=(yyvsp[(3) - (7)].exp_val);
		ast->ifBlock=(yyvsp[(5) - (7)].stmt_val);
		ast->elseBlock=(yyvsp[(7) - (7)].stmt_val);
		(yyval.stmt_val)=ast;
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 282 "src/parser.y"
    {
		auto ast=new AST::WhileStmt();
		ast->stmtType=whileStmt;
		ast->condition=(yyvsp[(3) - (5)].exp_val);
		ast->loopBlock=(yyvsp[(5) - (5)].stmt_val);
		(yyval.stmt_val)=ast;
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 289 "src/parser.y"
    {
		auto ast=new AST::Stmt();
		ast->stmtType=breakStmt;
		(yyval.stmt_val)=ast;
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 294 "src/parser.y"
    {
		auto ast=new AST::Stmt();
		ast->stmtType=continueStmt;
		(yyval.stmt_val)=ast;
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 299 "src/parser.y"
    {
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=(yyvsp[(2) - (3)].exp_val);
		(yyval.stmt_val)=ast;
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 305 "src/parser.y"
    {
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=nullptr;
		(yyval.stmt_val)=ast;
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 313 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 315 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 318 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->varName=(yyvsp[(1) - (1)].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 326 "src/parser.y"
    {
		auto ast=new AST::Variable();
		ast->varName=(yyvsp[(1) - (2)].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[(2) - (2)].arr_val);//�����¼��������λ�ò�������size
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 337 "src/parser.y"
    {(yyvsp[(1) - (1)].exp_val)->expType=finalExp;(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 338 "src/parser.y"
    {(yyvsp[(1) - (1)].var_val)->expType=lValExp;(yyval.exp_val)=(yyvsp[(1) - (1)].var_val);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 339 "src/parser.y"
    {(yyvsp[(1) - (1)].exp_val)->expType=constNumExp;(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 343 "src/parser.y"
    {
		auto ast=new AST::FinalExp();
		ast->iExp=(yyvsp[(2) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Int;
	  ast->val=(yyvsp[(1) - (1)].int_val);
	  (yyval.exp_val)=ast;
  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 357 "src/parser.y"
    {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Float;
	  ast->val=(yyvsp[(1) - (1)].float_val);
	  (yyval.exp_val)=ast;
  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 366 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 368 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=(yyvsp[(1) - (3)].str_val);
		ast->realArgList=nullptr;
		ast->IO=nullptr;
		(yyval.exp_val)=ast;
		
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 377 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=(yyvsp[(1) - (4)].str_val);
		ast->realArgList=(yyvsp[(3) - (4)].real_arg_list_val);
		ast->IO=nullptr;
		(yyval.exp_val)=ast;
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 385 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=nullptr;
		ast->IO=(yyvsp[(3) - (4)].str_val);
		(yyval.exp_val)=ast;
	
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 394 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=(yyvsp[(5) - (6)].real_arg_list_val);
		ast->IO=(yyvsp[(3) - (6)].str_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 402 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=nullptr;
		ast->IO=(yyvsp[(3) - (4)].str_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 410 "src/parser.y"
    {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=(yyvsp[(5) - (6)].real_arg_list_val);
		ast->IO=(yyvsp[(3) - (6)].str_val);
		(yyval.exp_val)=ast;
		
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 419 "src/parser.y"
    {;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 423 "src/parser.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 424 "src/parser.y"
    {;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 425 "src/parser.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 429 "src/parser.y"
    {
		auto ast=new AST::RealArgList();
		ast->realArgs.push_back((yyvsp[(1) - (1)].exp_val));
		(yyval.real_arg_list_val)=ast;
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 434 "src/parser.y"
    {
		(yyvsp[(1) - (3)].real_arg_list_val)->realArgs.push_back((yyvsp[(3) - (3)].exp_val));
		(yyval.real_arg_list_val)=(yyvsp[(1) - (3)].real_arg_list_val);
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 441 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 442 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=mulExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 449 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=divExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 456 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=modExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 466 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 467 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=addExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 474 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=subExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 484 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 485 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=LTexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 492 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=GTexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 499 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=LEexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 506 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=GEexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 516 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 517 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=EQexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 524 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=NEexp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 534 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 535 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=lAndExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 545 "src/parser.y"
    {(yyval.exp_val)=(yyvsp[(1) - (1)].exp_val);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 546 "src/parser.y"
    {
		auto ast=new AST::BinaryExp();
		ast->expType=lOrExp;
		ast->lExp=(yyvsp[(1) - (3)].exp_val);
		ast->rExp=(yyvsp[(3) - (3)].exp_val);
		(yyval.exp_val)=ast;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2446 "C:/course/Compiler/myCompiler/src/parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (Ast, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (Ast, yymsg);
	  }
	else
	  {
	    yyerror (Ast, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, Ast);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, Ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (Ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, Ast);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, Ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 554 "src/parser.y"


void yyerror(AST::CompUnit* &Ast , const char *s) {
  cerr << "error: " << s << endl;
}
