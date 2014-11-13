#include <iostream>

int main()
{
	int i, a;
	for(i = 0,a = 0; i < 1 && (10 != i++); i++)
	//for(i = 0; i < 1; i++)
	{
	}
	std::cout << i << std::endl;
	return 0;
}
