#ifndef VULTUSSERVICECLIENT_H
#define VULTUSSERVICECLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>

#include "VultusRegistrationDialog.h"

class VultusServiceClient : public QTcpSocket
{
    Q_OBJECT
public:
    static VultusServiceClient& client(){
        static VultusServiceClient client;
        return client;
    }

private:
    explicit VultusServiceClient(QObject *parent = nullptr);
    ~VultusServiceClient();

public:
    void sendToServer(QJsonArray &_send_data);
    void connectToServer(QString &_address);

private slots:
    void readyReadMessage();
    void errorConnectToServer();
    void doneConnectToServer();

private:
    VultusRegistrationDialog *registrationDialog = new VultusRegistrationDialog;
    QByteArray m_data;
    quint16 m_block_size = 0;
};

#endif // VULTUSSERVICECLIENT_H
