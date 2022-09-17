#include "VultusMainWindow.h"
#include "ui_VultusMainWindow.h"

#include "VultusServiceClient.h"
#include "VultusResponseHandler.h"

VultusMainWindow::VultusMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::VultusMainWindow)
{
    m_ui->setupUi(this);
    m_ui->main_place->setCurrentIndex(0);

    initUI();
    connectionUI();

    connect(VultusServiceClient::client().m_response_handler, &VultusResponseHandler::authToServerResponse,
            this, &VultusMainWindow::authToServerIsDone);
    connect(VultusServiceClient::client().m_response_handler, &VultusResponseHandler::getUsersResponse,
            this, &VultusMainWindow::getUsersIsDone);
}

VultusMainWindow::~VultusMainWindow()
{
    delete m_ui;
    delete m_profile_main;
}

void VultusMainWindow::initUI()
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

void VultusMainWindow::authToServerIsDone(QJsonArray _response)
{
    m_profile_main = new VultusProfileMain(_response.first().toObject());

    VultusCommand *command_get_users = new VultusCommand("getUsers");
    VultusServiceClient::client().sendToServer(command_get_users);
}

void VultusMainWindow::getUsersIsDone(QJsonArray _response)
{
    for(QJsonValueRef profile_object : _response){
        VultusProfileInterface *profile_members = new VultusProfileInterface(profile_object.toObject());
        m_profile_members.insert(profile_members->id(), profile_members);
    }
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

