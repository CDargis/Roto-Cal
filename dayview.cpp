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

    QPixmap rightArrow(tr(":/images/rightArrow.png"));
    QLabel* arrowIndicator = new QLabel(this);
    int scalar = pageHeight * .050;
    rightArrow = rightArrow.scaled(scalar, scalar);
    arrowIndicator->setPixmap(rightArrow);
    arrowIndicator->setGeometry((screenWidth / 2) - (rightArrow.width() / 2),
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 8),
                                rightArrow.width(), rightArrow.height());

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
    Event* e = NULL;
    Event_set& set = this->getEventSet();
    set.deleteEvent(e);
}
