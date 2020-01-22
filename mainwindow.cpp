#include "mainwindow.h"
#include "ui_mainwindow.h"

/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: MainWindow
--
-- PROGRAM: COMP_4985Assign1
--
-- FUNCTIONS:
-- void on_buttonBox_accepted()
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
-- Main Window of program
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- Constructor: MainWindow
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: MainWindow(QWidget *parent)
--
-- RETURNS: MainWindow
--
-- NOTES:
-- Main window of application used to display results of resolving an ip or address
-- Creates all dialogs and connects all slots to signals to resolve
----------------------------------------------------------------------------------------------------------------------*/
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
    delete winsock;
    delete ipDialog;
    delete hostDialog;
    delete portDialog;
    delete serviceDialog;
    delete ui;
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: writeToScreen
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: writeToScreen(QString str)
--
-- RETURNS: void
--
-- NOTES:
-- Writes QString to MainWindow Screen
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::writeToScreen(QString str)
{
    ui->label->setText(str);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionIP_Host_triggered
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_actionIP_Host_triggered
--
-- RETURNS: void
--
-- NOTES:
-- Shows Ip Dialog
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::on_actionIP_Host_triggered()
{
    ipDialog->show();
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionHost_IP_triggered
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_actionHost_IP_triggered
--
-- RETURNS: void
--
-- NOTES:
-- Shows Host Dialog
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::on_actionHost_IP_triggered()
{
    hostDialog->show();
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionPort_Service_triggered
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_actionPort_Service_triggered
--
-- RETURNS: void
--
-- NOTES:
-- Shows service Dialog
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::on_actionPort_Service_triggered()
{
    portDialog->show();

}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionService_Port_triggered
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_actionService_Port_triggered
--
-- RETURNS: void
--
-- NOTES:
-- Shows Service Dialog
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::on_actionService_Port_triggered()
{
    serviceDialog->show();
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: hostResolve
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: hostResolve(QString)
--
-- RETURNS: void
--
-- NOTES:
-- Connected to Host Resolve Dialog. Slot catches signal with params and resolves through winsock
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::hostResolve(QString host)
{
    QString hostName = winsock->hostToIp(host);
    if(hostName.isEmpty())
        hostName = "Could not resolve Host Name to IP";
    writeToScreen(hostName);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: portResolve
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: portResolve(QString)
--
-- RETURNS: void
--
-- NOTES:
-- Connected to port Resolve Dialog. Slot catches signal with params and resolves through winsock
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::portResolve(QString port, QString connection)
{
    QString resolve = winsock->portToService(port,connection);

    if(resolve.isEmpty())
        resolve = "Could not resolve port to Service Name";
    writeToScreen(resolve);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: serviceResolve
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: serviceResolve(QString)
--
-- RETURNS: void
--
-- NOTES:
-- Connected to service Resolve Dialog. Slot catches signal with params and resolves through winsock
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::serviceResolve(QString service, QString connection)
{
    QString resolve = winsock->serviceToPort(service,connection);
    if(resolve.isEmpty())
        resolve = "Could not resolve Service to port Number";
    writeToScreen(resolve);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ipResolve
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: ipResolve(QString)
--
-- RETURNS: void
--
-- NOTES:
-- Connected to ip Resolve Dialog. Slot catches signal with params and resolves through winsock
----------------------------------------------------------------------------------------------------------------------*/
void MainWindow::ipResolve(QString ip)
{
    QString hostName = winsock->ipToHost(ip);
    //Error Handling
    if(hostName.isEmpty())
        hostName = "Could not resolve IP to HostName";
    writeToScreen(hostName);

}

