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
