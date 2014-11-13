#include <hash_map>
#include <iostream>
#include <string>
#include <list>

using namespace std;
using namespace __gnu_cxx;

namespace Fruit
{
enum FRUIT_RC
{
	FRUIT_OK			= 0,
	FRUIT_SET_PRICE_DATE_INVALID	= 1,
	
};

struct TradeDateFormat
{
	int	Month;
	int 	Day;
};

class Fruit
{
public:
	Fruit(string name): m_name(name){};
	FRUIT_RC SetPrice(int month, int day, double price)
	{
		FRUIT_RC rc = FRUIT_OK;
		if(month < 1 || month > 12 || day < 1 || day > 30)
		{
			std::cout <<"...." << std::endl;
			rc = FRUIT_SET_PRICE_DATE_INVALID;
			goto Exit;
		}
		TradeDateFormat date;
		date.month = month;
		date.day   = day;
		try
		{
			m_price[date] = price;
		}
		catch
		{

		}
	Exit:
		return rc;
	};

protected:
	string 						m_name;
	hash_map<TradeDateFormat, double>		m_price;

private:
	

};
}


int main()
{
	return 0;
}

