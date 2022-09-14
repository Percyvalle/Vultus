#include "VultusMainWindow.h"

#include <QApplication>
#include <singleapplication.h>
#include <QJsonArray>

#include "VultusServiceClient.h"
#include "VultusRegistrationDialog.h"
#include "VultusCommand.h"

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);

    QString address("192.168.0.182");
    VultusServiceClient::client().connectToServer(address);

    VultusCommand* cmd = new VultusCommand("authToServer");
    cmd->addPayload("LOGIN", "admin");
    cmd->addPayload("PASSWORD", "admin");

    VultusServiceClient::client().sendToServer(cmd);

    VultusCommand* cmdd = new VultusCommand("getUsers");

    VultusServiceClient::client().sendToServer(cmdd);

    return app.exec();
}
