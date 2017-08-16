#include <bits/stdc++.h>
#include <ctype.h>
#include "lexical_hardcoded.hpp"
using namespace std;

FILE *yyin, *yyout;
char *yyt;
int yyleng;

int yylex();
int isReserved(char a[])
{
	if(!strcmp(a, "for"))
		return FOR_TOK;
	if(!strcmp(a, "switch"))
		return SWITCH_TOK;
	if(!strcmp(a, "case"))
		return CASE_TOK;
	if(!strcmp(a, "if"))
		return IF_TOK;
	if(!strcmp(a, "else"))
		return ELSE_TOK;
	if(!strcmp(a, "main"))
		return MAIN_TOK;
	if(!strcmp(a, "void"))
		return VOID_TOK;
	else
		return ID_TOK;
}

int isComparator(char a[])
{
	if(!strcmp(a, ">="))
		return GTEQ_TOK;
	if(!strcmp(a, "<="))
		return LSEQ_TOK;
	if(!strcmp(a, "=="))
		return EQ2_TOK;
	if(!strcmp(a, "!="))
		return NOTEQ_TOK;
}

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
			fprintf(yyout, "%d\n", token);
		}
	}
	fclose(yyin);
	fclose(yyout);
}



int yylex()
{
	char c;
	yyleng = 0;
	if(yyin == NULL)
		yyin = stdin;
	c = getc(yyin);
	while(isspace(c))
		c = getc(yyin);


	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '(':
		case ')':
		case '}':
		case '{':
		case '&':
		case '|':
		case '^':
		{
			yyt[0] = c;
			yyleng = 1;
			printf("%c\n", c);
			return c;
		}

		case '=':
		case '>':
		case '<':
		case '!':
		{	
			char temp[2];
			temp[0] = c;
			char ch = getc(yyin);
			if(ch != '=')
			{
				yyt[0] = c;
				yyleng = 1;
				printf("%c\n", c);
				return c;
			}
			else
			{
				fseek(yyin, -1, SEEK_CUR);
				yyt = (char*)malloc(2*sizeof(char));
				yyt[0] = c; yyt[1] = ch;
				yyleng = 2;
				return isComparator(yyt);
			} 

		}

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			int len = 0;
			char ch = c;
			while(isdigit(ch))
			{
				len++;
				ch = getc(yyin);
			}
			fseek(yyin, -len, SEEK_CUR);
			yyt = (char*)malloc(len*sizeof(char));
			memset(yyt, '\0', len*sizeof(char));

			int temp = 0;
			while(isdigit(c))
			{
				yyt[yyleng] = c;
				yyleng++;
				temp = temp*10+c-'0';
				c = getc(yyin);
			}
			fseek(yyin, -1, SEEK_CUR);
			printf("%s\n", yyt);
			return temp; 	
		}

		default:/*
			if(isalpha(c) && isupper(c))
			{
				int len = 0;
				char ch = c;
				while(isalnum(ch))
				{
					len++;
					ch = getc(yyin);
				}
				fseek(yyin, -len, SEEK_CUR);
				yyt = (char*)malloc(len*sizeof(char));
				memset(yyt, '\0', len*sizeof(char));

				while(isalnum(c))
				{
					yyt[yyleng++] = c;
					c = getc(yyin);
				}
				fseek(yyin, -1, SEEK_CUR);
				printf("%s\n", yyt);
				return ID_TOK;
			}*/

			if(isalpha(c))
			{
				int upp = 1;
				if(islower(c))
					upp = 0;

				int len = 0;
				char ch = c;
				while(isalnum(ch))
				{
					len++;
					ch = getc(yyin);
				}
				fseek(yyin, -len, SEEK_CUR);
				yyt = (char*)malloc(len*sizeof(char));
				memset(yyt, '\0', len*sizeof(char));

				while(isalnum(c))
				{
					yyt[yyleng++] = c;
					c = getc(yyin);
				}
				fseek(yyin, -1, SEEK_CUR);
				printf("%s\n", yyt);
				if(upp)
					return ID_TOK;
				return isReserved(yyt);
			}

	}
}
