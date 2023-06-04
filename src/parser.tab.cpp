/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "src/parser.y"

#define YYDEBUG 1
#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"
#include"myFlexer.hpp"
#define parser_class_name{myFlexer}

int yylex();
void yyerror(AST::CompUnit* &Ast, myFlexer &Flexer,const char *s);
using namespace std;

#undef yylex
#define yylex Flexer.yylex

#line 88 "/home/skylar/myCompiler/src/parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_PRINTF = 19,                    /* PRINTF  */
  YYSYMBOL_SCANF = 20,                     /* SCANF  */
  YYSYMBOL_IDENT = 21,                     /* IDENT  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_INT_CONST = 23,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 24,               /* FLOAT_CONST  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '['  */
  YYSYMBOL_28_ = 28,                       /* ']'  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_BType = 44,                     /* BType  */
  YYSYMBOL_VarDecl = 45,                   /* VarDecl  */
  YYSYMBOL_VarDef = 46,                    /* VarDef  */
  YYSYMBOL_Exp_Wrap = 47,                  /* Exp_Wrap  */
  YYSYMBOL_InitVal = 48,                   /* InitVal  */
  YYSYMBOL_InitValList = 49,               /* InitValList  */
  YYSYMBOL_FuncDef = 50,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 51,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 52,                /* FuncFParam  */
  YYSYMBOL_Block = 53,                     /* Block  */
  YYSYMBOL_BlockItemList = 54,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 55,                 /* BlockItem  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_Exp = 57,                       /* Exp  */
  YYSYMBOL_Cond = 58,                      /* Cond  */
  YYSYMBOL_LVal = 59,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 60,                /* PrimaryExp  */
  YYSYMBOL_FinalExp = 61,                  /* FinalExp  */
  YYSYMBOL_Number = 62,                    /* Number  */
  YYSYMBOL_UnaryExp = 63,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 64,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 65,               /* FuncRParams  */
  YYSYMBOL_MulExp = 66,                    /* MulExp  */
  YYSYMBOL_AddExp = 67,                    /* AddExp  */
  YYSYMBOL_RelExp = 68,                    /* RelExp  */
  YYSYMBOL_EqExp = 69,                     /* EqExp  */
  YYSYMBOL_LAndExp = 70,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 71                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    77,    84,    90,    99,   103,   107,   114,
     120,   129,   138,   147,   159,   164,   171,   176,   181,   186,
     193,   201,   212,   217,   224,   231,   238,   242,   248,   253,
     260,   261,   265,   272,   273,   274,   282,   290,   297,   302,
     307,   313,   321,   323,   326,   334,   345,   346,   347,   351,
     359,   365,   374,   376,   385,   393,   402,   410,   418,   427,
     431,   432,   433,   437,   442,   449,   450,   457,   464,   474,
     475,   482,   492,   493,   500,   507,   514,   524,   525,   532,
     542,   543,   553,   554
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "VOID",
  "RETURN", "CONST", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "NE",
  "EQ", "LE", "GE", "AND", "OR", "PRINTF", "SCANF", "IDENT", "STRING",
  "INT_CONST", "FLOAT_CONST", "';'", "'='", "'['", "']'", "'{'", "'}'",
  "','", "'('", "')'", "'-'", "'+'", "'!'", "'*'", "'/'", "'%'", "'<'",
  "'>'", "$accept", "CompUnit", "BType", "VarDecl", "VarDef", "Exp_Wrap",
  "InitVal", "InitValList", "FuncDef", "FuncFParams", "FuncFParam",
  "Block", "BlockItemList", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "PrimaryExp", "FinalExp", "Number", "UnaryExp", "UnaryOp", "FuncRParams",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,   -13,    14,  -112,   -18,   137,  -112,   181,  -112,
     128,   -31,  -112,   101,  -111,   -14,    82,   -51,  -112,  -112,
    -112,   -12,  -112,   -74,    90,    40,    22,    53,    57,  -112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    84,     7,    17,    28,    48,     8,    41,
      42,    85,    86,    87,    88,    89,   117,    30,    31,    32,
      33,    34,    35,    68,    36,    37,   119,   120,   121,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (Ast, Flexer, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Ast, Flexer); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AST::CompUnit* &Ast, myFlexer &Flexer)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (Ast);
  YY_USE (Flexer);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AST::CompUnit* &Ast, myFlexer &Flexer)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, Ast, Flexer);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, AST::CompUnit* &Ast, myFlexer &Flexer)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], Ast, Flexer);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, Ast, Flexer); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, AST::CompUnit* &Ast, myFlexer &Flexer)
{
  YY_USE (yyvaluep);
  YY_USE (Ast);
  YY_USE (Flexer);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (AST::CompUnit* &Ast, myFlexer &Flexer)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: FuncDef  */
#line 69 "src/parser.y"
                  {
    auto comp_unit = new AST::CompUnit();
	(yyvsp[0].func_val)->unitType=Fun
	;
    comp_unit->units.push_back((yyvsp[0].func_val));
    Ast =comp_unit;
	(yyval.comp_unit_val)=comp_unit;
    }
#line 1272 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 3: /* CompUnit: VarDecl  */
#line 77 "src/parser.y"
                {
	auto comp_unit=new AST::CompUnit();
	(yyvsp[0].var_val)->unitType=VarDeclare;
	comp_unit->units.push_back((yyvsp[0].var_val));
	Ast =comp_unit;
	(yyval.comp_unit_val)=comp_unit;
	}
#line 1284 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 4: /* CompUnit: CompUnit FuncDef  */
#line 84 "src/parser.y"
                         {
	(yyvsp[0].func_val)->unitType=Fun;
	(yyvsp[-1].comp_unit_val)->units.push_back((yyvsp[0].func_val));
	Ast =(yyvsp[-1].comp_unit_val);
	(yyval.comp_unit_val)=(yyvsp[-1].comp_unit_val);
	}
#line 1295 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 5: /* CompUnit: CompUnit VarDecl  */
#line 90 "src/parser.y"
                         {
	(yyvsp[0].var_val)->unitType=VarDeclare;
	(yyvsp[-1].comp_unit_val)->units.push_back((yyvsp[0].var_val));
	Ast =(yyvsp[-1].comp_unit_val);
	(yyval.comp_unit_val)=(yyvsp[-1].comp_unit_val);
	}
#line 1306 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 6: /* BType: INT  */
#line 99 "src/parser.y"
            {
	    basType var_type=Int;
		(yyval.type_val)=var_type;
	}
#line 1315 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 7: /* BType: FLOAT  */
#line 103 "src/parser.y"
              {
		basType var_type=Float;
		(yyval.type_val)=var_type;
	}
#line 1324 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 8: /* BType: VOID  */
#line 107 "src/parser.y"
             {
		basType var_type=Void;
		(yyval.type_val)=var_type;  
	}
#line 1333 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 9: /* VarDecl: VarDef ';'  */
#line 114 "src/parser.y"
                   {
		(yyval.var_val)=(yyvsp[-1].var_val);
	}
#line 1341 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 10: /* VarDef: BType IDENT  */
#line 120 "src/parser.y"
                    {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[-1].type_val);
		ast->varName=(yyvsp[0].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	}
#line 1355 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 11: /* VarDef: BType IDENT Exp_Wrap  */
#line 129 "src/parser.y"
                             {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[-2].type_val);
		ast->varName=(yyvsp[-1].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[0].arr_val);
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	}
#line 1369 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 12: /* VarDef: BType IDENT '=' InitVal  */
#line 138 "src/parser.y"
                              {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[-3].type_val);
		ast->varName=(yyvsp[-2].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=(yyvsp[0].init_val_list_val);
		(yyval.var_val)=ast;
	}
