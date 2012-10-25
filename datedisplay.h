// @authors Chris Dargis
// @Copyright 2012

#ifndef DATEDISPLAY_H
#define DATEDISPLAY_H

#include <QLabel>

#include "calobject.h"

class DateDisplay : public QLabel, CalObject
{
    Q_OBJECT
public:
    explicit DateDisplay(int xOffset, int yOffset, int width, int height, Event_set& set,QWidget* parent = 0);
    QDate getDate();
    QDateTime getDateTime();
signals:
    void dateChanged(QDate date);
public slots:
    void slotyearChanged(int year);
    void slotMonthChanged(int month);
    void slotdayChanged(int day);
private:
};

#endif // DATEDISPLAY_H
