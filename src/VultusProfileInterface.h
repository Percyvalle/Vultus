#ifndef VULTUSPROFILEINTERFACE_H
#define VULTUSPROFILEINTERFACE_H

#include <QDate>
#include <QJsonObject>
#include <QString>

class VultusProfileInterface
{
public:
    VultusProfileInterface(QJsonObject _json_profile);
    ~VultusProfileInterface();

    int id() const;
    int work_phone() const;
    int work_place() const;
    int status() const;
    const QString &phone() const;
    const QString &birthday() const;
    const QString &description() const;
    const QString &status_text() const;
    const QString &first_name() const;
    const QString &middle_name() const;
    const QString &last_name() const;
    const QString &position() const;
    const QString &subdivision() const;

    bool online_status() const;
    void setOnlineStatus(bool newOnline_status);

protected:
    int m_id;
    int m_work_phone;
    int m_work_place;
    int m_status;
    bool m_online_status;
    QString m_phone;
    QString m_birthday;
    QString m_description;
    QString m_status_text;
    QString m_first_name;
    QString m_middle_name;
    QString m_last_name;
    QString m_position;
    QString m_subdivision;
};

#endif // VULTUSPROFILEINTERFACE_H
