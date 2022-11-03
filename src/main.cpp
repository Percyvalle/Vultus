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

    QString address("localhost");
    VultusServiceClient::client().connectToServer(address);

    return app.exec();
}
