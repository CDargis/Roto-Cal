// @authors Chris Dargis
// @Copyright 2012

#ifndef CALOBJECT_H
#define CALOBJECT_H

#include <QDate>
#include "event_set.h"

/**
 * @brief The CalObject class.
 * This class is used to encapsulate an object in the calendar application.
 * It encapsulates all data that is shared accross the various objects in the application.
 */
class CalObject
{
public:
    /**
     * @brief CalObject constructor
     * @param set a reference to the Event_set object
     */
    explicit CalObject(Event_set& set);
    /**
     * @brief getEventSet get a reference to the event set
     * @return a referenc to the Event_set object
     */
    virtual Event_set& getEventSet() { return eventSet; }
protected:
    /**
     * @brief eventSet The current event set object
     */
    Event_set& eventSet;
signals:
    /**
     * @brief setScreenIndex Set the current screen index
     * @param index of which screen to be displayed
     */
    void setScreenIndex(int index);
public slots:
    /**
     * @brief setDate set the date of a calendar object
     * @param date to be set
     */
    virtual void setDate(QDate date);
};

#endif // CALOBJECT_H
