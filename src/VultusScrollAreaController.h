#ifndef VULTUSSCROLLAREACONTROLLER_H
#define VULTUSSCROLLAREACONTROLLER_H

#include "VultusProfileInterface.h"

#include <QPushButton>
#include <QScrollArea>
#include <QVector>

class VultusScrollAreaController : public QScrollArea
{
public:
    VultusScrollAreaController();
    ~VultusScrollAreaController();

    void addWidget(VultusProfileInterface *_profile);
    void rmvWidget(VultusProfileInterface *_profile);

private:
    QVector<QPushButton*> m_connect_list;
};

#endif // VULTUSSCROLLAREACONTROLLER_H
