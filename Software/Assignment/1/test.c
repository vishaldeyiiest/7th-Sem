#include <stdio.h>

int main()
{
	int a[10] = {10};
	a[1] = a[1] * 10;
	printf("%d\n", a[1]);
}