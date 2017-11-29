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
#line 55 "intmed_code.y" /* yacc.c:1909  */

	Number val;
	char *tokname;
	expression expr_st;

#line 136 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
