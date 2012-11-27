#include "daylabel.h"
#include <QDebug>

DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(parent)
{
    originalPixmap = pixmap;
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

void DayLabel::slotGrabMouseMove()
{
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    float mod = fmod(cRotation, rotationRange);
    //qDebug() << rotationRange << " - " << mod;
    if(mod < 2 || mod > 8)
    {
        float day = (cRotation / rotationRange) + .5;
        setCurrentRotation((int)day * rotationRange);
        emit dayChanged((int)day + 1);
    }
}

void DayLabel::setDate(QDate date, Event_set& eventSet)
{
    int totalEvents = eventSet.getNumOfEventsInMonth(date.month(), date.year());
    int daysInMoth = date.daysInMonth();
    double rotationStep = 1.0 / (double)daysInMoth;
    qDebug() << rotationStep;
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    double rot = 0;
    float firstNum = RotatableLabel::scaleRange(eventSet.getNumOfEventsInDay(1, date.month(), date.year()),
                                                0, totalEvents, 125, 255);
    QColor firstColor =  RotatableLabel::getColorFromRange(firstNum, totalEvents);
    grad.setColorAt(rot, firstColor);
    rot = rotationStep;
    for(int i = daysInMoth; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInDay(i, date.month(), date.year());
        QColor col = RotatableLabel::getColorFromRange(numEvents, totalEvents);
        grad.setColorAt(rot, col);
        rot += rotationStep;
    }
    grad.setColorAt(rot, firstColor);
    p.setBrush(grad);
    p.drawEllipse(0, 0, originalPixmap.size().width(), originalPixmap.size().height());

    int xPos = originalPixmap.width() * .04;
    int yPos = originalPixmap.height() / 2;
    int xTranslate = originalPixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::white);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(16);
    p.setFont(f);
    float rotation = 360.00 / (float)daysInMoth;
    for(int i = 1; i <= daysInMoth; i++)
    {
        p.drawText(xPos, yPos, QString::number(i));
        p.translate(xTranslate, yTranslate);
        p.rotate(rotation);
        p.translate(-xTranslate, -yTranslate);
    }

    // Setting the pixmap
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
