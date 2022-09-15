#include "VultusResponseHandler.h"

VultusResponseHandler::VultusResponseHandler()
{

}

VultusResponseHandler::~VultusResponseHandler()
{

}

void VultusResponseHandler::processResponse(QJsonArray& _response)
{
    QJsonObject response = _response.first().toObject();

    if(!response["RESPONSE"].isNull()) {
        QString response_name = response["RESPONSE"].toString();

        _response.removeFirst();
        if(response_name == "authToServerResponse"){
            emit authToServerResponse(_response);
        } else if (response_name == "getUsersResponse"){
            emit getUsersResponse(_response);
        } else if (response_name == "getIsOnlineUsersResponse"){
            emit getOnlineUsersResponse(_response);
        }
    } else if (!response["ERROR"].isNull()){
        emit errorResponse(_response);
    }
}
