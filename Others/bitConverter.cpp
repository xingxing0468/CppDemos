#include "stdio.h"
#include <iostream>
#include "string.h"

unsigned int getBitValue(unsigned char input[],int inputLength, int bitOffset, int length)
{
	unsigned int ret = 0;
	int validStartByte = bitOffset / 8;
	int validEndByte = (bitOffset + length - 1) / 8;
	int validByteCount = validEndByte - validStartByte + 1;
	if(validByteCount > 8) { return ret; }
	memcpy(&ret, input, validByteCount);
	printf("%x\n",ret);
	ret = ( ret << bitOffset % 8 );
	printf("%x\n",ret);
	ret = ( ret >> validByteCount * 8 - length);
	return ret;
};
int main()
{
	unsigned char input[5] = {0x1F, 0x2E, 0x3D, 0x4C, 0x5B};
	unsigned int ret = getBitValue(input, 5, 5, 16);
	printf("%x\n", ret);
	return 0;

}
