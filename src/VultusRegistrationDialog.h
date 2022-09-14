#ifndef VULTUSREGISTRATIONDIALOG_H
#define VULTUSREGISTRATIONDIALOG_H

#include <QDialog>

namespace Ui {
class VultusRegistrationDialog;
}

class VultusRegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VultusRegistrationDialog(QWidget *parent = nullptr);
    ~VultusRegistrationDialog();

    void initUI();
    void connectionUI();

private slots:
    void clickedAuthorization();

private:
    Ui::VultusRegistrationDialog *ui;
};

#endif // VULTUSREGISTRATIONDIALOG_H
