/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "intmed_code.y" /* yacc.c:339  */

#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "symb.h"
#include "helper.h"
int yylex(void);
void yyerror(const char *);
extern FILE *yyin;
extern int yylineno;
extern char* yytext;

int scope = 0;
typedef struct buffer
{
	char *name;
	int type;
}buff;
buff buffer[56];

int id_buff = 0;
void put_tobuffer(char*, int);
void insert(int );

expression codegen(expression, char*, expression);
expression codegenAssign(char*, expression);	
expression codegenAssignCompound(char*, char*, expression);
expression shorthand(char *a, char *op);		// only works for statements a++ or --a

char* out;
char *buffer_quad;			// to store the var definitions in list declarations before type checking

#line 99 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID_TOK = 258,
    INT_TOK = 259,
    FLOAT_TOK = 260,
    CHAR_TOK = 261,
    INT_CONST = 262,
    FLOAT_CONST = 263,
    CHAR_CONST = 264,
    FOR_TOK = 265,
    WHILE_TOK = 266,
    DO_TOK = 267,
    IF_TOK = 268,
    ELSE_TOK = 269,
    SWITCH_TOK = 270,
    CASE_TOK = 271,
    DEFAULT_TOK = 272,
    VOID_TOK = 273,
    IFX = 274,
    MINEQ_TOK = 275,
    ADDEQ_TOK = 276,
    MODEQ_TOK = 277,
    MULTEQ_TOK = 278,
    DIVEQ_TOK = 279,
    BITANDEQ_TOK = 280,
    BITOREQ_TOK = 281,
    BITXOREQ_TOK = 282,
    OR_TOK = 283,
    AND_TOK = 284,
    EQ2_TOK = 285,
    NOTEQ_TOK = 286,
    GTEQ_TOK = 287,
    LSEQ_TOK = 288,
    LSHIFT_TOK = 289,
    RSHIFT_TOK = 290,
    INC_TOK = 291,
    DEC_TOK = 292,
    UMINUS = 293
  };
#endif
/* Tokens.  */
#define ID_TOK 258
#define INT_TOK 259
#define FLOAT_TOK 260
#define CHAR_TOK 261
#define INT_CONST 262
#define FLOAT_CONST 263
#define CHAR_CONST 264
#define FOR_TOK 265
#define WHILE_TOK 266
#define DO_TOK 267
#define IF_TOK 268
#define ELSE_TOK 269
#define SWITCH_TOK 270
#define CASE_TOK 271
#define DEFAULT_TOK 272
#define VOID_TOK 273
#define IFX 274
#define MINEQ_TOK 275
#define ADDEQ_TOK 276
#define MODEQ_TOK 277
#define MULTEQ_TOK 278
#define DIVEQ_TOK 279
#define BITANDEQ_TOK 280
#define BITOREQ_TOK 281
#define BITXOREQ_TOK 282
#define OR_TOK 283
#define AND_TOK 284
#define EQ2_TOK 285
#define NOTEQ_TOK 286
#define GTEQ_TOK 287
#define LSEQ_TOK 288
#define LSHIFT_TOK 289
#define RSHIFT_TOK 290
#define INC_TOK 291
#define DEC_TOK 292
#define UMINUS 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "intmed_code.y" /* yacc.c:355  */

	Number val;
	char *tokname;
	expression expr_st;

