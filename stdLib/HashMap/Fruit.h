#ifndef FRUIT_H
#define FRUIT_H
#include <hash_map>
#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;
using namespace __gnu_cxx;

namespace FruitNameSpace
{
    enum FRUIT_RC
    {
        FRUIT_OK                                   = 0,
        FRUIT_ERROR_DATE_INVALID                   = 1,
        FRUIT_ERROR_DATE_NOT_EXIST                 = 2,
    };
    struct TradeDateFormat
    {
        int     Month;
        int 	Day;
        bool operator ==(const TradeDateFormat &input)
        {
          if(Month == input.Month && Day == input.Day)
          {
              return true;
          }
          return false;
        }
    };

    class Fruit
    {
    public:
        Fruit(string name): m_name(name){}
        FRUIT_RC SetPrice(int month, int day, double price)
        {
            FRUIT_RC rc = FRUIT_OK;
            stringstream ssMonth; stringstream ssDay;
            string strMonth, strDay;
            if(month < 1 || month > 12 || day < 1 || day > 30)
            {
                std::cout <<"INVALID DATE!" << std::endl;
                rc = FRUIT_ERROR_DATE_INVALID;
                goto Exit;
            }

            ssMonth << month;       ssDay << day;
            ssMonth >> strMonth;    ssDay >> strDay;
            try
            {
                //m_price[strMonth + "-" + strDay] = price;
            }
            catch(exception e)
            {

            }
        Exit:
        return rc;
        }
        FRUIT_RC GetPrice(int month, int day, double &price)
        {
            hash_map<string, double>::iterator iter;
            FRUIT_RC rc = FRUIT_OK;
            stringstream ssMonth; stringstream ssDay;
            string strMonth, strDay;
            string indexStr;
            if(month < 1 || month > 12 || day < 1 || day > 30)
            {
                std::cout <<"INVALID DATE!!" << std::endl;
                rc = FRUIT_ERROR_DATE_NOT_EXIST;
                goto Exit;
            }
            ssMonth << month;           ssDay << day;
            ssMonth >> strMonth;        ssDay >> strDay;
            indexStr = strMonth + "-" + strDay;

            if(m_price.find(indexStr) == m_price.end())
            {
                std::cout << "NO EXPECTED DATA EXISTED" << std::endl;
                rc = FRUIT_ERROR_DATE_NOT_EXIST;
                goto Exit;
            }
            //price = m_price[indexStr];

        Exit:
            return rc;
        }
        void PrintAllPrice()
        {
            std::cout << "ENTRY PRICE:" << std::endl;
            //for(hash_map<string, double>::iterator iter = m_price.begin(); iter != m_price.end(); iter++)
            //{
                //std::cout << "\t" << iter->first << ":\t" << iter->second << std::endl;
            //}
            return;

        }
    protected:
        string                                  m_name;
        hash_map<string, double>                m_price;

    };
}




#endif // FRUIT_H
