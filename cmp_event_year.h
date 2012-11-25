#ifndef _cmp_event_year_
#define _cmp_event_year_
#include <ctime>
#include "time_t_read.h"
#include "event.h"

/**
 * @brief The cmp_event_year class.
 * This class contains comparison functors for years in event_set.
 * @author Jason Moreau
 */

class Cmp_event_year 
{                                                                               
    public:                                                                     
        bool operator()(Event *, Event *);                        
    private:                                                                    
        Time_t_read r1;                                                         
        Time_t_read r2;                                                         
        short CmpVal;                                                          
		short CompareYear(Event *, Event *);                      
};                                                                              
#endif
