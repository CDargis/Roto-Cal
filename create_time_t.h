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

    //! Military Hour used for time_t (static).
   /*!
   \param int as hour.
   \param bool as am
   \return Military hour converted from Time1
   \sa createTime(Date date, Time1 time)
   */
    static int militaryHour(int hour, bool am);

    //! Create time_t for Event (static).
   /*!
   \param Date argument
   \param a Time1 argument.
   \return time_t created from Date and Time1
   \sa militaryHour(Time1 time)
   */
    static time_t createTime(Date date, Time1 time);

    //! Create time_t for Event (static).
   /*!
   \param int day
   \param int month
   \param int minute
   \param int hour
   \return time_t created from date and time
   \sa militaryHour(Time1 time)
   */
    static time_t createTime(int day, int month, int year, int minute, int hour, bool am);
};

#endif // CREATE_TIME_T_H
