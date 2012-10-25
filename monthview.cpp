#include "monthview.h"

MonthView::MonthView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    int pageHeight = geometry().height();
    int screenWidth = geometry().width();
    QPixmap pixmap(tr(":/images/blank_circle.png"));
    monthLabel = new MonthLabel(pixmap.scaled(pageHeight, pageHeight), this);
    monthLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);

    /**
    QPixmap rightArrow(tr(":/images/rightArrow.png"));
    QLabel* arrowIndicator = new QLabel(this);
    int scalar = pageHeight * .075;
    rightArrow = rightArrow.scaled(scalar, scalar);
    arrowIndicator->setPixmap(rightArrow);
    arrowIndicator->setGeometry((screenWidth / 2) - rightArrow.width(),
                                (pageHeight / 2) - (rightArrow.height()),
                                rightArrow.width(), rightArrow.height());
    */
}

void MonthView::setDate(QDate date)
{
    int month = date.month();
    switch(month)
    {
        case 1: monthLabel->setCurrentRotation(0); break;
        case 2: monthLabel->setCurrentRotation(30); break;
        case 3: monthLabel->setCurrentRotation(60); break;
        case 4: monthLabel->setCurrentRotation(90); break;
        case 5: monthLabel->setCurrentRotation(120); break;
        case 6: monthLabel->setCurrentRotation(150); break;
        case 7: monthLabel->setCurrentRotation(180); break;
        case 8: monthLabel->setCurrentRotation(210); break;
        case 9: monthLabel->setCurrentRotation(240); break;
        case 10: monthLabel->setCurrentRotation(270); break;
        case 11: monthLabel->setCurrentRotation(300); break;
        case 12: monthLabel->setCurrentRotation(330); break;
        default: monthLabel->setCurrentRotation(0); break;
    }
}
