#include "VultusProfileMain.h"

VultusProfileMain::VultusProfileMain(QJsonObject _json_profile) : VultusProfileInterface(_json_profile)
{

}

VultusProfileMain::~VultusProfileMain()
{

}

void VultusProfileMain::setPhone(int _new_phone)
{
    m_phone = _new_phone;
}

void VultusProfileMain::setWorkPhone(int _new_work_phone)
{
    m_work_phone = _new_work_phone;
}

void VultusProfileMain::setWorkPlace(int _new_work_place)
{
    m_work_place = _new_work_place;
}

void VultusProfileMain::setStatus(int _new_status)
{
    m_status = _new_status;
}

void VultusProfileMain::setBirthday(const QString &_new_birthday)
{
    m_birthday = _new_birthday;
}

void VultusProfileMain::setDescription(const QString &_new_description)
{
    m_description = _new_description;
}

void VultusProfileMain::setStatusText(const QString &_new_status_text)
{
    m_status_text = _new_status_text;
}

void VultusProfileMain::setFirstName(const QString &_new_first_name)
{
    m_first_name = _new_first_name;
}

void VultusProfileMain::setMiddleName(const QString &_new_middle_name)
{
    m_middle_name = _new_middle_name;
}

void VultusProfileMain::setLastName(const QString &_new_position)
{
    m_last_name = _new_position;
}

void VultusProfileMain::setPosition(const QString &_new_position)
{
    m_position = _new_position;
}

void VultusProfileMain::setSubdivision(const QString &_new_Subdivision)
{
    m_subdivision = _new_Subdivision;
}
