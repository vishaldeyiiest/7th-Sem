/*single character tokens*/
#define LPAREN_TOK '(' 
#define RPAREN_TOK ')'
#define GT_TOK '>'
#define LS_TOK '<'
#define EQ_TOK '='
#define MINUS_TOK '-'
#define ADDITION_TOK '+'
#define MULTI_TOK '*'
#define DIVISION_TOK '/'
#define MOD_TOK '%'
#define LCURLY_TOK '{'
#define RCURLY_TOK '}'
#define BITOR_TOK '|'
#define BITAND_TOK '&'
#define XOR_TOK '^'
#define NOT_TOK '!'
#define COMMA_TOK ','
#define SEMCOL_TOK ';'

/*Assignment*/
#define MINEQ_TOK 300
#define ADDEQ_TOK 301
#define MODEQ_TOK 302
#define MULTEQ_TOK 303
#define DIVEQ_TOK 304
#define BITANDEQ_TOK 305
#define BITOREQ_TOK 306
#define BITXOREQ_TOK 307

/*reserved words*/
#define FOR_TOK 256
#define SWITCH_TOK 257
#define CASE_TOK 258
#define IF_TOK 259
#define ELSE_TOK 260
#define VOID_TOK 261
#define WHILE_TOK 262

/*identifiers, int constants*/
#define ID_TOK 350
#define INTCONST 351

#define GTEQ_TOK 400
#define LSEQ_TOK 401
#define AND_TOK 402
#define OR_TOK 403
#define EQ2_TOK 404
#define NOTEQ_TOK 405
#define LSHIFT_TOK 406
#define RSHIFT_TOK 407

#define INC_TOK 450
#define DEC_TOK 451