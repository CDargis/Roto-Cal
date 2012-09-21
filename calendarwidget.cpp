#include "calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent) :
    QWidget(parent)
{
    cLabel = new CalendarLabel(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(cLabel);
}

CalendarWidget::~CalendarWidget()
{
    delete cLabel;
}
