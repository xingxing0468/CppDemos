#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "unistd.h"
#include "x86_64-linux-gnu/sys/stat.h"
int main()
{
	FILE *fp;
	int i = 0;	
	std::cout << "Opening FIFO..." << std::endl;
	if((fp = fopen("MYFIFO", "w")) == NULL)
	{
		perror("failed open pipe!");
		exit(1);
	}
	std::cout << "Open FIFO Completed!!" << std::endl;
	int sendBuf[1];
	while(i < 20)
	{
		sendBuf[0] =  i ;
		fwrite(sendBuf,4, 1, fp);
		std::cout << "Putting i = " << i << std::endl;
		i ++; 
	}

	std::cout << "Completed sending msg to server" << std::endl;
	fclose(fp);
	return(0);

}
