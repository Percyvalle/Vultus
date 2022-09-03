#include "VultusMainWindow.h"

#include <QApplication>

#include "VultusServiceClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VultusServiceClient client;
    client.connectToServer();

    QList<QVariant> list_command;
    list_command.append(QVariant("login"));
    list_command.append(QVariant("password"));
    client.sendToServer(authToServer, list_command);

    VultusMainWindow w;
    w.show();
    return a.exec();
}
