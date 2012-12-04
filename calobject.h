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
     * @author Chris Dargis
     */
    explicit CalObject(Event_set& set);
    /**
     * @brief getEventSet get a reference to the event set
     * @return a referenc to the Event_set object
     */
    Event_set& getEventSet() { return eventSet; }
protected:
    /**
     * @brief eventSet The current event set object
     */
    Event_set& eventSet;
signals:

public slots:
    /**
     * @brief setDate set the date of a calendar object
     * @param date to be set
     */
    virtual void setDate(QDate date) = 0;
};

#endif // CALOBJECT_H
