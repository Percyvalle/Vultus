#include "VultusServiceClient.h"

#include <QJsonArray>

VultusServiceClient::VultusServiceClient(QObject *parent)
    : QTcpSocket{parent}
{
}

VultusServiceClient::~VultusServiceClient()
{

}


void VultusServiceClient::connectToServer()
{
    connectToHost("192.168.0.182", 2000);

    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}


void VultusServiceClient::sendToServer(uint _command, QList<QVariant> _send_data)
{
    m_data.clear();
    QDataStream out(&m_data, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_15);

    QJsonObject ddd;
    QJsonArray vvv;

    ddd["COMMAND"] = "authToServer";
    vvv.append(ddd);

    out << quint16(0) << QVariant(vvv);
    for(const QVariant &i : _send_data){
        out << i;
    }
    out.device()->seek(0);
    out << quint16(m_data.size() - sizeof(quint16));

    write(m_data);
}

void VultusServiceClient::readyReadMessage()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_15);

    if(in.status() == QDataStream::Ok){
        if(m_block_size == 0){
            if(bytesAvailable() < 2){
                return;
            }

            in >> m_block_size;
        }
        if(bytesAvailable() < m_block_size){
            return;
        } else {
            m_block_size = 0;
        }

        QVariant command;
        in >> command;
        QVariant msg;
        in >> msg;
        qDebug() << msg.value<QJsonArray>();
    }
}
