#include "VultusMainWindow.h"

#include <QApplication>

#include "VultusServiceClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VultusServiceClient client;
    client.connectToServer();

    QVector<QVariant> variants;
    variants.append(QVariant("login"));
    variants.append(QVariant("pass"));
    client.sendToServer(authToServer, variants);
    client.sendToServer(getOnlineUsers);

    VultusMainWindow w;
    w.show();
    return a.exec();
}
