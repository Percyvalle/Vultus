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
    connect(VultusServiceClient::client().m_response_handler, &VultusResponseHandler::errorResponse,
            this, &VultusMainWindow::showError);
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
    m_ui->profile_member_name->setText(_profile->full_name());
    m_ui->position_label->setText(_profile->position());
    m_ui->subdivision_label->setText(_profile->subdivision());
    m_ui->birthday_label->setText(_profile->birthday());
    m_ui->discription_label->setText(_profile->description());
    m_ui->phone_label->setText(QString::number(_profile->phone()));
    m_ui->work_place_label->setText(QString::number(_profile->work_place()));
    m_ui->work_phone_label->setText(QString::number(_profile->work_phone()));

    if (_profile->super_busy()){
        m_ui->profile_member_status->setStyleSheet("background-color: #cd5c5c;");
    } else {
        m_ui->profile_member_status->setStyleSheet("background-color: #3cb371;");
    }

    QPixmap status_icon(":/icon/resource/status_icon/thunder_icon.png");
    m_ui->profile_member_status->setPixmap(status_icon.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_ui->profile_member_status->setAlignment(Qt::AlignCenter);

    if(_profile->online_status()){
        m_ui->profile_member_online_status->setText("В сети");
    } else {
        m_ui->profile_member_online_status->setText("Не в сети");
    }
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
    for(QJsonValueRef profile_object : _response){
        if(profile_object.toObject()["id"].toInt() == m_profile_main->id()){
            continue;
        }
        VultusProfileInterface *profile_members = new VultusProfileInterface(profile_object.toObject());
        m_profile_members.insert(QString::number(profile_members->id()), profile_members);
        m_ui->profile_layout_area->layout()->addWidget(m_area_controller->addWidget(profile_members));
    }

    for(QPushButton* profile_button : m_area_controller->connect_list()){
        connect(profile_button, &QPushButton::clicked, this, &VultusMainWindow::profileClicked);
    }

    updateDossier(m_profile_members.first());

    VultusCommand *command_get_online_users = new VultusCommand("getOnlineUsers");
    VultusServiceClient::client().sendToServer(command_get_online_users);
}

void VultusMainWindow::getOnlineUsersIsDone(QJsonArray _response)
{
    for(VultusProfileInterface *profile_interface : m_profile_members){
        profile_interface->setOnlineStatus(false);
    }

    for(QJsonValueRef profile_object : _response){
        m_profile_members[profile_object.toObject()["id"].toString()]->setOnlineStatus(true);
    }
}

void VultusMainWindow::showError(QJsonArray _response)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error", _response.first().toObject()["ERROR"].toString());
    messageBox.setFixedSize(500,200);
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

