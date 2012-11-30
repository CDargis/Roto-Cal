#include "monthview.h"
#include <QDebug>

// Constructor for MonthView Class. Initialize parent class with geometry and acess to
// Event_set object.
MonthView::MonthView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    // Initialize this view as active to false
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

    /* initialize current date (year) */
    currDate.setDate(QDate::currentDate().year(),QDate::currentDate().month(),\
                         QDate::currentDate().day());
    holiday = new Holiday(this);
    holiday->setYear(currDate);

    // Determine height and width of view. Initialize the month pixmap
    // Set the geometry of the DayLabel so that only half of the wheel is displayed
    int pageHeight = geometry().height();
    int screenWidth = geometry().width();
    QPixmap pixmap(tr(":/images/blank_circle.png"));
    monthLabel = new MonthLabel(pixmap.scaled(pageHeight, pageHeight), this);
    monthLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);

    // Setup the right arrow indicator that indicates which day the user is selecting
    QPixmap rightArrow(tr(":/images/rightArrow.png"));
    QLabel* arrowIndicator = new QLabel(this);
    int scalar = pageHeight * .050;
    rightArrow = rightArrow.scaled(scalar, scalar);
    arrowIndicator->setPixmap(rightArrow);
    arrowIndicator->setGeometry((screenWidth / 2) - (rightArrow.width() / 2),
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 3),
                                rightArrow.width(), rightArrow.height());
}

// Forward the setDate function to the label to handle
void MonthView::setDate(QDate date)
{
    monthLabel->setDate(date, this->getEventSet());
}

// This slot is called from the DateDisplay object. It is called when there is a date
// change caused by a wheel rotation. Need to determine which events are to be displayed
// within the time parameters of the current wheel position
void MonthView::slotDateChanged(QDateTime dateTime)
{
    // Return if the view is not currently active
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
    listWidget->setSortingEnabled(true);
    listWidget->sortItems(Qt::AscendingOrder);

    /* check if year rolled over and reinitialize holiday data structs */
    if(currDate.year() != dateTime.date().year()) {
        holiday->setYear(dateTime.date());
        currDate.setDate(dateTime.date().year(),dateTime.date().month(),\
                         dateTime.date().day());
    /* update current date */
    } else {
        currDate.setDate(dateTime.date().year(),dateTime.date().month(),\
                         dateTime.date().day());
    }

    QVector< QList<QString> > monthVector = holiday->getMonthVector();

    QColor foreGround;
    QColor backGround;
    foreGround.setRgb(0, 0, 0); // black
    backGround.setRgb(255, 0, 0); // red

    /* no events, no holidays */
    if(monthSet.size()==0 && monthVector[currDate.month()-1].isEmpty()) {
        CalendarListItem *item = new CalendarListItem(NULL, tr("No events"),\
                                                      listWidget);
        item->setFlags(Qt::ItemIsEnabled);
    /* events and holidays */
    } else if (monthSet.size()!=0 && !monthVector[currDate.month()-1].isEmpty()) {
        for(int i=0; i<monthVector[currDate.month()-1].size(); i++) {
            CalendarListItem * item =\
                    new CalendarListItem(NULL, monthVector[currDate.month()-1].at(i), listWidget);
            item->setFlags(Qt::ItemIsEnabled);
            item->setBackgroundColor(backGround);
            item->setForeground(foreGround);
        }
        for (it=monthSet.begin(); it!=monthSet.end(); it++) {
            new CalendarListItem((*it), (*it)->getDayString().append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    /* events, no holidays */
    } else if (monthSet.size()!=0 && monthVector[currDate.month()-1].isEmpty()) {
        for (it=monthSet.begin(); it!=monthSet.end(); it++) {
            new CalendarListItem((*it), (*it)->getDayString().append\
                                (" ").append(((*it)->getName())), listWidget);
            connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                    this, SLOT(slotListItemClicked(QListWidgetItem*)));
        }
    } else {
        for(int i=0; i<monthVector[currDate.month()-1].size(); i++) {
            CalendarListItem * item =\
                    new CalendarListItem(NULL, monthVector[currDate.month()-1].at(i), listWidget);
            item->setFlags(Qt::ItemIsEnabled);
            item->setBackgroundColor(backGround);
            item->setForeground(foreGround);
        }
    }
    listWidget->updateGeometry();
}

// This slot is called when an item in the QListWidget is clicked
// Need to emit the emitClicked() signal if the pointer is not null
void MonthView::slotListItemClicked(QListWidgetItem* item)
{
    CalendarListItem* cItem = static_cast<CalendarListItem*>(item);
    if(cItem->event != NULL)
        emit eventClicked(cItem->event);
}

// This slot is called when the year changes in result from moving the month wheel
// Need to call the setDate() function to update the gradient on the wheel
void MonthView::slotYearChanged(QDateTime dateTime)
{
    if(active)
        setDate(dateTime.date());
}
