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
    int daysInMonth = date.daysInMonth();
    double rotationStep = 1.0 / (double)daysInMonth;
    qDebug() << rotationStep;
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    double rot = 0;
    int firstNum = eventSet.getNumOfEventsInDay(1, date.month(), date.year());
    QColor firstColor =  RotatableLabel::getColorFromRange(firstNum, totalEvents);
    grad.setColorAt(rot, firstColor);
    rot = rotationStep;
    for(int i = daysInMonth; i > 1; i--)
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
    QPen wPen(Qt::black);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(16);
    f.setStyleStrategy(QFont::ForceOutline);
    p.setBrush(QBrush(QColor(Qt::white)));
    float rotation = 360.00 / (float)daysInMonth;
    for(int i = 1; i <= daysInMonth; i++)
    {
        QPainterPath path;
        path.addText(xPos, yPos + 10, f, QString::number(i));
        p.drawPath(path);
        p.translate(xTranslate, yTranslate);
        p.rotate(rotation);
        p.translate(-xTranslate, -yTranslate);
    }

    // Setting the pixmap
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
