#include <iostream>
#include "stdio.h"
#include <string.h>
struct A
{
	struct
	{
		unsigned int x:1;
		unsigned int y:2;
		unsigned int z:25;
	}xyzFlag;

	unsigned int a:5;	
};

struct C
{
	unsigned int x;
};

//#pragma pack(1)
struct B
{
	char 		 a;
	long long   	 c;
	int   		 b;
	
};
//#pragma pack()
void foo(){};

int main()
{
	/*
	A a;
	a.x = 0;
	a.y = 2;
	a.z = 0x154AB54A;
	int *b;
	memcpy(b, &a, sizeof(int));
	char c = '0';
	printf("char size: %d\n", int(sizeof(a)));
	printf("%d,  %d,  %d", a.x, a.y, a.z);
	printf("%d\n", static_cast<int>(sizeof(a)));
	printf("%X\n", *b);
	*/
	//B b;
	//unsigned bb;
	//int **c[3][4];
	//printf("**c[3][4]'s size: %d\n", sizeof(c));
	//printf("unsigned default size: %d\n", sizeof(bb));
	//int *baAdd = (int*)&b.a;
	//int *bbAdd = (int*)&b.b;
	//int *bcAdd = (int*)&b.c;
	//int *bdAdd = (int*)&b.d;
	//printf("void func size: %d", int(sizeof(foo)));
	A a;
	a.xyzFlag.z = 5;
	
	std::cout<< a.xyzFlag.z << std::endl;
	printf("char size: %d\n", int(sizeof(char)));
	printf("int size: %d\n", int(sizeof(int)));
	printf("Struct B size: %d\n", int(sizeof(B)));
	printf("Struct A size: %d\n", int(sizeof(A)));
	//printf("B's instance size: %d\n", int(sizeof(b)));
	printf("double's size: %d\n", int(sizeof(double)));
	//printf("B.a add: %#x\n",baAdd);
	//printf("B.b add: %#x\n",bbAdd);
	//printf("B.c add: %#x\n",bcAdd);
	//printf("B.d add: %#x\n,",&b.d);
	//std::cout<<"B.b's address:"<<&b.b<<std::endl;
	return 0;

}
