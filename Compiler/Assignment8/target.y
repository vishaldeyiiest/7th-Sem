%{
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "symb.h"
#include "helper.h"
int yylex(void);
void yyerror(const char *);
extern FILE *yyin;
extern int yylineno;
extern char* yytext; 
int scope = 0;
typedef struct buffer
{
	char *name;
	int type;
}buff;
buff buffer[56];

int id_buff = 0;
void put_tobuffer(char*, int);
void insert(int );

char *targetcode(char*, char*, char*, char*);
char *targetcode_assign(char*, char*);

char* extract(char*);
expression codegen(expression, char*, expression);
expression codegenAssign(char*, expression);	
expression codegenAssignCompound(char*, char*, expression);
expression shorthand(char *a, char *op);		// only works for statements a++ or --a

char* out;
char *buffer_quad;			// to store the var definitions in list declarations before type checking

int cond_mem = 0;
int memory = 800, jmp_mem;
FILE *fpout = NULL;			// output for target code

%}

%token ID_TOK INT_TOK FLOAT_TOK CHAR_TOK INT_CONST FLOAT_CONST CHAR_CONST
%token FOR_TOK WHILE_TOK DO_TOK IF_TOK ELSE_TOK SWITCH_TOK CASE_TOK DEFAULT_TOK
%token VOID_TOK 

%nonassoc IFX
%nonassoc ELSE_TOK
%right '=' MINEQ_TOK ADDEQ_TOK MODEQ_TOK MULTEQ_TOK DIVEQ_TOK BITANDEQ_TOK BITOREQ_TOK BITXOREQ_TOK
%left OR_TOK
%left AND_TOK
%left '|'
%left '^'
%left '&'
%left EQ2_TOK NOTEQ_TOK
%left GTEQ_TOK LSEQ_TOK '>' '<'
%left LSHIFT_TOK RSHIFT_TOK
%left '+' '-'
%left '*' '/' '%'
%right INC_TOK DEC_TOK
%nonassoc UMINUS

%union
{
	Number val;
	char *tokname;
	expression expr_st;
	statement st;
};
%type<val.type> type  	// CHAR_CONST '(' ')' INC_TOK DEC_TOK MINUS_TOK
%type<val> INT_CONST FLOAT_CONST const
%type<expr_st> expr unary 
%type<st> stmt stmt_list cmp_stmt cond loop vd var_list list
%type<tokname> ID_TOK 
%%
start:
	stmt_list {out = formatCode($1.code); }
	; 					

const:	INT_CONST | FLOAT_CONST ;
/*
vd:
	type ID_TOK	{	int t = lookup_scope($2, scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $2, yylineno);
				else put_symb($2, $1, scope);
				$$ = (char *)malloc((strlen($2) + 6) * sizeof(char));
				strcpy($$, "DEC: ");
				strcat($$, $2);
			}
	| type ID_TOK '=' expr	
				{ 	int t = lookup_scope($2, scope); 
					if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $2, yylineno);
					else	put_symb($2, $1, scope);
				
					$$ = (char*)malloc((2 * strlen($2) + strlen($4.place) + strlen($4.code) + 11) * sizeof(char));
				strcpy($$, $4.code);
				strcat($$, "\n");
				strcat($$, "DEC: ");
				strcat($$, $2);
				strcat($$, "\n");
				strcat($$, $2);
				strcat($$, " = ");
				strcat($$, $4.place);
	
				free($4.code);
				}
	;
*/	

vd:
	ID_TOK	{	int t = lookup_scope($1, scope); 
			if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $1, yylineno);
			else put_tobuffer($1, -1);
			buffer_quad = (char *)realloc(buffer_quad, (strlen(buffer_quad) + strlen($1) + 8) * sizeof(char));
			char temp[7]; sprintf(temp, "\n0x%x: ", memory);
			strcat(buffer_quad, temp);
			strcat(buffer_quad, $1); //printf("%s\n", buffer_quad);
			
			add_address($1, 8, memory); memory++;
		}
	| ID_TOK '=' expr	
			{ 	int t = lookup_scope($1, scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $1, yylineno);
				else	put_tobuffer($1, $3.type);
				add_address($1, 8, memory);
				int temp_mem = memory;  memory++;
				char *temp_code = targetcode_assign($1, $3.place);
				buffer_quad = (char*)realloc(buffer_quad, (strlen(buffer_quad) + strlen($3.code) + 
								strlen(temp_code) + strlen($1) + 12) * sizeof(char));
		
				strcat(buffer_quad, $3.code);
				char temp[10]; sprintf(temp, "\n0x%x: ", temp_mem);
				strcat(buffer_quad, temp); 
				strcat(buffer_quad, $1);
				
				strcat(buffer_quad, temp_code);
				free($3.code); 
				//printf("%s\n", buffer_quad);
			}
	;
