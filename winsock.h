#ifndef WINSOCK_H
#define WINSOCK_H

#include <QString>
#include <WinSock2.h>

class WinSock
{
public:
    WinSock();

    QString ipToHost(QString ip);
};

#endif // WINSOCK_H
