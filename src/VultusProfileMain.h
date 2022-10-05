#ifndef VULTUSPROFILEMAIN_H
#define VULTUSPROFILEMAIN_H

#include "VultusProfileInterface.h"

class VultusProfileMain : public VultusProfileInterface
{
public:
    VultusProfileMain(QJsonObject _json_profile);
    ~VultusProfileMain();

    void setPhone(int _new_phone);
    void setWorkPhone(int _new_work_phone);
    void setWorkPlace(int _new_work_place);
    void setStatus(const QString &_new_status);
    void setBirthday(const QString &_new_birthday);
    void setDescription(const QString &_new_description);
    void setStatusText(const QString &_new_status_text);
    void setFullName(const QString &_new_first_name);
    void setPosition(const QString &_new_position);
    void setSubdivision(const QString &_new_subdivision);

};

#endif // VULTUSPROFILEMAIN_H
