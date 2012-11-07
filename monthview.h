// @authors Chris Dargis
// @Copyright 2012

#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include "rotaryview.h"
#include "monthlabel.h"
#include "calobject.h"

class MonthView : public RotaryView
{
    Q_OBJECT
public:
    explicit MonthView(QRect& pageGeometry, Event_set& set, QWidget *parent);
    MonthLabel* monthLabel;
signals:
    
public slots:
    void setDate(QDate date);
    void slotDateChanged(QDate date);
};

#endif // MONTHVIEW_H
