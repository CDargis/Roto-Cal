/**
 * \file Event_set.h
 *
 * \author Jason Moreau
 * \date Oct 2012
 *
 */

#ifndef _event_set_
#define _event_set_

#include <set>
#include <ctime>
#include "cmp_event_set.h"
#include "cmp_event_year.h"
#include "cmp_event_month.h"
#include "cmp_event_day.h"

class Event_set
{                                                                               
    public:                                                                     
		~Event_set();
		short getSize(); // for debugging purposes
		/** inserts event into year, month, day sets                                    
 		 *  @param e Event object pointer                                                
 		 *  @returns false if already exists 
		 */
        bool insertEvent(Event * e);                                              
		/** deletes event from year, month, day sets                                    
         *  @param e Event object pointer                                                
 		 *  @returns false if Event not found
		 */
        bool deleteEvent(Event * e);                                              
		/** edits event in year, month, day sets
		 *  @param current_e event to be edited
		 *  @param new_e new event to replace edited event
		 *  @returns false if Event with date, time, and title already exists 
		 */
        bool editEvent(Event * current_e, Event * new_e);                                       
		/** delete all sets, and call delete on all event objects
		 */
        void deleteSets();
		/** returns ordered multiset of year containing Event object pointers 
		 *  @param e event object of year to select for
		 *  @returns ordered multiset by year, month, day, hour, and minute
		 */ 
        std::multiset<Event *, Cmp_event_set> * getYear(Event * e);              
		/** returns ordered multiset of month containing Event object pointers 
		 *  @param e event object of year, and month to select for
		 *  @returns ordered multiset by year, month, day, hour, and minute
		 */ 
        std::multiset<Event *, Cmp_event_set> * getMonth(Event * e);             
		/** returns ordered multiset of day containing Event object pointers 
		 *  @param e event object of year, month, and day to select for
		 *  @returns ordered multiset by year, month, day, hour, and minute
		 */ 
        std::multiset<Event *, Cmp_event_set> * getDay(Event * e);                                                                    
    private:                                                                    
		/* general use multiset iterator  */
		typedef std::multiset<Event*>::iterator SetIter;                
        std::multiset<Event *, Cmp_event_set> * ms_ptr;                         
        std::multiset<Event*, Cmp_event_year> year_set;                
        std::multiset<Event*, Cmp_event_month> month_set;              
        std::multiset<Event*, Cmp_event_day> day_set;                  
        std::multiset<Event *, Cmp_event_set> sorted_year_set;                         
        std::multiset<Event *, Cmp_event_set> sorted_month_set;                        
        std::multiset<Event *, Cmp_event_set> sorted_day_set;                          
		/* called in insertion function */
        bool insertToYear(Event *);                                     
        bool insertToMonth(Event *);                                    
        bool insertToDay(Event *);                                      
		/* called in delete function */
        bool deleteFromYear(Event *);                                           
        bool deleteFromMonth(Event *);                                          
        bool deleteFromDay(Event *);                                            
        bool findDuplicate(Event *);                                            
};
#endif
