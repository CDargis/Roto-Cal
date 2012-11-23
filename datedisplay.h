// @authors Chris Dargis
// @Copyright 2012

#ifndef DATEDISPLAY_H
#define DATEDISPLAY_H

#include <QLabel>

#include "calobject.h"

/**
 * @brief The DateDisplay class.
 * This class represents the current date of the calendar.
 */
class DateDisplay : public QLabel, CalObject
{
    Q_OBJECT
public:
    /**
     * @brief DateDisplay constructor for a date display object
     * @param xOffset the x offset of the display
     * @param yOffset the y offset of the display
     * @param width the width of the display
     * @param height the height of the display
     * @param set a reference to the Event_set object
     * @param parent a pointer to the object's parent
     */
    explicit DateDisplay(int xOffset, int yOffset, int width, int height, Event_set& set, QWidget* parent = 0);
    /**
     * @brief getDate get the current date of the object
     * @return the current date of the calendar
     */
    QDate getDate();
    /**
     * @brief getDateTime get the current date and time of the object
     * @return the current date of the calendar, plus the systems time determined by the OS
     */
    QDateTime getDateTime();
signals:
    /**
     * @brief dateChanged emited when the date is changed
     * @param dateTime a date time object that represents the objects date and time
     */
    void dateChanged(QDateTime dateTime);
    /**
     * @brief yearRolled emited when the year is rolled over to a different year
     * @param newDateDate the new date and time
     */
    void yearRolled(QDateTime newDateTime);
public slots:
    /**
     * @brief slotyearChanged slot is called when the year is changed from outside the display
     * @param year the new year
     */
    void slotyearChanged(int year);
    /**
     * @brief slotMonthChanged slot is called when the month dial is rolled
     * @param month the new month
     */
    void slotMonthChanged(int month);
    /**
     * @brief slotdayChanged the slot is called when the day dial is rolled
     * @param day the new day
     */
    void slotdayChanged(int day);
private:
};

#endif // DATEDISPLAY_H
