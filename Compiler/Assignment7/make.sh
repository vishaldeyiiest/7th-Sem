yacc -d intmed_code.y
lex intmed.l
gcc -g -o intmed lex.yy.c y.tab.c symb.c helper.c
