#ifndef VULTUSCOMMAND_H
#define VULTUSCOMMAND_H

#include <QJsonArray>
#include <QJsonObject>

class VultusCommand
{
public:
    VultusCommand(QString _command);
    ~VultusCommand();

    void addPayload(QString _key, QString _value);
    QJsonArray& getCommand();

private:
    QJsonArray m_command_array;
    QJsonObject m_command_header;
    QJsonObject m_command_payload;
};

#endif // VULTUSCOMMAND_H
