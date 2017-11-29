%{
#include <stdio.h>
#include "symb.h"
#include "helper.h"
#include "y.tab.h"
%}

LETTER [a-z_A-Z]
DIGIT [0-9]
SPACE [ \v\t]
LINE [\n]
%x COMMENT

%%
"/*"		{ printf("Multiline comments started at %d\n", yylineno); BEGIN(COMMENT); }
<COMMENT>{LINE}	{ yylineno++; }
<COMMENT>"*/"	{ printf("Multiline comments ended at %d\n", yylineno); BEGIN(INITIAL); }	
<COMMENT>.
"//".*		{ printf("Single line comments at %d\n", yylineno); }

"for" 		{return FOR_TOK;}
"while" 	{return WHILE_TOK;}
"if" 		{return IF_TOK;}
"else" 		{return ELSE_TOK;}
"switch"	 {return SWITCH_TOK;}
"case" 		{return CASE_TOK;}
"void" 		{return VOID_TOK;}
"default"	 {return DEFAULT_TOK; }
"int"		 {return INT_TOK;}
"float" 	{return FLOAT_TOK; }
"char"		{return CHAR_TOK; }


"\'"."\'"	{ return CHAR_CONST; }
{DIGIT}+	{ yylval.val.value.ival = atoi(yytext); yylval.val.type = INTEGER; return INT_CONST; }
{DIGIT}+"."{DIGIT}+ { yylval.val.value.fval = atof(yytext); yylval.val.type = FLOAT; return FLOAT_CONST; }
{LETTER}+({DIGIT}|{LETTER})* {yylval.tokname = strdup(yytext); return ID_TOK; } 

{SPACE}+ {}
{LINE} {yylineno++; }
{DIGIT}+{LETTER}+({LETTER}|{DIGIT})* {ECHO; printf(" - Illegal Identifier\n");} 


"-=" {return MINEQ_TOK;}
"+=" {return ADDEQ_TOK;}
"%=" {return MODEQ_TOK;}
"*=" {return MULTEQ_TOK;}
"/=" {return DIVEQ_TOK;}
"&=" {return BITANDEQ_TOK;}
"|=" {return BITOREQ_TOK;}
"^=" {return BITXOREQ_TOK;}
">=" {return GTEQ_TOK;}
"<=" {return LSEQ_TOK;}
"&&" {return AND_TOK;}
"||" {return OR_TOK;}
"==" {return EQ2_TOK;}
"!=" {return NOTEQ_TOK;}
"<<" {return LSHIFT_TOK;}
">>" {return RSHIFT_TOK;}
"++" {return INC_TOK;}
"--" {return DEC_TOK;}

. 	{return yytext[0]; }
%%

int yywrap(void)
{ return 1; }