var_list: vd 		
	| var_list ',' vd		
	;	

list: type 	{	buffer_quad = (char*)malloc(sizeof(char)); buffer_quad[0] = '\0'; } 
	var_list	{	insert($1); 
				$$.code = (char*)malloc((strlen(buffer_quad)+1)*sizeof(char)); 
				strcpy($$.code, buffer_quad); free(buffer_quad);
			};


type: INT_TOK {$$ = INTEGER; } | FLOAT_TOK {$$ = FLOAT;};

cmp_stmt:
	'{' {scope++; printf("Entering Scope: %d\n", scope); } stmt_list 
	'}' { //show_symtable(); 
		printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; 
		$$ = $3; //show_symtable();
	};

stmt_list:
	stmt stmt_list	{	
				$$.code = (char *)malloc((strlen($1.code) + strlen($2.code) + 2) * sizeof(char));
				strcpy($$.code, $1.code);
				strcat($$.code, "\n");
				strcat($$.code, $2.code);
				$$.size = $1.size + $2.size;
				free($1.code);
				free($2.code);
			}
	|	{$$.code = (char *)malloc(sizeof(char)); $$.code[0] = '\0';}
	;

stmt:		
	list ';'		
	| ';'		{ $$.code = (char *)malloc(sizeof(char)); $$.code[0] = '\0'; }
 	| cmp_stmt	
	| cond		
	| loop
	| expr ';'	{ $$.code = $1.code; $$.size = $1.size; }
	;

loop:	
	//FOR_TOK '(' expr ';' expr ';' expr ')' stmt
	WHILE_TOK '(' expr ')' stmt	
	{
		$$.code = (char *)malloc((strlen($3.code) + strlen($5.code) + 50) * sizeof(char));
		char *l1 = newLabel(), *l2 = newLabel(), *l3 = newLabel();
	
		memory = memory - $5.size-1;
		char loc[10]; //sprintf(loc, "\n0x%x: ", memory);
		strcpy($$.code, "\n");
		strcat($$.code, l1); strcat($$.code, ": ");
		strcat($$.code, $3.code);
	
		int jc_loc = memory+6;
		strcat($$.code, "\nJC "); 
		//sprintf(loc, "0x%x", jc_loc);
		strcat($$.code, l2);

		strcat($$.code, "\nJMP ");
		int jmp_loc = jc_loc+$5.size+1;
		//sprintf(loc, "0x%x", jmp_loc); 			
		strcat($$.code, l3);

		//sprintf(loc, "\n0x%x: ", jc_loc);
		strcat($$.code, "\n");
		strcat($$.code, l2); strcat($$.code, ": ");
		strcat($$.code, $5.code);

		strcat($$.code, "\nJMP ");
		//sprintf(loc, "0x%x", memory); 			
		strcat($$.code, l1);

		//sprintf(loc, "\n0x%x: ", jmp_loc);
		strcat($$.code, "\n");
		strcat($$.code, l3); strcat($$.code, ": ");
		$$.size = jmp_loc - memory;
		memory = jmp_loc;
		free($3.code); 

	}
	//| DO_TOK stmt WHILE_TOK '(' expr ')' ';'
	;

