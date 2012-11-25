#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include "rotaryview.h"
#include "monthlabel.h"
#include "calobject.h"
#include "event.h"
#include "calendarlistitem.h"
#include "holiday.h"

/**
 * @brief The MonthView class.
 * The class represents the "Month View" of the calendar
 * @author Chris Dargis
 * @author Jason Moreau
 */
class MonthView : public RotaryView
{
    Q_OBJECT
public:
    /**
     * @brief MonthView constructor for a month view object
     * @param pageGeometry the geometry that the view will use
     * @param set a reference to the Event_set object
     * @param parent a pointer to the object's parent
     */
    explicit MonthView(QRect& pageGeometry, Event_set& set, QWidget *parent);
    /**
     * @brief monthLabel a pointer to the MonthLabel object tha represents the current month
     */
    MonthLabel* monthLabel;
    /**
     * @brief active a boolean value representing if the object is currently active (being viewed)
     */
    bool active;
signals:
    /**
     * @brief eventClicked emited when an event is clicked in the month view
     * @param e a pointer to the event that was clicked
     */
    void eventClicked(Event* e);
public slots:
    /**
     * @brief setDate used to set the date of the entire view
     * @param date to be set
     */
    void setDate(QDate date);
    /**
     * @brief slotDateChanged slot is called whenever the date display emits a date change signal
     * @param dateTime the current date time of the date display
     */
    void slotDateChanged(QDateTime dateTime);
    /**
     * @brief slotYearChanged slot is called whenever the date display emits a year change signal
     * @param dateTime the current date time of the date display
     */
    void slotYearChanged(QDateTime dateTime);
    /**
     * @brief slotListItemClicked slot is called when there is a list item clicked in the view
     * @param item a pointer to a QListWidgetItem
     */
    void slotListItemClicked(QListWidgetItem* item);
private:
    QListWidget* listWidget;
    QDate currDate;
    Holiday* holiday;
};

#endif // MONTHVIEW_H
