#ifndef HOSTRESOLVEDIALOG_H
#define HOSTRESOLVEDIALOG_H

#include <QDialog>

namespace Ui {
class HostResolveDialog;
}

class HostResolveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HostResolveDialog(QWidget *parent = nullptr);
    ~HostResolveDialog();

private:
    Ui::HostResolveDialog *ui;
};

#endif // HOSTRESOLVEDIALOG_H
