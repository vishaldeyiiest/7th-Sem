%{
	#include <stdio.h>
	#include "symb.h"
	#include "y.tab.h"
%}
LETTER [a-zA-Z_]
DIGIT [0-9]
SPACE [ \v\t]
LINE [\n]
%x COMMENT
%%
"/*" 			{printf("Multiline comments started at %d\n", yylineno); BEGIN(COMMENT); }
<COMMENT>\n		{yylineno++; }
<COMMENT>"*/"		{printf("Multiline comments ended at %d\n", yylineno); BEGIN(INITIAL); }
<COMMENT>.	;
"//".* 					{printf("Single line comment\n");}

"for" {return FOR_TOK;}
"while" {return WHILE_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"switch" {return SWITCH_TOK;}
"case" {return CASE_TOK;}
"void" {return VOID_TOK;}
"default" {return DEFAULT_TOK; }

"\'"."\'" { return CHAR_CONST; }
{DIGIT}*"."{DIGIT}+ {yylval.val.value.fval = atof(yytext); yylval.val.type = 2; return FLOAT_CONST; }
"(" {return LPAREN_TOK;}
")" {return RPAREN_TOK;}
">" {return GT_TOK;}
"<" {return LS_TOK;}
"=" {return EQ_TOK;}
"-" {return MINUS_TOK;}
"+" {return ADDITION_TOK;}
"*" {return MULTI_TOK;}
"/" {return DIVISION_TOK;}
"%" {return MOD_TOK;}
"{" {return LCURLY_TOK;}
"}" {return RCURLY_TOK;}
"|" {return BITOR_TOK;}
"&" {return BITAND_TOK;}
"^" {return XOR_TOK;}
"!" {return NOT_TOK;}
"," {return COMMA_TOK;}
";" {return SEMCOL_TOK;}
"'" {return COT_TOK; }
":"	{return COL_TOK; }

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
"int" {return INT_TOK;}
"float" {return FLOAT_TOK; }
"char"	{return CHAR_TOK; }

{SPACE}+ {}
{LINE} {yylineno++; }
{LETTER}({LETTER}|{DIGIT})* {yylval.tokname = strdup(yytext); return ID_TOK;}
{DIGIT}+ {yylval.val.value.ival = atoi(yytext); yylval.val.type = 1; return NUM_TOK;}
{DIGIT}+{LETTER}+({LETTER}|{DIGIT})* {ECHO; printf(" - Illegal Identifier\n");} 
. {ECHO; printf(" - Unknown character\n");}

%%
/*
int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("No file specified!..Reading from stdin and writing to stdout.\n");
		yyin = stdin;
		yyout = stdout;
	}
	else if(argc == 2)
	{
		printf("No output file specified!..Writing to stdout.\n");
		yyout = stdout;
		yyin = fopen(argv[1], "r");
	}
	else
	{	
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
	}
	
	int token;
	while(token = yylex())
	{
		fprintf(yyout, "%d\n", token);
	}
	fclose(yyin);
	fclose(yyout);
}*/
int yywrap(void)
{
	return 1;
}
