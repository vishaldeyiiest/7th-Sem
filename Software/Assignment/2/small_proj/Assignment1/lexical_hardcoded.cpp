#include <bits/stdc++.h>
#include <ctype.h>
#include "lexical_hardcoded.hpp"
#define SHOW_DEFINE(x) fprintf(yyout, "%s	-	", #x)
#define ERROR 777
using namespace std;

FILE *yyin, *yyout;
char *yyt;
int yyleng, flag_sub;

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
	if(!strcmp(a, "void"))
		return VOID_TOK;
	else
		return ID_TOK;
}

int check_operator(char a[])
{
	if(!strcmp(a, ">="))
		return GTEQ_TOK;
	if(!strcmp(a, "<="))
		return LSEQ_TOK;
	if(!strcmp(a, "=="))
		return EQ2_TOK;
	if(!strcmp(a, "!="))
		return NOTEQ_TOK;
	if(!strcmp(a, "+="))
		return ADDEQ_TOK;
	if(!strcmp(a, "-="))
		return MINEQ_TOK;
	if(!strcmp(a, "*="))
		return MULTEQ_TOK;
	if(!strcmp(a, "/="))
		return DIVEQ_TOK;
	if(!strcmp(a, "%="))
		return MODEQ_TOK;
	if(!strcmp(a, "&="))
		return BITANDEQ_TOK;
	if(!strcmp(a, "|="))
		return BITOREQ_TOK;
	if(!strcmp(a, "^="))
		return BITXOREQ_TOK;
	if(!strcmp(a, "&&"))
		return AND_TOK;
	if(!strcmp(a, "||"))
		return OR_TOK;
	if(!strcmp(a, "++"))
		return INC_TOK;
	if(!strcmp(a, "--"))
		return DEC_TOK;

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
	yyin = stdin;
	c = getc(yyin);
	while(isspace(c))
		c = getc(yyin);

	switch(c)
	{
		
		case '(':
		case ')':
		case '}':
		case '{':
		case ';':
		case ',':
		{
			yyt[0] = c;
			yyleng = 1;
			printf("%c\n", c);
			return c;
		}

		case '&':
		case '|':
		{
			char ch = getc(yyin);
			if(ch == '=' or ch == c)
			{
				yyt = (char*)malloc(2*sizeof(char));
				yyt[0] = c; yyt[1] = ch;
				yyleng = 2;
				printf("%s\n", yyt);
				return check_operator(yyt);
			}
			else
			{
				fseek(yyin, -1, SEEK_CUR);
				yyt[0] = c;
				yyleng = 1;
				printf("%c\n", c);
				return c;
			}
		}

		case '-':
		{
			char ch = getc(yyin);
			if(ch == '=' or ch == c)
			{
				yyt = (char*)malloc(2*sizeof(char));
				yyt[0] = c; yyt[1] = ch;
				yyleng = 2;
				printf("%s\n", yyt);
				return MINEQ_TOK;
			}
			else
				fseek(yyin, -1, SEEK_CUR);
			 
			int l = 0;
			0_sub = 0;
			fseek(yyin, -2, SEEK_CUR);
			char prev = getc(yyin);
			/*fseek(yyin, -1, SEEK_CUR);
			*/
			while(isspace(prev))
			{
				l++;
				fseek(yyin, -l, SEEK_CUR);
				prev = getc(yyin);
			}
			fseek(yyin, l, SEEK_CUR);
			c = getc(yyin);
			while(isspace(c))
				c = getc(yyin);
			//fseek(yyin, -1, SEEK_CUR);
			//printf("%c %c\n", prev, c);
			if((prev == '=' || prev == '(') && (isalpha(c) || isdigit(c)))
			{	
				int len = 0, temp = 0, flag = 0;
				if(isdigit(c))
				{
					flag = 1;
					while(isdigit(c))
					{
						len++; 
						temp = temp*10+c-'0';
						c = getc(yyin);
					}
				}
				if(isalpha(c))
				{
					while(isalnum(c))
						len++, c = getc(yyin);
				}
				len++;
				fseek(yyin, -len, SEEK_CUR);
				yyt = (char*)malloc(len*sizeof(char));
				yyt[yyleng++] = '-';
				while(len--)
					yyt[yyleng++] = getc(yyin);
				if(flag)
				{
					printf("-%d\n", temp);
					return -temp;
				}
				else
				{
					printf("%s\n", yyt);
					return ID_TOK;
				}
			}
			else
			{
				yyt[0] = c;
				yyleng = 1;
				printf("%c\n", c);
				return c;
			}
		}

		case '=':
		case '+':
		case '*':
		case '/':
		case '>':
		case '<':
		case '!':
		case '%':
		case '^':
		{	
			char ch = getc(yyin);
			if(ch == '=' || (ch == c && c == '+'))
			{
				yyt = (char*)malloc(2*sizeof(char));
				yyt[0] = c; yyt[1] = ch;
				yyleng = 2;
				printf("%s\n", yyt);
				return check_operator(yyt);
			}
			else
			{
				fseek(yyin, -1, SEEK_CUR);
				yyt[0] = c;
				yyleng = 1;
				printf("%c\n", c);
				return c;
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
			int len = 0, error_flag = 0;
			char ch = c;
			while(isdigit(ch))
			{
				len++;
				ch = getc(yyin);
			}
			if(isalpha(ch))
			{
				error_flag = 1;
				while(isalnum(ch))
					len++, ch = getc(yyin);
			}
			fseek(yyin, -len, SEEK_CUR);
			yyt = (char*)malloc(len*sizeof(char));
			memset(yyt, '\0', len*sizeof(char));

			ch = c;
			int temp = 0;
			while(isdigit(ch))
			{
				yyt[yyleng] = ch;
				yyleng++;
				temp = temp*10+ch-'0';
				ch = getc(yyin);
			}
			if(isalpha(ch))
			{
				while(isalnum(ch))
				{
					yyt[yyleng] = ch;
					yyleng++; 
					ch = getc(yyin);
				}
			}
			
			fseek(yyin, -1, SEEK_CUR);
			if(error_flag)
			{
				printf("%d\n", ERROR);
				return ERROR;
			}
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
				{
					return ID_TOK;
				}
				return isReserved(yyt);
			}

	}
}
