#ifndef VULTUSRESPONSEHANDLER_H
#define VULTUSRESPONSEHANDLER_H

#include <QObject>

class VultusResponseHandler : public QObject
{
    Q_OBJECT
public:
    VultusResponseHandler();
    ~VultusResponseHandler();

    void processResponse(QJsonArray _response);
};

#endif // VULTUSRESPONSEHANDLER_H
