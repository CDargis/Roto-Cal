#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include "calendarlabel.h"

class CalendarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarWidget(QWidget *parent = 0);
    ~CalendarWidget();
signals:
    
public slots:

private:
    CalendarLabel* cLabel;
};

#endif // CALENDARWIDGET_H
