/**
 * \file time_t_read.h
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#include "time_t_read.h"                                                        
#include <iostream>                                                             
short Time_t_read::getYear (const time_t * t)                                   
{                                                                               
	/* initialize tm struct */
    tm_ptr = localtime(t);                                                      
    /* adjust for year offset */
    return tm_ptr->tm_year + 1900;                                              
}                                                                               
                                                                                
short Time_t_read::getMonth (const time_t * t)                                  
{                                                                               
	/* initialize tm struct */
    tm_ptr = localtime(t);                                                      
    /* adjust for month (starts at 0) */
    return tm_ptr->tm_mon + 1;                                                  
}                                                                               
                                                                                
short Time_t_read::getDay (const time_t * t)                                    
{                                                                               
	/* initialize tm struct */
    tm_ptr = localtime(t);                                                      
    return tm_ptr->tm_mday;                                                     
}                                                                               
                                                                                
short Time_t_read::getHour (const time_t * t)                                   
{                                                                               
	/* initialize tm struct */
    tm_ptr = localtime(t);                                                      
    return tm_ptr->tm_hour;                                                     
}                                                    

short Time_t_read::getMinute (const time_t * t)                                 
{                                                                               
	/* initialize tm struct */
    tm_ptr = localtime(t);                                                      
    return tm_ptr->tm_min;                                                      
}                                                                               
                                                                                
