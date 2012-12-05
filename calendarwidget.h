#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMenuBar>

#include "calendarmenu.h"
#include "monthview.h"
#include "dayview.h"
#include "detailview.h"
#include "datedisplay.h"
#include "calobject.h"
#include "event_set.h"
#include "event.h"

/**
 * @brief The CalendarWidget class.
 * This class encapsulates the calendar application
 * @author Chris Dargis
 */
class CalendarWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    /**
     * @brief CalendarWidget constructor for calendar widget object
     * @param screenRes screen resolution
     * @param set reference to Event_set object
     * @param parent a pointer to the objcet's parent
     */
    explicit CalendarWidget(QRect screenRes, Event_set& set, QWidget *parent = 0);
    /**
     * @brief getCurrentDate get the current date of the calendar
     * @return the current date of the calendar
     */
    QDate getCurrentDate();
    /**
     * @brief getCurrentDateTime get the current date and time of the calendar
     * @return the current date of the object plus the time currently running in the OS
     */
    QDateTime getCurrentDateTime();
    /**
     * @brief pokeDateChange function used to refresh the calendar's views after an insert
     */
    void pokeDateChange();
    /**
     * @brief emitEventEditedSignal function used to emit an event edited signal
     * @param e the event to be emited
     */
    void emitEventEditedSignal(Event* e);
    /**
     * @brief setDate used to set the date of the entire view
     * @param date to be set
     */
    void setDate(QDate date);
signals:
    /**
     * @brief editEvent emited when there is an event to be edited
     * @param e a pointer to the event to be edited
     */
    void editEvent(Event* e);
    /**
     * @brief eventEdited emited when an event was edited
     * @param e a pointer to the event that was edited
     */
    void eventEdited(Event* e);
public slots:
    /**
     * @brief slotLabelClicked slot called when a label was clicked
     * @param index label that was clicked
     */
    void slotLabelClicked(int index);
    /**
     * @brief slotEventClicked slot called when an event is clicked
     * @param e a pointer to the event that was clicked
     */
    void slotEventClicked(Event* e);
private:
    QRect screen;
    QStackedWidget* rotaryViews;
    CalendarMenu* menu;
    DateDisplay* dateDisplay;
    QMenuBar* menuBar;

    MonthView* monthView;
    DayView* dayView;
    DetailView* detailView;
};

#endif // CALENDARWIDGET_H
