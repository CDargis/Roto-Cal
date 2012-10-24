#ifndef DAYVIEW_H
#define DAYVIEW_H

#include "rotaryview.h"
#include "daylabel.h"

class DayView : public RotaryView
{
    Q_OBJECT
public:
    explicit DayView(QRect& pageGeometry, Event_map& map, QWidget *parent = 0);
    void setDate(QDate date);
    DayLabel* dayLabel;
signals:
    
public slots:
    
};

#endif // DAYVIEW_H
