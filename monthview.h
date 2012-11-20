// @authors Chris Dargis
// @Copyright 2012

#ifndef MONTHVIEW_H
#define MONTHVIEW_H

#include "rotaryview.h"
#include "monthlabel.h"
#include "calobject.h"
#include "event.h"
#include "calendarlistitem.h"

class MonthView : public RotaryView
{
    Q_OBJECT
public:
    explicit MonthView(QRect& pageGeometry, Event_set& set, QWidget *parent);
    MonthLabel* monthLabel;
    bool active;
signals:
    void eventClicked(Event* e);
public slots:
    void setDate(QDate date);
    void slotDateChanged(QDateTime dateTime);
    void slotYearChanged(QDateTime dateTime);
    void slotListItemClicked(QListWidgetItem* item);
private:
    QListWidget* listWidget;
};

#endif // MONTHVIEW_H