#line 221 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    46,    33,     2,
      54,    55,    44,    42,    50,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
      39,    20,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    31,    52,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    34,    35,    36,    37,    40,
      41,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    70,    70,   101,   109,   130,   131,   134,
     134,   141,   141,   144,   144,   151,   159,   163,   164,   165,
     166,   167,   168,   173,   213,   237,   272,   287,   296,   298,
     299,   300,   301,   302,   304,   305,   306,   307,   308,   309,
     311,   312,   313,   314,   315,   316,   318,   320,   321,   322,
     323,   324,   325,   326,   327,   329,   333,   334,   335,   336,
     337
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID_TOK", "INT_TOK", "FLOAT_TOK",
  "CHAR_TOK", "INT_CONST", "FLOAT_CONST", "CHAR_CONST", "FOR_TOK",
  "WHILE_TOK", "DO_TOK", "IF_TOK", "ELSE_TOK", "SWITCH_TOK", "CASE_TOK",
  "DEFAULT_TOK", "VOID_TOK", "IFX", "'='", "MINEQ_TOK", "ADDEQ_TOK",
  "MODEQ_TOK", "MULTEQ_TOK", "DIVEQ_TOK", "BITANDEQ_TOK", "BITOREQ_TOK",
  "BITXOREQ_TOK", "OR_TOK", "AND_TOK", "'|'", "'^'", "'&'", "EQ2_TOK",
  "NOTEQ_TOK", "GTEQ_TOK", "LSEQ_TOK", "'>'", "'<'", "LSHIFT_TOK",
  "RSHIFT_TOK", "'+'", "'-'", "'*'", "'/'", "'%'", "INC_TOK", "DEC_TOK",
  "UMINUS", "','", "'{'", "'}'", "';'", "'('", "')'", "$accept", "start",
  "const", "vd", "var_list", "list", "$@1", "type", "cmp_stmt", "$@2",
  "stmt_list", "stmt", "loop", "cond", "expr", "unary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   124,    94,    38,   285,   286,   287,   288,    62,    60,
     289,   290,    43,    45,    42,    47,    37,   291,   292,   293,
      44,   123,   125,    59,    40,    41
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,   -14,   -51,   -51,   -51,   -51,   -50,   -38,    24,    23,
      27,   -51,   -51,    24,    35,   -51,   -16,   -51,   -51,   -51,
      53,   -51,   -51,    46,   -51,    24,    24,    24,    24,    24,
      24,    24,    24,    24,   -51,   -51,    24,    24,   -51,   -51,
     -51,    53,    79,   -51,   -51,    56,   -51,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,   -51,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   102,   125,    10,   -51,    18,   -51,
      13,   165,   181,   195,   208,   219,   219,   226,   226,   226,
     226,    84,    84,   -43,   -43,   -51,   -51,   -51,    53,    53,
     -51,    24,    56,   -51,    51,   148,   -51,    53,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,    27,    11,    12,     3,     4,     0,     0,     0,     0,
       0,    13,    18,     0,     0,    26,     0,     9,    19,     2,
      16,    21,    20,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     0,    60,    58,
      59,    16,     0,     1,    17,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    46,    48,    47,    49,    50,
      51,    52,    53,    54,     0,     0,     0,    55,     5,     7,
      10,    43,    42,    36,    37,    44,    45,    38,    39,    34,
      35,    40,    41,    29,    30,    31,    32,    33,     0,     0,
      14,     0,     0,    23,    24,     6,     8,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -34,   -51,   -51,   -51,   -51,   -51,   -51,
      -5,    -4,   -51,   -51,    -8,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    79,    80,    16,    45,    17,    18,    41,
      19,    20,    21,    22,    23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    61,    62,    63,    36,    42,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    46,    37,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    39,     1,    74,    75,
      40,     4,     5,    34,    35,    43,    76,    44,   101,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     1,     2,     3,    78,
       4,     5,   100,   102,     6,   107,     7,     8,   106,     0,
       0,     9,    10,     0,     0,    47,    48,    49,    13,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   105,   103,   104,     8,     0,     0,    64,
       9,    10,     0,   108,    11,     0,    12,    13,    47,    48,
      49,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    59,    60,    61,    62,
      63,    47,    48,    49,    77,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,     0,     0,     0,    47,    48,    49,    98,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,    47,    48,    49,
      99,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    48,    49,     0,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    49,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    57,    58,    59,    60,
      61,    62,    63
};

