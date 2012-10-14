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
#include "listview.h"
#include "todoview.h"
#include "datedisplay.h"
#include "calobject.h"

class CalendarWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    explicit CalendarWidget(QRect screenRes, QWidget *parent = 0);
signals:
    
public slots:

private:
    QRect screen;
    QStackedWidget* rotaryViews;
    CalendarMenu* menu;
    DateDisplay* dateDisplay;
    QMenuBar* menuBar;

    MonthView* monthView;
    DayView* dayView;
    ListView* listView;
    ToDoView* toDoView;
};

#endif // CALENDARWIDGET_H
