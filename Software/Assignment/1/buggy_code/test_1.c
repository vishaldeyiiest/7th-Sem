#include <stdio.h>
void f1();
void f2();
int a = 0;
void f1()
{
	f2();
}

void f2()
{
	a++;
	f1();
}

int main()
{
	f1();
	
}
