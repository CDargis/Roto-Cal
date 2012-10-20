/**                                                                             
 * \file Cmp_event_day.cpp                                                           
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#include "cmp_event_day.h"
#include <ctime>
#include <iostream>
#include <time.h>

/* compare event year, month, then day values 
 * returns false if less than comparison object 
 */
bool Cmp_event_day::operator()(Event * t1, Event * t2)            
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

short Cmp_event_day::CompareYear(Event * t1, Event * t2)          
{                                                                               
	if(t1->getYear() < t2->getYear()) {return -1;}                            
	if(t1->getYear() == t2->getYear()) {return 0;}                            

	return -2;                                                                  
}                                                                               

short Cmp_event_day::CompareMonth(Event * t1, Event * t2)         
{                                                                               
	if(t1->getMonth() < t2->getMonth()) {return -1;}                          
	if(t1->getMonth() == t2->getMonth()) {return 0;}                          

	return -2;                                                                  
}                                                                               

short Cmp_event_day::CompareDay(Event * t1, Event * t2)           
{                                                                               
	if(t1->getDay() < t2->getDay()) {return -1;}                              

	return -2;                                                                  
}                       

