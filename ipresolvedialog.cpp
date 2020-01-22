#include "ipresolvedialog.h"
#include "ui_ipresolvedialog.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: IpResolveDialog - Dialog used to grab IP and pass onto winSock
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
-- Dialog is used to grab IP and then passes it back to mainwindow to run through winsock
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: IpResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: IpResolveDialog(QWidget *parent)
--
-- RETURNS: IpResolveDialog(QWidget *parent)
--
-- NOTES:
-- Default Constructor for IpResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
ipResolveDialog::ipResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ipResolveDialog)
{
    ui->setupUi(this);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~IpResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: IpResolveDialog()
--
-- RETURNS: IpResolveDialog()
--
-- NOTES:
-- Deconstructor for IpResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
ipResolveDialog::~ipResolveDialog()
{
    delete ui;
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_buttonBox_accepted
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: on_buttonBox_accepted()
--
-- RETURNS: void
--
-- NOTES:
-- On "Ok" button press emits signal with Host Name value to be resolved into an Host Name
----------------------------------------------------------------------------------------------------------------------*/
void ipResolveDialog::on_buttonBox_accepted()
{
    emit ipResolveSignal(ui->textEdit->toPlainText());
    ui->textEdit->clear();
    hide();
}
