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
    setDate(QDate::currentDate());

    QWidget* eventList = new QWidget(this);
    eventList->setGeometry(0, 0, screenWidth / 2, pageHeight);
    QVBoxLayout* layout = new QVBoxLayout(eventList);
    QLabel* event1 = new QLabel(tr("Event 1"), eventList);
    QLabel* event2 = new QLabel(tr("Event 2"), eventList);
    layout->addWidget(event1);
    layout->addWidget(event2);
}

void DayView::setDate(QDate date)
{
    dayLabel->setDayPixmap(date.daysInMonth());
    dayLabel->setCurrentRotation((date.day() - 1) * 11.612903226);
}