cond:		
	IF_TOK '(' expr ')' stmt 
		{	
			//char * tmp1 = newLabel(); char * tmp2 = newLabel();
			//printf("%s\n", $<expr_st.code>5);
			$$.code = (char *)malloc((strlen($3.code) + strlen($5.code) + 50) * sizeof(char));
			//$5 = extract($5);
			char *l1 = newLabel(), *l2 = newLabel();
			memory = memory - $5.size-1;
			strcpy($$.code, $3.code);
			char loc[10]; //sprintf(loc, "\n0x%x: ", memory);
			strcat($$.code, "\n");
			//strcat($$.code, loc); 
		
			int jc_loc = memory+6;
			strcat($$.code, "JC "); 
			//sprintf(loc, "0x%x", jc_loc);
			strcat($$.code, l1);
	
			strcat($$.code, "\nJMP ");
			int jmp_loc = jc_loc+$5.size+1;
			//sprintf(loc, "0x%x", jmp_loc); 			
			strcat($$.code, l2);

			//sprintf(loc, "\n0x%x: ", jc_loc);
			strcat($$.code, "\n");
			strcat($$.code, l1); strcat($$.code, ": ");
			strcat($$.code, $5.code);

			strcat($$.code, "\n");
			//sprintf(loc, "\n0x%x: ", jmp_loc);
			strcat($$.code, l2); strcat($$.code, ": ");
			$$.size = jmp_loc - memory;
			memory = jmp_loc;
			free($3.code); 
			free($5.code);
			
		}%prec IFX	//note this rule to avoid warning shift-reduce conflict: default action shift
	| IF_TOK '(' expr ')' stmt ELSE_TOK stmt
	{
		char *l1 = newLabel(), *l2 = newLabel(), *l3 = newLabel();
		$$.code = (char *)malloc((strlen($3.code) + strlen($5.code) + strlen($7.code) + 70) * sizeof(char));
		strcpy($$.code, $3.code);
		memory = memory - $5.size-1;
		char loc[10]; //sprintf(loc, "\n0x%x: ", memory);
		strcat($$.code, "\n");
		//strcat($$.code, l1); strcat($$.code, ": ");
		
		int jc_loc = memory+6;
		strcat($$.code, "JC "); 
		//sprintf(loc, "0x%x", jc_loc);
		//strcat($$.code, "\n");
		strcat($$.code, l1); 
		
		strcat($$.code, "\nJMP ");
		int jmp1_loc = memory+$5.size+3;		
		//sprintf(loc, "0x%x", jmp1_loc);
		strcat($$.code, l2);

		//sprintf(loc, "\n0x%x: ", jc_loc);
		strcat($$.code, "\n");		
		strcat($$.code, l1); strcat($$.code, ": ");
		strcat($$.code, $5.code);
		
		strcat($$.code, "\nJMP ");
		int jmp2_loc = jmp1_loc + $7.size;		
		//sprintf(loc, "0x%x", jmp2_loc);	
		strcat($$.code, l3); 		

		//sprintf(loc, "\n0x%x: ", jmp1_loc);
		strcat($$.code, "\n");		
		strcat($$.code, l2); strcat($$.code, ": ");		
		strcat($$.code, $7.code);	
		
		//sprintf(loc, "\n0x%x: ", jmp2_loc);
		strcat($$.code, "\n");		
		strcat($$.code, l3); strcat($$.code, ": ");		
		$$.size = jmp2_loc - memory;
		memory = jmp2_loc;
		free($3.code); 
		free($5.code);
		free($7.code);
	}
	;						

expr:
	const		{ 	$$.type = $1.type; 
				$$.place = newtemp();
				char ss[20];
				if($1.type == INTEGER){
					sprintf(ss, "%d", $1.value.ival);
				}
				if($1.type == FLOAT){
					sprintf(ss, "%f", $1.value.fval);
				}
				$$.code = (char*)malloc((strlen(ss) + 18)*sizeof(char));
				int reg = getreg($$.place);
				sprintf($$.code, "\nMVI R%d, ", reg);
				strcat($$.code, ss);
				add_address($$.place, reg, 0);
				memory += 2;
				$$.size = 1;
			}
	| ID_TOK	{ 	
				int t = lookup($1, scope); 		//only type checking done
				if(t < 0) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno);
				else $$.type = t; 
				$$.place = strdup($1);
				$$.code = (char*)malloc(sizeof(char));
				$$.code[0] = '\0';
				
			}
	| unary		

	| expr '+' expr 	{ $$ = codegen($1, "+", $3); }
	| expr '-' expr 	{ $$ = codegen($1, "-", $3); }
	| expr '*' expr 	{ $$ = codegen($1, "*", $3); }
	| expr '/' expr 	{ $$ = codegen($1, "/", $3); }
	| expr '%' expr 	{ $$ = codegen($1, "%", $3); }

	| expr '>' expr 	{ $$ = codegen($1, ">", $3); }
	| expr '<' expr		{ $$ = codegen($1, "<", $3); }
	| expr '|' expr 	{ $$ = codegen($1, "|", $3); }
	| expr '&' expr 	{ $$ = codegen($1, "&", $3); }
	| expr GTEQ_TOK expr	{ $$ = codegen($1, ">=", $3); }
	| expr LSEQ_TOK expr 	{ $$ = codegen($1, "<=", $3); }

	| expr LSHIFT_TOK expr 	{ $$ = codegen($1, "<<", $3); }
	| expr RSHIFT_TOK expr  { $$ = codegen($1, ">>", $3); }
	| expr AND_TOK expr 	{ $$ = codegen($1, "&&", $3); }
	| expr OR_TOK expr 	{ $$ = codegen($1, "||", $3); }
	| expr EQ2_TOK expr 	{ $$ = codegen($1, "==", $3); } 
	| expr NOTEQ_TOK expr 	{ $$ = codegen($1, "!=", $3); }

	| ID_TOK '=' expr 	{	$$ = codegenAssign($1, $3); }

	| ID_TOK ADDEQ_TOK expr	{ 	$$ = codegenAssignCompound($1, "+=", $3); }
	| ID_TOK MINEQ_TOK expr { 	$$ = codegenAssignCompound($1, "-=", $3); }
	| ID_TOK MODEQ_TOK expr { 	$$ = codegenAssignCompound($1, "%=", $3); }
	| ID_TOK MULTEQ_TOK expr { 	$$ = codegenAssignCompound($1, "*=", $3); }
	| ID_TOK DIVEQ_TOK expr { 	$$ = codegenAssignCompound($1, "/=", $3); }
	| ID_TOK BITANDEQ_TOK expr { 	$$ = codegenAssignCompound($1, "&=", $3); }
	| ID_TOK BITOREQ_TOK expr { 	$$ = codegenAssignCompound($1, "|=", $3); }
	| ID_TOK BITXOREQ_TOK expr {	$$ = codegenAssignCompound($1, "^=", $3); }

	| '(' expr ')'	{ $$ = $2; }
	;

