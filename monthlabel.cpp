#include "monthlabel.h"
#include <QDebug>

const QString MonthLabel::months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
                                    "OCT", "NOV", "DEC"};

MonthLabel::MonthLabel(QPixmap pixmap, QWidget *parent) : RotatableLabel(parent)
{
    originalPixmap = pixmap;
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

void MonthLabel::slotGrabMouseMove()
{
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    int mod = (int)cRotation % 30;
    if(mod < 5 || mod > 25)
    {
        int month = (int)(round(cRotation / 30));
        setCurrentRotation(month * 30);
        emit monthChanged(month + 1);
    }
}

void MonthLabel::setDate(QDate date, Event_set& eventSet)
{
    int totalEvents = eventSet.getNumOfEventsInYear(date.year());
    //qDebug() << numEvents;

    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    float rot = 0;
    float firstNum = RotatableLabel::scaleRange(eventSet.getNumOfEventsInMonth(1, date.year()),
                                                0, totalEvents, 125, 255);
    QColor firstColor = QColor::fromRgb((int)firstNum, 255 - (int)firstNum, 255);
    grad.setColorAt(rot, firstColor);
    rot = 0.083333333;
    for(int i = 12; i > 1; i--)
    {
        //qDebug() << "month: " << i << " - " << eventSet.getNumOfEventsInMonth(i, date.year());
        float scaledNumberOfEvents = RotatableLabel::scaleRange(eventSet.getNumOfEventsInMonth(i, date.year()),
                                               0, totalEvents, 125, 255);
        //qDebug() << num;
        grad.setColorAt(rot, QColor::fromRgb((int)scaledNumberOfEvents, 255 - (int)scaledNumberOfEvents , 255));
        rot += 0.083333333;
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
    f.setPointSize(18);
    p.setFont(f);
    for(int i = 0; i < 12; i++)
    {
        p.drawText(xPos, yPos + 10, months[i]);
        p.translate(xTranslate, yTranslate);
        p.rotate(30);
        p.translate(-xTranslate, -yTranslate);
    }
    int month = date.month();
    setCurrentRotation((month - 1) * 30);
}
