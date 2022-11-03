#include "VultusResponseHandler.h"

VultusResponseHandler::VultusResponseHandler()
{

}

VultusResponseHandler::~VultusResponseHandler()
{

}

void VultusResponseHandler::processResponse(QJsonArray _response)
{
    QJsonObject response = _response.first().toObject();

    if(!response["RESPONSE"].isNull()) {
        QString response_name = response["RESPONSE"].toString();

        if(response_name == "authToServerResponse"){
            _response.removeFirst();
            emit authToServerResponse(_response);
            return;
        } else if (response_name == "getUsersResponse"){
            _response.removeFirst();
            emit getUsersResponse(_response);
            return;
        } else if (response_name == "getIsOnlineUsersResponse"){
            _response.removeFirst();
            emit getOnlineUsersResponse(_response);
            return;
        } else if (response_name == "getMainProfile"){
            emit sendMainProfile();
            return;
        }
    } else if (!response["ERROR"].isNull()){
        emit errorResponse(_response);
        return;
    }
}
