#include "VultusProfileInterface.h"

VultusProfileInterface::VultusProfileInterface(QJsonObject _json_profile)
{
    m_id = _json_profile["id"].toInt();
    m_phone = _json_profile["phone"].toInt();
    m_work_phone = _json_profile["workphone"].toInt();
    m_work_place = _json_profile["workplace"].toInt();
    m_status = _json_profile["status"].toInt();
    m_birthday = _json_profile["birthday"].toString();
    m_description = _json_profile["description"].toString();
    m_status_text = _json_profile["status_text"].toString();
    m_first_name = _json_profile["first_name"].toString();
    m_middle_name = _json_profile["middle_name"].toString();
    m_last_name = _json_profile["last_name"].toString();
    m_position = _json_profile["position"].toString();
    m_subdivision = _json_profile["subdivision"].toString();
}

VultusProfileInterface::~VultusProfileInterface()
{

}

int VultusProfileInterface::id() const
{
    return m_id;
}

int VultusProfileInterface::phone() const
{
    return m_phone;
}

int VultusProfileInterface::work_phone() const
{
    return m_work_phone;
}

int VultusProfileInterface::work_place() const
{
    return m_work_place;
}

int VultusProfileInterface::status() const
{
    return m_status;
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

const QString &VultusProfileInterface::first_name() const
{
    return m_first_name;
}

const QString &VultusProfileInterface::middle_name() const
{
    return m_middle_name;
}

const QString &VultusProfileInterface::last_name() const
{
    return m_last_name;
}

const QString &VultusProfileInterface::position() const
{
    return m_position;
}

const QString &VultusProfileInterface::subdivision() const
{
    return m_subdivision;
}

bool VultusProfileInterface::online_status() const
{
    return m_online_status;
}
