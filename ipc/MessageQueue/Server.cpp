#include "ControlService.h"

int main()
{
	extern int errno;
	char *receiveBuf;
	ssize_t receiveByteCount = 0;
	timespec receiveTimeOut;
	clock_gettime(CLOCK_REALTIME, &receiveTimeOut);
	mq_attr receiveMqAttr = 
			{
				.mq_flags	= O_CREAT|O_RDONLY,
				.mq_maxmsg	= ControlService::DEFAULT_MQ_MAX_MSG,
				.mq_msgsize	= ControlService::DFFAULT_MQ_MSG_SIZE,
			};
	
	receiveTimeOut.tv_sec += 2;
	mqd_t mqfd = mq_open(ControlService::MQ_NAME.c_str(), O_RDONLY | O_CREAT);
	if(mqfd == -1)
	{
		perror("Open MQ Failed!!");
		std::cout << "Error Number: [" << errno << "]" << std::endl;
		exit(-1);
	}
	std::cout << "Mq Attr MSG Size: [" << receiveMqAttr.mq_msgsize << "]" << std::endl;
	std::cout << "Mq Attr MAX MSG: [" << receiveMqAttr.mq_maxmsg << "]" << std::endl;
	receiveBuf = new char[receiveMqAttr.mq_msgsize];
	int i = 0;
	while(i < 10)
	{
		std::cout << "Waiting for MQ..." << std::endl;
		if(-1 == mq_getattr(mqfd, &receiveMqAttr))
		{
			perror("Get Attr Error:");
			std::cout << "Get Attr Error No: [" << errno << "]" << std::endl;
			exit(-1);
		}
		std::cout << "Mq Attr CUR MSG No: [" << receiveMqAttr.mq_curmsgs << "]" << std::endl;
		if(-1 != mq_timedreceive(mqfd, receiveBuf, receiveMqAttr.mq_msgsize, NULL, &receiveTimeOut))
		{
			std::cout << "Buf Length: [" << strlen(receiveBuf) << "]" <<std::endl;
			std::cout <<"Received: [" << receiveBuf << "]" << std::endl;
		}
		else
		{
			std::cout << "Timed Out!!" << std::endl;
			perror("Receive Message Fail!!");
			std::cout << "ERROR Number: [" << errno << "]" << std::endl;
		}
		sleep(10);
		i++;
	}
	mq_close(mqfd);
	return 0;
}
