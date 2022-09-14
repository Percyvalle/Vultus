#include "VultusServiceClient.h"

VultusServiceClient::VultusServiceClient(QObject *parent)
    : QTcpSocket{parent}
{
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorConnectToServer()));
    connect(this, SIGNAL(connected()), this, SLOT(doneConnectToServer()));
}

VultusServiceClient::~VultusServiceClient()
{
    delete registrationDialog;
}

void VultusServiceClient::connectToServer(QString &_address)
{
    connectToHost(_address, 2000);

    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

void VultusServiceClient::sendToServer(VultusCommand* _command)
{
    m_data.clear();
    QDataStream out(&m_data, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_15);

    out << quint16(0) << QVariant(_command->getCommand());
    out.device()->seek(0);
    out << quint16(m_data.size() - sizeof(quint16));

    write(m_data);
    waitForReadyRead();
}

#include <QMessageBox>
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

        QMessageBox msgBox;
        QVariant msg;

        in >> msg;

        QJsonArray ar = msg.value<QJsonArray>();

        msgBox.information(0, "Пришло", msg.value<QJsonArray>()[2].toObject()["first_name"].toString());
        msgBox.setMinimumSize(800, 800);
        qDebug() << ar;
    }
}

void VultusServiceClient::errorConnectToServer()
{
    QMessageBox msgBox;
    msgBox.critical(0, "Ошибка подключения к серверу", "Ошибка подключения: " + errorString());
    msgBox.setFixedSize(500, 200);

    disconnectFromHost();
}

void VultusServiceClient::doneConnectToServer()
{
    registrationDialog->show();
}


