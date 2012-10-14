#include "dayview.h"

#include <QLabel>

DayView::DayView(QRect &pageGeometry, QWidget *parent) :
    RotaryView(pageGeometry, parent)
{
    int pageHeight = geometry().height();
    int screenWidth = geometry().width();
    QPixmap pixmap(tr(":/images/blank_circle.png"));
    dayLabel = new DayLabel(pixmap.scaled(pageHeight, pageHeight), this);
    dayLabel->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);
}
