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

expression codegen(expression, char*, expression);
expression codegenAssign(char*, expression);	
expression codegenAssignCompound(char*, char*, expression);
expression shorthand(char *a, char *op);		// only works for statements a++ or --a

char* out;
char *buffer_quad;			// to store the var definitions in list declarations before type checking
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
};
%type<val.type> type  	// CHAR_CONST '(' ')' INC_TOK DEC_TOK MINUS_TOK
%type<val> INT_CONST FLOAT_CONST const
%type<expr_st> expr unary 
%type<expr_st.code> stmt stmt_list cmp_stmt cond loop vd var_list list
%type<tokname> ID_TOK 
%%
start:
	stmt_list {out = formatCode($1); }
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
			buffer_quad = (char *)realloc(buffer_quad, (strlen(buffer_quad) + strlen($1) + 7) * sizeof(char));
			strcat(buffer_quad, "\n");
			strcat(buffer_quad, "DEC: ");
			strcat(buffer_quad, $1); //printf("%s\n", buffer_quad);
		}
	| ID_TOK '=' expr	
			{ 	int t = lookup_scope($1, scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $1, yylineno);
				else	put_tobuffer($1, $3.type);
				
				buffer_quad = (char*)realloc(buffer_quad, (strlen(buffer_quad) + 2 * strlen($1) + strlen($3.place) + 
											strlen($3.code) + 12) * sizeof(char));
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, $3.code);
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, "DEC: ");
				strcat(buffer_quad, $1);
				strcat(buffer_quad, "\n");
				strcat(buffer_quad, $1);
				strcat(buffer_quad, " = ");
				strcat(buffer_quad, $3.place);
	
				free($3.code); 
				//printf("%s\n", buffer_quad);
			}
	;
var_list: vd 		
	| var_list ',' vd		
	;	

list: type 	{	buffer_quad = (char*)malloc(sizeof(char)); buffer_quad[0] = '\0'; } 
	var_list	{	insert($1); 
				$$ = (char*)malloc((strlen(buffer_quad)+1)*sizeof(char)); 
				strcpy($$, buffer_quad); free(buffer_quad);
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
				$$ = (char *)malloc((strlen($1) + strlen($2) + 2) * sizeof(char));
				strcpy($$, $1);
				strcat($$, "\n");
				strcat($$, $2);
				free($1);
				free($2);
			}
	|	{$$ = (char *)malloc(sizeof(char)); $$[0] = '\0';}
	;

stmt:		
	list ';'		
	| ';'		{ $$ = (char *)malloc(sizeof(char)); $$[0] = '\0'; }
 	| cmp_stmt	
	| cond		
	| loop
	| expr ';'	{ $$ = $1.code; }
	;

loop:	
	//FOR_TOK '(' expr ';' expr ';' expr ')' stmt
	WHILE_TOK '(' expr ')' stmt	
	{
		char *t1 = newLabel();
		char *t2 = newLabel();
		char *t3 = newLabel();
		//printf("WWW%s", $3.code);
		char *ss = (char*)malloc(strlen($3.code) + 2);
		strcpy(ss, ": ");
		int i, k = 2;
		for(i = 1; i < strlen($3.code); i++, k++)	
			ss[k] = $3.code[i]; 
		$$ = (char *)malloc((strlen(ss) + strlen($5) + strlen($3.place) + 2* strlen(t1) + 2* strlen(t2) + 2* strlen(t3) + 33) * sizeof(char));
		strcpy($$, t1);	 
		strcat($$, ss);
		//printf("%s\n", $$);	
		strcat($$, "\nIF ");
		strcat($$, $3.place); 
		strcat($$, " GOTO ");
		strcat($$, t2);
		strcat($$, "\nGOTO ");
		strcat($$, t3);
		strcat($$, "\n"); 
		strcat($$, t2);	 
		strcat($$, ": ");  
		strcat($$, $5);  
		strcat($$, "\nGOTO ");				
		strcat($$, t1); 
		strcat($$, "\n");	
		strcat($$, t3);				
		strcat($$, ": \n");	
		//printf("%s\n", $$);
		free(ss);
		free($3.code); 
		free($5);

	}
	//| DO_TOK stmt WHILE_TOK '(' expr ')' ';'
	;

