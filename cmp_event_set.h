/**                                                                             
 * \file Cmp_event_set.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#ifndef _cmp_event_set_
#define _cmp_event_set_
#include <ctime>
#include "event.h"
class Cmp_event_set
{                                                                               
    public:                                                                     
        Cmp_event_set() {};                                                     
        ~Cmp_event_set() {};                                                    
        bool operator()(Event *, Event *);                        
    private:                                                                    
        short CmpVal;                                                          
        short CompareYear(Event *, Event *);                      
        short CompareMonth(Event *, Event *);                     
        short CompareDay(Event *, Event *);                       
        short CompareHour(Event *, Event *);                       
        short CompareMinute(Event *, Event *);                       
};                                                                              
#endif

