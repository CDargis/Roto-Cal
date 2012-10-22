#include "calendarwidget.h"
#include <QStackedWidget>

CalendarWidget::CalendarWidget(QRect screenRes, QWidget *parent) :
    QWidget(parent), screen(screenRes)
{
    int menuHeight = screen.width() * .15;
    int screenHeight = screen.height();
    int screenWidth = screen.width();

    menu = new CalendarMenu(0, 0 , screenWidth, menuHeight, this);
    int dateDisplayHeight = screen.height() * .05;

    dateDisplay = new DateDisplay(0, menuHeight, screenWidth, dateDisplayHeight ,this);
    int pageHeight = screenHeight - menuHeight - dateDisplayHeight;
    int pageOffset = menuHeight + dateDisplayHeight;

    QRect pageGeometry(0, pageOffset, screenWidth, pageHeight);
    rotaryViews = new QStackedWidget(this);
    rotaryViews->setGeometry(pageGeometry);

    monthView = new MonthView(pageGeometry, this);
    monthView->setDate(QDate::currentDate());
    rotaryViews->addWidget(monthView);

    dayView = new DayView(pageGeometry, this);
    //dayView->setDate(QDate::currentDate());
    rotaryViews->addWidget(dayView);

    detailView = new DetailView(pageGeometry, this);
    //detailView->setDate(QDate::currentDate());
    rotaryViews->addWidget(detailView);

    toDoView = new ToDoView(pageGeometry, this);
    rotaryViews->addWidget(toDoView);

    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(labelClicked(int)), rotaryViews, SLOT(setCurrentIndex(int)));
    connect(monthView->monthLabel, SIGNAL(yearChanged(int)), dateDisplay, SLOT(slotyearChanged(int)));
    connect(monthView->monthLabel, SIGNAL(monthChanged(int)), dateDisplay, SLOT(slotMonthChanged(int)));
    connect(dayView->dayLabel, SIGNAL(dayChanged(int)), dateDisplay, SLOT(slotdayChanged(int)));
}
