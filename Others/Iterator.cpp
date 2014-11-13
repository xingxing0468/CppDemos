#include <iostream>
#include <vector>

using namespace std;
int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout<<*iter<<std::endl;
	}
	return 0;
}
