#include "symb.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int hash(char *name)
{ 
	int temp = 0, i = 0;
  	while (name[i] != '\0')
  	{
  		temp = ((temp << SHIFT) + name[i]) % SIZE;
    		i++;
  	}
  	return temp;
}

void put_symb(char *name, int type, int scope)
{
	int key = hash(name);
	symrec *s = symtable[key];
	while(s != NULL)
		s = s->next;
	if(s == NULL)
	{
		s = (symrec*)malloc(sizeof(struct symrec));
		s->name = strdup(name);
		s->type = type;
		s->scope = scope;
		s->value.ival = 0;
		s->value.fval = 0;		
		s->next = symtable[key];
		symtable[key] = s;
	}
	
}

/*
void put_func(char *name, int type, int scope, int nump, vtype types[])
{
	int key = hash(name);
	symrec *s = symtable[key];
	while(s != NULL)
		s = s->next;
	if(s == NULL)
	{
		s = (symrec*)malloc(sizeof(struct symrec));
		s->name = strdup(name);
		s->type = type;
		s->scope = scope;
		s->value.ival = 0;
		s->value.fval = 0;	
		function *temp = s->fptr;
		while(temp != NULL)
			temp = temp->next;
		if(temp == NULL)
		{
			temp = (function*)malloc(sizeof(function));
			temp->num_par = nump;
			temp->type = (vtype*)malloc(sizeof(int)*nump);
			memcpy(temp->type, types, nump);
			temp->next = s->fptr;
			s->fptr = temp;
		}	
		s->next = symtable[key];
		symtable[key] = s;
	}
	
}
*/
int lookup_type(char *name, int scope)
{
	int k = hash(name);
	symrec *temp = symtable[k];
	while(temp != NULL)
	{ 
		if(strcmp(temp->name, name) == 0)
			break;
		temp = temp->next;
	}
	
	if(temp == NULL)
		return -1;
	return temp->type;
}

int lookup_scope(char *name, int scope)
{
	int k = hash(name);
	symrec *temp = symtable[k];
	while(temp != NULL)
	{
		if(strcmp(temp->name, name) == 0 && temp->scope == scope)
			break;
		temp = temp->next;
	}
	if(temp == NULL)
		return -1;
	else
	{
		//printf("%s %d %d\n", name, temp->type, temp->scope);
		return temp->scope;
	}
}

int lookup(char *name, int scope)
{
	int s = -1;
	while(scope)
	{
		s = lookup_type(name, scope);
		if(s == -1)
			scope--;
		else
			return s;	
	}
	return s;
}
/*
int setType(char *name, int type, int scope)
{
	int k = hash(name);
	symrec *temp = symtable[k];
	while(temp != NULL)
	{
		if(strcmp(temp->name, name) == 0 && temp->scope == scope)
			break;
		temp = temp->next;
	}
	if(temp == NULL)
		return -1;
	else
	{
		temp->type = type;
	}
}

int setval(char *name, tvalue v, int scope)
{
   	int k = hash(name);
	symrec temp = symtable[k];
	while(temp != NULL && strcmp(temp->name, name) != 0 && temp->scope != scope)
		temp = temp->next;
	if(temp == NULL)
		return -1;
	else
	{
		temp->value.ival = v.ival;
		temp->value.fval = v.fval;
		return 0;
	}
}
*/
void show_symtable() 
{ 
  	int i;
  	printf("------------ ------ ------------\n");
 	printf("Name         Type   Scope\n");
	printf("------------ ------ -------------\n");
  	for(i = 0; i < SIZE; i++)
  	{ 
		if(symtable[i] != NULL)
    		{ 
			symrec *l = symtable[i];
      			while(l != NULL)
      			{ 
				printf("%-12s ",l->name);
				if (l->type == VOID)
           				printf("%-7s","VOID");				
				if (l->type == INTEGER)
           				printf("%-7s","INT");
        			if (l->type == FLOAT)
           				printf("%-7s","FLOAT");
        			printf("%-5d", l->scope);
        			printf("\n");
        			l = l->next;
      			}
    		}
  	}
}

void exitscope(int scope)
{
	int i;
	for(i = 0; i < SIZE; i++)
  	{ 
		if(symtable[i] != NULL)
    		{ 
			symrec *curr = symtable[i];	
			if(curr->scope == scope)
			{
				symtable[i] = curr->next;
				free(curr);	
			}
			curr = symtable[i];
			symrec **prev = &(symtable[i]) ; 
      			while(curr)
			{
				if(curr->scope == scope)
				{
					(*prev)->next = curr->next;
					free(curr);	
				}
				curr = curr->next;	
			}
    		}
  	}
	return;
}

