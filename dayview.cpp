#include "dayview.h"
#include "cmp_event_set.h"
#include "event_set.h"
#include "event.h"
#include "calendarlistitem.h"

#include <QLabel>

DayView::DayView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    active = false;
    /* widget for dayview events */
    listWidget = new QListWidget(this);
    QFont fnt;
    fnt.setPointSize(8);
    listWidget->setFont(fnt);
    listWidget->setPalette(Qt::black);
    listWidget->setSizePolicy (QSizePolicy(QSizePolicy::Ignored,\
                                           QSizePolicy::Ignored));
    listWidget->setMinimumSize(QSize(235, 700));
    listWidget->setMaximumWidth(235);
    listWidget->setMaximumHeight(800);
    listWidget->show();

    /* set current date */
    currDate.setDate(QDate::currentDate().year(),QDate::currentDate().month(),\
                         QDate::currentDate().day());
    holiday = new Holiday(this);
    holiday->setYear(currDate); // initialize holiday data structures

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
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 3),
                                rightArrow.width(), rightArrow.height());
}

void DayView::setDate(QDate date)
{
    dayLabel->setDate(date, this->getEventSet());
}

void DayView::slotDateChanged(QDateTime dateTime)
{
    if(!active)
        return;
    Event e;
    Event* e_ptr = &e;
    Event_set& set = this->getEventSet();
    std::multiset<Event *, Cmp_event_set> daySet;
    std::multiset<Event*, Cmp_event_set>::iterator it;
    e_ptr->setStartTime(dateTime.toTime_t());
    daySet = set.getDay(e_ptr);

    listWidget->clear();

    /* check if year rolled over and reinitialize holiday data structs */
    if(currDate.year() != dateTime.date().year()) {
        holiday->setYear(dateTime.date());
        currDate.setDate(dateTime.date().year(),dateTime.date().month(),\
                         dateTime.date().day());
    /* same year, just update current date */
    } else {
        currDate.setDate(dateTime.date().year(),dateTime.date().month(),\
                         dateTime.date().day());
    }

    /* get list of holidays for current date */
    QList<QString> list = holiday->hDayLookup(currDate);

    QColor foreGround;
    QColor backGround;
    foreGround.setRgb(0, 0, 0); // black
    backGround.setRgb(255, 0, 0); // red

    /* not events and no nolidays */
    if(daySet.size()==0 && list.isEmpty()) {
        CalendarListItem *item = new CalendarListItem(NULL, tr("No events"),\
                                                      listWidget);
        item->setFlags(Qt::ItemIsEnabled);
    /* events but no holidays */
    } else if (daySet.size()!=0 && list.isEmpty()) {
        for (it=daySet.begin(); it!=daySet.end(); it++) {
            new CalendarListItem((*it), (*it)->getHourString().append\
                                (":").append((*it)->getMinuteString()).append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    /* events and holidays */
    } else if (daySet.size()!=0 && !list.isEmpty()) {
        for (int i=0; i < list.size(); i++) {
            CalendarListItem *item = new CalendarListItem(NULL, list.at(i),\
                                                          listWidget);
            item->setFlags(Qt::ItemIsEnabled);
            item->setBackgroundColor(backGround);
            item->setForeground(foreGround);
        }
        for (it=daySet.begin(); it!=daySet.end(); it++) {
            new CalendarListItem((*it), (*it)->getHourString().append\
                                (":").append((*it)->getMinuteString()).append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    /* no events but holidays */
    } else {
        for (int i=0; i < list.size(); i++) {
            CalendarListItem *item = new CalendarListItem(NULL, list.at(i),\
                                                          listWidget);
            item->setFlags(Qt::ItemIsEnabled);
            item->setBackgroundColor(backGround);
            item->setForeground(foreGround);
        }
    }
    listWidget->updateGeometry();
}

// This slot is called when an item in the QListWidget is clicked
void DayView::slotListItemClicked(QListWidgetItem* item)
{
    CalendarListItem* cItem = static_cast<CalendarListItem*>(item);
    if(cItem->event != NULL)
        emit eventClicked(cItem->event);
}
