yacc -d -t -v another.y	
# for debug and -v for dumping parse states to y.output
# also can do lex -d for debug
lex test.l
gcc -o cparser lex.yy.c y.tab.c