cond:		
	IF_TOK '(' expr ')' stmt 
		{	
			char * tmp1 = newLabel(); char * tmp2 = newLabel();
			$$ = (char *)malloc((strlen($3.code) + strlen($5) + strlen($3.place) + 2*strlen(tmp1) + 2*strlen(tmp2) + 24) * sizeof(char));
			
			strcpy($$, $3.code);
			strcat($$, "\nIF ");
			strcat($$, $3.place);
			strcat($$, " GOTO ");
			strcat($$, tmp1);
			strcat($$, "\nGOTO ");
			strcat($$, tmp2);
			strcat($$, "\n");
			strcat($$, tmp1);
			strcat($$, ": ");
			strcat($$, $5);
			strcat($$, "\n");
			strcat($$, tmp2);
			strcat($$, ": ");			
			strcat($$, "\n");		
			
			free($3.code); 
			free($5);
		}%prec IFX	//note this rule to avoid warning shift-reduce conflict: default action shift
	| IF_TOK '(' expr ')' stmt ELSE_TOK stmt
	{
		char * tmp1 = newLabel();
		char * tmp2 = newLabel();
		char * tmp3 = newLabel();
		$$ = (char *)malloc((strlen($3.code) + strlen($5) + strlen($7) + strlen($3.place) + 2* strlen(tmp1) + 2* strlen(tmp2) + 2* strlen(tmp3) + 33) * sizeof(char));
		strcpy($$, $3.code);
		strcat($$, "\nIF ");
		strcat($$, $3.place);
		strcat($$, " GOTO ");
		strcat($$, tmp1);
		strcat($$, "\nGOTO ");
		strcat($$, tmp2);
		strcat($$, "\n");
		strcat($$, tmp1);
		strcat($$, ": ");
		strcat($$, $5);
		strcat($$, "\n");
		strcat($$, "GOTO ");
		strcat($$, tmp3);
		strcat($$, "\n");
		strcat($$, tmp2);
		strcat($$, ": ");			
		strcat($$, $7);
		strcat($$, "\n");
		strcat($$, tmp3);
		strcat($$, ": ");

		free($3.code); 
		free($5);
		free($7);
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
				$$.code = (char*)malloc((strlen(ss) + strlen($$.place) + 4)*sizeof(char));
				strcpy($$.code, $$.place);
				strcat($$.code, " = ");				
				strcat($$.code, ss);
				
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
	expression ret;
	if(a.type == b.type) 
		ret.type = a.type; 		//only type checking done
	else printf("ERROR: Type (%d %d) mismatch at line %d\n", a.type, b.type, yylineno); 
				
	ret.place = newtemp();
	ret.code = (char*)malloc((strlen(a.code) + strlen(b.code) + strlen(ret.place) + strlen(a.place) + strlen(b.place) + strlen(op) + 8 ) * sizeof(char));
	strcpy(ret.code, a.code);	
	if(a.code[0] != '\0')
		 strcat(ret.code, "\n");
	strcat(ret.code, b.code);
	if(b.code[0] != '\0')
		strcat(ret.code, "\n");
	//printf("%sWWW", ret.code);
	strcat(ret.code, ret.place);
	strcat(ret.code, " = ");
	strcat(ret.code, a.place);
	strcat(ret.code, " ");
	strcat(ret.code, op);
	strcat(ret.code, " ");
	strcat(ret.code, b.place);
	
	free(a.code);
	free(b.code);
	return ret;
}

expression codegenAssign(char *a,  expression c)
{
	expression buffer_quad;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	
	buffer_quad.place = strdup(a); 
	buffer_quad.code = (char*)malloc((strlen(a) + strlen(c.place) + strlen(c.code) + 4) * sizeof(char));
	strcpy(buffer_quad.code, c.code);	
	if(c.code[0] != '\0')
		strcat(buffer_quad.code, "\n");
	strcat(buffer_quad.code, a);
	strcat(buffer_quad.code, " = ");
	strcat(buffer_quad.code, c.place);
	free(c.code);
	return buffer_quad;
}

expression codegenAssignCompound(char *a, char *op, expression c)
{
	char op_first[4];
	sprintf(op_first, " %c ", op[0]); 
	expression buffer_quad, ret;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else if(t == c.type) buffer_quad.type = t; 
	else printf("ERROR: Type (%s: %d %d) mismatch at line %d\n", a, t, c.type, yylineno); 
	
	buffer_quad.place = newtemp(); 
	buffer_quad.code = (char*)malloc((strlen(a) + strlen(c.place) + strlen(c.code) + strlen(buffer_quad.place) + 9) * sizeof(char));
	strcpy(buffer_quad.code, c.code);
	if(c.code[0] != '\0')
		strcat(buffer_quad.code, "\n");
	strcat(buffer_quad.code, buffer_quad.place);
	strcat(buffer_quad.code, " = ");
	strcat(buffer_quad.code, a);
	strcat(buffer_quad.code, op_first);
	strcat(buffer_quad.code, c.place);
	free(c.code);
	ret = codegenAssign(a, buffer_quad);
	return ret;
}

expression shorthand(char *a, char *op)
{
	expression ret;
	int t = lookup(a, scope); 		
	if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", a, yylineno);
	else ret.type = t;
	
	char op_first[4];
	sprintf(op_first, " %c ", op[0]);
	
	ret.place = newtemp();
	ret.code = (char*)malloc((2*strlen(a) + 2*strlen(ret.place) + 10) * sizeof(char));
	strcpy(ret.code, ret.place);
	strcat(ret.code, " = ");
	strcat(ret.code, a);
	strcat(ret.code, op_first);
	strcat(ret.code, "1");
	strcat(ret.code, "\n");
	strcat(ret.code, a);
	strcat(ret.code, " = ");
	strcat(ret.code, ret.place);
	return ret;

}

int main(int argc, char *argv[]) {
	int i;
	
	char errorMessage[256];
	
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("SUCCESS.. NO SYNTAX ERROR :).. INTERMEDIATE CODE GENERATED\n");
		printf("=====================================================================\n");
		puts(out);
		FILE *fo = fopen("abc.o", "w");
		fprintf(fo, "%s", out); 
		free(out);
		fclose(fo);
	}	
	//getchar();
	fclose(yyin);
	
	//show_symtable();
	return 0;
}

