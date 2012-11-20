// @authors Chris Dargis
// @Copyright 2012

#ifndef DAYLABEL_H
#define DAYLABEL_H

#include "rotatablelabel.h"

class DayLabel : public RotatableLabel
{
    Q_OBJECT
public:
    explicit DayLabel(QPixmap pixmap, QWidget *parent = 0);
    static QPixmap paintDaysOnPixmap(int numDays, QPixmap pixmap);
    void setDayPixmap(int days);
    void setDate(QDate date, Event_set& eventSet);
    float getRotationRange() { return rotationRange; }
protected:
    QPixmap pixmap28Days;
    QPixmap pixmap29Days;
    QPixmap pixmap30Days;
    QPixmap pixmap31Days;
signals:
    void dayChanged(int day);
public slots:
    void slotGrabMouseMove();
protected:
    float rotationRange;

};

#endif // DAYLABEL_H
