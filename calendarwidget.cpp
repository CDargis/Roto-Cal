#include "calendarwidget.h"
#include <QStackedWidget>

// Constructor for the Calendar Widgit object
// Instantiate parent classes and instance variables in initialization list
CalendarWidget::CalendarWidget(QRect screenRes, Event_set &set, QWidget *parent) :
    QWidget(parent), CalObject(set), screen(screenRes)
{
    // Calculate the dimensions for the menu and screen
    int menuHeight = screen.width() * .15;
    int screenHeight = screen.height();
    int screenWidth = screen.width();

    menu = new CalendarMenu(0, 0 , screenWidth, menuHeight, this);
    int dateDisplayHeight = screen.height() * .05;

    dateDisplay = new DateDisplay(0, menuHeight, screenWidth, dateDisplayHeight, set, this);
    int pageHeight = screenHeight - menuHeight - dateDisplayHeight;
    int pageOffset = menuHeight + dateDisplayHeight;

    // Create the "Rotary Views", set their geometry and add them to the QStackedWidget
    // to handle different "screens"
    QRect pageGeometry(0, pageOffset, screenWidth, pageHeight);
    rotaryViews = new QStackedWidget(this);
    rotaryViews->setGeometry(pageGeometry);
    monthView = new MonthView(pageGeometry, set, this);
    rotaryViews->addWidget(monthView);
    dayView = new DayView(pageGeometry, set, this);
    rotaryViews->addWidget(dayView);
    detailView = new DetailView(pageGeometry, set, this);
    rotaryViews->addWidget(detailView);

    // Connect label click signals to slots to handle those signals
    connect(menu, SIGNAL(labelClicked(int)), this, SLOT(slotLabelClicked(int)));
    // Connect month and day change signals to slots to handle those signals
    connect(monthView->monthLabel, SIGNAL(monthChanged(int)), dateDisplay, SLOT(slotMonthChanged(int)));
    connect(dayView->dayLabel, SIGNAL(dayChanged(int)), dateDisplay, SLOT(slotdayChanged(int)));
    // Connect the dateChanged signal to the slots to handle those signals
    connect(dateDisplay, SIGNAL(dateChanged(QDateTime)), monthView, SLOT(slotDateChanged(QDateTime)));
    connect(dateDisplay, SIGNAL(dateChanged(QDateTime)), dayView, SLOT(slotDateChanged(QDateTime)));
    // Connect the signals to slots that handle the editing and creation of an event
    connect(monthView, SIGNAL(eventClicked(Event*)), this, SLOT(slotEventClicked(Event*)));
    connect(dayView, SIGNAL(eventClicked(Event*)), this, SLOT(slotEventClicked(Event*)));
    connect(detailView, SIGNAL(editEventClicked(Event*)), SIGNAL(editEvent(Event*)));
    connect(this, SIGNAL(eventEdited(Event*)), this, SLOT(slotEventClicked(Event*)));
    connect(dateDisplay, SIGNAL(yearRolled(QDateTime)), monthView, SLOT(slotYearChanged(QDateTime)));

    // Set day view as current view
    dayView->active = true;
    rotaryViews->setCurrentIndex(1);
}

// Handler for label being selected. Need to set instance variables in RotaryView objects
// and set their dates to do the gradient painting. Finally change the view index
void CalendarWidget::slotLabelClicked(int index)
{
    switch(index) {
        case 0:
        {
            dayView->active = false;
            monthView->active = true;
            monthView->setDate(this->getCurrentDate());
            monthView->slotDateChanged(this->getCurrentDateTime());
            break;
        }
        case 1:
        {
            monthView->active = false;
            dayView->active = true;
            dayView->slotDateChanged(this->getCurrentDateTime());
            dayView->setDate(this->getCurrentDate());
            break;
        }
        case 2: break;
        default: break;
    }
    rotaryViews->setCurrentIndex(index);
}

// Return the date from the date display
QDate CalendarWidget::getCurrentDate()
{
    return dateDisplay->getDate();
}

// Return the date and time from the date display
QDateTime CalendarWidget::getCurrentDateTime()
{
    return dateDisplay->getDateTime();
}

// Handler for an event being clicked. Need to preset the detail views input data with
// the information from the event object. Then change the view index to the detail view
void CalendarWidget::slotEventClicked(Event* e)
{
    detailView->setCurrentEvent(e);
    menu->slotDetailLabelClicked();   // Trigger the detail view menu item being clicked
}

// This function is used after a fresh event is inserted into the set by a user via
// the AddEventWidget
void CalendarWidget::pokeDateChange()
{
    QDateTime dt = this->getCurrentDateTime();
    monthView->slotDateChanged(dt);
    monthView->setDate(this->getCurrentDate());
    dayView->slotDateChanged(dt);
    dayView->setDate(this->getCurrentDate());
}

// This is a public function used to "poke" the object in order to emit an eventEdited signal
void CalendarWidget::emitEventEditedSignal(Event *e)
{
    emit eventEdited(e);
}
