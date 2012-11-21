/*!
 * \class Event_set.cpp
 *
 * \brief runtime Event object pointer container class (storage and retrieval)
 *
 * This class is used to insert, delete, and edit object pointers in set
 * containers by year, month, and day.  Also, this class returns sorted set 
 * containers by year, month, day, hour, and minute.
 *
 * \author Jason Moreau
 * \date Oct 2012
 */
#include <iostream>
#include "cmp_event_day.h"                                                      
#include "cmp_event_month.h"                                                    
#include "cmp_event_year.h"                                                     
#include "cmp_event_set.h"
#include "event.h"
#include "create_time_t.h"
#include "event_set.h"

Event_set::~Event_set() {}
/* START INSERT FUNCTIONS */                                                    
bool Event_set::insertEvent(Event * e)
{                                                                               
    if (!insertToYear(e))                                        
        return true;
    insertToMonth(e);                                            
    insertToDay(e);                                              
    return false;
}                                                                               
                                                                                
/* inserts event into year */
bool Event_set::insertToYear(Event * e)
{                                                                               
    /* check if already exists */                                               
    if (findDuplicate(e))                                                       
        return false;                                                           
    year_set.insert(e);                         
    return true;                                                                
}                                                                               
                                                                                
/* inserts event into month set */
bool Event_set::insertToMonth(Event * e)
{                                                                               
    month_set.insert(e);                        
    return true;                                                                
}                                                                               
                                                                                
/* inserts event into day set */
bool Event_set::insertToDay(Event * e)
{                                                                               
    day_set.insert(e);                          
    return true;                                                                
}          
/* END INSERT FUNCTIONS */

/* START DELETE FUNCTIONS */                                                    
bool Event_set::deleteEvent(Event * e)
{                                                                               
    if (!deleteFromYear(e))                                                     
        return false;  // not found                                             
    deleteFromMonth(e);                                                         
    deleteFromDay(e);                                                           
    delete(e);                                                                  
                                                                                
    return true;                                                                
}                                                                               
         
/* deletes event from year map */
bool Event_set::deleteFromYear(Event * e)
{                                                                               
    SetIter lower, upper, it;                                                   
    lower = year_set.lower_bound(e);                                
    upper = year_set.upper_bound(e);                                
                                                                                
    if (lower != year_set.end()) { // check for out of bounds(+)                
        for (it = lower ; it != upper; it++) {                                  
            /* check equality for month, day, hour, min, and title */           
            if ((*it)->getMonth() == e->getMonth() && (*it)->getDay() \
                    == e->getDay() && (*it)->getHour() == e->getHour() && \
                    (*it)->getMinute() == e->getMinute() && \
					(*it)->getName() == e->getName()) {
                year_set.erase(it);                                             
                return true; // once matched and erased (for efficiency)        
            }                                                                   
        }                                                                       
    } else {                                                                    
        return false;                                                           
    }                                                                           
    return false;                                                               
}         

/* deletes event from month map */
bool Event_set::deleteFromMonth(Event * e)
{                                                                               
    SetIter lower = month_set.lower_bound(e);                       
    SetIter upper = month_set.upper_bound(e);                       
    SetIter it;                                                                 
                                                                                
    // check equality for day, hour, min, and title                             
    for (it = lower ; it != upper; it++) {                                      
        if ((*it)->getDay() == e->getDay() && (*it)->getHour() \
                == e->getHour() && (*it)->getMinute() == e->getMinute() \
                && (*it)->getName() == e->getName()) {                   
            month_set.erase(it);                                                
            return true; // once matched and erased (for efficiency)             
        }                                                                       
    }                                                                           
    return false;                                                               
                                                                                
}   

/* deletes event from day set */
bool Event_set::deleteFromDay(Event * e)
{                                                                               
    SetIter lower = day_set.lower_bound(e);                         
    SetIter upper = day_set.upper_bound(e);                         
    SetIter it;                                                                 
                                                                                
    // check equality for hour, min, and title                                  
    for (it = lower ; it != upper; it++) {                                      
        if ((*it)->getHour() == e->getHour() && (*it)->getMinute()\
                == e->getMinute() && (*it)->getName() == e->getName()) { 
            day_set.erase(it);                                                  
            return true; // once matched and erased (for efficiency)              
        }                                                                       
    }                                                                           
    return false;                                                               
}                                                                               

/* deletes year, month, day set containers and objects within */
void Event_set::deleteSets()
{                                                                               
    SetIter it;                                                                 
    /*  delete year event objects, effectively deleting all objects of event    
     *  type stored in sets
     */                                                                         
    for (it = year_set.begin(); it != year_set.end(); it++) {                   
        delete(*it);                                                     
    }                                                                           
    /* delete containers */                                                     
    year_set.clear();                                                           
    month_set.clear();                                                          
    day_set.clear();                                                            
}                                                                               
/* END DELETE FUNCTIONS */ 

