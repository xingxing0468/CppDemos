#include "stdlib.h"
#include <iostream>
#include "stdio.h"

class base
{
public:
	base(){};
	int		baseMember;
	virtual void foo()
	{
		std::cout << "base function!" << std::endl;
	}
};

class inherite: public base
{
public:
	int		inheriteMember;
	void foo()
	{
		std::cout << "inherite function!!" << std::endl;
	}
};

int main()
{
	base *a = new base();
	inherite  *b = (inherite*)a;


	base *c = new base();
	inherite *d = dynamic_cast<inherite*>(c);
	if(d == NULL)
	{
		std::cout << "Base to inherit dynamic cast failed!!" << std::endl;
	}

	inherite *f = new inherite();
	c = dynamic_cast<base*>(f);
	if(c == NULL)
	{
		std::cout << "Inherit to base dynamic cast failed!!" << std::endl;
	}
	else
	{
		std::cout << "Inherit to base dynamic cast pass!!" << std::endl;
	}
	return 0;

}
