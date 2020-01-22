#include "ServiceResolveDialog.h"
#include "ui_ServiceResolveDialog.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: ServiceResolveDialog - Dialog used to grab IP and pass onto winSock
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
-- Dialog is used to grab service,connection and then passes it back to mainwindow to resolve to portnumber through winsock
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ServiceResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: ServiceResolveDialog(QWidget *parent)
--
-- RETURNS: ServiceResolveDialog(QWidget *parent)
--
-- NOTES:
-- Default Constructor for ServiceResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
ServiceResolveDialog::ServiceResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceResolveDialog)
{
    ui->setupUi(this);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~ServiceResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: ServiceResolveDialog()
--
-- RETURNS: ServiceResolveDialog()
--
-- NOTES:
-- Deconstructor for ServiceResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
ServiceResolveDialog::~ServiceResolveDialog()
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
-- On "Ok" button press emits signal with service, and connection to be resolved into an port number.
----------------------------------------------------------------------------------------------------------------------*/
void ServiceResolveDialog::on_buttonBox_accepted()
{
    emit serviceResolveSignal(ui->serviceTextEdit->toPlainText(),ui->connectionTextEdit->toPlainText());
    ui->serviceTextEdit->clear();
    ui->connectionTextEdit->clear();
    hide();
}
