# TARGET CODE GENERATION

## Running the program
- Run make.sh
- Then run the executable 'target' using
	./target <input-file> <output-file>

## PARTS
- target.l for lex specification
- target.y for yacc specification
- helper.c, helper.h for implementing address and register descriptors
- symb.h, symb.c for implementing symbol table
- \test folder contains test sample c codes 
