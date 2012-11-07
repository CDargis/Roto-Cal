/**                                                                             
 * \file Cmp_event_day.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#ifndef _cmp_event_day_
#define _cmp_event_day_
#include <ctime>
#include "time_t_read.h"
#include "event.h"
class Cmp_event_day                                                             
{                                                                               
    public:                                                                     
        bool operator()(Event *, Event *);                        
    private:                                                                    
        Time_t_read r1;                                                         
        Time_t_read r2;                                                         
        short CmpVal;                                                          
        short CompareYear(Event *, Event *);                      
        short CompareMonth(Event *, Event *);                     
        short CompareDay(Event *, Event *);                       
        short CompareHour(Event *, Event *);                       
        short CompareMinute(Event *, Event *);                       
};                                                                              
#endif
