#include "ControlService.h"

int main()
{
	std::string sendStr = "Message Queue Content Demo";
	timespec sendTimeOut;
	clock_gettime(CLOCK_REALTIME, &sendTimeOut);
	sendTimeOut.tv_sec += 2;
	extern int errno;
	struct mq_attr sendMqAttr = 
				{
					.mq_flags	= 0,
					.mq_maxmsg	= 5,
					.mq_msgsize	= 20,
				};
	mqd_t mqfd = mq_open(ControlService::MQ_NAME.c_str(), O_WRONLY|O_CREAT, ControlService::PMODE, &sendMqAttr);
	std::cout << "MQ Attr MSG SIZE: [" << sendMqAttr.mq_msgsize << "]" << std::endl;
	std::cout << "MQ Attr MAX MSG: ["  << sendMqAttr.mq_maxmsg << "]" <<std::endl;
	if(mqfd == -1)
	{
		perror("Open MQ Failed!!");
		std::cout << "Error Number:[" << errno << "]" << std::endl;
		exit(-1);
	}
	int i = 0;
	while(i < 20)
	{
		sendStr += "A";
		if(0 != mq_timedsend(mqfd, sendStr.c_str(), strlen(sendStr.c_str()) + 1, 0, &sendTimeOut))
		{
			std::cout << "Sending Message Queue Failed!!" << std::endl;
		}
		else
		{
			std::cout << "Sending Mesaage Queue: [" << sendStr.c_str() << "] Completed" << std::endl;
		}
		i++;
	}
	mq_close(mqfd);
	return 0;
	

}
