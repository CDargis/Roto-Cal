#include "calendarmenu.h"

CalendarMenu::CalendarMenu(int xOffset, int yOffset, int menuWidth, int menuHeight, QWidget *parent)
    : QWidget(parent)
{
    this->menuWidth = menuWidth;
    this->menuHeight = menuHeight;
    labelWidth = menuWidth / 4;

    setGeometry(xOffset, yOffset, menuWidth, menuHeight);

    yearLabel = new ClickableLabel("Year", this);
    monthLabel = new ClickableLabel("Month", this);
    dayLabel = new ClickableLabel("Day", this);
    toDoLabel = new ClickableLabel("To-Do", this);

    connect(yearLabel, SIGNAL(clicked()), this, SLOT(slotYearlLabelClicked()));
    connect(monthLabel, SIGNAL(clicked()), this, SLOT(slotMonthLabelClicked()));
    connect(dayLabel, SIGNAL(clicked()), this, SLOT(slotDayLabelClicked()));
    connect(toDoLabel, SIGNAL(clicked()), this, SLOT(slotToDoLabelClicked()));

    yearLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    yearLabel->setGeometry(0, 0, labelWidth, menuHeight);
    yearLabel->setSelectStyleSheet(true);
    yearLabel->setAlignment(Qt::AlignCenter);

    monthLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    monthLabel->setGeometry(labelWidth, 0, labelWidth, menuHeight);
    monthLabel->setSelectStyleSheet(false);
    monthLabel->setAlignment(Qt::AlignCenter);

    dayLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dayLabel->setGeometry(labelWidth*2, 0, labelWidth, menuHeight);
    dayLabel->setSelectStyleSheet(false);
    dayLabel->setAlignment(Qt::AlignCenter);

    toDoLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    toDoLabel->setGeometry(labelWidth*3, 0, labelWidth, menuHeight);
    toDoLabel->setSelectStyleSheet(false);
    toDoLabel->setAlignment(Qt::AlignCenter);
}

void CalendarMenu::slotYearlLabelClicked()
{
    yearLabel->setSelectStyleSheet(true);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit yearLabelClicked(0);
}

void CalendarMenu::slotMonthLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(true);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit monthLabelClicked(1);
}

void CalendarMenu::slotDayLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(true);
    toDoLabel->setSelectStyleSheet(false);
    emit dayLabelClicked(2);
}

void CalendarMenu::slotToDoLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(true);
    emit toDoLabelClicked(3);
}
