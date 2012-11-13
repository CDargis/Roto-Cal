#include "dayview.h"
#include "cmp_event_set.h"
#include "event_set.h"
#include "event.h"

#include <QLabel>

DayView::DayView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    /* widget for dayview events */
    listWidget = new QListWidget(this);
    QFont fnt;
    fnt.setPointSize(9);
    listWidget->setFont(fnt);
    listWidget->setPalette(Qt::black);
    listWidget->setSizePolicy (QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    listWidget->setMinimumSize(QSize(235, 800));
    listWidget->setMaximumWidth(235);
    listWidget->setMaximumHeight(1000);
    listWidget->show();

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

    Event_set& set = this->getEventSet();

    std::multiset<Event *, Cmp_event_set>* daySet;

    std::multiset<Event*, Cmp_event_set>::iterator it;

    e->setStartTime(dateTime.toTime_t());
    daySet = set.getDay(e);

    listWidget->clear();

    if(daySet->size()==0) {
        new QListWidgetItem(tr("No Appt. Today"), listWidget);
    } else {
        for (it=daySet->begin(); it!=daySet->end(); it++) {
            new QListWidgetItem(QString::number((*it)->getHour()).append\
                                (":").append(QString::number((*it)->getMinute())).append\
                                (" ").append(((*it)->getName())), listWidget);
        }
    }

    listWidget->updateGeometry();
    delete(e);
}
