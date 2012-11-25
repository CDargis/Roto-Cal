#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <QFile>
#include <string.h>
#include <QDebug>
#include <set>
#include "event.h"
#include "event_set.h"

/**
 * @brief Serialization class used for serialization and deserialiation of Events
 * @author Gerron Thurman
*/
class Serialization
{
public:
    //Static functions
    //! Save events from sets to QFile (static).
   /*!
   \param std::multiset<Event *, Cmp_event_day>  reference argument
   \sa load(Event_set &set)
   */
    static bool save(std::multiset<Event *, Cmp_event_day> &events);

    //! Load events to Event_set (static).
   /*!
   \param Event_set reference argument
   \returns true if the load was successful and false if not
   \sa save(std::multiset<Event *, Cmp_event_day> &events)
   */
    static bool load(Event_set &set);
};

#endif // SERIALIZATION_H
