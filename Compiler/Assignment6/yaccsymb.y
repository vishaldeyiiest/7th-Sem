%{
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include "symb.h"
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
}temp_buff;
temp_buff buffer[56];
int id_buff = 0;
void put_tobuffer(char*, int);
void insert(int );

%}

%token ID_TOK INT_TOK FLOAT_TOK CHAR_TOK NUM_TOK FLOAT_CONST CHAR_CONST LPAREN_TOK RPAREN_TOK COT_TOK
%token FOR_TOK WHILE_TOK DO_TOK IF_TOK ELSE_TOK SWITCH_TOK CASE_TOK DEFAULT_TOK
%token VOID_TOK MAIN_TOK LCURLY_TOK RCURLY_TOK NOT_TOK COMMA_TOK SEMCOL_TOK COL_TOK

%nonassoc IFX
%nonassoc ELSE_TOK
%right EQ_TOK MINEQ_TOK ADDEQ_TOK MODEQ_TOK MULTEQ_TOK DIVEQ_TOK BITANDEQ_TOK BITOREQ_TOK BITXOREQ_TOK
%left OR_TOK
%left AND_TOK
%left BITOR_TOK
%left XOR_TOK
%left BITAND_TOK
%left EQ2_TOK NOTEQ_TOK
%left GTEQ_TOK LSEQ_TOK GT_TOK LS_TOK
%left LSHIFT_TOK RSHIFT_TOK
%left ADDITION_TOK MINUS_TOK
%left MULTI_TOK DIVISION_TOK MOD_TOK
%right INC_TOK DEC_TOK
%nonassoc UMINUS

%union
{
	Number val;
	char *tokname;
};
%type<val.type> type list var_list vd
%type<val> NUM_TOK FLOAT_CONST 	// CHAR_CONST LPAREN_TOK RPAREN_TOK INC_TOK DEC_TOK MINUS_TOK
%type<val> expr const unary func_call 
%type<tokname> ID_TOK MAIN_TOK 
%%
start:
	start declare
	|
	; 					

declare: 	
	func_def | list SEMCOL_TOK | func_decl SEMCOL_TOK;

func_decl:	
	type ID_TOK LPAREN_TOK list_parameters RPAREN_TOK {int t = lookup_scope($2, scope); 
					if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $2, yylineno);
					else put_symb($2, $1, scope); }
	;

const:	NUM_TOK | FLOAT_CONST ;

vd:
	ID_TOK		{	int t = lookup_scope($1, scope); 
				if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $1, yylineno);
				else put_tobuffer($1, -1);; 
			}
	| ID_TOK EQ_TOK expr	{ 	int t = lookup_scope($1, scope); 
					if(t != -1) printf("ERROR: '%s' redeclared at %d\n", $1, yylineno);
					else	put_tobuffer($1, $3.type);;
					//if($$ != $3.type) printf("ERROR1: Type mismatch (%d %d) at line %d\n", $$, $3.type, yylineno); 
				}
	;	

var_list: vd 		//{setType($1, $<val.type>0, scope); }
	| var_list COMMA_TOK vd		//{setType($3, $<val.type>0, scope); }
	;	

list: type var_list	{insert($1); };
/*	
list: 		
	var_decl 
	| var_decl COMMA_TOK vd	{ $$ = $1; $3 = $1; setType($3); }
	;
*/
func_def:	
	type ID_TOK LPAREN_TOK list_parameters RPAREN_TOK cmp_stmt	
			{	int t = lookup_scope($2, scope); 
				if(t != -1) printf("'%s' defined at %d\n", $2, yylineno);
				else put_symb($2, $1, scope); 
			}
	;

func_call: ID_TOK LPAREN_TOK list_arguments RPAREN_TOK	
			{	int t = lookup($1, scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno);
				else	$$.type = t;
			}
	;
list_arguments: list_arg | ;

list_arg:
	ID_TOK 		{	int t = lookup($1, scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno); 
				//$$.value.ival += 1;
			}
	| const		
	| ID_TOK COMMA_TOK list_arg {	int t = lookup($1, scope); 		//only type checking done
					if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno); }
	| const COMMA_TOK list_arg	
	;
	
list_parameters: list_param | ;
list_param:
	type ID_TOK 		{ put_symb($2, $1, scope+1); }
	| type ID_TOK COMMA_TOK list_param { put_symb($2, $1, scope+1); }	
	;

type: INT_TOK {$$ = INTEGER; } | FLOAT_TOK {$$ = FLOAT;};

cmp_stmt:
	LCURLY_TOK{scope++; printf("Entering Scope: %d\n", scope); } stmt_list 
	RCURLY_TOK{ show_symtable(); printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; show_symtable();
	};

