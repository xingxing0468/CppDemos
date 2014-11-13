#include <iostream>
#include <stdlib.h>
#include "stdio.h"
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int *ptr1 = (int *)(&a);
	int *ptr0 = ptr1 + 1;
	int *ptr2 = (int *)(&a + 1);
	int *ptr3 = (int *)(&a - 1);
	int *ptr4 = (int *)(&a[4] + 1);
	std::cout << "&a : "<< ptr1 << "\n"
		  << "*(&a):\t" << *ptr1 << "\n"
		  << "&a + 1:\t" << ptr2 << "\n"
		  << "*(&a + 1:\t)" << *ptr2 << "\n"
		  << "&a - 1:\t" << ptr3 << "\n"
		  << "*(&a - :1):\t" << *ptr3 << "\n"
		  << "ptr1 + 1: \t" << ptr0 << "\n"
		  << "&a[4] + 1: \t" << ptr4 << "\n";
		  
	return 0;
}
