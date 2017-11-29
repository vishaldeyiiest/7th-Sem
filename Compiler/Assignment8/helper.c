#include "helper.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;
char numtoconcat[10];
int ind = 1;

int adr_ind = 0;
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

int addresses[256];

char *formatCode(char *code)
{
	int count_line = 0, i;
	//printf("%d\n", count_line);
	memset(addresses, 0, 256);
	char *temp = (char *) malloc((strlen(code)+ 7) * sizeof(char));
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
	
	char *result = (char*)malloc(strlen(temp)+1000); strcpy(result, "\n");
	int mem = 1000; char loc[10];
	
	for(i = 0; i < strlen(temp)-1; i++)
	{
		char line[20] = {0}; 
		int k = 0;
		char *ptr = line;
		while(temp[i] != '\n')
		{
			line[k++] = temp[i++];
			if(line[0] == '_')
				addresses[line[2]] = mem, ptr = line + 5;
		}
		line[k] = '\n';
		//printf("%s", ptr);
		if(ptr[0] == '\n') continue;
		sprintf(loc, "0x%x: ", mem);
		if(k > 3 && line[k-3] != ':')
			strcat(result, loc);
		strcat(result, ptr);
		mem += size(ptr);
	}
	free(temp);
	char *result2 = (char*)malloc((strlen(result) + 200)*sizeof(char)); //strcpy(result2, "\n");
	for(i = 0; i < strlen(result)-1; i++)
	{
		char line[60] = {0}; 
		int j, k = 0;
		while(result[i++] && result[i] != '\n')
			line[k++] = result[i];
		
		for(j = 0; j < k; j++){
			if(line[j] == '_')
			{
				mem = addresses[line[j+2]];
				line[j] = '\0';
				sprintf(loc, "0x%x", mem);
				strcat(line, loc);
				break;
			}
		}	//printf("%s\n", line);
		strcat(result2, line); strcat(result2, "\n");
	}
	free(result);
	return result2;
}

int size(char *inst)
{
	int l = strlen(inst);
	if (l < 3)
		return 0;
	else if((l > 9 && inst[9] == 'x') || !strncmp(inst, "JC", 2) || !strncmp(inst, "STA", 3 || !strncmp(inst, "JMP", 3))) 
		return 3;
	else if (l > 2 && inst[2] == 'I')
		return 2;
	else
		return 1;
}

void setreg()
{
	int i;
	for(i = 0; i < 8; i++)
		reg_desc[i].flag = 0;
}

int getreg(char *op1)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if(reg_desc[i].flag && !strcmp(reg_desc[i].contents, op1))
			return i;
		if(reg_desc[i].flag == 0)
			break;
	}
	if(i == 8)
	{
		printf("All registers full...Emptying Register B..\n");
		i = 1;
	}
	return i;
}

int lookup_reg(int reg_index, char *id)
{
	//printf("REGFLAG: %d\n", reg_desc[reg_index].flag);
	if(reg_desc[reg_index].flag && !strcmp(reg_desc[reg_index].contents, id))
		return 1;
	return 0;
}

void update_reg(int reg_index, char *id)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if(reg_desc[i].flag && !strcmp(reg_desc[i].contents, id))
		{
			printf("Removing previous values of %s: clearing registers!!..\n", id);
			free(reg_desc[i].contents), reg_desc[i].flag = 0;
		}
	}
	reg_desc[reg_index].flag = 1;
	reg_desc[reg_index].contents = (char*)malloc(strlen(id)+1);
	strcpy(reg_desc[reg_index].contents, id);
}

void add_address(char *id, int reg, int mem_line)
{
	int i;
	for(i = 0; i < adr_ind; i++){
		if(adr_desc[i].name && !strcmp(adr_desc[i].name, id))
		{	
			update_address(reg, mem_line, adr_ind);
			return;
		}
	}
	
	adr_ind++;
	adr_desc[adr_ind].name = (char*)malloc(strlen(id)+1);
	strcpy(adr_desc[adr_ind].name, id);
	
	if(reg < 8)
	{
		update_reg(reg, id);
		sprintf(adr_desc[adr_ind].reg, "R%d", reg); adr_desc[adr_ind].location[0] = '\0';
		printf("Adding entry to address descriptor for %s at reg: %s\n", id, adr_desc[adr_ind].reg);	
	}
	else{
		sprintf(adr_desc[adr_ind].location, "0x%x", mem_line); 
		adr_desc[adr_ind].reg[0] = '\0';
		int r = adr_desc[adr_ind].reg[1] - '0';
		free(reg_desc[r].contents); reg_desc[r].flag = 0;
		printf("Adding entry to address descriptor for %s at loc: %s\n", id, adr_desc[adr_ind].location);	
	}
}

void update_address(int reg, int mem_line, int ind)
{	
	//adr_desc[ind].name = (char*)malloc(strlen(id)+1);
	//strcpy(adr_desc[ind].name, id);
	if(reg < 8)
	{
		update_reg(reg, adr_desc[ind].name);
		sprintf(adr_desc[ind].reg, "R%d", reg); 
		adr_desc[ind].location[0] = '\0';
	}
	else
	{
		sprintf(adr_desc[ind].location, "0x%x", mem_line); 
		adr_desc[ind].reg[0] = '\0';
		int r = adr_desc[ind].reg[1] - '0';
		free(reg_desc[r].contents); 
		reg_desc[r].flag = 0;
	}
}

char* search(char* id)
{
	int i;
	for(i = 0; i <= adr_ind; i++)
	{
		//printf("%s %s %s\n", adr_desc[i].name, adr_desc[i].reg, adr_desc[i].location);
		if(adr_desc[i].name && !strcmp(adr_desc[i].name, id))
		{
			//printf("%s %s %s\n", adr_desc[i].name, adr_desc[i].reg, adr_desc[i].location);
			if(adr_desc[i].reg[0] != '\0')
				return adr_desc[i].reg;
			else if(adr_desc[i].location[0] != '\0')
				return adr_desc[i].location;
		}
	}
	return NULL;
}

void show_regs()
{
	int i;
	for(i = 0; i < 8; i++)
		printf("R%d : %s\n", i, reg_desc[i].contents);
}

