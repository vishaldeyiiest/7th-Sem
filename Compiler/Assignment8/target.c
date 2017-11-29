#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
//! 8085 Instruction Set
char registers[8] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', '\0'}; 
int regflags[8];
char vars[MAX];

int getreg();

char *parse_array[10];
char* lookup(char *);

void parse(char *str)
{
	int i = 0, j;
	*parse_array = NULL;
	parse_array[i] = strtok(str, " ");
	while(str[i] != '\0')
		parse_array[++i] = strtok(NULL, " ");
	for(j = 0; j < i; j++)
		printf("%s ", parse_array[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	FILE *fp, *fout;
	fp = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	memset(regflags, 0, sizeof(regflags)); //set all regs empty
	
	char buffer[MAX];
	char left[MAX], right[MAX];
	int begin = 1, jmp = 0, cond = 0;
	
	while(fgets(buffer, sizeof(buffer), fp))
	{
		//printf("%s\n", buffer);
		parse(buffer);
		if(begin)
			{
				fprintf(fout, "%s ", "MAIN: ");
				begin = 0;
			}
		if(!strncmp(buffer, "IF", 2))
		{
			char *t1, *t2;
			t1 = strstr(buffer, "<");
			t2 = strstr(buffer, ">");
			if(t1)
			{
				strcpy(left, buffer+1);
				strcpy(right, t1+1);
				t1 = NULL;
			}
			else if(t2)
			{
				strcpy(left, buffer+1);
				strcpy(right, t2+1);
				t2 = NULL;
			}

			jmp = 1;
			fprintf(fout, "%s ", "MOV");
			fprintf(fout, "%s", "A");
			char reg1 = registers[getreg(left)];
			char reg2 = registers[getreg(right)];
			fprintf(fout, "%c\n", reg2);
			fprintf(fout, "%s ", "CMP");
			fprintf(fout, "%c\n", reg1); 
			cond = 1;
		}
		
		else if(!strncmp(buffer, "GOTO", 4))
		{
			if(begin)
			{
				fprintf(fout, "%s ", "MAIN: ");
				begin = 0;
			}
			if(cond)
			{
				fprintf(fout, "%s ", "JC: ");
				cond = 0; jmp = 1;
			}
			if(jmp)
			{
				fprintf(fout, "%s ", "JMP: ");
				jmp = 1;
			}
			
		}
		else
		{
			
		}
	}	
}

int getreg()
{
	int i;
	for(i = 1; i < 8; i++)
		if(regflags[i] == 0)
			break;
	if(i == 8)
	{
		printf("All registers full...Emptying Register B..\n");
		regflags[1] = 0;
		i = 1;
	}
	return i;
}

char* lookup(char *var)
{
	char reg = vars[var[2]];
	if(reg == '.')
		return (var+1);
	else
	{
		char temp[2] = {0};
		sprintf(temp, "%c", reg);
		return temp;
	}
}
