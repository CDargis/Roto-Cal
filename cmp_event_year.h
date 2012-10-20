/**                                                                             
 * \file Cmp_event_year.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#ifndef _cmp_event_year_
#define _cmp_event_year_
#include <ctime>
#include "time_t_read.h"
#include "event.h"
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
