// @authors Chris Dargis
// @Copyright 2012

#ifndef CALENDARMENU_H
#define CALENDARMENU_H

#include <QWidget>
#include <QLabel>

#include "clickablelabel.h"

class CalendarMenu : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarMenu(int xOffset, int yOffset, int menuWidth, int menuHeight, QWidget *parent = 0);
    const int& getMenuWidth() { return menuWidth; }
    const int& getLabelWidth() { return labelWidth; }
    const int& getMenuHeight() { return menuHeight; }
signals:
    void labelClicked(int pageIndex);
public slots:
    void slotMonthLabelClicked();
    void slotDayLabelClicked();
    void slotListLabelClicked();
    void slotToDoLabelClicked();
private:
    int menuWidth;
    int labelWidth;
    int menuHeight;

    ClickableLabel* monthLabel;
    ClickableLabel* dayLabel;
    ClickableLabel* listLabel;
    ClickableLabel* toDoLabel;
};

#endif // CALENDARMENU_H
