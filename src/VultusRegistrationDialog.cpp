#include "VultusRegistrationDialog.h"
#include "ui_VultusRegistrationDialog.h"

#include "VultusServiceClient.h"

VultusRegistrationDialog::VultusRegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VultusRegistrationDialog)
{
    ui->setupUi(this);

    initUI();
    connectionUI();

    m_main_window = new VultusMainWindow();

    connect(VultusServiceClient::m_response_handler, &VultusResponseHandler::authToServerResponse,
            this, &VultusRegistrationDialog::authToServerIsDone);
    connect(VultusServiceClient::m_response_handler, &VultusResponseHandler::errorResponse,
            this, &VultusRegistrationDialog::authToServerError);
}

VultusRegistrationDialog::~VultusRegistrationDialog()
{
    delete ui;
}

void VultusRegistrationDialog::initUI()
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(" ");
}

void VultusRegistrationDialog::connectionUI()
{
    connect(ui->authorization_button, &QPushButton::clicked, this, &VultusRegistrationDialog::clickedAuthorization);
}

void VultusRegistrationDialog::clickedAuthorization()
{
    VultusCommand* cmd = new VultusCommand("authToServer");
    cmd->addPayload("LOGIN", ui->login_line_edit->text());
    cmd->addPayload("PASSWORD", ui->password_line_edit->text());

    VultusServiceClient::client().sendToServer(cmd);
}

void VultusRegistrationDialog::authToServerIsDone()
{
    this->hide();
    this->disconnect();

    m_main_window->show();
}

void VultusRegistrationDialog::authToServerError(QJsonArray _response)
{
    QString error_response = _response.first().toObject()["ERROR"].toString();
    ui->info_label->setText(error_response);
}
