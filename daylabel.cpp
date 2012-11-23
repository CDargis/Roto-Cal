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
    float div = (cRotation / rotationRange) + .5;
    int day = ((int)div) + 1;
    emit dayChanged(day);
}

void DayLabel::setDate(QDate date, Event_set& eventSet)
{
    int totalEvents = eventSet.getNumOfEventsInMonth(date.month(), date.year());
    int daysInMoth = date.daysInMonth();
    float rotationStep = 1.0 / (float)daysInMoth;
    qDebug() << rotationStep;
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    float rot = 0;
    float firstNum = RotatableLabel::scaleRange(eventSet.getNumOfEventsInDay(1, date.month(), date.year()),
                                                0, totalEvents, 125, 255);
    QColor firstColor =  QColor::fromRgb((int)firstNum, 255 - (int)firstNum, 255);
    grad.setColorAt(rot, firstColor);
    rot = rotationStep;
    for(int i = daysInMoth; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInDay(i, date.month(), date.year());
        float scaledNumberOfEvents = RotatableLabel::scaleRange(numEvents, 0, totalEvents, 125, 255);
        grad.setColorAt(rot, QColor::fromRgb((int)scaledNumberOfEvents, 255 - (int)scaledNumberOfEvents , 255));
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
        p.drawText(xPos, yPos + 10, QString::number(i));
        p.translate(xTranslate, yTranslate);
        p.rotate(rotation);
        p.translate(-xTranslate, -yTranslate);
    }

    // Setting the pixmap
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
