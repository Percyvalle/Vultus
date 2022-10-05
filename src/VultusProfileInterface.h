#ifndef VULTUSPROFILEINTERFACE_H
#define VULTUSPROFILEINTERFACE_H

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
    qlonglong phone() const;
    const QString &status_name() const;
    const QString &birthday() const;
    const QString &description() const;
    const QString &status_text() const;
    const QString &full_name() const;
    const QString &position() const;
    const QString &subdivision() const;

    bool online_status() const;
    void setOnlineStatus(bool newOnline_status);

    bool super_busy() const;

protected:
    int m_id;
    int m_work_phone;
    int m_work_place;
    qlonglong m_phone;
    bool m_super_busy;
    bool m_online_status;
    QString m_status_name;
    QString m_birthday;
    QString m_description;
    QString m_status_text;
    QString m_full_name;
    QString m_position;
    QString m_subdivision;
};

#endif // VULTUSPROFILEINTERFACE_H
