#include "calendarmenu.h"

CalendarMenu::CalendarMenu(int xOffset, int yOffset, int menuWidth, int menuHeight, QWidget *parent)
    : QWidget(parent)
{
    this->menuWidth = menuWidth;
    this->menuHeight = menuHeight;
    labelWidth = menuWidth / 4;

    setGeometry(xOffset, yOffset, menuWidth, menuHeight);

    monthLabel = new ClickableLabel("Month", this);
    dayLabel = new ClickableLabel("Day", this);
    listLabel = new ClickableLabel("Event\nDetails", this);
    toDoLabel = new ClickableLabel("To-Do", this);

    connect(monthLabel, SIGNAL(clicked()), this, SLOT(slotMonthLabelClicked()));
    connect(dayLabel, SIGNAL(clicked()), this, SLOT(slotDayLabelClicked()));
    connect(listLabel, SIGNAL(clicked()), this, SLOT(slotListLabelClicked()));
    connect(toDoLabel, SIGNAL(clicked()), this, SLOT(slotToDoLabelClicked()));

    monthLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    monthLabel->setGeometry(0, 0, labelWidth, menuHeight);
    monthLabel->setSelectStyleSheet(true);
    monthLabel->setAlignment(Qt::AlignCenter);

    dayLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dayLabel->setGeometry(labelWidth, 0, labelWidth, menuHeight);
    dayLabel->setSelectStyleSheet(false);
    dayLabel->setAlignment(Qt::AlignCenter);

    listLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    listLabel->setGeometry(labelWidth*2, 0, labelWidth, menuHeight);
    listLabel->setSelectStyleSheet(false);
    listLabel->setAlignment(Qt::AlignCenter);

    toDoLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    toDoLabel->setGeometry(labelWidth*3, 0, labelWidth, menuHeight);
    toDoLabel->setSelectStyleSheet(false);
    toDoLabel->setAlignment(Qt::AlignCenter);
}

void CalendarMenu::slotMonthLabelClicked()
{
    monthLabel->setSelectStyleSheet(true);
    dayLabel->setSelectStyleSheet(false);
    listLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit labelClicked(0);
}

void CalendarMenu::slotDayLabelClicked()
{
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(true);
    listLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit labelClicked(1);
}

void CalendarMenu::slotListLabelClicked()
{
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    listLabel->setSelectStyleSheet(true);
    toDoLabel->setSelectStyleSheet(false);
    emit labelClicked(2);
}

void CalendarMenu::slotToDoLabelClicked()
{
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    listLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(true);
    emit labelClicked(3);
}
