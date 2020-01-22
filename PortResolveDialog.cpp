#include "PortResolveDialog.h"
#include "ui_PortResolveDialog.h"
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: PortResolveDialog - Dialog used to grab IP and pass onto winSock
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
-- Dialog is used to grab port,connection and then passes it back to mainwindow to resolve to service name through winsock
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: PortResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: PortResolveDialog(QWidget *parent)
--
-- RETURNS: PortResolveDialog(QWidget *parent)
--
-- NOTES:
-- Default Constructor for PortResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
PortResolveDialog::PortResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortResolveDialog)
{
    ui->setupUi(this);
}
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~PortResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: PortResolveDialog()
--
-- RETURNS: PortResolveDialog()
--
-- NOTES:
-- Deconstructor for PortResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
PortResolveDialog::~PortResolveDialog()
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
-- On "Ok" button press emits signal with port, and connection to be resolved into an Service Name
----------------------------------------------------------------------------------------------------------------------*/
void PortResolveDialog::on_buttonBox_accepted()
{
    emit portResolveSignal(ui->portTextEdit->toPlainText(),ui->connectionTextEdit->toPlainText());
    ui->portTextEdit->clear();
    ui->connectionTextEdit->clear();
    hide();
}
