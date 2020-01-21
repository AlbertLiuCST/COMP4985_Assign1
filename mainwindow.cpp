#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    winsock = new WinSock();
    ipDialog = new ipResolveDialog();




    connect(ipDialog,&ipResolveDialog::ipResolveSignal,this,&MainWindow::ipResolve);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeToScreen(String str)
{
    ui->label->setText(str);
}


void MainWindow::on_actionHost_IP_triggered()
{
    ipDialog->show();
}

void MainWindow::ipResolve(String ip)
{
    ui->label->setText(winsock->ipToHost(ip));

}
