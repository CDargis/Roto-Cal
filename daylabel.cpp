#include "daylabel.h"
#include <QDebug>

DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(parent)
{
    pixmap28Days = paintDaysOnPixmap(28, pixmap);
    pixmap29Days = paintDaysOnPixmap(29, pixmap);
    pixmap30Days = paintDaysOnPixmap(30, pixmap);
    pixmap31Days = paintDaysOnPixmap(31, pixmap);
    setDayPixmap(28);
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
    int xPos = pixmap.width() * .04;
    int yPos = pixmap.height() / 2;
    int xTranslate = pixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::white);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(16);
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
}

void DayLabel::setDate(QDate date, Event_set& eventSet)
{
    int totalEvents = eventSet.getNumOfEventsInMonth(date.month(), date.year());
    int daysInMoth = date.daysInMonth();
    float rotationStep = 1.0 / (float)daysInMoth;
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    float rot = 0;
    for(int i = daysInMoth; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInDay(i, date.month(), date.year());
        float scaledNumberOfEvents = RotatableLabel::scaleRange(numEvents, 0, totalEvents, 125, 255);
        qDebug() << scaledNumberOfEvents << " - " << numEvents;
        grad.setColorAt(rot, QColor::fromRgb((int)scaledNumberOfEvents, 255 - (int)scaledNumberOfEvents , 255));
        rot += rotationStep;
    }
    p.setBrush(grad);
    p.drawEllipse(0, 0, originalPixmap.size().width(), originalPixmap.size().height());

    // Setting the pixmap
    // setDayPixmap(date.daysInMonth());
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