static const yytype_int8 yycheck[] =
{
       8,    44,    45,    46,    54,    13,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    20,    54,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     3,     3,    36,    37,
       3,     7,     8,    47,    48,     0,    41,    53,    20,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     3,     4,     5,     3,
       7,     8,    52,    50,    11,    14,    13,    43,   102,    -1,
      -1,    47,    48,    -1,    -1,    29,    30,    31,    54,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   101,    98,    99,    43,    -1,    -1,    53,
      47,    48,    -1,   107,    51,    -1,    53,    54,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    42,    43,    44,    45,
      46,    29,    30,    31,    55,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    55,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      55,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    40,    41,    42,    43,
      44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    11,    13,    43,    47,
      48,    51,    53,    54,    57,    58,    61,    63,    64,    66,
      67,    68,    69,    70,    71,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    47,    48,    54,    54,    70,     3,
       3,    65,    70,     0,    53,    62,    66,    29,    30,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    53,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    66,    55,     3,    59,
      60,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    55,    55,
      52,    20,    50,    67,    67,    70,    59,    14,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    60,    62,
      61,    63,    63,    65,    64,    66,    66,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     3,     0,
       3,     1,     1,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     2,     5,     5,     7,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 67 "intmed_code.y" /* yacc.c:1646  */
    {out = formatCode((yyvsp[0].expr_st.code)); }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "intmed_code.y" /* yacc.c:1646  */
    {	int t = lookup_scope((yyvsp[0].tokname), scope); 
			if(t != -1) printf("ERROR: '%s' redeclared at %d\n", (yyvsp[0].tokname), yylineno);
			else put_tobuffer((yyvsp[0].tokname), -1);
			buffer_quad = (char *)realloc(buffer_quad, (strlen(buffer_quad) + strlen((yyvsp[0].tokname)) + 7) * sizeof(char));
			strcat(buffer_quad, "\n");
			strcat(buffer_quad, "DEC: ");
			strcat(buffer_quad, (yyvsp[0].tokname)); //printf("%s\n", buffer_quad);
		}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "intmed_code.y" /* yacc.c:1646  */
    { 	int t = lookup_scope((yyvsp[-2].tokname), scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", (yyvsp[-2].tokname), yylineno);
				else	put_tobuffer((yyvsp[-2].tokname), (yyvsp[0].expr_st).type);
				
				buffer_quad = (char*)realloc(buffer_quad, (strlen(buffer_quad) + 2 * strlen((yyvsp[-2].tokname)) + strlen((yyvsp[0].expr_st).place) + 
											strlen((yyvsp[0].expr_st).code) + 12) * sizeof(char));
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, (yyvsp[0].expr_st).code);
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, "DEC: ");
				strcat(buffer_quad, (yyvsp[-2].tokname));
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, (yyvsp[-2].tokname));
				strcat(buffer_quad, " = ");
				strcat(buffer_quad, (yyvsp[0].expr_st).place);
	
				free((yyvsp[0].expr_st).code); 
				//printf("%s\n", buffer_quad);
			}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "intmed_code.y" /* yacc.c:1646  */
    {	buffer_quad = (char*)malloc(sizeof(char)); buffer_quad[0] = '\0'; }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "intmed_code.y" /* yacc.c:1646  */
    {	insert((yyvsp[-2].val.type)); 
				(yyval.expr_st.code) = (char*)malloc((strlen(buffer_quad)+1)*sizeof(char)); 
				strcpy((yyval.expr_st.code), buffer_quad); free(buffer_quad);
			}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "intmed_code.y" /* yacc.c:1646  */
    {(yyval.val.type) = INTEGER; }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "intmed_code.y" /* yacc.c:1646  */
    {(yyval.val.type) = FLOAT;}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 144 "intmed_code.y" /* yacc.c:1646  */
    {scope++; printf("Entering Scope: %d\n", scope); }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "intmed_code.y" /* yacc.c:1646  */
    { //show_symtable(); 
		printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; 
		(yyval.expr_st.code) = (yyvsp[-1].expr_st.code); //show_symtable();
	}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 151 "intmed_code.y" /* yacc.c:1646  */
    {	
				(yyval.expr_st.code) = (char *)malloc((strlen((yyvsp[-1].expr_st.code)) + strlen((yyvsp[0].expr_st.code)) + 2) * sizeof(char));
				strcpy((yyval.expr_st.code), (yyvsp[-1].expr_st.code));
				strcat((yyval.expr_st.code), "\n");
				strcat((yyval.expr_st.code), (yyvsp[0].expr_st.code));
				free((yyvsp[-1].expr_st.code));
				free((yyvsp[0].expr_st.code));
			}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "intmed_code.y" /* yacc.c:1646  */
    {(yyval.expr_st.code) = (char *)malloc(sizeof(char)); (yyval.expr_st.code)[0] = '\0';}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st.code) = (char *)malloc(sizeof(char)); (yyval.expr_st.code)[0] = '\0'; }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st.code) = (yyvsp[-1].expr_st).code; }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 174 "intmed_code.y" /* yacc.c:1646  */
    {
		char *t1 = newLabel();
		char *t2 = newLabel();
		char *t3 = newLabel();
		//printf("WWW%s", $3.code);
		char *ss = (char*)malloc(strlen((yyvsp[-2].expr_st).code) + 2);
		strcpy(ss, ": ");
		int i, k = 2;
		for(i = 1; i < strlen((yyvsp[-2].expr_st).code); i++, k++)	
			ss[k] = (yyvsp[-2].expr_st).code[i]; 
		(yyval.expr_st.code) = (char *)malloc((strlen(ss) + strlen((yyvsp[0].expr_st.code)) + strlen((yyvsp[-2].expr_st).place) + 2* strlen(t1) + 2* strlen(t2) + 2* strlen(t3) + 33) * sizeof(char));
		strcpy((yyval.expr_st.code), t1);	 
		strcat((yyval.expr_st.code), ss);
		//printf("%s\n", $$);	
		strcat((yyval.expr_st.code), "\nIF ");
		strcat((yyval.expr_st.code), (yyvsp[-2].expr_st).place); 
		strcat((yyval.expr_st.code), " GOTO ");
		strcat((yyval.expr_st.code), t2);
		strcat((yyval.expr_st.code), "\nGOTO ");
		strcat((yyval.expr_st.code), t3);
		strcat((yyval.expr_st.code), "\n"); 
		strcat((yyval.expr_st.code), t2);	 
		strcat((yyval.expr_st.code), ": ");  
		strcat((yyval.expr_st.code), (yyvsp[0].expr_st.code));  
		strcat((yyval.expr_st.code), "\nGOTO ");				
		strcat((yyval.expr_st.code), t1); 
		strcat((yyval.expr_st.code), "\n");	
		strcat((yyval.expr_st.code), t3);				
		strcat((yyval.expr_st.code), ": \n");	
		//printf("%s\n", $$);
		free(ss);
		free((yyvsp[-2].expr_st).code); 
		free((yyvsp[0].expr_st.code));

	}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "intmed_code.y" /* yacc.c:1646  */
    {	
			char * tmp1 = newLabel(); char * tmp2 = newLabel();
			(yyval.expr_st.code) = (char *)malloc((strlen((yyvsp[-2].expr_st).code) + strlen((yyvsp[0].expr_st.code)) + strlen((yyvsp[-2].expr_st).place) + 2*strlen(tmp1) + 2*strlen(tmp2) + 24) * sizeof(char));
			
			strcpy((yyval.expr_st.code), (yyvsp[-2].expr_st).code);
			strcat((yyval.expr_st.code), "\nIF ");
			strcat((yyval.expr_st.code), (yyvsp[-2].expr_st).place);
			strcat((yyval.expr_st.code), " GOTO ");
			strcat((yyval.expr_st.code), tmp1);
			strcat((yyval.expr_st.code), "\nGOTO ");
			strcat((yyval.expr_st.code), tmp2);
			strcat((yyval.expr_st.code), "\n");
			strcat((yyval.expr_st.code), tmp1);
			strcat((yyval.expr_st.code), ": ");
			strcat((yyval.expr_st.code), (yyvsp[0].expr_st.code));
			strcat((yyval.expr_st.code), "\n");
			strcat((yyval.expr_st.code), tmp2);
			strcat((yyval.expr_st.code), ": ");			
			strcat((yyval.expr_st.code), "\n");		
			
			free((yyvsp[-2].expr_st).code); 
			free((yyvsp[0].expr_st.code));
		}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 238 "intmed_code.y" /* yacc.c:1646  */
    {
		char * tmp1 = newLabel();
		char * tmp2 = newLabel();
		char * tmp3 = newLabel();
		(yyval.expr_st.code) = (char *)malloc((strlen((yyvsp[-4].expr_st).code) + strlen((yyvsp[-2].expr_st.code)) + strlen((yyvsp[0].expr_st.code)) + strlen((yyvsp[-4].expr_st).place) + 2* strlen(tmp1) + 2* strlen(tmp2) + 2* strlen(tmp3) + 33) * sizeof(char));
		strcpy((yyval.expr_st.code), (yyvsp[-4].expr_st).code);
		strcat((yyval.expr_st.code), "\nIF ");
		strcat((yyval.expr_st.code), (yyvsp[-4].expr_st).place);
		strcat((yyval.expr_st.code), " GOTO ");
		strcat((yyval.expr_st.code), tmp1);
		strcat((yyval.expr_st.code), "\nGOTO ");
		strcat((yyval.expr_st.code), tmp2);
		strcat((yyval.expr_st.code), "\n");
		strcat((yyval.expr_st.code), tmp1);
		strcat((yyval.expr_st.code), ": ");
		strcat((yyval.expr_st.code), (yyvsp[-2].expr_st.code));
		strcat((yyval.expr_st.code), "\n");
		strcat((yyval.expr_st.code), "GOTO ");
		strcat((yyval.expr_st.code), tmp3);
		strcat((yyval.expr_st.code), "\n");
		strcat((yyval.expr_st.code), tmp2);
		strcat((yyval.expr_st.code), ": ");			
		strcat((yyval.expr_st.code), (yyvsp[0].expr_st.code));
		strcat((yyval.expr_st.code), "\n");
		strcat((yyval.expr_st.code), tmp3);
		strcat((yyval.expr_st.code), ": ");

		free((yyvsp[-4].expr_st).code); 
		free((yyvsp[-2].expr_st.code));
		free((yyvsp[0].expr_st.code));
	}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 272 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st).type = (yyvsp[0].val).type; 
				(yyval.expr_st).place = newtemp();
				char ss[20];
				if((yyvsp[0].val).type == INTEGER){
					sprintf(ss, "%d", (yyvsp[0].val).value.ival);
				}
				if((yyvsp[0].val).type == FLOAT){
					sprintf(ss, "%f", (yyvsp[0].val).value.fval);
				}
				(yyval.expr_st).code = (char*)malloc((strlen(ss) + strlen((yyval.expr_st).place) + 4)*sizeof(char));
				strcpy((yyval.expr_st).code, (yyval.expr_st).place);
				strcat((yyval.expr_st).code, " = ");				
				strcat((yyval.expr_st).code, ss);
				
			}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 287 "intmed_code.y" /* yacc.c:1646  */
    { 	
				int t = lookup((yyvsp[0].tokname), scope); 		//only type checking done
				if(t < 0) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[0].tokname), yylineno);
				else (yyval.expr_st).type = t; 
				(yyval.expr_st).place = strdup((yyvsp[0].tokname));
				(yyval.expr_st).code = (char*)malloc(sizeof(char));
				(yyval.expr_st).code[0] = '\0';
				
			}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 298 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "+", (yyvsp[0].expr_st)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 299 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "-", (yyvsp[0].expr_st)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "*", (yyvsp[0].expr_st)); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 301 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "/", (yyvsp[0].expr_st)); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 302 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "%", (yyvsp[0].expr_st)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 304 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), ">", (yyvsp[0].expr_st)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 305 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "<", (yyvsp[0].expr_st)); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 306 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "|", (yyvsp[0].expr_st)); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "&", (yyvsp[0].expr_st)); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), ">=", (yyvsp[0].expr_st)); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 309 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "<=", (yyvsp[0].expr_st)); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "<<", (yyvsp[0].expr_st)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 312 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), ">>", (yyvsp[0].expr_st)); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 313 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "&&", (yyvsp[0].expr_st)); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 314 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "||", (yyvsp[0].expr_st)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 315 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "==", (yyvsp[0].expr_st)); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 316 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = codegen((yyvsp[-2].expr_st), "!=", (yyvsp[0].expr_st)); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 318 "intmed_code.y" /* yacc.c:1646  */
    {	(yyval.expr_st) = codegenAssign((yyvsp[-2].tokname), (yyvsp[0].expr_st)); }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 320 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "+=", (yyvsp[0].expr_st)); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 321 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "-=", (yyvsp[0].expr_st)); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 322 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "%=", (yyvsp[0].expr_st)); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 323 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "*=", (yyvsp[0].expr_st)); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 324 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "/=", (yyvsp[0].expr_st)); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 325 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "&=", (yyvsp[0].expr_st)); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 326 "intmed_code.y" /* yacc.c:1646  */
    { 	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "|=", (yyvsp[0].expr_st)); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 327 "intmed_code.y" /* yacc.c:1646  */
    {	(yyval.expr_st) = codegenAssignCompound((yyvsp[-2].tokname), "^=", (yyvsp[0].expr_st)); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 329 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = (yyvsp[-1].expr_st); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 333 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = shorthand((yyvsp[-1].tokname), "++"); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 334 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = shorthand((yyvsp[-1].tokname), "--"); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 335 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = shorthand((yyvsp[0].tokname), "++"); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 336 "intmed_code.y" /* yacc.c:1646  */
    { (yyval.expr_st) = shorthand((yyvsp[0].tokname), "--"); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 337 "intmed_code.y" /* yacc.c:1646  */
    {
			(yyval.expr_st).type = (yyvsp[0].expr_st).type; 
			char *tmp = newtemp();
			(yyval.expr_st).place = tmp;
			(yyval.expr_st).code =  (char*)malloc((strlen(tmp) + strlen((yyvsp[0].expr_st).place) + strlen((yyvsp[0].expr_st).code)+ 7) * sizeof(char));
			strcpy((yyval.expr_st).code, (yyvsp[0].expr_st).code);
			strcat((yyval.expr_st).code, "\n");
			strcat((yyval.expr_st).code, tmp);
			strcat((yyval.expr_st).code, " = - ");
			strcat((yyval.expr_st).code, (yyvsp[0].expr_st).place);
			free((yyvsp[0].expr_st).code); 
		}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1880 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 350 "intmed_code.y" /* yacc.c:1906  */


void yyerror(const char *s) {
	fprintf(stderr, "%s At line %d: %s\n", s, yylineno, yytext);
	return;
}

void put_tobuffer(char *idname, int type)
{
	buffer[id_buff].name = (char*)malloc(strlen(idname)+1);
	strcpy(buffer[id_buff].name, idname);
	buffer[id_buff].type = type;
	id_buff++;
}

void insert(int type)
{
	int i;
	for(i = 0; i < id_buff; i++)
	{
		if(buffer[i].type == type || buffer[i].type == -1)
		{
			put_symb(buffer[i].name, type, scope);
			free(buffer[i].name); 
			buffer[i].type = 0;
		}
		else
			printf("ERROR: Type mismatch (%d %d) at line %d\n", buffer[i].type, type, yylineno); 
	}
	id_buff = 0;
}

expression codegen(expression a, char *op, expression b)
{
	expression ret;
	if(a.type == b.type) 
		ret.type = a.type; 		//only type checking done
	else printf("ERROR: Type (%d %d) mismatch at line %d\n", a.type, b.type, yylineno); 
				
	ret.place = newtemp();
	ret.code = (char*)malloc((strlen(a.code) + strlen(b.code) + strlen(ret.place) + strlen(a.place) + strlen(b.place) + strlen(op) + 8 ) * sizeof(char));
	strcpy(ret.code, a.code);	
	if(a.code[0] != '\0')
		 strcat(ret.code, "\n");
	strcat(ret.code, b.code);
	if(b.code[0] != '\0')
		strcat(ret.code, "\n");
	//printf("%sWWW", ret.code);
	strcat(ret.code, ret.place);
	strcat(ret.code, " = ");
	strcat(ret.code, a.place);
	strcat(ret.code, " ");
	strcat(ret.code, op);
	strcat(ret.code, " ");
	strcat(ret.code, b.place);
	
	free(a.code);
	free(b.code);
	return ret;
}

expression codegenAssign(char *a,  expression c)
{
	expression buffer_quad;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	
	buffer_quad.place = strdup(a); 
	buffer_quad.code = (char*)malloc((strlen(a) + strlen(c.place) + strlen(c.code) + 4) * sizeof(char));
	strcpy(buffer_quad.code, c.code);	
	if(c.code[0] != '\0')
		strcat(buffer_quad.code, "\n");
	strcat(buffer_quad.code, a);
	strcat(buffer_quad.code, " = ");
	strcat(buffer_quad.code, c.place);
	free(c.code);
	return buffer_quad;
}

expression codegenAssignCompound(char *a, char *op, expression c)
{
	char op_first[4];
	sprintf(op_first, " %c ", op[0]); 
	expression buffer_quad, ret;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	
	buffer_quad.place = newtemp(); 
	buffer_quad.code = (char*)malloc((strlen(a) + strlen(c.place) + strlen(c.code) + strlen(buffer_quad.place) + 9) * sizeof(char));
	strcpy(buffer_quad.code, c.code);
	if(c.code[0] != '\0')
		strcat(buffer_quad.code, "\n");
	strcat(buffer_quad.code, buffer_quad.place);
	strcat(buffer_quad.code, " = ");
	strcat(buffer_quad.code, a);
	strcat(buffer_quad.code, op_first);
	strcat(buffer_quad.code, c.place);
	free(c.code);
	ret = codegenAssign(a, buffer_quad);
	return ret;
}

expression shorthand(char *a, char *op)
{
	expression ret;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else ret.type = t;
	
	char op_first[4];
	sprintf(op_first, " %c ", op[0]);
	
	ret.place = newtemp();
	ret.code = (char*)malloc((2*strlen(a) + 2*strlen(ret.place) + 10) * sizeof(char));
	strcpy(ret.code, ret.place);
	strcat(ret.code, " = ");
	strcat(ret.code, a);
	strcat(ret.code, op_first);
	strcat(ret.code, "1");
	strcat(ret.code, "\n");
	strcat(ret.code, a);
	strcat(ret.code, " = ");
	strcat(ret.code, ret.place);
	return ret;

}

int main(int argc, char *argv[]) {
	int i;
	
	char errorMessage[256];
	
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("SUCCESS.. NO SYNTAX ERROR :).. INTERMEDIATE CODE GENERATED\n");
		printf("=====================================================================\n");
		puts(out);
		FILE *fo = fopen("abc.o", "w");
		fprintf(fo, "%s", out); 
		free(out);
		fclose(fo);
	}	
	//getchar();
	fclose(yyin);
	
	//show_symtable();
	return 0;
}

