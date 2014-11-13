#include <iostream>

class B;
class A
{
public:
	A(): m(10){};
	int M() {return m;};
	friend class B;
private:
	int m;
};

class B
{
public:
	int SetAsPrivateMember(A &a)
	{
		a.m = 10;
		return 0;
	};
};

int main()
{
	A a;
	B b;
	b.SetAsPrivateMember(a);
	std::cout << a.M() << std::endl;
	return 0;
}


	
