#include "monthview.h"

MonthView::MonthView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
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
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 3),
                                rightArrow.width(), rightArrow.height());
}

void MonthView::setDate(QDate date)
{
    monthLabel->setDate(date, this->getEventSet());
}

void MonthView::slotDateChanged(QDateTime dateTime)
{
    if(!active)
        return;
    Event e;
    Event* e_ptr = &e;
    Event_set& set = this->getEventSet();
    std::multiset<Event *, Cmp_event_set> monthSet;
    std::multiset<Event*, Cmp_event_set>::iterator it;
    e_ptr->setStartTime(dateTime.toTime_t());
    monthSet = set.getMonth(e_ptr);

    listWidget->clear();

    if(monthSet.size()==0) {
        CalendarListItem *item = new CalendarListItem(NULL, tr("No events"),\
                                                      listWidget);
        item->setFlags(Qt::ItemIsEnabled);
    } else {
        for (it=monthSet.begin(); it!=monthSet.end(); it++) {
            new CalendarListItem((*it), (*it)->getDayString().append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    }
    listWidget->updateGeometry();
}

// This slot is called when an item in the QListWidget is clicked
void MonthView::slotListItemClicked(QListWidgetItem* item)
{
    CalendarListItem* cItem = static_cast<CalendarListItem*>(item);
    if(cItem->event != NULL)
        emit eventClicked(cItem->event);
}

void MonthView::slotYearChanged(QDateTime dateTime)
{
    if(active)
        setDate(dateTime.date());
}
