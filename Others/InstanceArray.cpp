#include <iostream>

class A
{
public:

	explicit A(){ std::cout << "constructor" << std::endl;};
	
		
};

int main()
{
	A a[10];
	return 0;
}
