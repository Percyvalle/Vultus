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
    connect(VultusServiceClient::client().m_response_handler, &VultusResponseHandler::getOnlineUsersResponse,
            this, &VultusMainWindow::getOnlineUsersIsDone);
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

    m_ui->profile_layout_area->layout()->setSizeConstraint(QLayout::SetMaximumSize);

    QPixmap search_icon(":/icon/resource/icon_search.png");
    m_ui->search_icon_label->setPixmap(search_icon.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void VultusMainWindow::connectionUI()
{
    connect(m_ui->employees_button, SIGNAL(clicked()), SLOT(employeesButtonClicked()));
    connect(m_ui->profile_button, SIGNAL(clicked()), SLOT(profileButtonClicked()));
    connect(m_ui->tasks_button, SIGNAL(clicked()), SLOT(tasksButtonClicked()));
}

void VultusMainWindow::updateDossier(VultusProfileInterface *_profile)
{
    m_ui->profile_member_name->setText(_profile->last_name() + " " + _profile->first_name() + " " + _profile->middle_name());
}

void VultusMainWindow::authToServerIsDone(QJsonArray _response)
{
    m_profile_main = new VultusProfileMain(_response.first().toObject());
    m_area_controller = m_ui->profile_scroll_area;

    VultusCommand *command_get_users = new VultusCommand("getUsers");
    VultusServiceClient::client().sendToServer(command_get_users);
}

void VultusMainWindow::getUsersIsDone(QJsonArray _response)
{
    _response.removeFirst();
    for(QJsonValueRef profile_object : _response){
        VultusProfileInterface *profile_members = new VultusProfileInterface(profile_object.toObject());
        m_profile_members.insert(QString::number(profile_members->id()), profile_members);
        m_ui->profile_layout_area->layout()->addWidget(m_area_controller->addWidget(profile_members));
    }

    for(QPushButton* profile_button : m_area_controller->connect_list()){
        connect(profile_button, &QPushButton::clicked, this, &VultusMainWindow::profileClicked);
    }
}

void VultusMainWindow::getOnlineUsersIsDone(QJsonArray _response)
{
    qDebug() << _response;
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

void VultusMainWindow::profileClicked()
{
    QPushButton *sender_button = (QPushButton*)sender();

    updateDossier(m_profile_members[sender_button->objectName()]);
}

