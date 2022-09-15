#ifndef VULTUSREGISTRATIONDIALOG_H
#define VULTUSREGISTRATIONDIALOG_H

#include <QDialog>

#include "VultusMainWindow.h"
#include "VultusResponseHandler.h"

namespace Ui {
class VultusRegistrationDialog;
}

class VultusRegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    VultusRegistrationDialog(QWidget *parent = nullptr);
    ~VultusRegistrationDialog();

    void initUI();
    void connectionUI();

private slots:
    void clickedAuthorization();
    void authToServerIsDone(QJsonArray _response);
    void authToServerError(QJsonArray _response);

private:
    Ui::VultusRegistrationDialog *ui;
    VultusMainWindow* m_main_window;
};

#endif // VULTUSREGISTRATIONDIALOG_H
