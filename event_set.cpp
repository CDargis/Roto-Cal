/*!
 * \class Event_map.cpp
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
#include "event_set.h"

/* START INSERT FUNCTIONS */                                                    
bool Event_map::insertEvent(Event * e)                                          
{                                                                               
    if (!insertToYear(e))                                        
        return false;                                                           
    insertToMonth(e);                                            
    insertToDay(e);                                              
    return true;                                                                
}                                                                               
                                                                                
/* inserts event into year */
bool Event_map::insertToYear(Event * e)                               
{                                                                               
    /* check if already exists */                                               
    if (findDuplicate(e))                                                       
        return false;                                                           
    year_set.insert(e);                         
    return true;                                                                
}                                                                               
                                                                                
/* inserts event into month map */
bool Event_map::insertToMonth(Event * e)                              
{                                                                               
    month_set.insert(e);                        
    return true;                                                                
}                                                                               
                                                                                
/* inserts event into day map */
bool Event_map::insertToDay(Event * e)                              
{                                                                               
    day_set.insert(e);                          
    return true;                                                                
}          
/* END INSERT FUNCTIONS */

/* START DELETE FUNCTIONS */                                                    
bool Event_map::deleteEvent(Event * e)                                          
{                                                                               
    if (!deleteFromYear(e))                                                     
        return false;  // not found                                             
    deleteFromMonth(e);                                                         
    deleteFromDay(e);                                                           
    delete(e);                                                                  
                                                                                
    return true;                                                                
}                                                                               
         
/* deletes event from year map */
bool Event_map::deleteFromYear(Event * e)   
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
bool Event_map::deleteFromMonth(Event * e)                                      
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

/* deletes event from day map */
bool Event_map::deleteFromDay(Event * e)                                        
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

/* deletes year, month, day map containers and objects within */
void Event_map::deleteMaps()                                                     
{                                                                               
    SetIter it;                                                                 
    /*  delete year event objects, effectively deleting all objects of event    
     *  type stored in maps                                                     
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
std::multiset<Event *, Cmp_event_set> * Event_map::getYear(Event * e)          
{                                                                               
    SetIter lower, upper, it;                                                   
    lower = year_set.lower_bound(e);                                           
    upper = year_set.upper_bound(e);                                           
                                                                                
	/* iterate from lower to upper bounds to get set of year Event objects */
    for (it = lower; it != upper; it++) {                                       
        sorted_year_set.insert((*it));                                            
    }                                                                           
    ms_ptr = &sorted_year_set;                                                         
    return ms_ptr;                                                              
}                                                                               
                                                                                
/* returns ordered multiset of month containing Event object pointer */
std::multiset<Event *, Cmp_event_set> * Event_map::getMonth(Event * e)         
{                                                                               
    SetIter lower, upper, it;                                                   
    lower = month_set.lower_bound(e);                                          
    upper = month_set.upper_bound(e);                                          
                                                                                
	/* iterate from lower to upper bounds to get set of month Event objects */
    for (it = lower; it != upper; it++) {                                       
        sorted_month_set.insert((*it));                                           
    }                                                                           
    ms_ptr = &sorted_month_set;                                                        
    return ms_ptr;                                                              
}   

/* returns ordered multiset of day Event object pointers */
std::multiset<Event *, Cmp_event_set> * Event_map::getDay(Event * e)           
{                                                                               
    SetIter lower, upper, it;                                                   
    lower = day_set.lower_bound(e);                                            
    upper = day_set.upper_bound(e);                                            
                                                                                
	/* iterate from lower to upper bounds to get set of day Event objects */
    for (it = lower; it != upper; it++) {                                       
        sorted_day_set.insert((*it));                                             
    }                                                                           
    ms_ptr = &sorted_month_set;                                                          
    return ms_ptr;                                                              
}                     
/* END GET EVENT SET FUNCTIONS */

/* START EDIT FUNCTION */                                                       
/* deletes Event object pointer from year, month, day maps and inserts 
 * new object 
 * returns false if object already exists 
 * */
bool Event_map::editEvent(Event * current_e, Event * new_e)                     
{                                                                               
    /* if same start time / title already exists */                             
    if (findDuplicate(new_e))                                                   
        return false;                                                           
    deleteEvent(current_e);                                                     
    insertEvent(new_e);                                                         
    return true;                                                                
}                                                                               
                                                                                
/* finds duplicate objects using day map */
bool Event_map::findDuplicate(Event * e)                                        
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

/* CODE FOR TESTING PURPOSES BELOW */
void Event_map::printMap()                                                      
{                                                                               
    std::cout << std::endl;                                                     
    printYearMap(year_set);                                                     
    printMonthMap(month_set);                                                   
    printDayMap(day_set);                                                       
}                                                                               
                                                                                
void Event_map::printYearMap(std::multiset<Event *, Cmp_event_year> & m)
{                                                                               
    std::cout << "SIZE = " << m.size() << "  YEAR MAP -------------------------------------" << std::endl;
    for (SetIter itr = m.begin(); itr != m.end(); itr++) {
        std::cout << ctime((*itr)->getDate()) << "--" << (*itr)->getName() << std::endl;
    }                                                                           
    std::cout << std::endl;                                                     
}                                                                               
                                                                                
void Event_map::printMonthMap(std::multiset<Event *, Cmp_event_month> & m)
{                                                                               
    std::cout << "SIZE = " << m.size() << "  MONTH MAP -------------------------------------" << std::endl;
    for (SetIter itr = m.begin(); itr != m.end(); itr++) {
        std::cout << ctime((*itr)->getDate()) << "--" << (*itr)->getName() << std::endl;
    }                                                                           
    std::cout << std::endl;                                                     
}                  

void Event_map::printDayMap(std::multiset<Event *, Cmp_event_day> & m)  
{                                                                               
    std::cout << "SIZE = " << m.size() << "  DAY MAP -------------------------------------" << std::endl;
    for (SetIter itr = m.begin(); itr != m.end(); itr++) {
        std::cout << ctime((*itr)->getDate()) << "--" << (*itr)->getName() << std::endl;
    }                                                                           
}   
/* END TESTING CODE */

