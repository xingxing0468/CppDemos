#ifndef _CONTROL_SERVICE_H
#define _CONTROL_SERVICE_H

#include <unistd.h>
#include <iostream>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "time.h"
#include "stdlib.h"
#include "errno.h"
namespace ControlService
{
	enum MODE
	{
		PMODE 		= 0666,
		DEFAULT_MODE	= S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP,
	};
	

	enum MQ_ATTR_MODE
	{
		DEFAULT_MQ_ATTR_MODE 		= 0,
	};
	
	enum PHYSICAL
	{	
		DEFAULT_MQ_MAX_MSG 		= 20,
		DFFAULT_MQ_MSG_SIZE		= 1024,
		DEFAULT_MQ_MSG_FLAGS		= 0, 
		DEFAULT_SECOND_TIMEOUT		= 5,
	};
	const static std::string MQ_NAME		 = "/MyMessageQueue";
							
							  
}
#endif
