#include <iostream>

class baseFunPtr
{

};

int foo_1(int a)
{
	std::cout << "foo_1 " << a  << std::endl;
	return 5;
}

void foo_2(int b)
{
	return;
}

int main()
{
	typedef void (*funcPtr)(int);
	funcPtr f = foo_2;
	(*f)(10);
	//std::cout << b << std::endl;
	return 0;
}
