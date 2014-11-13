#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << "v : ";
	for(std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;

	
	std::vector<int> v2(v.begin(), v.begin() + 4);
	std:: cout << "v2 : ";
	for(std::vector<int>::iterator iter = v2.begin(); iter != v2.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
	return 0;
}
