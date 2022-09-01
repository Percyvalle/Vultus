#ifndef VULTUSSERVICECLIENT_H
#define VULTUSSERVICECLIENT_H

#include <QTcpSocket>
#include <QDataStream>

enum sendCommand {
    authToServer= 0,
    getUserInfo = 1,
    getOnlineUsers = 2
};

class VultusServiceClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit VultusServiceClient(QObject *parent = nullptr);
    ~VultusServiceClient();

    void sendToServer(quint8 _command, QVector<QVariant> &_sendData);
    void sendToServer(quint8 _command);
    void connectToServer();

private slots:
    void readyReadMessage();

private:
    QByteArray m_data;
    quint16 m_block_size = 0;
};

#endif // VULTUSSERVICECLIENT_H
