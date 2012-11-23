#ifndef DAYVIEW_H
#define DAYVIEW_H

#include "rotaryview.h"
#include "daylabel.h"
#include "clickablelabel.h"
#include "event.h"

/**
 * @brief The DayView class.
 * This class represents the "Day View" of the calendar.
 * @author Chris Dargis
 * @author Jay Moreau
 */
class DayView : public RotaryView
{
    Q_OBJECT
public:
    /**
     * @brief DayView constructor of the object
     * @param pageGeometry the geometry allowed for the view to use
     * @param set the current Event_set object
     * @param parent a pointer to the objects parent
     */
    explicit DayView(QRect& pageGeometry, Event_set& set, QWidget *parent = 0);
    /**
     * @brief dayLabel a pointer to a DayLabel object that represents the current day
     */
    DayLabel* dayLabel;
    /**
     * @brief active a boolean value representing if the object is currently active (being viewed)
     */
    bool active;
signals:
    /**
     * @brief eventClicked emited when an event is clicked
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
     * @brief slotListItemClicked slot is called when there is a list item clicked in the view
     * @param item a pointer to a QListWidgetItem
     */
    void slotListItemClicked(QListWidgetItem* item);
private:
    QListWidget* listWidget;
};

#endif // DAYVIEW_H
