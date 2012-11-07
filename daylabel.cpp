#include "daylabel.h"
#include <QDebug>

DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(parent)
{
    pixmap28Days = paintDaysOnPixmap(28, pixmap);
    pixmap29Days = paintDaysOnPixmap(29, pixmap);
    pixmap30Days = paintDaysOnPixmap(30, pixmap);
    pixmap31Days = paintDaysOnPixmap(31, pixmap);
    originalPixmap = pixmap31Days;
    setPixmap(originalPixmap);
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

void DayLabel::slotGrabMouseMove()
{
    int cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    float div = (float)cRotation / 11.612903226;
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
    for(int i = 1; i <= numDays; i++)
    {
        p.drawText(xPos, yPos, QString::number(i));
        p.translate(xTranslate, yTranslate);
        p.rotate(11.612903226);
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
