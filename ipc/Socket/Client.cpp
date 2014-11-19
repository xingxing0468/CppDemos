#include "ControlService.h"

using namespace ControlService;
int main(int argc, char *argv[])
{
	IpcTracer::TraceLevel = IpcTracer::TRACE_LEVEL_INFO;
	int rc = IPC_RC_OK;
	extern int errno;
	ControlService::IpcTracer::AppName = ControlService::APP_NAME[ControlService::APP_NAME_CLIENT];
	ControlService::IpcTracer::ProcessName = argv[0];

	int serverSockFd = 0, clientSockFd = 0;
        sockaddr_un serverSockAddr, clientSockAddr;
        clientSockAddr.sun_family = AF_LOCAL;
        const char* socketAddrStr = ControlService::SOCKET_ADDR.c_str();
        int on = 1, clientSockAddrSize;
        FILE *fp = NULL;
        const char* sendBuf = "This is Hello From Client!";
	std::string sendStr(sendBuf);
	memcpy(&clientSockAddr.sun_path, socketAddrStr, strlen(socketAddrStr) + 1);
        if((clientSockFd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
        {
                ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET,     IpcTracer::ACTION_CREATE, errno);
                rc = 1000 * IpcTracer::ACTION_CREATE + errno;
                goto Exit;
        }	
        if((connect(clientSockFd, (sockaddr*)(&clientSockAddr), sizeof(clientSockAddr))) < 0)
        {
                ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET,     IpcTracer::ACTION_CONNECT, errno);
                rc = 1000 * IpcTracer::ACTION_CONNECT + errno;
                goto Exit;
        }
	if(send(clientSockFd, sendBuf, strlen(sendBuf) + 1, 0) < 0)
        {
                ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET,     IpcTracer::ACTION_SEND, errno);
                rc = 1000 * IpcTracer::ACTION_SEND + errno;
                goto Exit;
        }
	ControlService::IpcTracer::WriteLine(IpcTracer::CATEGORY_SOCKET, IpcTracer::SERVERITY_INFO, "Message: [" + sendStr + "] sent");


		
Exit:
	if((close(clientSockFd)) != 0)
        {
                ControlService::IpcTracer::Error(IpcTracer::CATEGORY_SOCKET,     IpcTracer::ACTION_CLOSE_FD, errno);
                rc = 1000 * IpcTracer::ACTION_CLOSE_FD + errno;
        }
	return rc;

}
