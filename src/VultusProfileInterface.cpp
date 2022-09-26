#include "VultusProfileInterface.h"

VultusProfileInterface::VultusProfileInterface(QJsonObject _json_profile)
{
    m_id = _json_profile["id"].toInt();
    m_work_phone = _json_profile["work_phone"].toInt();
    m_work_place = _json_profile["work_place"].toInt();
    m_phone = _json_profile["phone"].toDouble();
    m_birthday = _json_profile["birthday"].toString();
    m_description = _json_profile["description"].toString();
    m_status_text = _json_profile["status_text"].toString();
    m_full_name = _json_profile["full_name"].toString();
    m_position = _json_profile["position"].toString();
    m_subdivision = _json_profile["subdivision"].toString();
    m_status_name = _json_profile["status_name"].toString();
    m_super_busy = _json_profile["super_busy"].toBool();
    m_online_status = false;
}

VultusProfileInterface::~VultusProfileInterface()
{

}

int VultusProfileInterface::id() const
{
    return m_id;
}

int VultusProfileInterface::work_phone() const
{
    return m_work_phone;
}

int VultusProfileInterface::work_place() const
{
    return m_work_place;
}

const QString &VultusProfileInterface::status_name() const
{
    return m_status_name;
}

qlonglong VultusProfileInterface::phone() const
{
    return m_phone;
}

const QString &VultusProfileInterface::birthday() const
{
    return m_birthday;
}

const QString &VultusProfileInterface::description() const
{
    return m_description;
}

const QString &VultusProfileInterface::status_text() const
{
    return m_status_text;
}

const QString &VultusProfileInterface::full_name() const
{
    return m_full_name;
}

const QString &VultusProfileInterface::position() const
{
    return m_position;
}

const QString &VultusProfileInterface::subdivision() const
{
    return m_subdivision;
}

void VultusProfileInterface::setOnlineStatus(bool newOnlineStatus)
{
    m_online_status = newOnlineStatus;
}

bool VultusProfileInterface::super_busy() const
{
    return m_super_busy;
}

bool VultusProfileInterface::online_status() const
{
    return m_online_status;
}
