#include <bits/stdc++.h>
#include <ctype.h>
#include "lexical_parser.hpp"
#define ERROR 777
using namespace std;

FILE *yyin, *yyout;
char *yytext;
int yyleng;

int yylex();

int main(int argc, char *argv[])
{
	int token;
	if(argc != 3)
	{
		fprintf(stderr, "Usage: <input file> <output file>\n");
		exit(1);
	}
	else
	{
		yyin = fopen(argv[1], "r");
		yyout = fopen(argv[2], "w");
		while(!feof(yyin))
		{
			token = yylex();
			printf("%s %d\n", yytext, token);
			fprintf(yyout, "%d\n", token);
			delete yytext;
		}	
	}
	fclose(yyin);
	fclose(yyout);
}

char get_ch()
{
	char ch = getc(yyin);
	while(isspace(ch))
		ch = getc(yyin);
	return ch;
}

int convto_int(char *a)
{
	int temp = 0;
	for(int i = 0; i < yyleng; i++)
		temp = temp*10 + yytext[i] - '0';
	return temp;
}

int yylex()
{
	char c;
	int state = 0, prev_state = 0, len = 0;
	yyleng = 0;
	yytext = (char*)malloc(256);
	memset(yytext, '\0', 256);
	while(!feof(yyin))	
	{	
		if(state != -1)
		{
			c = getc(yyin);
			while(isspace(c))
				c = getc(yyin);
			yytext[yyleng++] = c;
			//printf("%s %d\n", yytext, state);
		}
		switch(state)
		{
			
			case -1:
			{
				yytext[--yyleng] = '\0';
				state = 0;
				ungetc(c, yyin);
				//printf("%s\n", yytext);
				if(prev_state == INTCONST)
				{
					return convto_int(yytext);
				}
				return prev_state;
			}
			case 0: 
			{
				//c = get_ch();
				//printf("%c\n", c);
				if(c == ';')
					state = SEMCOL_TOK;
				else if(c == '(')
					state = LPAREN_TOK;
				else if(c == ')')
					state = RPAREN_TOK;
				else if(c == '{')
					state = LCURLY_TOK;
				else if(c == '}')
					state = RCURLY_TOK;
				else if(c == ',')
					state = COMMA_TOK;
				else if(c == 'f')
					state = 2;
				else if(c == 'w')
					state = 3;
				else if(c == 'i')
					state = 4;
				else if(c == 'e')
					state = 5;
				else if((c >= 'a' && c <= 'd') || (c == 'g') || (c == 'h') || (c >= 'j' && c <= 'v') || (c >= 'x' && c <= 'z') || (c >= 'A' && c <= 'Z'))
					state = ID_TOK;
				else if(c >= '0' && c <= '9')
					state = INTCONST;
				else if(c == '+')
					state = ADDITION_TOK;
				else if(c == '-')
					state = MINUS_TOK;
				else if(c == '*')
					state = MULTI_TOK;
				else if(c == '/')
					state = DIVISION_TOK;
				else if(c == '%')
					state = MOD_TOK;
				else if(c == '=')
					state = EQ_TOK;
				else if(c == '<')
					state = LS_TOK;
				else if(c == '>')
					state = GT_TOK;
				else if(c == '&')
					state = BITAND_TOK;
				else if(c == '|')
					state = BITOR_TOK;
				else if(c == '!')
					state = NOT_TOK;
				else if(c == '^')
					state = XOR_TOK;
				//printf("%c\n", c);
				break;
			}
			/* for 'for' keyword*/
			case 2:
			{
				//c = get_ch();
				if(c == 'o')
					state = 20;
				else
					prev_state = ID_TOK, state = -1;
				/*else if((c >= 'a' && c <= 'p') || (c >= 'q' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;
			}

			case 20:
				//c = get_ch();
				if(c == 'r')
					state = FOR_TOK;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'q') || (c >= 's' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;	

			case INTCONST:
				if(c >= '0' && c <= '9')
					state = INTCONST;
				else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
					return ERROR;
				else
					prev_state = state, state = -1;
				break;


			case FOR_TOK:
			case WHILE_TOK:
			case IF_TOK:
			case ELSE_TOK:
			case ID_TOK:
				//c = get_ch();
				if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, //printf("%c %d\n", c, state),
					state = -1;
				break;

			/* for 'while' keyword*/
			case 3:
				//c = get_ch();
				if(c == 'h')
					state = 22;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'g') || (c >= 'i' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;	

			case 22:
				//c = get_ch();
				if(c == 'i')
					state = 23;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'h') || (c >= 'j' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;

			case 23:
				//c = get_ch();
				if(c == 'l')
					state = 24;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'k') || (c >= 'm' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;

			case 24:
				//c = get_ch();
				if(c == 'e')
					state = WHILE_TOK;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'd') || (c >= 'f' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;

			/* for 'if' keyword*/
			case 4:
				//c = get_ch();
				if(c == 'f')
					state = IF_TOK;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'e') || (c >= 'g' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = , state = -1;*/
				break;

			/* for 'else' keyword*/
			case 5:
				//c = get_ch();
				if(c == 'l')
					state = 27;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'k') || (c >= 'm' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;

			case 27:
				//c = get_ch();
				if(c == 's')
					state = 28;
				else
					prev_state = ID_TOK, state = -1;
				break;
			
			case 28:
				//c = get_ch();
				if(c == 'e')
					state = ELSE_TOK;
				else
					prev_state = ID_TOK, state = -1;/*
				else if((c >= 'a' && c <= 'd') || (c >= 'f' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
					state = ID_TOK;
				else
					prev_state = state, state = -1;*/
				break;

			//for addition and increment 
			case ADDITION_TOK:
				if(c == '+')
					state = INC_TOK;
				else if(c == '=')
					state = ADDEQ_TOK;
				else
					prev_state = state, state = -1;
				break;
			
			// for subtraction and decrement
			case MINUS_TOK:
				//c = get_ch();
				if(c == '-')
					state = DEC_TOK;
				else if(c == '=')
					state = MINEQ_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for multiplication
			case MULTI_TOK:
				//c = get_ch();
				if(c == '=')
					state = MULTEQ_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for division
			case DIVISION_TOK:
				//c = get_ch();
				if(c == '=')
					state = DIVEQ_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for MODULAR 
			case MOD_TOK:
				//c = get_ch();
				if(c == '=')
					state = MODEQ_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for bit AND
			case BITAND_TOK:
				//c = get_ch();
				if(c == '=')
					state = BITANDEQ_TOK;
				else if(c == '&')
					state = AND_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for bit OR
			case BITOR_TOK:
				//c = get_ch();
				if(c == '=')
					state = BITOREQ_TOK;
				else if(c == '|')
					state = OR_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for bit XOR
			case XOR_TOK:
				//c = get_ch();
				if(c == '=')
					state = BITXOREQ_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for LESS THAN
			case LS_TOK:
				//c = get_ch();
				if(c == '=')
					state = LSEQ_TOK;
				else if(c == '<')
					state = LSHIFT_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for GREATER THAN
			case GT_TOK:
				//c = get_ch();
				if(c == '=')
					state = GTEQ_TOK;
				else if(c == '>')
					state = RSHIFT_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for EQUAL comparison
			case EQ_TOK:
				//c = get_ch();
				if(c == '=')
					state = EQ2_TOK;
				else
					prev_state = state, state = -1;
				break;

			// for NOT equal comparison
			case NOT_TOK:
				//c = get_ch();
				if(c == '=')
					state = NOTEQ_TOK;
				else
					prev_state = state, state = -1;
				break;
			
			
			case ADDEQ_TOK:
			case MINEQ_TOK:
			case MULTEQ_TOK:
			case MODEQ_TOK:
			case DIVEQ_TOK:
			case INC_TOK:
			case DEC_TOK:
			case LSEQ_TOK:
			case GTEQ_TOK:
			case EQ2_TOK:
			case NOTEQ_TOK:
			case LSHIFT_TOK:
			case RSHIFT_TOK:
			case LPAREN_TOK:
			case RPAREN_TOK:
			case LCURLY_TOK:
			case RCURLY_TOK:
			case AND_TOK:
			case OR_TOK:
			case SEMCOL_TOK:
			case COMMA_TOK:
				ungetc(c, yyin);
				yytext[--yyleng] = '\0';
				//printf("%s\n", yytext);
				return state;
			
			default:
				return ERROR;	
		}
		
	}
	
}
