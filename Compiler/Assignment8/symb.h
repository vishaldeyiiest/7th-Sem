#define SIZE 256
#define SHIFT 2

typedef enum type{VOID, INTEGER, FLOAT} vtype;
typedef union value
{
	int ival;
	float fval;
}tvalue; 

typedef struct Number
{
	tvalue value;
	vtype type;
}Number;																										

typedef struct symrec
{
	vtype type;
	//int f_or_symb;
	char *name;
	tvalue value;
	int scope;
	struct symrec *next;
	//function *fptr;
}symrec;

symrec* symtable[SIZE];

//hash function
int hash(char *);
//insert symbol
void put_symb(char *name, int type, int scope);

void put_func(char *name, int type, int scope, int nump, vtype types[]);

//int setval(char *name, tvalue t, int scope);
//tvalue lookup_val(char *name, int scope);
int lookup_scope(char *name, int scope);
int lookup_type(char *name, int scope);
int lookup(char *name, int scope);
int setType(char *name, int t, int scope);
void show_symtable();

void exitscope(int scope);

typedef struct expr
{
	char *code;
	char *place;
	int size;
	vtype type;
}expression;

typedef struct stmt
{
	char *code;
	int size;
}statement;
