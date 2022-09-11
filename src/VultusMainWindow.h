#ifndef VULTUSMAINWINDOW_H
#define VULTUSMAINWINDOW_H

#include <QMainWindow>

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

private slots:

    void employeesButtonClicked();
    void profileButtonClicked();
    void tasksButtonClicked();

private:
    Ui::VultusMainWindow *m_ui;
};
#endif // VULTUSMAINWINDOW_H
