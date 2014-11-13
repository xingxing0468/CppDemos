#include <iostream>
#include "stdlib.h"
#include "x86_64-linux-gnu/sys/stat.h"
#include <unistd.h>
#include <stdio.h>


#include <linux/stat.h>


int main()
{
	FILE *fp;
	int readbuf[100];
	
	mknod("MYFIFO", S_IFIFO|0666, 0);

	while(1)
	{
		std::cout << "Blocking for Client Writing....." << std::endl;
		fp = fopen("MYFIFO", "r");
		std::cout << "fopen ended" << std::endl;
		fread(readbuf, 4, 20, fp);
		std::cout << "Received: ";
		for(int i = 0; i< 20; i++)
		{
			std::cout << readbuf[i] << " ";
		}
		std::cout << std::endl;
		fclose(fp);
	}
	

	return 0;

}
