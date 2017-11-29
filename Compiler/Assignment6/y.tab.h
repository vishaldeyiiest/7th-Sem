/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 46 "yaccsymb.y" /* yacc.c:1909  */

	Number val;
	char *tokname;

#line 177 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
