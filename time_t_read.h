/**                                                                             
 * \file Time_t_read.h                                                            
 *                                                                              
 * \author Jason Moreau                                                         
 * \date Oct 2012                                                               
 *                                                                              
 */
#ifndef _time_t_read_                                                           
#define _time_t_read_                                                           
                                                                                
#include<ctime>                                                                 
#include<time.h>                                                                
                                                                                
class Time_t_read                                                               
{                                                                               
    public:                                                                     
	    /** gets year from time_t object
         *  @param t time_t pointer                                               
         *  @returns short with 4 digit year                                    
         */
        short getYear(const time_t * t);                                          
	    /** gets month from time_t object
         *  @param t time_t pointer                                               
         *  @returns short with 2 digit month                                   
         */
        short getMonth(const time_t * t);                                         
	    /** gets day from time_t object
         *  @param t time_t pointer                                               
         *  @returns short with 2 digit day                                   
         */
        short getDay(const time_t * t);                                           
	    /** gets hour from time_t object
         *  @param t time_t pointer                                               
         *  @returns short with 2 digit hour                                   
         */
        short getHour(const time_t * t);                                          
	    /** gets minute from time_t object
         *  @param t time_t pointer                                               
         *  @returns short with 2 digit minute
         */
        short getMinute (const time_t * t);                                       
    private:                                                                    
        short year;                                                             
        short month;                                                            
        short day;                                                              
        short hour;                                                             
        struct tm * tm_ptr;                                                     
};                                                                              
#endif
