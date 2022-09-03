#include "VultusServiceClient.h"

VultusServiceClient::VultusServiceClient(QObject *parent)
    : QTcpSocket{parent}
{
}

VultusServiceClient::~VultusServiceClient()
{

}


void VultusServiceClient::connectToServer()
{
    connectToHost("127.0.01", 2000);

    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}


void VultusServiceClient::sendToServer()
{
    m_data.clear();
    QDataStream out(&m_data, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_15);
    out << quint16(0) << QString("login");
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
    }
}
