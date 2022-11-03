#ifndef VULTUSRESPONSEHANDLER_H
#define VULTUSRESPONSEHANDLER_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QObject>

class VultusResponseHandler : public QObject
{
    Q_OBJECT
public:
    VultusResponseHandler();
    ~VultusResponseHandler();

    void processResponse(QJsonArray _response);

signals:
    void errorResponse(QJsonArray _response);
    void authToServerResponse(QJsonArray _response);
    void getOnlineUsersResponse(QJsonArray _response);
    void getUsersResponse(QJsonArray _response);
    void sendMainProfile();
};

#endif // VULTUSRESPONSEHANDLER_H
