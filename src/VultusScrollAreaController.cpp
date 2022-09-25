#include "VultusScrollAreaController.h"

VultusScrollAreaController::VultusScrollAreaController(QWidget *parent) :
    QScrollArea(parent)
{
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

VultusScrollAreaController::~VultusScrollAreaController()
{

}

QFrame* VultusScrollAreaController::addWidget(VultusProfileInterface *_profile)
{
    QFrame *widget_frame = new QFrame;
    QLabel *widget_status_label = new QLabel;
    QLabel *widget_photo_label = new QLabel;
    QPushButton *widget_button = new QPushButton;
    QHBoxLayout *widget_layout = new QHBoxLayout;

    QPixmap status_icon(":/icon/resource/status_icon/thunder_icon.png");
    widget_status_label->setPixmap(status_icon.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    widget_status_label->setAlignment(Qt::AlignCenter);
    widget_status_label->setMinimumWidth(60);
    widget_status_label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    switch(_profile->status()) {
    case notAvailable:
        widget_status_label->setStyleSheet("background-color: #cccccc;");
        break;
    case atWorkPlace:
        widget_status_label->setStyleSheet("background-color: #3cb371;");
        break;
    case veryBusy:
        widget_status_label->setStyleSheet("background-color: #cd5c5c;");
        break;
    }

    widget_button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    widget_button->setText(_profile->last_name() + " " + _profile->first_name() + " " + _profile->middle_name());
    widget_button->setObjectName(QString::number(_profile->id()));
    widget_button->setStyleSheet("QPushButton{background: rgba(245, 245, 245,0%); \
                                              border: 0;}");
    m_connect_list.append(widget_button);

    widget_photo_label->setMinimumWidth(70);
    widget_photo_label->setMaximumHeight(70);
    widget_photo_label->setText(_profile->first_name().front());
    widget_photo_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    widget_photo_label->setObjectName("photo_label");
    widget_photo_label->setStyleSheet("background-color: white; \
                                       font: 24px Bahnschrift SemiBold; \
                                       border: 0; \
                                       border-radius: 35;");

    widget_layout->setMargin(0);
    widget_layout->addWidget(widget_status_label);
    widget_layout->addWidget(widget_photo_label);
    widget_layout->addWidget(widget_button);
    widget_layout->setStretch(2, 1);

    widget_frame->setMaximumHeight(90);
    widget_frame->setStyleSheet("QFrame{background: rgba(245, 245, 245,50%); \
                                        border: 0;} \
                                 QFrame::hover{background: grey; \
                                               border: 0;}");
    widget_frame->setLayout(widget_layout);

    return widget_frame;
}

void VultusScrollAreaController::rmvWidget(VultusProfileInterface *_profile)
{

}

const QVector<QPushButton *> &VultusScrollAreaController::connect_list() const
{
    return m_connect_list;
}
