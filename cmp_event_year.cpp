/**                                                                             
 * \file Cmp_event_year.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#include "cmp_event_year.h"
#include <ctime>
#include <time.h>

/* compares event object year values.  returns false if 
 * comparison object less than input object
 */
bool Cmp_event_year::operator()(Event * t1, Event * t2) 
{                                                                               
	/* compare events on year */
    if(t1->getYear() < t2->getYear()) {return true;}                            
    return false;                                                                  
}                                                                               
                                                                                
