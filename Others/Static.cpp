#include <iostream>

class A
{
public:
	static const int a = 1000;
	static int f()
	{
		b = 200;
		return a + b + 100;
	}
	static int b;
};

int main()
{
	A a;
	std::cout<<A::a<<std::endl;
	std::cout<<A::f()<<std::endl;
}
