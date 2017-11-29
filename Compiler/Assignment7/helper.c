#include "helper.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;
char numtoconcat[10];
int ind = 1;


int quad_index = 0;
void display_Quad()
{	int i;
	printf("\n INTERMEDIATE CODE : \n");	
	printf("\n Operator  Operand1  Operand2  Result");
	for(i = 0; i < quad_index; i++)
		printf("\n %d %-5s %-7s %-7s %-7s", i, quad[i].op, quad[i].op1, quad[i].op2, quad[i].res);
}

void addQuad(char op[], char op1[], char op2[], char res[])
{
	strcpy(quad[quad_index].op, op);
	strcpy(quad[quad_index].op1, op1);
	strcpy(quad[quad_index].op2, op2);
	strcpy(quad[quad_index].res, res);
	quad_index++;
}

char* newtemp()
{
	char *temp = (char*)malloc(20);
	snprintf(temp, 10, "_t%d", ind);
	ind++;	
	return temp;	
}

char *newLabel()
{
	char *tmp;
	tmp = (char*) malloc(9*sizeof(char));
	sprintf(tmp, "_L%d", cnt);
	cnt ++;
	return tmp;
}


char *formatCode(char *code)
{
	int count_line = 0, i;
	//printf("%d\n", count_line);
	
	char *temp = (char *) malloc((strlen(code)+ 4) * sizeof(char));
	char lines[10]; memset(lines, 0, 10);
	int len = 0, count = 0;

	for(i = 0; i < strlen(code)-1 ; i ++)
	{
		if(code[i] == '\n' && code[i + 1] == '\n')
			continue;
		if(code[i] == ':')
		{
			temp[len++] = code[i++];
			temp[len++] = code[i++];
			if(code[i] == '\n')
				continue;
		}
		
		temp[len++] = code[i];
	}
	if(temp[len - 2] != ':') temp[len++] = '\n';
	temp[len] = '\0';
	strcat(temp, "end");
	//printf("%s\n", code);
	free(code);
	/*
	for(i = 0; i < strlen(temp); i ++)
		if(temp[i] == '\n')
			count_line++;
	temp = (char*)realloc(temp, (strlen(code)+ count_line*3) * sizeof(char));	
	for(i = 0; i < strlen(temp); i ++)
	{
		sprintf(lines, "%2d ", count++);
		strcat(temp, lines);
		lines[0] = '\0';
		char buff[200] = {0};
		int k = 0;
		while(temp[i] != '\n')
			buff[k++] = temp[i++];
		strcat(temp, buff);
		strcat(temp, "\n");	
	}*/
	return temp;
}

