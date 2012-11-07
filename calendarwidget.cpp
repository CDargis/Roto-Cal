#include "calendarwidget.h"
#include <QStackedWidget>

CalendarWidget::CalendarWidget(QRect screenRes, Event_set &set, QWidget *parent) :
    QWidget(parent), CalObject(set), screen(screenRes)
{
    int menuHeight = screen.width() * .15;
    int screenHeight = screen.height();
    int screenWidth = screen.width();

    menu = new CalendarMenu(0, 0 , screenWidth, menuHeight, this);
    int dateDisplayHeight = screen.height() * .05;

    dateDisplay = new DateDisplay(0, menuHeight, screenWidth, dateDisplayHeight, set, this);
    int pageHeight = screenHeight - menuHeight - dateDisplayHeight;
    int pageOffset = menuHeight + dateDisplayHeight;

    QRect pageGeometry(0, pageOffset, screenWidth, pageHeight);
    rotaryViews = new QStackedWidget(this);
    rotaryViews->setGeometry(pageGeometry);

    monthView = new MonthView(pageGeometry, set, this);
    monthView->setDate(QDate::currentDate());
    rotaryViews->addWidget(monthView);

    dayView = new DayView(pageGeometry, set, this);
    //dayView->setDate(QDate::currentDate());
    rotaryViews->addWidget(dayView);

    detailView = new DetailView(pageGeometry, set, this);
    //detailView->setDate(QDate::currentDate());
    rotaryViews->addWidget(detailView);

    toDoView = new ToDoView(pageGeometry, set, this);
    rotaryViews->addWidget(toDoView);

    connect(menu, SIGNAL(labelClicked(int)), this, SLOT(slotLabelClicked(int)));
    connect(monthView->monthLabel, SIGNAL(yearChanged(int)), dateDisplay, SLOT(slotyearChanged(int)));
    connect(monthView->monthLabel, SIGNAL(monthChanged(int)), dateDisplay, SLOT(slotMonthChanged(int)));
    connect(dayView->dayLabel, SIGNAL(dayChanged(int)), dateDisplay, SLOT(slotdayChanged(int)));
    connect(dateDisplay, SIGNAL(dateChanged(QDate)), monthView, SLOT(slotDateChanged(QDate)));
    connect(dateDisplay, SIGNAL(dateChanged(QDate)), dayView, SLOT(slotDateChanged(QDate)));
    rotaryViews->setCurrentIndex(1);
}

void CalendarWidget::slotLabelClicked(int index)
{
    switch(index) {
        case 0: monthView->setDate(this->getCurrentDate()); break;
        case 1: dayView->setDate(this->getCurrentDate()); break;
        case 2: break;
        case 3: break;
        default: break;
    }
    rotaryViews->setCurrentIndex(index);
}

QDate CalendarWidget::getCurrentDate()
{
    return dateDisplay->getDate();
}

QDateTime CalendarWidget::getCurrentDateTime()
{
    return dateDisplay->getDateTime();
}
