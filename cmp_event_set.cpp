/**                                                                             
 * \file Cmp_event_set.cpp                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */

#include "cmp_event_set.h"
#include <ctime>
#include <iostream>
#include <time.h>

/* compare year, month, day, hour, and minute of input object to
 * comparison object.  return false if less than
 */
bool Cmp_event_set::operator()(Event * t1, Event * t2)            
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

	CmpVal = CompareDay(t1, t2);                                               
	if(CmpVal != 0)                                                            
	{                                                                           
		if(CmpVal == -1) {return true;}                                                       

		return false;                                                           
	}                                                                           
	return false;                                                                
} 

short Cmp_event_set::CompareYear(Event * t1, Event * t2)          
{                                                                               
	if(t1->getYear() < t2->getYear()) {return -1;}                            
	if(t1->getYear() == t2->getYear()) {return 0;}                            

	return -2;                                                                  
}                                                                               

short Cmp_event_set::CompareMonth(Event * t1, Event * t2)         
{                                                                               
	if(t1->getMonth() < t2->getMonth()) {return -1;}                          
	if(t1->getMonth() == t2->getMonth()) {return 0;}                          

	return -2;                                                                  
}                                                                               

short Cmp_event_set::CompareDay(Event * t1, Event * t2)           
{                                                                                
	if(t1->getDay() < t2->getDay()) {return -1;}                              
	if(t1->getDay() == t2->getDay()) {return 0;}                          

	return -2;                                                                  
}                       

short Cmp_event_set::CompareHour(Event * t1, Event * t2)           
{                                                                               
	if(t1->getHour() < t2->getHour()) {return -1;}                              
	if(t1->getHour() == t2->getHour()) {return 0;}                          

	return -2;                                                                  
}                       

short Cmp_event_set::CompareMinute(Event * t1, Event * t2)           
{                                                                               
	if(t1->getMinute() < t2->getMinute()) {return -1;}                              

	return -2;                                                                  
}                       