#line 1383 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 13: /* VarDef: BType IDENT Exp_Wrap '=' InitVal  */
#line 147 "src/parser.y"
                                        {
		auto ast=new AST::Variable();
		ast->bType=(yyvsp[-4].type_val);
		ast->varName=(yyvsp[-3].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[-2].arr_val);
		ast->initValList=(yyvsp[0].init_val_list_val);
		(yyval.var_val)=ast;
	}
#line 1397 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 14: /* Exp_Wrap: '[' Exp ']'  */
#line 159 "src/parser.y"
                    {
		auto ast=new AST::ArrayType();
		ast->len.push_back((yyvsp[-1].exp_val));
		(yyval.arr_val)=ast;
	}
#line 1407 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 15: /* Exp_Wrap: '[' Exp ']' Exp_Wrap  */
#line 164 "src/parser.y"
                             {
		(yyvsp[0].arr_val)->len.insert((yyvsp[0].arr_val)->len.begin(),(yyvsp[-2].exp_val));
		(yyval.arr_val)=(yyvsp[0].arr_val);
	}
#line 1416 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 16: /* InitVal: Exp  */
#line 171 "src/parser.y"
            {
		auto ast=new AST::InitValList();
		ast->valList.push_back((yyvsp[0].exp_val));
		(yyval.init_val_list_val)=ast;
	}
