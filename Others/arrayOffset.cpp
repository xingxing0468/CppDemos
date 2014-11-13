#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int *intArray = new int[10];
	int  srcArray[10];
	for(int i = 0; i < 10; i++)
	{
		srcArray[i] = 10 - i;
	}
	memcpy(intArray, srcArray, 10 * sizeof(int));

	std::cout << "Array start address:          " << (int*)(intArray) << std::endl;
	std::cout << "Array + 1 address:            " << (int*)(intArray + 1) << std::endl;
	std::cout << "Array[1] address:             " << (int*)(&intArray[1]) << std::endl;
	std::cout << "<srcArray address:>	    " << srcArray << std::endl;
	std::cout << "<srcArray[10]> srcArray + 1:  " << srcArray + 1 << std::endl; 
	std::cout << "Array + sizeof int address:   " << intArray + sizeof(int) << std::endl;
	std::cout << "size of int	  " << sizeof(int) << std::endl;
	std::cout << "size array   	  " << sizeof(intArray) << std::endl;

	for(int i = 0; i < 10; i++)
	{
		std::cout << intArray[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}
