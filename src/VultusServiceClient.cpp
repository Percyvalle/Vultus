#include "VultusServiceClient.h"

VultusServiceClient::VultusServiceClient(QObject *parent)
    : QTcpSocket{parent}
{
}
VultusServiceClient::~VultusServiceClient()
{
    delete m_registration_dialog;
    delete m_response_handler;
}

void VultusServiceClient::connectToServer(QString &_address)
{
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorConnectToServer()));
    connect(this, SIGNAL(connected()), this, SLOT(doneConnectToServer()));
    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadMessage()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));

    connectToHost(_address, 2000);
}

void VultusServiceClient::sendToServer(VultusCommand* _command)
{
    m_data.clear();
    QDataStream out(&m_data, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_11);

    out << quint16(0) << QVariant(QJsonDocument(_command->getCommand()).toJson());
    out.device()->seek(0);
    out << quint16(m_data.size() - sizeof(quint16));

    write(m_data);
}

void VultusServiceClient::readyReadMessage()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_11);

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

        QVariant response;
        in >> response;
        QJsonDocument json_response = QJsonDocument::fromJson(QString(response.toByteArray().data()).toUtf8());
        qDebug() << json_response.array();
        m_response_handler->processResponse(json_response.array());
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
    m_registration_dialog = new VultusRegistrationDialog;
    m_registration_dialog->show();
}

VultusResponseHandler *VultusServiceClient::m_response_handler = new VultusResponseHandler;

