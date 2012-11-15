#include "create_time_t.h"

int Create_time_t::militaryHour(Time1 time)
{
    int hour = time.getHour();

    if(time.isAm()){
        if(time.getHour() == 12)
        {
            return 0;
        }
        else
        {
            return hour;
        }
    }
    else
    {
        if(hour != 12)
        {
            return hour+12;
        }
    }
    return hour;
}

int Create_time_t::militaryHour(int hour, bool am)
{

    if(am){
        if(hour == 12)
        {
            return 0;
        }
        else
        {
            return hour;
        }
    }
    else
    {
        if(hour != 12)
        {
            return hour+12;
        }
    }
    return hour;
}

time_t Create_time_t::createTime(Date date, Time1 time)
{
        struct tm t;
        time_t raw;
        t.tm_year = (date.getYear())-1900;
        t.tm_mon = date.getMonth()-1;
        t.tm_mday = date.getDay();
        t.tm_hour = militaryHour(time);
        t.tm_min = time.getMinute();
        t.tm_sec = 0;
        t.tm_isdst = -1;
        raw = mktime(&t);
        return raw;
}

time_t Create_time_t::createTime(int day, int month, int year, int minute, int hour, bool am)
{
        struct tm t;
        time_t raw;
        t.tm_year = year-1900;
        t.tm_mon = month-1;
        t.tm_mday = day;
        t.tm_hour = militaryHour(hour, am);
        t.tm_min = minute;
        t.tm_sec = 0;
        t.tm_isdst = -1;
        raw = mktime(&t);
        return raw;
}
