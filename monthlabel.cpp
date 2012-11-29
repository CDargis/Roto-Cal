#include "monthlabel.h"
#include <QDebug>

const QString MonthLabel::months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
                                    "OCT", "NOV", "DEC"};

MonthLabel::MonthLabel(QPixmap pixmap, QWidget *parent) : RotatableLabel(pixmap, parent)
{
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
    QPixmap originalPixmap(*(this->pixmap()));
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    float rot = 0;
    int firstNum = eventSet.getNumOfEventsInMonth(1, date.year());
    QColor firstColor = RotatableLabel::getColorFromRange(firstNum, totalEvents);
    grad.setColorAt(rot, firstColor);
    rot = 0.083333333;
    for(int i = 12; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInMonth(i, date.year());
        QColor col = RotatableLabel::getColorFromRange(numEvents, totalEvents);
        grad.setColorAt(rot, col);
        rot += 0.083333333;
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
    f.setPointSize(18);
    f.setStyleStrategy(QFont::ForceOutline);
    p.setBrush(QBrush(QColor(Qt::white)));
    for(int i = 0; i < 12; i++)
    {
        QPainterPath path;
        path.addText(xPos, yPos + 10, f, months[i]);
        p.drawPath(path);
        p.translate(xTranslate, yTranslate);
        p.rotate(30);
        p.translate(-xTranslate, -yTranslate);
    }
    this->setPixmap(originalPixmap);
    int month = date.month();
    setCurrentRotation((month - 1) * 30);
}
