#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ipresolvedialog.h"
#include "HostResolveDialog.h"
#include "PortResolveDialog.h"
#include "ServiceResolveDialog.h"

#include "winsock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeToScreen(QString str);


private slots:
    void on_actionHost_IP_triggered();
    void on_actionIP_Host_triggered();
    void on_actionPort_Service_triggered();
    void on_actionService_Port_triggered();

    void ipResolve(QString ip);
    void hostResolve(QString host);
    void portResolve(QString port, QString connection);
    void serviceResolve(QString service, QString connection);

private:
    WinSock *winsock;

    ipResolveDialog *ipDialog;
    HostResolveDialog *hostDialog;
    ServiceResolveDialog *serviceDialog;
    PortResolveDialog *portDialog;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
