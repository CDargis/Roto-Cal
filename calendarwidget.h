#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMenuBar>

#include "calendarmenu.h"
#include "rotaryview.h"
#include "datedisplay.h"

class CalendarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarWidget(QRect screenRes, QWidget *parent = 0);
signals:
    
public slots:

private:
    QRect screen;
    CalendarMenu* menu;
    QMenuBar* menuBar;
    RotaryView* yearView;
    RotaryView* monthView;
    DateDisplay* dateDisplay;
};

#endif // CALENDARWIDGET_H
