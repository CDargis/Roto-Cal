#include "holiday.h"
#include <QDebug>
#include <QLinkedList>
#include <vector>

Holiday::Holiday(QObject *parent) :
    QObject(parent)
{
}

int Holiday::getMapSize()
{
    return this->dayMap.size();
}

void Holiday::initVector()
{
    QList<QString> list;
    for (int i=0; i<12; i++) {
        this->monthVector << list;
    }
}

void Holiday::setYear(QDate year)
{
    this->monthVector.clear();
    this->dayMap.clear();
    this->initVector();

    this->newYearsDay(year);
    this->mlkDay(year);
    this->presDay(year);
    this->memDay(year);
    this->indepDay(year);
    this->labDay(year);
    this->columDay(year);
    this->vetDay(year);
    this->thanksDay(year);
    this->xmasDay(year);
}

void Holiday::newYearsDay(QDate year)
{
    /* 01-Jan-year */
    this->holidayTitle = "New Year's Day";
    this->holidayDate.setDate(year.year(), 1, 1);
    this->dayMap.insert(holidayDate, holidayTitle);
    /* insert into month vector */
    this->monthVector[0].append(QString("%1").arg(holidayDate.day()).\
                                prepend("0").append(" ").append(holidayTitle));
}

void Holiday::mlkDay(QDate year)
{
    /* 3rd Monday in January */
    int month = 1;
    holidayDate.setDate(year.year(), month, 1);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "MLK Jr. Day";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 15);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 21);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 20);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 19);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 18);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 17);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 16);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[0].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

void Holiday::presDay(QDate year)
{
    /* 3rd Mon in Feb */
    int month = 2;
    holidayDate.setDate(year.year(), month, 1);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "President's Day";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 15);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 21);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 20);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 19);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 18);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 17);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 16);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[1].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

void Holiday::memDay(QDate year)
{
    /* Last Mon in May */
    int month = 5;
    holidayDate.setDate(year.year(), month, 31);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "Memorial Day";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 31);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 30);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 29);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 28);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 27);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 26);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 25);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[4].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

void Holiday::indepDay(QDate year)
{
    /* 04-Jul-year */
    this->holidayTitle = "Indep. Day";
    this->holidayDate.setDate(year.year(), 7, 4);
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[6].append(QString("%1").arg(holidayDate.day()).\
                                prepend("0").append(" ").append(holidayTitle));
}

void Holiday::labDay(QDate year)
{
    /* First Mon in Sept */
    int month = 9;
    holidayDate.setDate(year.year(), month, 1);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "Labor Day";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 1);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 7);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 6);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 5);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 4);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 3);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 2);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[8].append(QString("%1").arg(holidayDate.day()).\
                                prepend("0").append(" ").append(holidayTitle));
}

void Holiday::columDay(QDate year)
{
    /* Second Mon in Oct */
    int month = 10;
    holidayDate.setDate(year.year(), month, 1);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "Columbus Day";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 8);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 14);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 13);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 12);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 11);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 10);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 9);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    if(holidayDate.day() < 10) {
        this->monthVector[9].append(QString("%1").arg(holidayDate.day()).\
                                    prepend("0").append(" ").\
                                    append(holidayTitle));
    } else {
        this->monthVector[9].append(QString("%1").arg(holidayDate.day()).\
                                    append(" ").append(holidayTitle));
    }

}

void Holiday::vetDay(QDate year)
{
    /* 11-nov-year */
    this->holidayTitle = "Veteran's Day";
    this->holidayDate.setDate(year.year(), 11, 11);
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[10].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

void Holiday::thanksDay(QDate year)
{
    /* 4th Thurs in Nov */
    int month = 11;
    holidayDate.setDate(year.year(), month, 1);
    int day = holidayDate.dayOfWeek();

    this->holidayTitle = "Thanksgiving";

    switch(day) {
    case 1: // Monday
        holidayDate.setDate(year.year(), month, 25);
        break;
    case 2: // Tuesday
        holidayDate.setDate(year.year(), month, 24);
        break;
    case 3: // Wednesday
        holidayDate.setDate(year.year(), month, 23);
        break;
    case 4: // Thursday
        holidayDate.setDate(year.year(), month, 22);
        break;
    case 5: // Friday
        holidayDate.setDate(year.year(), month, 28);
        break;
    case 6: // Saturday
        holidayDate.setDate(year.year(), month, 27);
        break;
    default: // Sunday
        holidayDate.setDate(year.year(), month, 26);
        break;
    }
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[10].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

void Holiday::xmasDay(QDate year)
{
    /* 25-Dec-year */
    this->holidayTitle = "Christmas Day";
    this->holidayDate.setDate(year.year(), 12, 25);
    this->dayMap.insert(holidayDate, holidayTitle);
    this->monthVector[11].append(QString("%1").arg(holidayDate.day()).\
                                append(" ").append(holidayTitle));
}

QList<QString> Holiday::hDayLookup(QDate date)
{
    QList<QString> values = this->dayMap.values(date);
    return values;
}

QVector< QList<QString> > Holiday::getMonthVector()
{
    return this->monthVector;
}


