
typedef struct Quad
{
	char op[5];
	char op1[20];
	char op2[20];
	char res[20];
}Quadruple;

Quadruple quad[256];

typedef struct addr_desc
{
	char *name;
	char reg[3];
	char location[6];
}address_desc;
address_desc adr_desc[256];

enum regs {R0, R1, R2, R3, R4, R5, R6, R7} regs;
typedef struct reg_desc
{
	int flag;
	char *contents;
}register_desc; 
//void push(char *str);
//char* pop();

register_desc reg_desc[8];

void addQuad(char [], char [], char [], char []);
void displayQuad();


char* newtemp();
char* newLabel();
char *formatCode(char*);
	
int getreg(char*);
void setreg();
int lookup_reg(int, char*);
void update_reg(int, char*);
void add_address(char*, int, int);
void update_address(int, int, int);
char *search(char*);

void show_regs();
void show_address();

int size(char *);
