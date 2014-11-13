#include "stdio.h"
#include <string.h>
struct A
{
	unsigned int x:1;
	unsigned int y:2;
	unsigned int z:29;
};

struct B
{
	char a;
	int b;
	bool c;
	bool d;
};

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
	B b;
	int *baAdd = (int*)&b.a;
	int *bbAdd = (int*)&b.b;
	int *bcAdd = (int*)&b.c;
	int *bdAdd = (int*)&b.d;
	printf("void func size: %d", int(sizeof(foo)));
	printf("char size: %d\n", int(sizeof(char)));
	printf("int size: %d\n", int(sizeof(int)));
	printf("Struct B size: %d\n", int(sizeof(B)));
	printf("B's instance size: %d\n", int(sizeof(b)));
	printf("double's size: %d\n", int(sizeof(double)));
	printf("B.a add: %#x\n",baAdd);
	printf("B.b add: %#x\n",bbAdd);
	printf("B.c add: %#x\n",bcAdd);
	printf("B.d add: %#x\n,",&b.d);
	//std::cout<<"B.b's address:"<<&b.b<<std::endl;
	return 0;

}
