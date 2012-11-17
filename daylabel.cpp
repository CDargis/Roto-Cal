#include "daylabel.h"
#include <QDebug>

DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(parent)
{
    pixmap28Days = paintDaysOnPixmap(28, pixmap);
    pixmap29Days = paintDaysOnPixmap(29, pixmap);
    pixmap30Days = paintDaysOnPixmap(30, pixmap);
    pixmap31Days = paintDaysOnPixmap(31, pixmap);
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

void DayLabel::slotGrabMouseMove()
{
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    float div = (cRotation / rotationRange) + .5;
    int day = ((int)div) + 1;
    emit dayChanged(day);
}

QPixmap DayLabel::paintDaysOnPixmap(int numDays, QPixmap pixmap)
{
    QPixmap labeledMap(pixmap);
    QPainter p(&labeledMap);
    int xPos = pixmap.width() * .035;
    int yPos = pixmap.height() / 2;
    int xTranslate = pixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::white);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(10);
    p.setFont(f);
    float rotation = 360.00 / (float)numDays;
    for(int i = 1; i <= numDays; i++)
    {
        p.drawText(xPos, yPos, QString::number(i));
        p.translate(xTranslate, yTranslate);
        p.rotate(rotation);
        p.translate(-xTranslate, -yTranslate);
    }
    return labeledMap;
}

void DayLabel::setDayPixmap(int days)
{
    if(days == 28)
        originalPixmap = pixmap28Days;
    else if(days == 29)
        originalPixmap = pixmap29Days;
    else if(days == 30)
        originalPixmap = pixmap30Days;
    else if(days == 31)
        originalPixmap = pixmap31Days;
    setPixmap(originalPixmap);
    update();
}

void DayLabel::setDate(QDate date)
{
    setDayPixmap(date.daysInMonth());
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