#line 1426 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 17: /* InitVal: '{' InitValList '}'  */
#line 176 "src/parser.y"
                            {(yyval.init_val_list_val)=(yyvsp[-1].init_val_list_val);}
#line 1432 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 18: /* InitValList: Exp  */
#line 181 "src/parser.y"
            {
		auto ast=new AST::InitValList();
		ast->valList.push_back((yyvsp[0].exp_val));
		(yyval.init_val_list_val)=ast;
	}
#line 1442 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 19: /* InitValList: InitValList ',' Exp  */
#line 186 "src/parser.y"
                            {
		(yyvsp[-2].init_val_list_val)->valList.push_back((yyvsp[0].exp_val));
		(yyval.init_val_list_val)=(yyvsp[-2].init_val_list_val);
	}
#line 1451 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 20: /* FuncDef: BType IDENT '(' ')' Block  */
#line 193 "src/parser.y"
                              {
    auto func = new AST::Func();
    func->funcType = (yyvsp[-4].type_val);
	func->funcName=(yyvsp[-3].str_val);
	func->argList=nullptr;
	func->funcBody = (yyvsp[0].block_val);
    (yyval.func_val) = func;
  }
#line 1464 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 21: /* FuncDef: BType IDENT '(' FuncFParams ')' Block  */
#line 201 "src/parser.y"
                                       {
	auto func = new AST::Func();
    func->funcType = (yyvsp[-5].type_val);
	func->funcName=(yyvsp[-4].str_val);
	func->argList=(yyvsp[-2].arg_list_val);
	func->funcBody = (yyvsp[0].block_val);
    (yyval.func_val) = func;
  }
#line 1477 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 22: /* FuncFParams: FuncFParam  */
#line 212 "src/parser.y"
                   {
		auto ast= new AST::ArgList();
	    ast->args.push_back((yyvsp[0].arg_val));
		(yyval.arg_list_val)=ast;
	}
#line 1487 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 23: /* FuncFParams: FuncFParams ',' FuncFParam  */
#line 217 "src/parser.y"
                                   {
		(yyvsp[-2].arg_list_val)->args.push_back((yyvsp[0].arg_val));
		(yyval.arg_list_val)=(yyvsp[-2].arg_list_val);
	}
#line 1496 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 24: /* FuncFParam: BType IDENT  */
#line 224 "src/parser.y"
                     {
		auto ast=new AST::Arg();
		ast->argName=(yyvsp[0].str_val);
		ast->bType=(yyvsp[-1].type_val);
		ast->is_pointer=false;
		(yyval.arg_val)=ast;
	}
#line 1508 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 25: /* FuncFParam: BType IDENT '[' ']'  */
#line 231 "src/parser.y"
                            {
		auto ast=new AST::Arg();
		ast->argName=(yyvsp[-2].str_val);
		ast->bType=(yyvsp[-3].type_val);
		ast->is_pointer=true;
		(yyval.arg_val)=ast;
	}
#line 1520 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 26: /* FuncFParam: BType IDENT '[' ']' Exp_Wrap  */
#line 238 "src/parser.y"
                                     {}
#line 1526 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 27: /* Block: '{' BlockItemList '}'  */
#line 242 "src/parser.y"
                          {
    (yyval.block_val)=(yyvsp[-1].block_val);
  }
#line 1534 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 28: /* BlockItemList: BlockItem  */
#line 248 "src/parser.y"
                  {
		auto ast=new AST::Block();
		ast->itemList.push_back((yyvsp[0].block_item_val));
		(yyval.block_val)=ast;
	}