stmt_list:
	stmt stmt_list	
	|
	;

stmt:		
	list SEMCOL_TOK
	| SEMCOL_TOK
 	| cmp_stmt
	| cond
	| loop
	| expr SEMCOL_TOK
	| SWITCH_TOK LPAREN_TOK expr RPAREN_TOK LCURLY_TOK { scope++; printf("Entering Scope: %d\n", scope);} cases 
		RCURLY_TOK { show_symtable(); printf("Exiting Scope: %d\n", scope); exitscope(scope); scope--; show_symtable();
	}
	;

loop:	
	FOR_TOK LPAREN_TOK expr SEMCOL_TOK expr SEMCOL_TOK expr RPAREN_TOK stmt
	| WHILE_TOK LPAREN_TOK expr RPAREN_TOK stmt
	| DO_TOK stmt WHILE_TOK LPAREN_TOK expr RPAREN_TOK SEMCOL_TOK
	;

cond:		
	IF_TOK LPAREN_TOK expr RPAREN_TOK stmt %prec IFX	//note this rule to avoid warning shift-reduce conflict: default action shift
	| IF_TOK LPAREN_TOK expr RPAREN_TOK stmt ELSE_TOK stmt
	;						

expr:
	const		
	| ID_TOK	{ 	int t = lookup($1, scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno);
				else $$.type = lookup($1, scope); 
			}
	| unary
	| const op expr {	if($1.type == $3.type) $$.type = $1.type; 		//only type checking done
				else printf("ERROR: Type (%d %d) mismatch at line %d\n", $1.type, $3.type, yylineno); }

	| ID_TOK op expr { 	int t = lookup($1, scope); 		//only type checking done
				if(t == -1) printf("ERROR: '%s' not declared before use at %d\n", $1, yylineno);
				else if(t == $3.type) $$.type = t; 
				else printf("ERROR: Type (%s:%d %d) mismatch at line %d\n", $1, t, $3.type, yylineno); }

	| ID_TOK assignop expr { 	int t = lookup($1, scope); 		//only type checking done
					if(t == -1) printf("ERROR: '%s' not declared before use at line %d\n", $1, yylineno);
					else if(t == $3.type) $$.type = t; 
					else printf("ERROR: Type (%s:%d %d) mismatch at line %d\n", $1, t, $3.type, yylineno); }
	
	| LPAREN_TOK expr RPAREN_TOK	{ $$ = $2; }
	| func_call	{ $$.type = $1.type; }
	;

op: 
	relationalop
	| eqop
	| logicalop
	| binop
	;

cases:	multcase | multcase defcase;

multcase: case multcase | ;

case:	CASE_TOK FLOAT_CONST COL_TOK caseblk
	| CASE_TOK CHAR_CONST COL_TOK caseblk 
	| CASE_TOK NUM_TOK COL_TOK caseblk
	;

caseblk: stmt | ;

defcase:
	DEFAULT_TOK COL_TOK caseblk;

unary:
	ID_TOK INC_TOK	{ int t = lookup($1, scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", $1); else $$.type = t; }  
	| ID_TOK DEC_TOK { int t = lookup($1, scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", $1); else $$.type = t; }
	| INC_TOK ID_TOK { int t = lookup($2, scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", $2); else $$.type = t; }
	| DEC_TOK ID_TOK { int t = lookup($2, scope); if(t == -1) printf("ERROR: Variable '%s' not declared\n", $2); else $$.type = t; }
	| MINUS_TOK expr %prec UMINUS {$$.type = $2.type; }	//only type checking done
	;

assignop:
	EQ_TOK | MINEQ_TOK | ADDEQ_TOK | MODEQ_TOK | MULTEQ_TOK | DIVEQ_TOK | BITANDEQ_TOK | BITOREQ_TOK | BITXOREQ_TOK;
						
binop:	ADDITION_TOK | MINUS_TOK | MULTI_TOK | DIVISION_TOK | MOD_TOK | LSHIFT_TOK | RSHIFT_TOK | BITAND_TOK | BITOR_TOK | XOR_TOK;		

relationalop:	GT_TOK | LS_TOK | GTEQ_TOK | LSEQ_TOK;

logicalop: NOT_TOK | AND_TOK | OR_TOK; 

eqop: EQ2_TOK | NOTEQ_TOK;

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

int main(int argc, char *argv[]) {
	int i;
	
	char errorMessage[256];
	
	yyin = fopen(argv[1], "r");

	if(!yyparse())
		printf("SUCCESS.. NO SYNTAX ERROR :)\n");
	//getchar();
	fclose(yyin);
	/*printGrammar(g);
	fprintf(grammarOutFile, "\n");
        generateString(g);
	*/
	show_symtable();
	return 0;
}

