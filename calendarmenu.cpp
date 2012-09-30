#include "calendarmenu.h"

CalendarMenu::CalendarMenu(QRect screenRes, QWidget *parent) :
    QWidget(parent), screen(screenRes)
{
    barWidth = screen.width();
    labelWidth = barWidth / 4;
    labelHeight = screen.height() * .0937;

    yearLabel = new ClickableLabel("Year", this);
    monthLabel = new ClickableLabel("Month", this);
    dayLabel = new ClickableLabel("Day", this);
    toDoLabel = new ClickableLabel("To-Do", this);

    connect(yearLabel, SIGNAL(clicked()), this, SLOT(slotYearlLabelClicked()));
    connect(monthLabel, SIGNAL(clicked()), this, SLOT(slotMonthLabelClicked()));
    connect(dayLabel, SIGNAL(clicked()), this, SLOT(slotDayLabelClicked()));
    connect(toDoLabel, SIGNAL(clicked()), this, SLOT(slotToDoLabelClicked()));

    yearLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    yearLabel->setGeometry(0, 0, labelWidth, labelHeight);
    yearLabel->setSelectStyleSheet(false);
    yearLabel->setAlignment(Qt::AlignCenter);

    monthLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    monthLabel->setGeometry(labelWidth, 0, labelWidth, labelHeight);
    monthLabel->setSelectStyleSheet(false);
    monthLabel->setAlignment(Qt::AlignCenter);

    dayLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dayLabel->setGeometry(labelWidth*2, 0, labelWidth, labelHeight);
    dayLabel->setSelectStyleSheet(false);
    dayLabel->setAlignment(Qt::AlignCenter);

    toDoLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    toDoLabel->setGeometry(labelWidth*3, 0, labelWidth, labelHeight);
    toDoLabel->setSelectStyleSheet(false);
    toDoLabel->setAlignment(Qt::AlignCenter);
}

void CalendarMenu::slotYearlLabelClicked()
{
    yearLabel->setSelectStyleSheet(true);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit yearLabelClicked();
}

void CalendarMenu::slotMonthLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(true);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(false);
    emit monthLabelClicked();
}

void CalendarMenu::slotDayLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(true);
    toDoLabel->setSelectStyleSheet(false);
    emit dayLabelClicked();
}

void CalendarMenu::slotToDoLabelClicked()
{
    yearLabel->setSelectStyleSheet(false);
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    toDoLabel->setSelectStyleSheet(true);
    emit toDoLabelClicked();
}
