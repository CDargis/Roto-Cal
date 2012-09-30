#ifndef CALENDARMENU_H
#define CALENDARMENU_H

#include <QWidget>
#include <QLabel>

#include "clickablelabel.h"

class CalendarMenu : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarMenu(QRect screenRes, QWidget *parent = 0);
signals:
    void yearLabelClicked();
    void monthLabelClicked();
    void dayLabelClicked();
    void toDoLabelClicked();
public slots:
    void slotYearlLabelClicked();
    void slotMonthLabelClicked();
    void slotDayLabelClicked();
    void slotToDoLabelClicked();
private:
    int barWidth;
    int labelWidth;
    int labelHeight;

    QRect screen;
    ClickableLabel* yearLabel;
    ClickableLabel* monthLabel;
    ClickableLabel* dayLabel;
    ClickableLabel* toDoLabel;
};

#endif // CALENDARMENU_H
