yacc -d target.y
lex target.l
gcc -g -o target lex.yy.c y.tab.c symb.c helper.c
