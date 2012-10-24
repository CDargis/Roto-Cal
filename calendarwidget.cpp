#include "calendarwidget.h"
#include <QStackedWidget>

CalendarWidget::CalendarWidget(QRect screenRes, Event_map &map, QWidget *parent) :
    QWidget(parent), CalObject(map), screen(screenRes)//, eventMap(map)
{
    int menuHeight = screen.width() * .15;
    int screenHeight = screen.height();
    int screenWidth = screen.width();

    menu = new CalendarMenu(0, 0 , screenWidth, menuHeight, this);
    int dateDisplayHeight = screen.height() * .05;

    dateDisplay = new DateDisplay(0, menuHeight, screenWidth, dateDisplayHeight, map, this);
    int pageHeight = screenHeight - menuHeight - dateDisplayHeight;
    int pageOffset = menuHeight + dateDisplayHeight;

    QRect pageGeometry(0, pageOffset, screenWidth, pageHeight);
    rotaryViews = new QStackedWidget(this);
    rotaryViews->setGeometry(pageGeometry);

    monthView = new MonthView(pageGeometry, map, this);
    monthView->setDate(QDate::currentDate());
    rotaryViews->addWidget(monthView);

    dayView = new DayView(pageGeometry, map, this);
    //dayView->setDate(QDate::currentDate());
    rotaryViews->addWidget(dayView);

    detailView = new DetailView(pageGeometry, map, this);
    //detailView->setDate(QDate::currentDate());
    rotaryViews->addWidget(detailView);

    toDoView = new ToDoView(pageGeometry, map, this);
    rotaryViews->addWidget(toDoView);

    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(monthView->monthLabel, SIGNAL(yearChanged(int)), dateDisplay, SLOT(slotyearChanged(int)));
    connect(monthView->monthLabel, SIGNAL(monthChanged(int)), dateDisplay, SLOT(slotMonthChanged(int)));
    connect(dayView->dayLabel, SIGNAL(dayChanged(int)), dateDisplay, SLOT(slotdayChanged(int)));
    connect(dateDisplay, SIGNAL(dateChanged(QDate)), dayView->dayLabel, SLOT(slotDateChanged(QDate)));
}