#line 1544 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 29: /* BlockItemList: BlockItemList BlockItem  */
#line 253 "src/parser.y"
                                {
		(yyvsp[-1].block_val)->itemList.push_back((yyvsp[0].block_item_val));
		(yyval.block_val)=(yyvsp[-1].block_val);
	}
#line 1553 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 30: /* BlockItem: VarDecl  */
#line 260 "src/parser.y"
                {(yyvsp[0].var_val)->itemType=DECL;(yyval.block_item_val)=(yyvsp[0].var_val);}
#line 1559 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 31: /* BlockItem: Stmt  */
#line 261 "src/parser.y"
             {(yyvsp[0].stmt_val)->itemType=STMT;(yyval.block_item_val)=(yyvsp[0].stmt_val);}
#line 1565 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 32: /* Stmt: LVal '=' Exp ';'  */
#line 265 "src/parser.y"
                         {
		auto ast=new AST::AssignStmt();
		ast->stmtType=assignStmt;
		ast->lVal=(yyvsp[-3].var_val);
		ast->rVal=(yyvsp[-1].exp_val);
		(yyval.stmt_val)=ast;
	}
#line 1577 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 33: /* Stmt: Exp ';'  */
#line 272 "src/parser.y"
                {(yyvsp[-1].exp_val)->stmtType=expStmt;(yyval.stmt_val)=(yyvsp[-1].exp_val);}
#line 1583 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 34: /* Stmt: Block  */
#line 273 "src/parser.y"
              {(yyvsp[0].block_val)->stmtType=blockStmt;(yyval.stmt_val)=(yyvsp[0].block_val);}
#line 1589 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 35: /* Stmt: IF '(' Cond ')' Stmt  */
#line 274 "src/parser.y"
                             {
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=(yyvsp[-2].exp_val);
		ast->ifBlock=(yyvsp[0].stmt_val);
		ast->elseBlock=nullptr;
		(yyval.stmt_val)=ast;
	}
#line 1602 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 36: /* Stmt: IF '(' Cond ')' Stmt ELSE Stmt  */
#line 282 "src/parser.y"
                                       {
		auto ast=new AST::IfStmt();
		ast->stmtType=ifStmt;
		ast->condition=(yyvsp[-4].exp_val);
		ast->ifBlock=(yyvsp[-2].stmt_val);
		ast->elseBlock=(yyvsp[0].stmt_val);
		(yyval.stmt_val)=ast;
	}
#line 1615 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 37: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 290 "src/parser.y"
                                {
		auto ast=new AST::WhileStmt();
		ast->stmtType=whileStmt;
		ast->condition=(yyvsp[-2].exp_val);
		ast->loopBlock=(yyvsp[0].stmt_val);
		(yyval.stmt_val)=ast;
	}
#line 1627 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 38: /* Stmt: BREAK ';'  */
#line 297 "src/parser.y"
                  {
		auto ast=new AST::Stmt();
		ast->stmtType=breakStmt;
		(yyval.stmt_val)=ast;
	}
#line 1637 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 39: /* Stmt: CONTINUE ';'  */
#line 302 "src/parser.y"
                     {
		auto ast=new AST::Stmt();
		ast->stmtType=continueStmt;
		(yyval.stmt_val)=ast;
	}
#line 1647 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 40: /* Stmt: RETURN Exp ';'  */
#line 307 "src/parser.y"
                       {
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=(yyvsp[-1].exp_val);
		(yyval.stmt_val)=ast;
	}
#line 1658 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 41: /* Stmt: RETURN ';'  */
#line 313 "src/parser.y"
                    {
		auto ast=new AST::ReturnStmt();
		ast->stmtType=returnStmt;
		ast->retVal=nullptr;
		(yyval.stmt_val)=ast;
	}
