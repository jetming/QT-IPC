#include "ipcserver.h"

#include <QDataStream>

IpcServer::IpcServer(const QString &servername, IHandleMsg *ihm, QObject *parent) : QObject(parent),
    m_ihm(ihm)
{
    printf("server listen on:%s\n",qPrintable(servername));
    if(isServerRun(servername))
    {
        printf("server is run.\n");
        return;
    }
    m_server=new QLocalServer;
    QLocalServer::removeServer(servername);
    // 进行监听
    m_server->listen(servername);
    connect(m_server, SIGNAL(newConnection()), this, SLOT(ServerNewConnection()));
}

void IpcServer::ServerNewConnection()
{
    printf("get new connection\n");
    QLocalSocket *newsocket(m_server->nextPendingConnection());
    connect(newsocket, SIGNAL(readyRead()), this, SLOT(ServerReadyRead()));
    lsq.push(newsocket);
}

void IpcServer::ServerReadyRead()
{
    printf("server is ready read.\n");
    blockSize=0;

    QLocalSocket *lsocket=lsq.front();
    QDataStream in(lsocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (lsocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (in.atEnd())
        return;
    QString  readMsg;
    // 读出数据
    in>>readMsg;

    delete lsocket;
    lsq.pop();

    m_ihm->handle(readMsg);
}



int IpcServer::isServerRun(const QString &servername)
{
    // 用一个localsocket去连一下,如果能连上就说明有一个在运行了
    QLocalSocket ls;
    ls.connectToServer(servername);
    if (ls.waitForConnected(1000))
    {
     // 说明已经在运行了
        ls.disconnectFromServer();
        ls.close();
        return 1;
    }
    return 0;
}
