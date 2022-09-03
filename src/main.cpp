#include "VultusMainWindow.h"

#include <QApplication>

#include "VultusServiceClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VultusServiceClient client;
    client.connectToServer();
    client.sendToServer();

    VultusMainWindow w;
    w.show();
    return a.exec();
}