#line 1669 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 42: /* Exp: AddExp  */
#line 321 "src/parser.y"
          {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1675 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 43: /* Cond: LOrExp  */
#line 323 "src/parser.y"
           {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1681 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 44: /* LVal: IDENT  */
#line 326 "src/parser.y"
              {
		auto ast=new AST::Variable();
		ast->varName=(yyvsp[0].str_val);
		ast->is_array=false;
		ast->arr=nullptr;
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	}
#line 1694 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 45: /* LVal: IDENT Exp_Wrap  */
#line 334 "src/parser.y"
                       {
		auto ast=new AST::Variable();
		ast->varName=(yyvsp[-1].str_val);
		ast->is_array=true;
		ast->arr=(yyvsp[0].arr_val);//�����¼��������λ�ò�������size
		ast->initValList=nullptr;
		(yyval.var_val)=ast;
	}
#line 1707 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 46: /* PrimaryExp: FinalExp  */
#line 345 "src/parser.y"
                 {(yyvsp[0].exp_val)->expType=finalExp;(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1713 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 47: /* PrimaryExp: LVal  */
#line 346 "src/parser.y"
             {(yyvsp[0].var_val)->expType=lValExp;(yyval.exp_val)=(yyvsp[0].var_val);}
#line 1719 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 48: /* PrimaryExp: Number  */
#line 347 "src/parser.y"
               {(yyvsp[0].exp_val)->expType=constNumExp;(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1725 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 49: /* FinalExp: '(' Exp ')'  */
#line 351 "src/parser.y"
                    {
		auto ast=new AST::FinalExp();
		ast->iExp=(yyvsp[-1].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1735 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 50: /* Number: INT_CONST  */
#line 359 "src/parser.y"
              {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Int;
	  ast->val=(yyvsp[0].int_val);
	  (yyval.exp_val)=ast;
  }
#line 1746 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 51: /* Number: FLOAT_CONST  */
#line 365 "src/parser.y"
                {
	  auto ast=new AST::ConstNumber();
	  ast->constType=Float;
	  ast->val=(yyvsp[0].float_val);
	  (yyval.exp_val)=ast;
  }
#line 1757 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 52: /* UnaryExp: PrimaryExp  */
#line 374 "src/parser.y"
                   {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1763 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 53: /* UnaryExp: IDENT '(' ')'  */
#line 376 "src/parser.y"
                      {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=(yyvsp[-2].str_val);
		ast->realArgList=nullptr;
		ast->IO=nullptr;
		(yyval.exp_val)=ast;
		
	}
#line 1777 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 54: /* UnaryExp: IDENT '(' FuncRParams ')'  */
#line 385 "src/parser.y"
                                  {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=(yyvsp[-3].str_val);
		ast->realArgList=(yyvsp[-1].real_arg_list_val);
		ast->IO=nullptr;
		(yyval.exp_val)=ast;
	}
#line 1790 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 55: /* UnaryExp: PRINTF '(' STRING ')'  */
#line 393 "src/parser.y"
                               {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=nullptr;
		ast->IO=(yyvsp[-1].str_val);
		(yyval.exp_val)=ast;
	
	}
#line 1804 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 56: /* UnaryExp: PRINTF '(' STRING ',' FuncRParams ')'  */
#line 402 "src/parser.y"
                                              {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("printf");
		ast->realArgList=(yyvsp[-1].real_arg_list_val);
		ast->IO=(yyvsp[-3].str_val);
		(yyval.exp_val)=ast;
	}
#line 1817 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 57: /* UnaryExp: SCANF '(' STRING ')'  */
#line 410 "src/parser.y"
                              {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=nullptr;
		ast->IO=(yyvsp[-1].str_val);
		(yyval.exp_val)=ast;
	}
#line 1830 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 58: /* UnaryExp: SCANF '(' STRING ',' FuncRParams ')'  */
#line 418 "src/parser.y"
                                             {
		auto ast=new AST::FuncCall();
		ast->expType=funcCall;
		ast->funcName=new string("scanf");
		ast->realArgList=(yyvsp[-1].real_arg_list_val);
		ast->IO=(yyvsp[-3].str_val);
		(yyval.exp_val)=ast;
		
	}
#line 1844 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 59: /* UnaryExp: UnaryOp UnaryExp  */
#line 427 "src/parser.y"
                          {}
#line 1850 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 60: /* UnaryOp: '-'  */
#line 431 "src/parser.y"
            {}
#line 1856 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 61: /* UnaryOp: '+'  */
#line 432 "src/parser.y"
            {}
#line 1862 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 62: /* UnaryOp: '!'  */
#line 433 "src/parser.y"
            {}
#line 1868 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 63: /* FuncRParams: Exp  */
#line 437 "src/parser.y"
            {
		auto ast=new AST::RealArgList();
		ast->realArgs.push_back((yyvsp[0].exp_val));
		(yyval.real_arg_list_val)=ast;
	}
#line 1878 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 64: /* FuncRParams: FuncRParams ',' Exp  */
#line 442 "src/parser.y"
                            {
		(yyvsp[-2].real_arg_list_val)->realArgs.push_back((yyvsp[0].exp_val));
		(yyval.real_arg_list_val)=(yyvsp[-2].real_arg_list_val);
	}
#line 1887 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 65: /* MulExp: UnaryExp  */
#line 449 "src/parser.y"
                 {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1893 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 66: /* MulExp: MulExp '*' UnaryExp  */
#line 450 "src/parser.y"
                            {
		auto ast=new AST::BinaryExp();
		ast->expType=mulExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1905 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 67: /* MulExp: MulExp '/' UnaryExp  */
#line 457 "src/parser.y"
                            {
		auto ast=new AST::BinaryExp();
		ast->expType=divExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1917 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 68: /* MulExp: MulExp '%' UnaryExp  */
#line 464 "src/parser.y"
                            {
		auto ast=new AST::BinaryExp();
		ast->expType=modExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1929 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 69: /* AddExp: MulExp  */
#line 474 "src/parser.y"
               {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1935 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 70: /* AddExp: AddExp '+' MulExp  */
#line 475 "src/parser.y"
                          {
		auto ast=new AST::BinaryExp();
		ast->expType=addExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1947 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 71: /* AddExp: AddExp '-' MulExp  */
#line 482 "src/parser.y"
                          {
		auto ast=new AST::BinaryExp();
		ast->expType=subExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1959 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 72: /* RelExp: AddExp  */
#line 492 "src/parser.y"
               {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 1965 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 73: /* RelExp: RelExp '<' AddExp  */
#line 493 "src/parser.y"
                          {
		auto ast=new AST::BinaryExp();
		ast->expType=LTexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1977 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 74: /* RelExp: RelExp '>' AddExp  */
#line 500 "src/parser.y"
                          {
		auto ast=new AST::BinaryExp();
		ast->expType=GTexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 1989 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 75: /* RelExp: RelExp LE AddExp  */
#line 507 "src/parser.y"
                         {
		auto ast=new AST::BinaryExp();
		ast->expType=LEexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2001 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 76: /* RelExp: RelExp GE AddExp  */
#line 514 "src/parser.y"
                         {
		auto ast=new AST::BinaryExp();
		ast->expType=GEexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2013 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 77: /* EqExp: RelExp  */
#line 524 "src/parser.y"
               {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 2019 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 78: /* EqExp: EqExp EQ RelExp  */
#line 525 "src/parser.y"
                        {
		auto ast=new AST::BinaryExp();
		ast->expType=EQexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2031 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 79: /* EqExp: EqExp NE RelExp  */
#line 532 "src/parser.y"
                        {
		auto ast=new AST::BinaryExp();
		ast->expType=NEexp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2043 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 80: /* LAndExp: EqExp  */
#line 542 "src/parser.y"
              {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 2049 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 81: /* LAndExp: LAndExp AND EqExp  */
#line 543 "src/parser.y"
                           {
		auto ast=new AST::BinaryExp();
		ast->expType=lAndExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2061 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 82: /* LOrExp: LAndExp  */
#line 553 "src/parser.y"
                {(yyval.exp_val)=(yyvsp[0].exp_val);}
#line 2067 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;

  case 83: /* LOrExp: LOrExp OR LAndExp  */
#line 554 "src/parser.y"
                          {
		auto ast=new AST::BinaryExp();
		ast->expType=lOrExp;
		ast->lExp=(yyvsp[-2].exp_val);
		ast->rExp=(yyvsp[0].exp_val);
		(yyval.exp_val)=ast;
	}
#line 2079 "/home/skylar/myCompiler/src/parser.tab.cpp"
    break;


#line 2083 "/home/skylar/myCompiler/src/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (Ast, Flexer, YY_("syntax error"));
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
                      yytoken, &yylval, Ast, Flexer);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, Ast, Flexer);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (Ast, Flexer, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, Ast, Flexer);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, Ast, Flexer);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 562 "src/parser.y"


void yyerror(AST::CompUnit* &Ast ,myFlexer&Flexer,const char *s) {
  cerr << "error: " << s << endl;
}
