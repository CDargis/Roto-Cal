/*
 * event.cpp
 *
 *  Created on: October 3, 2012
 *      Author: Gerron
 */

#include "event.h"

Event::Event()
{

}

Event::Event(QString name, QString location, QString description, Date startDate, Time1 startTime, Date endDate, Time1 endTime)
{
    this->name = name;
    this->location = location;
    this->description = description;
    this->startTime = createTime(startDate, startTime);
    this->endTime = createTime(endDate, endTime);
}

Event::~Event()
{

}


void Event::display(){
    std::string s = ctime(&startTime);
    std::string e = ctime(&endTime);
    s.erase(s.find('\n', 0), 1);
    e.erase(e.find('\n', 0), 1);
    qDebug() << "Name:" << name << "Location:" << location << "Desc:" << description;
    qDebug() << "From:" << QString::fromUtf8(s.data(), s.size()) << "- " << QString::fromUtf8(e.data(), e.size()) << "\n";

}

int Event::militaryHour(Time1 time)
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

time_t Event::createTime(Date date, Time1 time)
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



QDataStream &operator<<(QDataStream &out, const Event &event)
{
    out << event.getName() << event.getLocation() << event.getDescription() << (qint64)event.getStartTime() << (qint64)event.getEndTime();
    return out;
}

QDataStream &operator>>(QDataStream &in, Event &event)
{
    QString name;
    QString location;
    QString description;
    qint64 startTime;
    qint64 endTime;
    in >> name >> location >> description >> startTime >> endTime;
    event.setName(name);
    event.setLocation(location);
    event.setDescription(description);
    event.setStartTime(startTime);
    event.setEndTime(endTime);
    return in;
}