/* START GET EVENT SET FUNCTIONS */                                             
/* returns ordered multiset of year containing Event object pointers */
std::multiset<Event *, Cmp_event_set> Event_set::getYear(Event * e)
{
    std::multiset<Event *, Cmp_event_set> sorted_year_set;

    SetIter lower, upper, it;
    lower = year_set.lower_bound(e);                                           
    upper = year_set.upper_bound(e);                                           
                                                                                
	/* iterate from lower to upper bounds to get set of year Event objects */
    for (it = lower; it != upper; it++) {                                       
        sorted_year_set.insert((*it));                                            
    }                                                                           
    return sorted_year_set;
}                                                                               
                                                                                
/* returns ordered multiset of month containing Event object pointer */
std::multiset<Event *, Cmp_event_set> Event_set::getMonth(Event * e)
{
    std::multiset<Event *, Cmp_event_set> sorted_month_set;

    SetIter lower, upper, it;
    lower = month_set.lower_bound(e);                                          
    upper = month_set.upper_bound(e);
                                                                                
	/* iterate from lower to upper bounds to get set of month Event objects */
    for (it = lower; it != upper; it++) {
        sorted_month_set.insert((*it));                                           
    }                                                                           
    return sorted_month_set;
}

/* returns ordered multiset of day Event object pointers */
std::multiset<Event *, Cmp_event_set> Event_set::getDay(Event * e)
{
    std::multiset<Event *, Cmp_event_set> sorted_day_set;

    SetIter lower, upper, it;                                                   
    lower = day_set.lower_bound(e);                                            
    upper = day_set.upper_bound(e);

	/* iterate from lower to upper bounds to get set of day Event objects */
    for (it = lower; it != upper; it++) {
        sorted_day_set.insert((*it));
    }
    return sorted_day_set;
}                     
/* END GET EVENT SET FUNCTIONS */

/* START EDIT FUNCTION */                                                       
/* deletes Event object pointer from year, month, day sets and inserts
 * new object 
 * returns false if object already exists 
 * */
bool Event_set::editEvent(Event * current_e, Event * new_e)
{                                                                               
    /* if same start time / title already exists */                             
    if (findDuplicate(new_e))                                                   
        return true;
    deleteEvent(current_e);                                                     
    insertEvent(new_e);                                                         
    return false;
}                                                                               
                                                                                
/* finds duplicate objects using day set */
bool Event_set::findDuplicate(Event * e)
{                                                                               
    SetIter lower = day_set.lower_bound(e);                         
    SetIter upper = day_set.upper_bound(e);                         
    SetIter it;                                                                 
                                                                                
    // check equality for hour, min, and title                                  
    for (it = lower ; it != upper; it++) {                                      
        if ((*it)->getHour() == e->getHour() && (*it)->getMinute() \
                == e->getMinute() && (*it)->getName() == e->getName()) { 
            return true; // match                                               
        }                                                                       
    }                                                                           
    return false; // no match                                                   
}                       

/*  for debugging purposes */                                                    
short Event_set::getSize()                                                      
{                                                                               
	    return year_set.size();                                                     
}

/* return number of events in year */
int Event_set::getNumOfEventsInYear(int year)
{
    Event tmp;
    Event* tmp_ptr = &tmp;

    time_t startTime;
    Create_time_t t;

    startTime = t.createTime(1,1,year,1,1,true);
    tmp.setStartTime(startTime);

    int result = 0;

    SetIter lower, upper, it;
    lower = year_set.lower_bound(tmp_ptr);
    upper = year_set.upper_bound(tmp_ptr);

    /* iterate from lower to upper bounds to get number year Event objects */
    for (it = lower; it != upper; it++) {
        result++;
    }
    return result;
}

/* returns number of events in month */
int Event_set::getNumOfEventsInMonth(int month, int year)
{
    Event tmp;
    Event* tmp_ptr = &tmp;

    time_t startTime;
    Create_time_t t;

    startTime = t.createTime(1,month,year,1,1,true);
    tmp.setStartTime(startTime);

    int result = 0;

    SetIter lower, upper, it;
    lower = month_set.lower_bound(tmp_ptr);
    upper = month_set.upper_bound(tmp_ptr);

    /* iterate from lower to upper bounds to get number month,
     * year Event objects */
    for (it = lower; it != upper; it++) {
        result++;
    }
    return result;
}

/* returns number of events in day */
int Event_set::getNumOfEventsInDay(int day, int month, int year)
{
    Event tmp;
    Event* tmp_ptr = &tmp;

    time_t startTime;
    Create_time_t t;

    startTime = t.createTime(day,month,year,1,1,true);
    tmp.setStartTime(startTime);

    int result = 0;

    SetIter lower, upper, it;
    lower = day_set.lower_bound(tmp_ptr);
    upper = day_set.upper_bound(tmp_ptr);

    /* iterate from lower to upper bounds to get number day, month,
     * year Event objects */
    for (it = lower; it != upper; it++) {
        result++;
    }
    return result;
}

/* for serialization */
std::multiset<Event *, Cmp_event_day>& Event_set::toSerialize()
{
    return day_set;
}
