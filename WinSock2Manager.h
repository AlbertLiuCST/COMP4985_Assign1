#ifndef WINSOCK2CONNECTION_H
#define WINSOCK2CONNECTION_H

#include <string>
#include <WinSock2.h>

class WinSock2Manager
{
public:
    WinSock2Manager();
    ~WinSock2Manager();

    QString ipToHost(QString ip);
};

#endif // WINSOCK2CONNECTION_H