unary:
	ID_TOK INC_TOK		{ $$ = shorthand($1, "++"); }  
	| ID_TOK DEC_TOK 	{ $$ = shorthand($1, "--"); }
	| INC_TOK ID_TOK 	{ $$ = shorthand($2, "++"); }
	| DEC_TOK ID_TOK 	{ $$ = shorthand($2, "--"); }
	| '-' expr %prec UMINUS {
			$$.type = $2.type; 
			char *tmp = newtemp();
			$$.place = tmp;
			$$.code =  (char*)malloc((strlen(tmp) + strlen($2.place) + strlen($2.code)+ 7) * sizeof(char));
			strcpy($$.code, $2.code);
			strcat($$.code, "\n");
			strcat($$.code, tmp);
			strcat($$.code, " = - ");
			strcat($$.code, $2.place);
			free($2.code); 
		}	
	;
%%

void yyerror(const char *s) {
	fprintf(stderr, "%s At line %d: %s\n", s, yylineno, yytext);
	return;
}

void put_tobuffer(char *idname, int type)
{
	buffer[id_buff].name = (char*)malloc(strlen(idname)+1);
	strcpy(buffer[id_buff].name, idname);
	buffer[id_buff].type = type;
	id_buff++;
}

void insert(int type)
{
	int i;
	for(i = 0; i < id_buff; i++)
	{
		if(buffer[i].type == type || buffer[i].type == -1)
		{
			put_symb(buffer[i].name, type, scope);
			free(buffer[i].name); 
			buffer[i].type = 0;
		}
		else
			printf("ERROR: Type mismatch (%d %d) at line %d\n", buffer[i].type, type, yylineno); 
	}
	id_buff = 0;
}

expression codegen(expression a, char *op, expression b)
{
	int start_mem = memory;
	expression ret;
	if(a.type == b.type) 
		ret.type = a.type; 		//only type checking done
	else printf("ERROR: Type (%d %d) mismatch at line %d\n", a.type, b.type, yylineno); 
				
	ret.place = newtemp();
	char *temp =  targetcode(ret.place, a.place, op, b.place);
	ret.code = (char*)malloc(strlen(a.code) + strlen(b.code) + strlen(temp) + 1);
	strcpy(ret.code, a.code);
	strcat(ret.code, b.code);
	strcat(ret.code, temp);
	
	ret.size = b.size + a.size + memory - start_mem;
	free(a.code);
	free(b.code);
	return ret;
}

expression codegenAssign(char *a,  expression c)
{
	int start_mem = memory;
	expression buffer_quad;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	
	buffer_quad.place = strdup(a);
	char *tmp = targetcode_assign(buffer_quad.place, c.place);
	buffer_quad.code = (char*)malloc(strlen(c.code) + strlen(tmp)+1); 	
	strcpy(buffer_quad.code, c.code);
	strcat(buffer_quad.code, tmp);
	//fprintf(fpout, "%s", temp);
	buffer_quad.size = c.size + memory - start_mem;
	//free(c.code);
	return buffer_quad;
}

