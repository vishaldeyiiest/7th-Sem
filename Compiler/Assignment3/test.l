%{
	#include <stdio.h>
	#include "lexical.hpp"
%}
LETTER [a-zA-Z_]
DIGIT [0-9]
SPACE [ \n\t]

%%
"//".* 								{printf("Single line comment\n");}
"/*"([^*]|[*]+[^*/])*[*]+"/"		{printf("Multiline comments\n");}
[/][*]                               {ECHO; printf(" Unterminated comment\n"); }

"for" {return FOR_TOK;}
"while" {return WHILE_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"switch" {return SWITCH_TOK;}
"case" {return CASE_TOK;}
"void" {return VOID_TOK;}
"main" {return MAIN_TOK;}

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

{SPACE}+ {}
{LETTER}({LETTER}|{DIGIT})* {return ID_TOK;}
{DIGIT}+ {return atoi(yytext);}
{DIGIT}+{LETTER}+({LETTER}|{DIGIT})* {ECHO; printf(" - Illegal Identifier\n");} 
. {ECHO; printf(" - Unknown character\n");}

%%

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
}
int yywrap(){}
