#include "dayview.h"
#include "cmp_event_set.h"
#include "event_set.h"
#include "event.h"

#include <QLabel>
#include <QString>


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

    //eventList = new QLabel(this);
    //eventList->setGeometry(0, 0, screenWidth / 2, pageHeight);

    setDate(QDate::currentDate());
}

void DayView::setDate(QDate date)
{
    dayLabel->setDayPixmap(date.daysInMonth());
    dayLabel->setCurrentRotation((date.day() - 1) * 11.612903226);
}

void DayView::slotDateChanged(QDateTime dateTime)
{
    Event* e = new Event;
    std::multiset<Event*, Cmp_event_set>::iterator it;
    Event_set& set = this->getEventSet();
    std::multiset<Event *, Cmp_event_set>* daySet;
    //QListWidget* listWidget = new QListWidget(this);

    e->setStartTime(dateTime.toTime_t());
    daySet = set.getDay(e);

    listWidget.setGeometry(0, 115, this->width(), this->height());
    listWidget.clear();
    listWidget.setPalette(Qt::black);
    listWidget.setMaximumWidth(235);

    if(daySet->size()==0) {
        new QListWidgetItem(tr("No Appt. Today"), &listWidget);
    } else {
        for (it=daySet->begin(); it!=daySet->end(); it++) {
            new QListWidgetItem(QString::number((*it)->getHour()).append\
                                (":").append(QString::number((*it)->getMinute())).append\
                                (" ").append(((*it)->getName())), &listWidget);
        }
    }

    listWidget.show();
    delete(e);
}
