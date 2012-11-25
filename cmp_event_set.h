#ifndef _cmp_event_set_
#define _cmp_event_set_
#include <ctime>
#include "event.h"

/**
 * @brief The cmp_event_set class.
 * This class contains comparison functors for event sets
 * @author Jason Moreau
 */

class Cmp_event_set
{                                                                               
    public:                                                                                                                   
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

