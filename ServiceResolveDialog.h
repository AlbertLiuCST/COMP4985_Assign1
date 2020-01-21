#ifndef SERVICERESOLVEDIALOG_H
#define SERVICERESOLVEDIALOG_H

#include <QDialog>

namespace Ui {
class ServiceResolveDialog;
}

class ServiceResolveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceResolveDialog(QWidget *parent = nullptr);
    ~ServiceResolveDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ServiceResolveDialog *ui;

signals:
    void serviceResolveSignal(const QString service, const QString protocol);
};

#endif // SERVICERESOLVEDIALOG_H
