#ifndef VULTUSSCROLLAREACONTROLLER_H
#define VULTUSSCROLLAREACONTROLLER_H

#include "VultusProfileInterface.h"

#include <QPushButton>
#include <QScrollArea>
#include <QSizePolicy>
#include <QHBoxLayout>
#include <QLabel>
#include <QVector>


class VultusScrollAreaController : public QScrollArea
{
public:
    VultusScrollAreaController(QWidget *parent = nullptr);
    ~VultusScrollAreaController();

    QFrame* addWidget(VultusProfileInterface *_profile);
    QFrame* updateWidget(VultusProfileInterface *_profile);
    void rmvWidget(VultusProfileInterface *_profile);

    const QVector<QPushButton *> &connect_list() const;

private:
    QVector<QPushButton*> m_connect_list;
};

#endif // VULTUSSCROLLAREACONTROLLER_H