expression codegenAssignCompound(char *a, char *op, expression c)
{
	int start_mem = memory;
	expression buffer_quad, ret;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	char operator[2];
	sprintf(operator, "%c", op[0]);
	buffer_quad.place = newtemp(); 
	char *temp1 = targetcode(buffer_quad.place, a, operator, c.place);
	//fprintf(fpout, "%s", ret);
	ret = codegenAssign(a, buffer_quad);
	buffer_quad.code = (char*)malloc(strlen(temp1) + strlen(ret.code) + strlen(c.code) + 1);
	strcpy(buffer_quad.code, c.code);
	strcat(buffer_quad.code, temp1);
	strcat(buffer_quad.code, ret.code);
	free(ret.code), free(c.code);
	buffer_quad.size = c.size + memory - start_mem;
	return buffer_quad;
}

expression shorthand(char *a, char *op)
{
	expression ret;
	int start_mem = memory;	
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else ret.type = t;
	
	char operator[2];
	sprintf(operator, " %c ", op[0]);
	
	ret.place = newtemp();
	ret.code = (char*)malloc(12);
	char *loc = search(a);
	
	if(op[0] == '+')
	{
		strcat(ret.code, "INR "), strcat(ret.code, loc);
		if(loc[0] == 'R')
			memory += 1;
		else	memory += 3;
	}
	else
	{
		strcat(ret.code, "DCR "), strcat(ret.code, loc);
		if(loc[0] == 'R')
			memory += 1;
		else	memory += 3;
	}	
	ret.size = memory-start_mem;
	return ret;

}

char* targetcode(char* result, char* opr1, char *op, char* opr2)
{
	char *ret = (char*)malloc(strlen(op)+53);
	strcpy(ret, "\n");
	int reg = getreg(result);
	char temp[6]; 
	char buf[3]; sprintf(buf, "R%d", reg); 
	char* loc = search(opr1); printf("%s at LOC: %s\n", opr1, loc); 
	if(loc && loc[1]-'0' != reg)
	{
		sprintf(temp, "0x%x: ", memory); //strcat(ret, temp);
		strcat(ret, "MOV ");
		strcat(ret, buf);
		strcat(ret, ", ");
		strcat(ret, loc); 
		strcat(ret, "\n");
		if(strlen(loc) == 2)	
			memory += 1; 
		else	memory += 3;
	}
	sprintf(temp, "0x%x: ", memory); //strcat(ret, temp);
	if(!strcmp(op, "+"))
		strcat(ret, "ADD ");
	if(!strcmp(op, "-"))
		strcat(ret, "SUB ");
	if(!strcmp(op, "<"))
		strcat(ret, "CMP ");
	loc = search(opr2);  printf("%s at LOC: %s\n", opr2, loc);
	strcat(ret, buf);
	strcat(ret, ", ");
	strcat(ret, loc);
	
	if(strlen(loc) == 2)	
		memory += 1; 
	else	memory += 3;
	//update_reg(reg, result);
	add_address(result, reg, 0);
	return ret;
}

char* targetcode_assign(char *lhs, char *rhs)
{
	char *temp = (char*)malloc(12+14);
	strcpy(temp, "\n");
	char tt[6];
	char *loc1 = search(lhs), *loc2 = search(rhs);
	if(loc2 && strcmp(loc2, "R0"))
	{
		sprintf(tt, "0x%x: ", memory); 
		//strcat(temp, tt);
		strcat(temp, "\nMOV R0, ");
		strcat(temp, loc2);
		strcat(temp, "\n");
		if(strlen(loc2) == 2)	
			memory += 1; 
		else	memory += 3;
	}
	
	sprintf(tt, "0x%x: ", memory); //strcat(temp, tt);
	strcat(temp, "STA ");
	strcat(temp, loc1);
	if(strlen(loc1) == 2)	
		memory += 1; 
	else	memory += 3;
	return temp;
}

int main(int argc, char *argv[]) {
	if(argc < 3)
	{
		printf("USAGE: ./target <input-c-file> <output-s-file>\n");
		exit(1);
	}
	int i;
	
	char errorMessage[256];
	
	yyin = fopen(argv[1], "r");
	fpout = fopen(argv[2], "w");
	setreg();
	if(!yyparse())
	{
		printf("SUCCESS.. NO SYNTAX ERROR :).. INTERMEDIATE CODE GENERATED\n");
		printf("=====================================================================\n");
		puts(out);
		fprintf(fpout, "%s", out); 
		free(out);
		fclose(fpout);
	}	
	//getchar();
	fclose(yyin);
	//fclose(fpout);
	show_regs();
	return 0;
}

