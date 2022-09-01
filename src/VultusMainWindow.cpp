#include "VultusMainWindow.h"
#include "ui_VultusMainWindow.h"

VultusMainWindow::VultusMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::VultusMainWindow)
{
    m_ui->setupUi(this);

    initWindow();
    connectionUI();
}

VultusMainWindow::~VultusMainWindow()
{
    delete m_ui;
}

void VultusMainWindow::initWindow()
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Vultus");

    QPixmap search_icon(":/icon/resource/icon_search.png");
    m_ui->search_icon_label->setPixmap(search_icon.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void VultusMainWindow::connectionUI()
{
    connect(m_ui->employees_button, SIGNAL(clicked()), SLOT(employeesButtonClicked()));
    connect(m_ui->profile_button, SIGNAL(clicked()), SLOT(profileButtonClicked()));
    connect(m_ui->tasks_button, SIGNAL(clicked()), SLOT(tasksButtonClicked()));
}

void VultusMainWindow::employeesButtonClicked()
{
    m_ui->main_place->setCurrentIndex(0);
}

void VultusMainWindow::profileButtonClicked()
{
    m_ui->main_place->setCurrentIndex(1);
}

void VultusMainWindow::tasksButtonClicked()
{
    m_ui->main_place->setCurrentIndex(2);
}

