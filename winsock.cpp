#include "winsock.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: WinSock - Interface for resolving using winsock2
--
-- PROGRAM: COMP_4985Assign1
--
-- FUNCTIONS:
--  QString ipToHost(QString ip)
--  QString hostToIp(QString host)
--  QString portToService(QString port, QString connection)
--  QString serviceToPort(QString service, QString connection);void on_buttonBox_accepted()
--
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- NOTES:
-- WinSock is acts as an interface between Dialogs and
-- Dialog is used to grab service,connection and then passes it back to mainwindow to resolve to portnumber through winsock
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ServiceResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: ServiceResolveDialog(QWidget *parent)
--
-- RETURNS: ServiceResolveDialog(QWidget *parent)
--
-- NOTES:
-- Default Constructor for ServiceResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
WinSock::WinSock()
{
    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

}

WinSock::~WinSock()
{
    WSACleanup();
}

QString WinSock::ipToHost(QString ip)
{
    const char *ipAddr = ip.toStdString().c_str();
    struct	hostent *hp;
    struct	in_addr my_addr, *addr_p;
    char	**p;
    QString hostName;

    addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
    addr_p = &my_addr;

    if(inet_addr(ipAddr) == INADDR_NONE)
        return QString("\0");
    else {
        addr_p->s_addr=inet_addr(ipAddr) ;
        if((hp = gethostbyaddr((char *)addr_p, PF_INET, sizeof (my_addr))) == NULL)
            return "";
    }

    for (p = hp->h_addr_list; *p != 0; p++){
        char **q;

        hostName = QString(hp->h_name);

        for (q = hp->h_aliases; *q != 0; q++)
                hostName.append(*q);
     }

    return hostName;
}

QString WinSock::hostToIp(QString host)
{
    const char *ipAddr = host.toStdString().c_str();
    struct	hostent *hp;
    char	**p;
    QString ipAddress;

    if((hp = gethostbyname(ipAddr)) == NULL)
        return "";
    else {
        for (p = hp->h_addr_list; *p != 0; p++){
            struct in_addr in;

        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        ipAddress = QString(inet_ntoa(in));
        }
    }

    return ipAddress;

}

QString WinSock::portToService(QString port, QString connection)
{
    struct servent *sv;
    int s_port;

    s_port = atoi(port.toStdString().c_str());
    sv = getservbyport (htons(s_port), connection.toStdString().c_str());

    if (sv == NULL)
        return "";
    else
        return QString(sv->s_name);
}

QString WinSock::serviceToPort(QString service, QString connection)
{
    struct servent *sv;
    sv = getservbyname(service.toStdString().c_str(), connection.toStdString().c_str());
    if (sv == NULL)
        return "";
    else
        return QString(ntohs(sv->s_port));
}
