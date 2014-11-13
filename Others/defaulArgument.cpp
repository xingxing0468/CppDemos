#include "stdio.h"

int foo();

int foo(int x, int y)
{
	return 100;
}

int main()
{
	int i = 0, j = 0;
	printf("i++ = %d\n", i++);
	printf("++j = %d\n", ++j);
	return 0;
}
