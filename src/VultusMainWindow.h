#ifndef VULTUSMAINWINDOW_H
#define VULTUSMAINWINDOW_H

#include "VultusProfileInterface.h"
#include "VultusProfileMain.h"
#include "VultusCommand.h"
#include "VultusScrollAreaController.h"

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class VultusMainWindow; }
QT_END_NAMESPACE

class VultusMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    VultusMainWindow(QWidget *parent = nullptr);
    ~VultusMainWindow();

    void initUI();
    void connectionUI();
    void connectionResponse();
    void updateDossier(VultusProfileInterface* _profile);

private slots:
    void authToServerIsDone(QJsonArray _response);
    void getUsersIsDone(QJsonArray _response);
    void getOnlineUsersIsDone(QJsonArray _response);
    void showError(QJsonArray _response);

    void employeesButtonClicked();
    void profileButtonClicked();
    void tasksButtonClicked();
    void profileClicked();

private:
    Ui::VultusMainWindow *m_ui;
    VultusProfileInterface *m_profile_main;
    VultusScrollAreaController *m_area_controller;
    QMap<QString, VultusProfileInterface*> m_profile_members;
};
#endif // VULTUSMAINWINDOW_H
