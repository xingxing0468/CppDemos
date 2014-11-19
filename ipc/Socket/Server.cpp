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
	serverSockAddr.sun_family = AF_LOCAL;
	const char* socketAddrStr = ControlService::SOCKET_ADDR.c_str();
	int on = 1, clientSockAddrSize;
	FILE *fp = NULL;
	char receiveBuf[DEFAULT_MAX_SOCKET_MSG_LENGTH];
	std::string receiveStr;
	memcpy(&serverSockAddr.sun_path, socketAddrStr, strlen(socketAddrStr) + 1);
	if((serverSockFd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
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

	if(listen(serverSockFd, DEFAULT_MAX_SOCKET_CLIENT_NUM) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_LISTEN, errno);
		rc = 1000 * IpcTracer::ACTION_LISTEN + errno;
		goto Exit;
	}
	ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Blocking for accept connect from client....");
	if((clientSockFd = accept(serverSockFd, (sockaddr*)(&clientSockAddr), (socklen_t*)&clientSockAddrSize)) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_ACCEPT, errno);
		rc = 1000 * IpcTracer::ACTION_ACCEPT + errno;
		goto Exit;
	}
	ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Client Connetion Accepted....");	

	
	for(int i = 0; i < 20; i++)
	{
		ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Sleeping..."); 
		sleep(1);
	}

	if(!(fp = fdopen(serverSockFd, "wr")))
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_OPEN_FD, errno);
		rc = 1000 * IpcTracer::ACTION_OPEN_FD + errno;
		goto Exit;
	}
	
	if(fread(receiveBuf, DEFAULT_MAX_SOCKET_MSG_LENGTH, sizeof(char), fp) < 0)
	{
		ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET, IpcTracer::ACTION_READ_FP, errno);
		rc = 1000 * IpcTracer::ACTION_READ_FP + errno;
		goto Exit;
	}
	
	receiveStr = receiveBuf;
	ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Received Message: [" +  receiveStr + "]");
	
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
