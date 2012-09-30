#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QLabel>

#include "calendarmenu.h"

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
};

#endif // CALENDARWIDGET_H
