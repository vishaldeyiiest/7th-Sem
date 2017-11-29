

typedef struct Quad
{
	char op[5];
	char op1[20];
	char op2[20];
	char res[20];
}Quadruple;

Quadruple quad[256];

//void push(char *str);
//char* pop();

void addQuad(char [], char [], char [], char []);
void displayQuad();


char* newtemp();
char* newLabel();
char *formatCode(char*);


