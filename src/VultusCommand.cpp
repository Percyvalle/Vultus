#include "VultusCommand.h"

VultusCommand::VultusCommand(QString _command)
{
    m_command_header["COMMAND"] = _command;
    m_command_array.push_front(m_command_header);
    m_command_array.push_back(m_command_payload);
}

VultusCommand::~VultusCommand()
{

}

void VultusCommand::addPayload(QString _key, QString _value)
{
    m_command_payload[_key] = _value;
    m_command_array.replace(m_command_array.size() - 1,m_command_payload);
}

QJsonArray &VultusCommand::getCommand()
{
    return m_command_array;
}
