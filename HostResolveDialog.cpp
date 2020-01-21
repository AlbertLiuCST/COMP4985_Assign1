#include "HostResolveDialog.h"
#include "ui_HostResolveDialog.h"

HostResolveDialog::HostResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostResolveDialog)
{
    ui->setupUi(this);
}

HostResolveDialog::~HostResolveDialog()
{
    delete ui;
}


void HostResolveDialog::on_buttonBox_accepted()
{
    emit hostResolveSignal(ui->textEdit->toPlainText());
    ui->textEdit->clear();
    hide();
}
