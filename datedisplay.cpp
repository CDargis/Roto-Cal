#include "datedisplay.h"

#include <QStyle>

DateDisplay::DateDisplay(int xOffset, int yOffset, int width, int height, QWidget *parent)
    : QLabel(parent)
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

void DateDisplay::slotyearChanged(int year)
{
    QDate date = QDate::fromString(text());
    date.setDate(year, date.month(), date.day());
    setText(date.toString());
}

void DateDisplay::slotMonthChanged(int month)
{
    QDate date = QDate::fromString(text());
    date.setDate(date.year(), month, date.day());
    setText(date.toString());
}

void DateDisplay::slotdayChanged(int day)
{
    QDate date = QDate::fromString(text());
    date.setDate(date.year(), date.month(), day);
    setText(date.toString());
}

/**
QDate DateDisplay::getDate()
{
    return QDate::fromString(text());
}
*/