#include <iostream>

using namespace std;

class A
{
public:
	static class AA
	{
	public:
		int a;
	};
	A() {};
};

int main()
{
	A a;
	Ä::AA b;
	b.a = 0;
	return 0;
}
