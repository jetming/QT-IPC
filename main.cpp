#include <QCoreApplication>
#include <QObject>

#include "IPC/ipcserver.h"
#include "ipcmsghandler.h"
#include "signalforward.h"
#include "sigtest.h"

SignalForward Gsigfor;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IpcMSGHandler *imh(new IpcMSGHandler);
    IpcServer *is(new IpcServer("default-listen",imh));

    SigTest st;
    QObject::connect(&Gsigfor,&SignalForward::open,&st,&SigTest::test);

    return a.exec();
}

