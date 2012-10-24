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
protected:
    QPixmap pixmap28Days;
    QPixmap pixmap29Days;
    QPixmap pixmap30Days;
    QPixmap pixmap31Days;
signals:
    void dayChanged(int day);
public slots:
    void slotGrabMouseMove();
    void slotDateChanged(QDate date);
protected:

};

#endif // DAYLABEL_H
