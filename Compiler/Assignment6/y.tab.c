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
#line 1 "yaccsymb.y" /* yacc.c:339  */

#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "symb.h"
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
}temp_buff;
temp_buff buffer[56];
int id_buff = 0;
void put_tobuffer(char*, int);
void insert(int );


#line 90 "y.tab.c" /* yacc.c:339  */

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
    NUM_TOK = 262,
    FLOAT_CONST = 263,
    CHAR_CONST = 264,
    LPAREN_TOK = 265,
    RPAREN_TOK = 266,
    COT_TOK = 267,
    FOR_TOK = 268,
    WHILE_TOK = 269,
    DO_TOK = 270,
    IF_TOK = 271,
    ELSE_TOK = 272,
    SWITCH_TOK = 273,
    CASE_TOK = 274,
    DEFAULT_TOK = 275,
    VOID_TOK = 276,
    MAIN_TOK = 277,
    LCURLY_TOK = 278,
    RCURLY_TOK = 279,
    NOT_TOK = 280,
    COMMA_TOK = 281,
    SEMCOL_TOK = 282,
    COL_TOK = 283,
    IFX = 284,
    EQ_TOK = 285,
    MINEQ_TOK = 286,
    ADDEQ_TOK = 287,
    MODEQ_TOK = 288,
    MULTEQ_TOK = 289,
    DIVEQ_TOK = 290,
    BITANDEQ_TOK = 291,
    BITOREQ_TOK = 292,
    BITXOREQ_TOK = 293,
    OR_TOK = 294,
    AND_TOK = 295,
    BITOR_TOK = 296,
    XOR_TOK = 297,
    BITAND_TOK = 298,
    EQ2_TOK = 299,
    NOTEQ_TOK = 300,
    GTEQ_TOK = 301,
    LSEQ_TOK = 302,
    GT_TOK = 303,
    LS_TOK = 304,
    LSHIFT_TOK = 305,
    RSHIFT_TOK = 306,
    ADDITION_TOK = 307,
    MINUS_TOK = 308,
    MULTI_TOK = 309,
    DIVISION_TOK = 310,
    MOD_TOK = 311,
    INC_TOK = 312,
    DEC_TOK = 313,
    UMINUS = 314
  };
