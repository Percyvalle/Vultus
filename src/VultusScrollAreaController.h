#ifndef VULTUSSCROLLAREACONTROLLER_H
#define VULTUSSCROLLAREACONTROLLER_H

#include "VultusProfileInterface.h"

#include <QPushButton>
#include <QScrollArea>
#include <QSizePolicy>
#include <QHBoxLayout>
#include <QLabel>
#include <QVector>

enum StatusList{
    notAvailable = 0,
    atWorkPlace = 1,
    veryBusy = 2

};

class VultusScrollAreaController : public QScrollArea
{
public:
    VultusScrollAreaController(QWidget *parent = nullptr);
    ~VultusScrollAreaController();

    QFrame* addWidget(VultusProfileInterface *_profile);
    void rmvWidget(VultusProfileInterface *_profile);

private:
    QVector<QPushButton*> m_connect_list;
};

#endif // VULTUSSCROLLAREACONTROLLER_H
