#include "monthview.h"

MonthView::MonthView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    int pageHeight = geometry().height();
    int screenWidth = geometry().width();
    QPixmap pixmap(tr(":/images/blank_circle.png"));
    monthLabel = new MonthLabel(pixmap.scaled(pageHeight, pageHeight), this);
    monthLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);

    QPixmap rightArrow(tr(":/images/rightArrow.png"));
    QLabel* arrowIndicator = new QLabel(this);
    int scalar = pageHeight * .050;
    rightArrow = rightArrow.scaled(scalar, scalar);
    arrowIndicator->setPixmap(rightArrow);
    arrowIndicator->setGeometry((screenWidth / 2) - (rightArrow.width() / 2),
                                (pageHeight / 2) - ((rightArrow.height()) - rightArrow.height() / 8),
                                rightArrow.width(), rightArrow.height());
}

void MonthView::setDate(QDate date)
{
    int month = date.month();
    monthLabel->setCurrentRotation((month - 1) * 30);
}

void MonthView::slotDateChanged(QDate date)
{

}
