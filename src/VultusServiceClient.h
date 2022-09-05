#ifndef VULTUSSERVICECLIENT_H
#define VULTUSSERVICECLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include <QJsonObject>

class VultusServiceClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit VultusServiceClient(QObject *parent = nullptr);
    ~VultusServiceClient();

    void sendToServer(QJsonArray _send_data);
    void connectToServer();

private slots:
    void readyReadMessage();

private:
    QByteArray m_data;
    quint16 m_block_size = 0;
};

#endif // VULTUSSERVICECLIENT_H
