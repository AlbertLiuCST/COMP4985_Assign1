#include "PortResolveDialog.h"
#include "ui_PortResolveDialog.h"

PortResolveDialog::PortResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortResolveDialog)
{
    ui->setupUi(this);
}

PortResolveDialog::~PortResolveDialog()
{
    delete ui;
}

void PortResolveDialog::on_buttonBox_accepted()
{
    emit portResolveSignal(ui->portTextEdit->toPlainText(),ui->connectionTextEdit->toPlainText());
    ui->portTextEdit->clear();
    ui->connectionTextEdit->clear();
    hide();
}
