#include "datedisplay.h"
#include <QStyle>

// Date Display inherits from QLabel and CalObject
// Initialize parent classes and set the geomtry of the object. Also set the text to the current date
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

// This slot is called when the month is changed via the MonthLabel (Month Wheel)
// Get the current date from the string in the QLabel and determine if the new date
// is valid. If the date is valid and actually changed then emit the dateChanged() signal
// Also, if the date rolled to a new year then emit the yearRolled() signal
void DateDisplay::slotMonthChanged(int month)
{
    bool newYear = false;
    QDate date = QDate::fromString(text());
    QDate originalDate(date);
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

    // Only emit date change if the date actually changed
    if(date != originalDate)
        emit dateChanged(this->getDateTime());
}

// This slot is called when the day is changed via the DayLabel (Day Wheel)
// Get the current fromthe string in the QLabel and determine if the new date
// is valid. If the date is valid and actually changed then emit the dateChanged() signal
void DateDisplay::slotdayChanged(int day)
{
    QDate date = QDate::fromString(text());
    QDate originalDate(date);
    if(day > date.daysInMonth())
        return;
    date.setDate(date.year(), date.month(), day);
    if(date.isValid())
        setText(date.toString());

    // Only emit date change if the date actually changed
    if(date != originalDate)
        emit dateChanged(this->getDateTime());
}

// Return the current date that the string in the QLabel represents
QDate DateDisplay::getDate()
{
    return QDate::fromString(text());
}

// Return the date plus the current time (used for implementation with Event_set data structure)
QDateTime DateDisplay::getDateTime()
{
    return QDateTime(getDate(), QTime::currentTime());
}
