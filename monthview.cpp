#include "monthview.h"

MonthView::MonthView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
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
    monthLabel = new MonthLabel(pixmap.scaled(pageHeight, pageHeight), this);
    monthLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);

    QPixmap rightArrow(tr(":/images/rightArrow.png"));
    QLabel* arrowIndicator = new QLabel(this);
    int scalar = pageHeight * .050;
    rightArrow = rightArrow.scaled(scalar, scalar);
    arrowIndicator->setPixmap(rightArrow);
    arrowIndicator->setGeometry((screenWidth / 2) - (rightArrow.width() / 2),
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 8),
                                rightArrow.width(), rightArrow.height());
}

void MonthView::setDate(QDate date)
{
    int month = date.month();
    monthLabel->setCurrentRotation((month - 1) * 30);
}

void MonthView::slotDateChanged(QDateTime dateTime)
{
    Event* e = new Event;
    Event_set& set = this->getEventSet();
    std::multiset<Event *, Cmp_event_set>* daySet;
    std::multiset<Event*, Cmp_event_set>::iterator it;
    e->setStartTime(dateTime.toTime_t());
    daySet = set.getDay(e);

    listWidget->clear();

    if(daySet->size()==0) {
        new CalendarListItem(NULL, tr("No events"), listWidget);
    } else {
        for (it=daySet->begin(); it!=daySet->end(); it++) {
            new CalendarListItem((*it), QString::number((*it)->getHour()).append\
                                (":").append(QString::number((*it)->getMinute())).append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    }
    listWidget->updateGeometry();
    delete(e);
}

// This slot is called when an item in the QListWidget is clicked
void MonthView::slotListItemClicked(QListWidgetItem* item)
{
    CalendarListItem* cItem = static_cast<CalendarListItem*>(item);
    if(cItem->event != NULL)
        emit eventClicked(cItem->event);
}
