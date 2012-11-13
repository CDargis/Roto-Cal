#ifndef DAYVIEW_H
#define DAYVIEW_H

#include "rotaryview.h"
#include "daylabel.h"
#include "clickablelabel.h"


class DayView : public RotaryView
{
    Q_OBJECT
public:
    explicit DayView(QRect& pageGeometry, Event_set& set, QWidget *parent = 0);
    DayLabel* dayLabel;
signals:
    
public slots:
    void setDate(QDate date);
    void slotDateChanged(QDateTime dateTime);
private:
    QListWidget* listWidget;
};

#endif // DAYVIEW_H