#endif
/* Tokens.  */
#define ID_TOK 258
#define INT_TOK 259
#define FLOAT_TOK 260
#define CHAR_TOK 261
#define NUM_TOK 262
#define FLOAT_CONST 263
#define CHAR_CONST 264
#define LPAREN_TOK 265
#define RPAREN_TOK 266
#define COT_TOK 267
#define FOR_TOK 268
#define WHILE_TOK 269
#define DO_TOK 270
#define IF_TOK 271
#define ELSE_TOK 272
#define SWITCH_TOK 273
#define CASE_TOK 274
#define DEFAULT_TOK 275
#define VOID_TOK 276
#define MAIN_TOK 277
#define LCURLY_TOK 278
#define RCURLY_TOK 279
#define NOT_TOK 280
#define COMMA_TOK 281
#define SEMCOL_TOK 282
#define COL_TOK 283
#define IFX 284
#define EQ_TOK 285
#define MINEQ_TOK 286
#define ADDEQ_TOK 287
#define MODEQ_TOK 288
#define MULTEQ_TOK 289
#define DIVEQ_TOK 290
#define BITANDEQ_TOK 291
#define BITOREQ_TOK 292
#define BITXOREQ_TOK 293
#define OR_TOK 294
#define AND_TOK 295
#define BITOR_TOK 296
#define XOR_TOK 297
#define BITAND_TOK 298
#define EQ2_TOK 299
#define NOTEQ_TOK 300
#define GTEQ_TOK 301
#define LSEQ_TOK 302
#define GT_TOK 303
#define LS_TOK 304
#define LSHIFT_TOK 305
#define RSHIFT_TOK 306
#define ADDITION_TOK 307
#define MINUS_TOK 308
#define MULTI_TOK 309
#define DIVISION_TOK 310
#define MOD_TOK 311
#define INC_TOK 312
#define DEC_TOK 313
#define UMINUS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 46 "yaccsymb.y" /* yacc.c:355  */

	Number val;
	char *tokname;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    61,    61,    61,    64,    69,    69,
      72,    76,    83,    84,    87,    95,   102,   108,   108,   111,
     115,   116,   118,   121,   121,   123,   124,   127,   127,   130,
     130,   135,   136,   140,   141,   142,   143,   144,   145,   146,
     146,   152,   153,   154,   158,   159,   163,   164,   168,   169,
     172,   177,   182,   183,   187,   188,   189,   190,   193,   193,
     195,   195,   197,   198,   199,   202,   202,   205,   208,   209,
     210,   211,   212,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   220,   220,   220,   220,   222,   222,   222,   224,
     224
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID_TOK", "INT_TOK", "FLOAT_TOK",
  "CHAR_TOK", "NUM_TOK", "FLOAT_CONST", "CHAR_CONST", "LPAREN_TOK",
  "RPAREN_TOK", "COT_TOK", "FOR_TOK", "WHILE_TOK", "DO_TOK", "IF_TOK",
  "ELSE_TOK", "SWITCH_TOK", "CASE_TOK", "DEFAULT_TOK", "VOID_TOK",
  "MAIN_TOK", "LCURLY_TOK", "RCURLY_TOK", "NOT_TOK", "COMMA_TOK",
  "SEMCOL_TOK", "COL_TOK", "IFX", "EQ_TOK", "MINEQ_TOK", "ADDEQ_TOK",
  "MODEQ_TOK", "MULTEQ_TOK", "DIVEQ_TOK", "BITANDEQ_TOK", "BITOREQ_TOK",
  "BITXOREQ_TOK", "OR_TOK", "AND_TOK", "BITOR_TOK", "XOR_TOK",
  "BITAND_TOK", "EQ2_TOK", "NOTEQ_TOK", "GTEQ_TOK", "LSEQ_TOK", "GT_TOK",
  "LS_TOK", "LSHIFT_TOK", "RSHIFT_TOK", "ADDITION_TOK", "MINUS_TOK",
  "MULTI_TOK", "DIVISION_TOK", "MOD_TOK", "INC_TOK", "DEC_TOK", "UMINUS",
  "$accept", "start", "declare", "func_decl", "const", "vd", "var_list",
  "list", "func_def", "func_call", "list_arguments", "list_arg",
  "list_parameters", "list_param", "type", "cmp_stmt", "$@1", "stmt_list",
  "stmt", "$@2", "loop", "cond", "expr", "op", "cases", "multcase", "case",
  "caseblk", "defcase", "unary", "assignop", "binop", "relationalop",
  "logicalop", "eqop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -103,    42,  -103,  -103,  -103,  -103,   -20,     1,  -103,     8,
    -103,  -103,    -4,  -103,     3,    16,    30,    28,    37,  -103,
      46,    89,  -103,  -103,    30,    30,    53,    57,   123,  -103,
    -103,  -103,    33,  -103,    41,    39,    27,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,    30,    30,  -103,
    -103,  -103,  -103,    58,  -103,  -103,  -103,    30,  -103,  -103,
      16,    44,    45,    61,  -103,  -103,  -103,  -103,  -103,     9,
    -103,    27,    27,  -103,    63,    64,     9,    65,    66,  -103,
      50,    28,  -103,    54,     9,  -103,  -103,    52,  -103,  -103,
      30,    30,    67,    30,    30,  -103,  -103,  -103,  -103,    55,
      73,    75,    78,    79,    30,     9,    30,     9,    68,    59,
    -103,    81,    51,  -103,    30,    69,     9,    74,    90,  -103,
    -103,    36,    76,    82,    74,     9,    77,    83,    84,  -103,
      85,  -103,  -103,  -103,     9,     9,     9,     9,  -103,  -103,
    -103,  -103,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    27,    28,     2,     0,     0,     4,     0,
       6,     5,    10,    12,    14,    24,     0,     0,     0,    23,
       0,    47,     8,     9,     0,     0,     0,     0,    46,    53,
      11,    48,    10,    13,     7,    25,    18,    96,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    98,    97,    90,
      91,    89,    99,   100,    94,    95,    92,    93,    87,    88,
      82,    83,    84,    85,    86,    68,    69,     0,     0,    57,
      54,    56,    55,     0,    72,    70,    71,     0,    29,    15,
       0,    19,    20,     0,    17,    50,    51,    52,    49,    32,
      26,     0,     0,    16,     0,     0,     0,     0,     0,    34,
       0,     0,    35,     0,    32,    37,    36,     0,    21,    22,
       0,     0,     0,     0,     0,    33,    30,    31,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    44,    39,     0,     0,     0,    61,     0,    43,
      45,     0,     0,    58,    61,     0,     0,     0,     0,    40,
       0,    59,    60,    41,    66,    66,    66,    66,    65,    64,
      62,    63,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,  -103,   -34,    86,  -103,   103,  -103,  -103,
    -103,   -87,  -103,    26,     0,   115,  -103,     5,   -86,  -103,
    -103,  -103,   -16,    87,  -103,   -37,  -103,  -102,  -103,  -103,
    -103,  -103,  -103,  -103,  -103
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     6,    28,    13,    14,   100,     8,    29,
      83,    84,    18,    19,   101,   102,    89,   103,   158,   137,
     105,   106,   107,    67,   142,   143,   144,   159,   151,    31,
      68,    69,    70,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,     9,    82,   104,   108,   109,    15,    10,    73,    74,
     112,    12,    21,     3,     4,    20,    22,    23,   104,    24,
       3,     4,    94,    95,    96,    97,    16,    98,    11,    17,
      81,    32,    78,    21,    22,    23,    99,    22,    23,   130,
      24,   132,     2,   146,   147,   148,     3,     4,    34,    35,
     140,    85,    86,   160,   161,   162,    75,    82,    82,   153,
      76,    88,    25,    16,    78,    80,    26,    27,   136,    87,
      91,    92,    93,   110,   111,   113,   114,   115,   116,   118,
      20,   121,   124,    25,   125,   126,   134,    26,    27,   127,
     128,   133,   135,   141,   119,   120,   139,   122,   123,    36,
     149,   145,   150,    33,     7,   154,    90,   152,   129,   117,
     131,   155,   156,   157,    37,    77,     0,     0,   138,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    37,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
      16,     1,    36,    89,    91,    92,    10,    27,    24,    25,
      96,     3,     3,     4,     5,    15,     7,     8,   104,    10,
       4,     5,    13,    14,    15,    16,    30,    18,    27,    26,
       3,     3,    23,     3,     7,     8,    27,     7,     8,   125,
      10,   127,     0,     7,     8,     9,     4,     5,    11,     3,
     136,    67,    68,   155,   156,   157,     3,    91,    92,   145,
       3,    77,    53,    30,    23,    26,    57,    58,    17,    11,
      26,    26,    11,    10,    10,    10,    10,    27,    24,    27,
      80,    14,    27,    53,    11,    10,    27,    57,    58,    11,
      11,    23,    11,    19,   110,   111,    27,   113,   114,    10,
      24,    11,    20,    17,     1,    28,    80,   144,   124,   104,
     126,    28,    28,    28,    25,    28,    -1,    -1,   134,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    25,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,     0,     4,     5,    62,    63,    67,    68,    74,
      27,    27,     3,    65,    66,    10,    30,    26,    72,    73,
      74,     3,     7,     8,    10,    53,    57,    58,    64,    69,
      82,    89,     3,    65,    11,     3,    10,    25,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    83,    90,    91,
      92,    93,    94,    82,    82,     3,     3,    83,    23,    75,
      26,     3,    64,    70,    71,    82,    82,    11,    82,    76,
      73,    26,    26,    11,    13,    14,    15,    16,    18,    27,
      67,    74,    75,    77,    78,    80,    81,    82,    71,    71,
      10,    10,    78,    10,    10,    27,    24,    77,    27,    82,
      82,    14,    82,    82,    27,    11,    10,    11,    11,    82,
      78,    82,    78,    23,    27,    11,    17,    79,    82,    27,
      78,    19,    84,    85,    86,    11,     7,     8,     9,    24,
      20,    88,    85,    78,    28,    28,    28,    28,    78,    87,
      87,    87,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    69,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    76,
      75,    77,    77,    78,    78,    78,    78,    78,    78,    79,
      78,    80,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    87,    87,    88,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    93,    93,    93,    94,
      94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     2,     5,     1,     1,
       1,     3,     1,     3,     2,     6,     4,     1,     0,     1,
       1,     3,     3,     1,     0,     2,     4,     1,     1,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     2,     0,
       8,     9,     5,     7,     5,     7,     1,     1,     1,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     4,     4,     4,     1,     0,     3,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
        case 7:
