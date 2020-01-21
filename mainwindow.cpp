#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    winsock = new WinSock();
    ipDialog = new ipResolveDialog();
    hostDialog = new HostResolveDialog();
    portDialog = new PortResolveDialog();
    serviceDialog = new ServiceResolveDialog();

    connect(ipDialog,&ipResolveDialog::ipResolveSignal,this,&MainWindow::ipResolve);
    connect(hostDialog,&HostResolveDialog::hostResolveSignal,this,&MainWindow::hostResolve);
    connect(portDialog,&PortResolveDialog::portResolveSignal,this,&MainWindow::portResolve);
    connect(serviceDialog,&ServiceResolveDialog::serviceResolveSignal,this,&MainWindow::serviceResolve);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeToScreen(QString str)
{
    ui->label->setText(str);
}


void MainWindow::on_actionIP_Host_triggered()
{
    ipDialog->show();
}
void MainWindow::on_actionHost_IP_triggered()
{
    hostDialog->show();
}

void MainWindow::on_actionPort_Service_triggered()
{
    portDialog->show();

}

void MainWindow::on_actionService_Port_triggered()
{
    serviceDialog->show();
}

void MainWindow::hostResolve(QString host)
{
    QString hostName = winsock->hostToIp(host);
    writeToScreen(hostName);
}

void MainWindow::portResolve(QString port, QString connection)
{
    QString resolve = winsock->portToService(port,connection);
    writeToScreen(resolve);
}
void MainWindow::serviceResolve(QString service, QString connection)
{
    QString resolve = winsock->serviceToPort(service,connection);
    writeToScreen(resolve);
}
void MainWindow::ipResolve(QString ip)
{
    QString hostName = winsock->ipToHost(ip);
    //Error Handling
    writeToScreen(hostName);

}

