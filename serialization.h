#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <QFile>
#include <string.h>
#include <QDebug>
#include <set>
#include "event.h"
#include "Event_set.h"

//! Serialization Class.
/*!
Serialization class for serialization and deserialization.
*/
class Serialization
{
public:
    //Static functions
    //! Save events from maps to QFile (static).
   /*!
   \param std::multiset<Event *, Cmp_event_day>  reference argument
   \sa load(Event_map &map)
   */
    static void save(std::multiset<Event *, Cmp_event_day> &events);

    //! Load events to Event_map (static).
   /*!
   \param Event_map reference argument
   \returns true if the load was successful and false if not
   \sa save(std::multiset<Event *, Cmp_event_day> &events)
   */
    static bool load(Event_map &map);
};

#endif // SERIALIZATION_H