#line 64 "yaccsymb.y" /* yacc.c:1646  */
    {int t = lookup_scope((yyvsp[-3].tokname), scope); 
					if(t != -1) printf("ERROR: '%s' redeclared at %d\n", (yyvsp[-3].tokname), yylineno);
					else put_symb((yyvsp[-3].tokname), (yyvsp[-4].val.type), scope); }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "yaccsymb.y" /* yacc.c:1646  */
    {	int t = lookup_scope((yyvsp[0].tokname), scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", (yyvsp[0].tokname), yylineno);
				else put_tobuffer((yyvsp[0].tokname), -1);; 
			}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "yaccsymb.y" /* yacc.c:1646  */
    { 	int t = lookup_scope((yyvsp[-2].tokname), scope); 
					if(t != -1) printf("ERROR: '%s' redeclared at %d\n", (yyvsp[-2].tokname), yylineno);
					else	put_tobuffer((yyvsp[-2].tokname), (yyvsp[0].val).type);;
					//if($$ != $3.type) printf("ERROR1: Type mismatch (%d %d) at line %d\n", $$, $3.type, yylineno); 
				}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "yaccsymb.y" /* yacc.c:1646  */
    {insert((yyvsp[-1].val.type)); }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "yaccsymb.y" /* yacc.c:1646  */
    {	int t = lookup_scope((yyvsp[-4].tokname), scope); 
				if(t != -1) printf("'%s' defined at %d\n", (yyvsp[-4].tokname), yylineno);
				else put_symb((yyvsp[-4].tokname), (yyvsp[-5].val.type), scope); 
			}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 103 "yaccsymb.y" /* yacc.c:1646  */
    {	int t = lookup((yyvsp[-3].tokname), scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[-3].tokname), yylineno);
				else	(yyval.val).type = t;
			}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 111 "yaccsymb.y" /* yacc.c:1646  */
    {	int t = lookup((yyvsp[0].tokname), scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[0].tokname), yylineno); 
				//$$.value.ival += 1;
			}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "yaccsymb.y" /* yacc.c:1646  */
    {	int t = lookup((yyvsp[-2].tokname), scope); 		//only type checking done
					if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[-2].tokname), yylineno); }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "yaccsymb.y" /* yacc.c:1646  */
    { put_symb((yyvsp[0].tokname), (yyvsp[-1].val.type), scope+1); }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "yaccsymb.y" /* yacc.c:1646  */
    { put_symb((yyvsp[-2].tokname), (yyvsp[-3].val.type), scope+1); }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "yaccsymb.y" /* yacc.c:1646  */
    {(yyval.val.type) = INTEGER; }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "yaccsymb.y" /* yacc.c:1646  */
    {(yyval.val.type) = FLOAT;}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "yaccsymb.y" /* yacc.c:1646  */
    {scope++; printf("Entering Scope: %d\n", scope); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 131 "yaccsymb.y" /* yacc.c:1646  */
    { show_symtable(); printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; show_symtable();
	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 146 "yaccsymb.y" /* yacc.c:1646  */
    { scope++; printf("Entering Scope: %d\n", scope);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "yaccsymb.y" /* yacc.c:1646  */
    { show_symtable(); printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; show_symtable();
	}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "yaccsymb.y" /* yacc.c:1646  */
    { 	int t = lookup((yyvsp[0].tokname), scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[0].tokname), yylineno);
				else (yyval.val).type = lookup((yyvsp[0].tokname), scope); 
			}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 169 "yaccsymb.y" /* yacc.c:1646  */
    {	if((yyvsp[-2].val).type == (yyvsp[0].val).type) (yyval.val).type = (yyvsp[-2].val).type; 		//only type checking done
				else printf("ERROR: Type (%d %d) mismatch at line %d\n", (yyvsp[-2].val).type, (yyvsp[0].val).type, yylineno); }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 172 "yaccsymb.y" /* yacc.c:1646  */
    { 	int t = lookup((yyvsp[-2].tokname), scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", (yyvsp[-2].tokname), yylineno);
				else if(t == (yyvsp[0].val).type) (yyval.val).type = t; 
				else printf("ERROR: Type (%s:%d %d) mismatch at line %d\n", (yyvsp[-2].tokname), t, (yyvsp[0].val).type, yylineno); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 177 "yaccsymb.y" /* yacc.c:1646  */
    { 	int t = lookup((yyvsp[-2].tokname), scope); 		//only type checking done
					if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", (yyvsp[-2].tokname), yylineno);
					else if(t == (yyvsp[0].val).type) (yyval.val).type = t; 
					else printf("ERROR: Type (%s:%d %d) mismatch at line %d\n", (yyvsp[-2].tokname), t, (yyvsp[0].val).type, yylineno); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 182 "yaccsymb.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[-1].val); }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 183 "yaccsymb.y" /* yacc.c:1646  */
    { (yyval.val).type = (yyvsp[0].val).type; }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 208 "yaccsymb.y" /* yacc.c:1646  */
    { int t = lookup((yyvsp[-1].tokname), scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", (yyvsp[-1].tokname)); else (yyval.val).type = t; }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 209 "yaccsymb.y" /* yacc.c:1646  */
    { int t = lookup((yyvsp[-1].tokname), scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", (yyvsp[-1].tokname)); else (yyval.val).type = t; }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 210 "yaccsymb.y" /* yacc.c:1646  */
    { int t = lookup((yyvsp[0].tokname), scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", (yyvsp[0].tokname)); else (yyval.val).type = t; }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 211 "yaccsymb.y" /* yacc.c:1646  */
    { int t = lookup((yyvsp[0].tokname), scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", (yyvsp[0].tokname)); else (yyval.val).type = t; }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 212 "yaccsymb.y" /* yacc.c:1646  */
    {(yyval.val).type = (yyvsp[0].val).type; }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1670 "y.tab.c" /* yacc.c:1646  */
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
#line 226 "yaccsymb.y" /* yacc.c:1906  */


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

int main(int argc, char *argv[]) {
	int i;
	
	char errorMessage[256];
	
	yyin = fopen(argv[1], "r");

	if(!yyparse())
		printf("SUCCESS.. NO SYNTAX ERROR :)\n");
	//getchar();
	fclose(yyin);
	/*printGrammar(g);
	fprintf(grammarOutFile, "\n");
        generateString(g);
	*/
	show_symtable();
	return 0;
}
