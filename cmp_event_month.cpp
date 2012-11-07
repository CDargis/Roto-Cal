/**                                                                             
 * \file Cmp_event_month.cpp                                                         
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#include "cmp_event_month.h"
#include <ctime>
#include <time.h>

/* compare event year, then month values 
 * returns false if less than comparison object 
 */
bool Cmp_event_month::operator()(Event * t1, Event * t2)            
{                                                                               
    CmpVal = CompareYear(t1, t2);                                              
    if(CmpVal != 0)                                                            
    {                                                                           
        if(CmpVal == -1) {return true;}                                                       

        return false;                                                           
    }                                                                           
                                                                                
    CmpVal = CompareMonth(t1, t2);                                             
    if(CmpVal != 0)                                                            
    {                                                                           
        if(CmpVal == -1) {return true;}                                                       

        return false;                                                           
    }                                                                           
    return true;                                                                
} 

short Cmp_event_month::CompareYear(Event * t1, Event * t2)          
{                                                                               
    if(t1->getYear() < t2->getYear()) {return -1;}                            
    if(t1->getYear() == t2->getYear()) {return 0;}                            
                                                                                
    return -2;                                                                  
}                                                                               
                                                                                
short Cmp_event_month::CompareMonth(Event * t1, Event * t2)         
{                                                                               
    if(t1->getMonth() < t2->getMonth()) {return -1;}                          
                                                                                
    return -2;                                                                  
}                                                                               
                                                                                
