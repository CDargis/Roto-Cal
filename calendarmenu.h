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
    void yearLabelClicked(int pageIndex);
    void monthLabelClicked(int pageIndex);
    void dayLabelClicked(int pageIndex);
    void toDoLabelClicked(int pageIndex);
public slots:
    void slotYearlLabelClicked();
    void slotMonthLabelClicked();
    void slotDayLabelClicked();
    void slotToDoLabelClicked();
private:
    int menuWidth;
    int labelWidth;
    int menuHeight;

    ClickableLabel* yearLabel;
    ClickableLabel* monthLabel;
    ClickableLabel* dayLabel;
    ClickableLabel* toDoLabel;
};

#endif // CALENDARMENU_H
