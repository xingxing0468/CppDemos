#include "ControlService.h"

using namespace ControlService;
int main(int argc, char *argv[])
{
	IpcTracer::TraceLevel = IpcTracer::TRACE_LEVEL_INFO;
	int rc = IPC_RC_OK;
	extern int errno;
	ControlService::IpcTracer::AppName = ControlService::APP_NAME[ControlService::APP_NAME_SERVER];
	ControlService::IpcTracer::ProcessName = argv[0];
	int serverSockFd = 0, clientSockFd = 0;
	sockaddr_un serverSockAddr, clientSockAddr;
	const char* socketAddrStr = ControlService::SOCKET_ADDR.c_str();
	int on = 1, clientSockAddrSize, serverSockAddrSize = sizeof(sockaddr_un);
	FILE *fp = NULL;
	char receiveBuf[DEFAULT_MAX_SOCKET_MSG_LENGTH] = "Origin Buffer";
	memset(&serverSockAddr, sizeof(sockaddr_un), 0);
	serverSockAddr.sun_family = AF_LOCAL;
	memcpy(&serverSockAddr.sun_path, socketAddrStr, strlen(socketAddrStr) + 1);
	if((serverSockFd = socket(AF_LOCAL, SOCK_DGRAM, 0)) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_CREATE, errno);
		rc = 1000 * IpcTracer::ACTION_CREATE + errno;
		goto Exit; 
	}
	if(unlink(ControlService::SOCKET_ADDR.c_str()) < 0)
	{
		IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_UNLINK, IpcTracer::SERVERITY_INFO, "Unlink failed, maybe the sockect fp not existed.");
	}
	if((setsockopt(serverSockFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0)
	{
		IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_SET_OPTION, errno);
		rc = 1000 * IpcTracer::ACTION_SET_OPTION + errno;
		goto Exit;
	}
	if(bind(serverSockFd, (sockaddr*)(&serverSockAddr), (sizeof(serverSockAddr))) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_BIND, errno);
		rc = 1000 * IpcTracer::ACTION_BIND + errno;
		goto Exit;
	}
	
	while(1)
	{
		ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Waiting For Message From Client Side....");		
		if(recvfrom(serverSockFd, receiveBuf, sizeof(receiveBuf), 0, (sockaddr*)(&serverSockAddr), (socklen_t*)&serverSockAddrSize) < 0)
		{
			ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_RECEIVE_FROM, errno);
			rc = 1000 * IpcTracer::ACTION_RECEIVE_FROM + errno;
			goto Exit;
		}
		std::string receiveStr(receiveBuf);
		ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Received Message: [" +  receiveStr + "]");
		ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Sleeping 5 seconds...");
		sleep(5);
	}
Exit:
	if(close(serverSockFd) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_CLOSE, errno);
	}
	if(remove(ControlService::SOCKET_ADDR.c_str()) < 0)
	{
		ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "SOCKET_ADDR's Name:" + SOCKET_ADDR);
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_REMOVE, errno);
	}
	return rc;
}
