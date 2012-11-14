// @authors Chris Dargis
// @Copyright 2012

#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMenuBar>

#include "calendarmenu.h"
#include "monthview.h"
#include "dayview.h"
#include "detailview.h"
#include "datedisplay.h"
#include "calobject.h"
#include "event_set.h"

class CalendarWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    explicit CalendarWidget(QRect screenRes, Event_set& set, QWidget *parent = 0);
    QDate getCurrentDate();
    QDateTime getCurrentDateTime();
    void pokeDateChange();
signals:

public slots:
    void slotLabelClicked(int index);
    void slotEventClicked(Event* e);
private:
    QRect screen;
    QStackedWidget* rotaryViews;
    CalendarMenu* menu;
    DateDisplay* dateDisplay;
    QMenuBar* menuBar;

    MonthView* monthView;
    DayView* dayView;
    DetailView* detailView;
};

#endif // CALENDARWIDGET_H
