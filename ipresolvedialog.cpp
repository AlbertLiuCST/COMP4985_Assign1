#include "ipresolvedialog.h"
#include "ui_ipresolvedialog.h"

ipResolveDialog::ipResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ipResolveDialog)
{
    ui->setupUi(this);
}

ipResolveDialog::~ipResolveDialog()
{
    delete ui;
}

void ipResolveDialog::on_buttonBox_accepted()
{
    emit ipResolveSignal(ui->textEdit->toPlainText());
    ui->textEdit->clear();
    hide();
}
