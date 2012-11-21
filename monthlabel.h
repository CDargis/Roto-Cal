// @authors Chris Dargis
// @Copyright 2012

#ifndef MONTHLABEL_H
#define MONTHLABEL_H

#include "rotatablelabel.h"
#include "event_set.h"

class MonthLabel : public RotatableLabel
{
    Q_OBJECT
public:
    explicit MonthLabel(QPixmap pixmap,QWidget *parent = 0);
    static QPixmap paintMonthsOnPixmap(QPixmap pixmap);
    void setDate(QDate date, Event_set& eventSet);
    static const QString months[12];
signals:
    void monthChanged(int month);
    void yearChanged(int year);
public slots:
    void slotGrabMouseMove();
protected:
};

#endif // MONTHLABEL_H
