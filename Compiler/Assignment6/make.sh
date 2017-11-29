yacc -d yaccsymb.y
lex test.l
gcc -o csymb_check lex.yy.c y.tab.c symb.c
