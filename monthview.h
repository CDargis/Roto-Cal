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
    explicit MonthView(QRect& pageGeometry, Event_map& map, QWidget *parent);
    void setDate(QDate date);
    MonthLabel* monthLabel;
signals:
    
public slots:
    
};

#endif // MONTHVIEW_H
