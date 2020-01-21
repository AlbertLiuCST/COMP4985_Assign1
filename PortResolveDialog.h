#ifndef PORTRESOLVEDIALOG_H
#define PORTRESOLVEDIALOG_H

#include <QDialog>

namespace Ui {
class PortResolveDialog;
}

class PortResolveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PortResolveDialog(QWidget *parent = nullptr);
    ~PortResolveDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PortResolveDialog *ui;

signals:
    void portResolveSignal(const QString port, const QString protocol);

};

#endif // PORTRESOLVEDIALOG_H
