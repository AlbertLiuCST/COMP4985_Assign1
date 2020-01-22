#ifndef WINSOCK_H
#define WINSOCK_H

#include <QString>
#include <WinSock2.h>
#include <ResolveDialog.h>
class WinSock
{
public:
    WinSock();
    ~WinSock();

    QString resolve(ResolveDialog resolve);

    QString ipToHost(QString ip);
    QString hostToIp(QString host);
    QString portToService(QString port, QString connection);
    QString serviceToPort(QString service, QString connection);
};

#endif // WINSOCK_H
