#include "datedisplay.h"

#include <QStyle>

DateDisplay::DateDisplay(int xOffset, int yOffset, int width, int height, Event_set &set, QWidget *parent)
    : QLabel(parent), CalObject(set)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setGeometry(xOffset, yOffset, width, height);
    QDate today = QDate::currentDate();
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QLabel { color: white;"
                  "border: 1px solid white;"
                  "font-size: 24px; }");
    setText(today.toString());
}

// Currently not being used
void DateDisplay::slotyearChanged(int year)
{
    QDate date = QDate::fromString(text());
    date.setDate(year, date.month(), date.day());
    if(date.isValid())
        setText(date.toString());
    emit dateChanged(this->getDateTime());
}

void DateDisplay::slotMonthChanged(int month)
{
    bool newYear = false;
    QDate date = QDate::fromString(text());
    int year = date.year();
    int cMonth = date.month();
    if(month == 1 && cMonth == 12)       // Going from december to january
        { year++; newYear = true; }
    if(month == 12 && cMonth == 1)       // Going from january to december
        { year--; newYear = true; }
    date.setDate(year, month, date.day());
    if(date.isValid())
        setText(date.toString());
    if(newYear)
        emit yearRolled(this->getDateTime());  // Emit signal that year changed
    emit dateChanged(this->getDateTime());
}

void DateDisplay::slotdayChanged(int day)
{
    QDate date = QDate::fromString(text());
    if(day > date.daysInMonth())
        return;
    date.setDate(date.year(), date.month(), day);
    if(date.isValid())
        setText(date.toString());
    emit dateChanged(this->getDateTime());
}

QDate DateDisplay::getDate()
{
    return QDate::fromString(text());
}

QDateTime DateDisplay::getDateTime()
{
    return QDateTime(getDate(), QTime::currentTime());
}
