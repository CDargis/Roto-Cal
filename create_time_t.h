#ifndef CREATE_TIME_T_H
#define CREATE_TIME_T_H

#include "time1.h"
#include "date.h"

class Create_time_t
{
public:
    //static functions
    //! Military Hour used for time_t (static).
   /*!
   \param a Time1 argument.
   \return Military hour converted from Time1
   \sa createTime(Date date, Time1 time)
   */
    static int militaryHour(Time1 time);

    //! Create time_t for Event (static).
   /*!
   \param Date argument
   \param a Time1 argument.
   \return time_t created from Date and Time1
   \sa militaryHour(Time1 time)
   */
    static time_t createTime(Date date, Time1 time);
};

#endif // CREATE_TIME_T_H
