#include "ipcmsghandler.h"
#include "signalforward.h"

extern SignalForward Gsigfor;

IpcMSGHandler::IpcMSGHandler(IHandleMsg *parent) : IHandleMsg(parent)
{

}

void IpcMSGHandler::handle(const QString &msg)
{
    printf("handle msg:%s\n",qPrintable(msg));


    Gsigfor.emitsignal();
}
