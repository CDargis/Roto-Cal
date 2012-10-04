#include "calendarwidget.h"
#include <QStackedWidget>

CalendarWidget::CalendarWidget(QRect screenRes, QWidget *parent) :
    QWidget(parent), screen(screenRes)
{
    int menuHeight = screen.width() * .15;
    int screenHeight = screen.height();
    int screenWidth = screen.width();

    menu = new CalendarMenu(0, 0 , screenWidth, menuHeight, this);
    int dateDisplayHeight = screen.height() * .05;

    dateDisplay = new DateDisplay(0, menuHeight, screenWidth, dateDisplayHeight ,this);
    int pageHeight = screenHeight - menuHeight - dateDisplayHeight;
    int pageOffset = menuHeight + dateDisplayHeight;

    QStackedWidget* stackedWidget = new QStackedWidget(this);
    stackedWidget->setGeometry(0, pageOffset, screenWidth, pageHeight);

    yearView = new
       RotaryView(tr(":/images/preAlpha.png"), pageHeight, screenWidth, this);
    stackedWidget->addWidget(yearView);

    monthView = new
            RotaryView(tr(":/images/dial.png"), pageHeight, screenWidth, this);
    stackedWidget->addWidget(monthView);

    QLabel* lab1 = new QLabel(tr("Day View Here..."), this);
    stackedWidget->addWidget(lab1);

    QLabel* lab2 = new QLabel(tr("ToDo List Here..."), this);
    stackedWidget->addWidget(lab2);

    connect(menu, SIGNAL(yearLabelClicked(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(monthLabelClicked(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(dayLabelClicked(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(menu, SIGNAL(toDoLabelClicked(int)), stackedWidget, SLOT(setCurrentIndex(int)));
}
