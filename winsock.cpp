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
-- WinSock is acts as an interface between Dialogs and WinSock2 API
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- Constructor: WinSock
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: WinSock()
--
-- RETURNS: WinSock()
--
-- NOTES:
-- Default Constructor for WinSock
----------------------------------------------------------------------------------------------------------------------*/
WinSock::WinSock()
{
    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;
    WSAStartup(wVersionRequested, &wsaData);

}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~WinSock
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_buttonBox_accepted()
--
-- RETURNS: void
--
-- NOTES:
-- Destructor for winsock used for cleanup
----------------------------------------------------------------------------------------------------------------------*/
WinSock::~WinSock()
{
    WSACleanup();
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ipToHost
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: ipToHost(QString)
--
-- RETURNS: QString
--
-- NOTES:
-- Resolves an ip address and returns a host name
----------------------------------------------------------------------------------------------------------------------*/
QString WinSock::ipToHost(QString ip)
{
    const char *ipAddr = ip.toStdString().c_str();
    struct	hostent *hp;
    struct	in_addr my_addr, *addr_p;
    char	**p;
    QString hostName = "Host Name is : ";

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

        hostName.append(hp->h_name);

        for (q = hp->h_aliases; *q != 0; q++){
                hostName.append(*q);
                hostName.append("\n");
        }
        hostName.append("\n");
     }

    return hostName;
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: hostToIp
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: hostToIp(QString)
--
-- RETURNS: QString
--
-- NOTES:
-- Resolves an host name and returns a ip address
----------------------------------------------------------------------------------------------------------------------*/
QString WinSock::hostToIp(QString host)
{
    const char *ipAddr = host.toStdString().c_str();
    struct	hostent *hp;
    char	**p;
    QString ipAddress = "Ip address is : ";

    if((hp = gethostbyname(ipAddr)) == NULL)
        return "";
    else {
        for (p = hp->h_addr_list; *p != 0; p++){
            struct in_addr in;

        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        ipAddress.append(inet_ntoa(in)) ;
        ipAddress.append("\n");
        }
    }

    return ipAddress;

}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: portToService
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: portToService(QString)
--
-- RETURNS: QString
--
-- NOTES:
-- Resolves an port number and returns a service name
----------------------------------------------------------------------------------------------------------------------*/
QString WinSock::portToService(QString port, QString connection)
{
    struct servent *sv;
    int s_port;
    QString str = "Service name is : ";

    s_port = atoi(port.toStdString().c_str());
    sv = getservbyport (htons(s_port), connection.toStdString().c_str());

    if (sv == NULL)
        return "";
    else
        return str.append(sv->s_name);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: serviceToPort
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: portToService(QString)
--
-- RETURNS: QString
--
-- NOTES:
-- Resolves an service name and returns a port number
----------------------------------------------------------------------------------------------------------------------*/
QString WinSock::serviceToPort(QString service, QString connection)
{
    struct servent *sv;
    QString str = "Port Number : ";
    sv = getservbyname(service.toStdString().c_str(), connection.toStdString().c_str());
    short port = ntohs(sv->s_port);
    if (sv == NULL)
        return "";
    else
        return str.append(port);
}
