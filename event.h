/*
 * event.h
 *
 *  Created on: October 3, 2012
 *      Author: Gerron
 */

#ifndef EVENT_H
#define EVENT_H

#include <QDataStream>
#include <QtCore>
#include <time.h>
#include "time1.h"
#include "date.h"
#include <string>
#include <iostream>


/**
 * @brief Event class which contains name, location, description, startTime, endTime
 * @author Gerron Thurman
*/

class Event
{
private:

    //data members
    QString name;           /**< Name of Event */
    QString location;       /**< Location of Event */
    QString description;    /**< Description of Event */
    time_t startTime;       /**< StartTime(time & date) of Event */
    time_t endTime;         /**< EndTime(time & date) of Event */

public:

    //constructors

    //! Event constructor.
   /*!
   Event's default constructor.
   \sa Event(QString name, QString location, QString description, Date startDate, Time1 startTime, Date endDate, Time1 endTime), ~Event()
   */
    Event();

    //! Event constructor.
   /*!
   \param name a QString argument.
   \param location a QString argument.
   \param description a QString argument
   \param startDate a Date argument.
   \param startTime a Time1 argument.
   \param endDate a Date argument.
   \param endTime a Time1 argument.
   \sa Event(), ~Event()
   */
    Event(QString name, QString location, QString description, Date startDate, Time1 startTime, Date endDate, Time1 endTime);

    //! Event constructor.
   /*!
   \param name a QString argument.
   \param location a QString argument.
   \param description a QString argument
   \param startTime a time_t argument.
   \param endTime a time_t argument.
   \sa Event(), ~Event()
   */
    Event(QString name, QString location, QString description, time_t startTime, time_t endtime);

    //! Event destructor.
   /*!
   Event's destructor.
   \sa Event(QString name, QString location, QString description, Date startDate, Time1 startTime, Date endDate, Time1 endTime), Event()
   */
    ~Event();

    //functions
    //! Display Event.
   /*!
   Displays Event
   */
    void display();

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

    //Getters & Setters
    //! Get Name.
   /*!
   \return Event name
   \sa setName(QString name)
   */
    QString getName() const {
        return name;
    }

    //! Set Name.
   /*!
   \param QString name
   \sa getName(QString name)
   */
    void setName(QString name) {
        this->name = name;
    }

    //! Get Location.
   /*!
   \return Event location
   \sa setLocation(QString Location)
   */
    QString getLocation() const {
        return location;
    }

    //! Set Location.
   /*!
   \param QString location
   \sa getLocation(QString location)
   */
    void setLocation(QString location) {
        this->location = location;
    }

    //! Get Description.
   /*!
   \return Event Description
   \sa setDescription(QString description)
   */
    QString getDescription() const {
        return description;
    }

    //! Set Description.
   /*!
   \param QString description
   \sa getDescription(QString description)
   */
    void setDescription(QString description) {
        this->description = description;
    }

    //! Get Start Time.
   /*!
   \return Event startTime
   \sa setStartTime(QString startTime)
   */
    time_t getStartTime() const {
        return startTime;
    }

    //! Set Start Time.
   /*!
   \param time_t startTime
   \sa getStartTime(time_t startTime)
   */
    void setStartTime(time_t startTime) {
        this->startTime = startTime;
    }

    //! Get End Time.
   /*!
   \return Event endTime
   \sa setEndTime(time_t endTime)
   */
    time_t getEndTime() const {
        return endTime;
    }

    //! Set End Time.
   /*!
   \param time_t endTime
   \sa getEndTime(time_t endTime)
   */
    void setEndTime(time_t endTime) {
        this->endTime = endTime;
    }

    //! Get Month.
   /*!
   \return Event month from time_t
   \sa getDay(),getYear(),getMinute(),getHour()
   */
    int getMonth() const {
        struct tm* time;
        time = localtime(&startTime);
        return time->tm_mon + 1;
    }

    //! Get Day.
   /*!
   \return Event day from time_t
   \sa getMonth(),getYear(),getMinute(),getHour()
   */
    int getDay() const {
        struct tm* time;
        time = localtime(&startTime);
        return time->tm_mday;
    }

    //! Get Year.
   /*!
   \return Event year from time_t
   \sa getDay(),getMonth(),getMinute(),getHour()
   */
    int getYear() const {
        struct tm* time;
        time = localtime(&startTime);
        return time->tm_year + 1900;
    }

    //! Get Minute.
   /*!
   \return Event minute from time_t
   \sa getDay(),getMonth(),getYear(),getHour()
   */
    int getMinute() const {
        struct tm* time;
        time = localtime(&startTime);
        return time->tm_min;
    }

    //! Get hour.
   /*!
   \return Event hour from time_t
   \sa getDay(),getMonth(),getYear(),getMinute()
   */
    int getHour() const {
        struct tm* time;
        time = localtime(&startTime);
        return time->tm_hour;
    }

    //! Get Month as string.
   /*!
   \return Event month as string from time_t
   \sa getDay(),getYear(),getMinute(),getHour()
   */
    QString getMonthString() const {
        struct tm* time;
        time = localtime(&startTime);
        QString month = QString("%1").arg(time->tm_mon + 1, 2, 10, QChar('0')).toUpper();
        return month;
    }

    //! Get Day as string.
   /*!
   \return Event day as string from time_t
   \sa getMonth(),getYear(),getMinute(),getHour()
   */
    QString getDayString() const {
        struct tm* time;
        time = localtime(&startTime);
        QString day = QString("%1").arg(time->tm_mday, 2, 10, QChar('0')).toUpper();
        return day;
    }

    //! Get Minute as string.
   /*!
   \return Event minute as string from time_t
   \sa getDay(),getMonth(),getYear(),getHour()
   */
    QString getMinuteString() const {
        struct tm* time;
        time = localtime(&startTime);
        QString minute = QString("%1").arg(time->tm_min, 2, 10, QChar('0')).toUpper();
        return minute;
    }

    //! Get hour as string.
   /*!
   \return Event hour as string from time_t
   \sa getDay(),getMonth(),getYear(),getMinute()
   */
    QString getHourString() const {
        struct tm* time;
        time = localtime(&startTime);
        QString minute = QString("%1").arg(time->tm_hour, 2, 10, QChar('0')).toUpper();
        return minute;
    }

};

//! Overloading << for serialization.
/*!
\sa &operator>>(QDataStream &in, Event &event)
*/
QDataStream &operator<<(QDataStream &out, const Event &event);

//! Overloading >> for serialization.
/*!
\sa &operator<<(QDataStream &out, const Event &event)
*/
QDataStream &operator>>(QDataStream &in, Event &event);

#endif // EVENT_H
