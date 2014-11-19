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
#include "sys/socket.h"
#include "sys/types.h"
#include "sys/un.h"
#include <vector>
namespace ControlService
{
	enum IPC_RC
	{
		IPC_RC_OK	= 0,
	};
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
		DEFAULT_MAX_SOCKET_CLIENT_NUM	= 5,
	};
	
	enum APP_NAME_INDEX
	{
		APP_NAME_SERVER,
		APP_NAME_CLIENT,
	};
	const static std::string Category[]			= {"Message Queue", 	"SOCKET"		      };
	const static std::string Action[]			= {"NONE",		"Create",		"Bind",
								   "Set Option",	"Listen",		"Accept",
								   "Connect",		"Unlink",		"Close",
								   "Remove",		"Open File Descriptor", "Close File Descriptor",
								   "Write File Descriptor",};
	const static std::string APP_NAME[]			= {"Server",	"Client"};
	const static std::string MQ_NAME		 	= "/MyMessageQueue";
	const static std::string SOCKET_ADDR		 	= "MySocketAddr";
	class IpcTracer
	{
	public:
		enum TRACE_LEVEL
		{
			TRACE_LEVEL_ERROR	= 0,
			TRACE_LEVEL_INFO	= 1,
		};
	
		enum CATEGORY
		{
			CATEGORY_MESSAGE_QUEUE,
			CATEGORY_SOCKET,
		};

		enum ACTION
		{
			ACTION_NONE,
			ACTION_CREATE,
			ACTION_BIND,
			ACTION_SET_OPTION,
			ACTION_LISTEN,
			ACTION_ACCEPT,
			ACTION_CONNECT,
			ACTION_UNLINK,
			ACTION_CLOSE,
			ACTION_REMOVE,
			ACTION_OPEN_FD,
			ACTION_CLOSE_FD,
			ACTION_WRITE_FD,
		};

		enum SERVERITY
		{
			SERVERITY_INFO		= 0,
			SERVERITY_ERROR		= 1,
		};
	
		static TRACE_LEVEL TraceLevel;
		static std::string AppName;
		static std::string ProcessName;
		
		static void WriteLine(CATEGORY eCategory, ACTION eAction, SERVERITY eServerity, std::string message)
		{
			if(eServerity | TraceLevel)
			{
				std::cout << "[PID:"		<<	getpid()		<< "]" 
					  << "[PName:"		<<	ProcessName		<< "]"
					  << "[App:"		<<	AppName			<< "]"
					  << "["		<<	Category[eCategory]	<< "]"
					  << "["		<<	Action[eAction]		<< "]"
					  << ": "		<<	message			<< std::endl;
			}
			return;
		};
		static void WriteLine(CATEGORY eCategory, SERVERITY eServerity, std::string message)
		{
			return WriteLine(eCategory, ACTION_NONE, eServerity, message);
		};
		static void Error(CATEGORY eCategory, ACTION eAction, int errorCode)
		{
			char errorCodeCharArray[10];
			std::string errorCodeStr = "";
			sprintf(errorCodeCharArray, "%d", errorCode);
			errorCodeStr.assign(errorCodeCharArray);
			std::string msgStr = "errno [" + errorCodeStr + "]";
			return WriteLine(eCategory, eAction, SERVERITY_ERROR, msgStr);
		};
	};
	IpcTracer::TRACE_LEVEL IpcTracer::TraceLevel	= IpcTracer::TRACE_LEVEL_INFO;
	std::string		IpcTracer::AppName	= APP_NAME[APP_NAME_SERVER];
	std::string 		IpcTracer::ProcessName;
}
#endif
