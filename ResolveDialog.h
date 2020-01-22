#ifndef RESOLVEDIALOG_H
#define RESOLVEDIALOG_H

#include <QString>

struct params{
    QString ipAddress;
    QString hostName;
    QString serviceName;
    QString portNumber;
    QString connectionType;
};

class ResolveDialog{
private:
    params par;
public:
    params getParams(){return params};

};

#endif // RESOLVEDIALOG_H
