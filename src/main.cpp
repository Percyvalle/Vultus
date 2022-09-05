#include "VultusMainWindow.h"

#include <QApplication>
#include <QJsonArray>

#include "VultusServiceClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VultusServiceClient client;
    client.connectToServer();


    QJsonObject ddd;
    QJsonArray vvv;

    ddd["COMMAND"] = "authToServer";
    ddd["LOGIN"] = "admin";
    ddd["PASSWORD"] = "admin";
    vvv.append(ddd);
    client.sendToServer(vvv);

    VultusMainWindow w;
    w.show();
    return a.exec();
}
