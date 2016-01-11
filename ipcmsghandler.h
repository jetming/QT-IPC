#ifndef IPCMSGHANDLER_H
#define IPCMSGHANDLER_H

#include "IPC/ihandlemsg.h"

class IpcMSGHandler : public IHandleMsg
{

public:
    IpcMSGHandler(IHandleMsg *parent=0);
    void handle(const QString &msg);

//signals:
//    void emitsig();
};

#endif // IPCMSGHANDLER_H
