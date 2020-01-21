#include "ServiceResolveDialog.h"
#include "ui_ServiceResolveDialog.h"

ServiceResolveDialog::ServiceResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceResolveDialog)
{
    ui->setupUi(this);
}

ServiceResolveDialog::~ServiceResolveDialog()
{
    delete ui;
}

void ServiceResolveDialog::on_buttonBox_accepted()
{
    emit serviceResolveSignal(ui->serviceTextEdit->toPlainText(),ui->connectionTextEdit->toPlainText());
    ui->serviceTextEdit->clear();
    ui->connectionTextEdit->clear();
    hide();
}
