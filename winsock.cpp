#include "winsock.h"

WinSock::WinSock()
{

}

QString WinSock::ipToHost(QString ip)
{
    const char *ipAddr = ip.toStdString().c_str();
    if(inet_addr(ipAddr))
        return QString("\0");
    else {
        gethostbyname(ip.toStdString().c_str());
        return QString( gethostbyname(ip.toStdString().c_str())->h_name);

    }
}
