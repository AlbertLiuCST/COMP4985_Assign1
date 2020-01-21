#ifndef IPRESOLVEDIALOG_H
#define IPRESOLVEDIALOG_H

#include <QDialog>

namespace Ui {
class ipResolveDialog;
}

class ipResolveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ipResolveDialog(QWidget *parent = nullptr);
    ~ipResolveDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ipResolveDialog *ui;

signals:
    void ipResolveSignal(const String ip);


};

#endif // IPRESOLVEDIALOG_H
