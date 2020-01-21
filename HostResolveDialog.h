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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::HostResolveDialog *ui;

signals:
    void hostResolveSignal(const QString ip);

};

#endif // HOSTRESOLVEDIALOG_H
