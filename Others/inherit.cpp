#include <stdlib.h>
#include <iostream>

class base
{
public:
	base()
	{
		std::cout << "base's constructor" << std::endl;
	};
	virtual void f() = 0;
 	virtual ~base()
	{
		std::cout << "base deconstructor" << std::endl;
	}
};

class derived: public base
{
public:
	derived()
	{
		std::cout << "derived's constructor" << std::endl;
	};

	void f()
	{
		std::cout << "inherit func" << std::endl;
	};
	~derived()
	{
		std::cout << "inherit deconstructor" <<std::endl;
	}
};

int main()
{
/*	std::cout << "derived instance: ";
	derived de;
	std::cout << std::endl;
	base *bs = &de;
	
	std::cout << "base instance: ";
	base pa;
	std::cout << std::endl;
	derived *pb = dynamic_cast<derived*>(&pa);
	if(pb == NULL) { std::cout << "Base instance to derived pointer dynamic cast failed!!" << std::endl;}
	else
	{
		
	 std::cout << "Base instance to derived pointer dynamic cast pass!!" << std::endl;
		bs->f();
	}
	derived *pc = static_cast<derived*>(&pa);
	std::cout << "Base instance static cast to derived pointer, then call the virtual func f:";
	pc->f();
	std::cout << std::endl;
*/
	//derived d;
	base *b = new derived();
	std::cout << "base pointer point to derived instance's address: ";
	b->f();
	delete b;
	return 0;
}
