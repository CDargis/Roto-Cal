#include "calendarmenu.h"

CalendarMenu::CalendarMenu(int xOffset, int yOffset, int menuWidth, int menuHeight, QWidget *parent)
    : QWidget(parent)
{
    this->menuWidth = menuWidth;
    this->menuHeight = menuHeight;
    labelWidth = menuWidth / 3;

    setGeometry(xOffset, yOffset, menuWidth, menuHeight);

    monthLabel = new SelectableLabel(tr("Month"), this);
    dayLabel = new SelectableLabel(tr("Day"), this);
    detailLabel = new SelectableLabel(tr("Event Details"), this);

    monthLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    monthLabel->setGeometry(0, 0, labelWidth, menuHeight);
    monthLabel->setSelectStyleSheet(false);
    monthLabel->setAlignment(Qt::AlignCenter);

    dayLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    dayLabel->setGeometry(labelWidth, 0, labelWidth, menuHeight);
    dayLabel->setSelectStyleSheet(true);
    dayLabel->setAlignment(Qt::AlignCenter);

    detailLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    detailLabel->setGeometry(labelWidth*2, 0, labelWidth, menuHeight);
    detailLabel->setSelectStyleSheet(false);
    detailLabel->setAlignment(Qt::AlignCenter);

    connect(monthLabel, SIGNAL(clicked()), this, SLOT(slotMonthLabelClicked()));
    connect(dayLabel, SIGNAL(clicked()), this, SLOT(slotDayLabelClicked()));
    connect(detailLabel, SIGNAL(clicked()), this, SLOT(slotDetailLabelClicked()));
}

void CalendarMenu::slotMonthLabelClicked()
{
    monthLabel->setSelectStyleSheet(true);
    dayLabel->setSelectStyleSheet(false);
    detailLabel->setSelectStyleSheet(false);
    emit labelClicked(0);
}

void CalendarMenu::slotDayLabelClicked()
{
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(true);
    detailLabel->setSelectStyleSheet(false);
    emit labelClicked(1);
}

void CalendarMenu::slotDetailLabelClicked()
{
    monthLabel->setSelectStyleSheet(false);
    dayLabel->setSelectStyleSheet(false);
    detailLabel->setSelectStyleSheet(true);
    emit labelClicked(2);
}
