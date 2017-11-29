%{
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(const char *);
extern FILE *yyin;
extern int yylineno;
extern char* yytext;

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

%%
start:
	start declare
	|
	; 					

declare: 	
	func_def | list ;
/*						
var_decl: 			
	type ID_TOK
	| type ID_TOK EQ_TOK expr
	;
*/
const:	NUM_TOK | FLOAT_CONST | CHAR_CONST;

vd:	ID_TOK
	| ID_TOK EQ_TOK expr	 
	;

list:   type var_list;	
	
var_list: vd 
	| var_list COMMA_TOK vd
	;	
	
func_def: type ID_TOK LPAREN_TOK list_parameters RPAREN_TOK cmp_stmt;
	
func_call: ID_TOK LPAREN_TOK list_arguments RPAREN_TOK;

list_arguments: list_arg | ;
list_arg:
	ID_TOK 
	| list_arg COMMA_TOK ID_TOK
	;
	
list_parameters: list_param | ;
list_param:
	type ID_TOK 
	| type ID_TOK COMMA_TOK list_param	
	;

type:
	INT_TOK | VOID_TOK | FLOAT_TOK | CHAR_TOK;

cmp_stmt:
	LCURLY_TOK stmt_list RCURLY_TOK;

stmt_list:
	stmt_list stmt	
	|
	;

stmt:		
	list SEMCOL_TOK
	| SEMCOL_TOK
 	| cmp_stmt
	| cond
	| loop
	| expr SEMCOL_TOK
	| SWITCH_TOK LPAREN_TOK expr RPAREN_TOK LCURLY_TOK cases RCURLY_TOK
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
	| ID_TOK
	| unary
	| const op expr
	| ID_TOK op expr
	| ID_TOK assignop expr	
	| LPAREN_TOK expr RPAREN_TOK	
	| func_call
	;

op: 
	relationalop
	| eqop
	| logicalop
	| binop
	;

cases:	multcase | multcase defcase;

multcase: multcase case | ;

case:	CASE_TOK FLOAT_CONST COL_TOK caseblk
	| CASE_TOK CHAR_CONST COL_TOK caseblk 
	| CASE_TOK NUM_TOK COL_TOK caseblk
	;

caseblk: stmt | ;

defcase:
	DEFAULT_TOK COL_TOK caseblk;

unary:
	ID_TOK INC_TOK
	| ID_TOK DEC_TOK
	| INC_TOK ID_TOK
	| DEC_TOK ID_TOK
	| MINUS_TOK expr %prec UMINUS
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
	return 0;
}
