#include "VultusMainWindow.h"

#include <QApplication>
#include <singleapplication.h>
#include <QJsonArray>

#include "VultusServiceClient.h"
#include "VultusRegistrationDialog.h"

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);

    QString address("192.168.0.182");
    VultusServiceClient::client().connectToServer(address);

    QJsonObject ddd;
    QJsonArray vvv;


    ddd["COMMAND"] = "authToServer";
    ddd["LOGIN"] = "admin";
    ddd["PASSWORD"] = "admin";
    vvv.append(ddd);
    VultusServiceClient::client().sendToServer(vvv);
    qDebug() << "Auth";

    QJsonObject sss;
    QJsonArray fff;

    sss["COMMAND"] = "getOnlineUsers";
    fff.append(sss);
    VultusServiceClient::client().sendToServer(fff);
    qDebug() << "Users";

    return app.exec();
}
