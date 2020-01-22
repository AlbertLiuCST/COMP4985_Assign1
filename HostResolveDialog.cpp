#include "HostResolveDialog.h"
#include "ui_HostResolveDialog.h"

/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: HostResolveDialog - Dialog used to grab Host Name and pass onto winSock
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
-- Dialog is used to grab Host Name and then pass it back to mainwindow to run through winsock
----------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: HostResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: HostResolveDialog(QWidget *parent)
--
-- RETURNS: HostResolveDialog(QWidget *parent)
--
-- NOTES:
-- Default Constructor for HostResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
HostResolveDialog::HostResolveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostResolveDialog)
{
    ui->setupUi(this);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~HostResolveDialog
--
-- DATE: January 21, 2020
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Albert Liu
--
-- PROGRAMMER: Albert Liu
--
-- INTERFACE: HostResolveDialog()
--
-- RETURNS: HostResolveDialog()
--
-- NOTES:
-- Deconstructor for HostResolveDialog
----------------------------------------------------------------------------------------------------------------------*/
HostResolveDialog::~HostResolveDialog()
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
-- On "Ok" button press emits signal with Host Name value to be resolved into an IP
----------------------------------------------------------------------------------------------------------------------*/
void HostResolveDialog::on_buttonBox_accepted()
{
    emit hostResolveSignal(ui->textEdit->toPlainText());
    ui->textEdit->clear();
    hide();
}
