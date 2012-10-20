/**                                                                             
 * \file Cmp_event_month.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#ifndef _cmp_event_month_
#define _cmp_event_month_
#include <ctime>
#include "time_t_read.h"
#include "event.h"
class Cmp_event_month
{                                                                               
	public:
        bool operator()(Event *, Event *);                        
    private:                                                                    
        Time_t_read r1;                                                         
        Time_t_read r2;                                                         
        short CmpVal;                                                          
        short CompareYear(Event *, Event *);                      
        short CompareMonth(Event *, Event *);                     
};                                                                              
#endif

