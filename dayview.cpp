#include "dayview.h"

#include <QLabel>

DayView::DayView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    int pageHeight = geometry().height();
    int screenWidth = geometry().width();
    QPixmap pixmap(tr(":/images/blank_circle.png"));
    dayLabel = new DayLabel(pixmap.scaled(pageHeight, pageHeight), this);
    dayLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);

    eventList = new QLabel(this);
    eventList->setGeometry(0, 0, screenWidth / 2, pageHeight);

    setDate(QDate::currentDate());
}

void DayView::setDate(QDate date)
{
    dayLabel->setDayPixmap(date.daysInMonth());
    dayLabel->setCurrentRotation((date.day() - 1) * 11.612903226);
}

void DayView::slotDateChanged(QDate date)
{
    eventList->setText(date.toString());
}
