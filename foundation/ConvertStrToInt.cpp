#include <iostream>
#include <string.h>
#include <math.h>

enum ConvertRC
{
    CONVERT_OK                      = 0,
    ERROR_NULL_INPUT                = 1,
    ERROR_CONVERT_TO_C_STR          = 2,
    ERROR_EMPTY_STRING              = 3,
    ERROR_INPUT_VALUE_OVERFLOW      = 4,
    ERROR_INPUT_VALUE_INVALID       = 5,
};



ConvertRC StringToInt(const std::string inputS, int &intRet)
{
    ConvertRC rc = CONVERT_OK;
    const char* charS = inputS.c_str();
    int length = 0;
    if(!charS)
    {
        std::cout << "ERROR, CONVERT TO C STRING " << std::endl;
        rc = ERROR_CONVERT_TO_C_STR;
        goto Exit;
    }
    length = strlen(charS);
    if(length == 0)
    {
        std::cout << "ERROR, THE INPUT STRING IS EMPTY!" << std::endl;
        rc = ERROR_EMPTY_STRING;
        goto Exit;
    }
    if(length > 8)
    {
        std::cout << "ERROR, INPUT VALUE OVERFLOW!" << std::endl;
        rc = ERROR_INPUT_VALUE_OVERFLOW;
        goto Exit;
    }


    for(int i = length - 1; i >=0; i--)
    {
        if(charS[i] >= '0' && charS[i] <= '9')
        {
            intRet += (charS[i] - '0') * pow(16, i);
        }
        else if(charS[i] >= 'A' && charS[i] <= 'F')
        {
            intRet += (charS[i] - 'A' + 10) * pow(16, i);
        }
        else
        {
            std::cout << "ERROR, INPUT VALUE IS INVALID!!" << std::endl;
            rc = ERROR_INPUT_VALUE_INVALID;
            goto Exit;
        }
    }

    Exit:
        return rc;
}




int main(int argc, char *argv[])
{

    std::string s = "FFFFGFF";

    int intRet = 0;
    ConvertRC rc = StringToInt(s, intRet);
    if(rc != CONVERT_OK)
    {
        std::cout << "CONVERT STRING TO INT FAILED!!" << std::endl;
        return 1;
    }
    std::cout << std::hex << "Convert Ret = " << intRet << std::endl;
    return 0;
}
