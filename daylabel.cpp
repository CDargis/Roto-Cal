#include "daylabel.h"

DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(parent)
{
    pixmap28Days = paintDaysOnPixmap(28, pixmap);
    pixmap29Days = paintDaysOnPixmap(29, pixmap);
    pixmap30Days = paintDaysOnPixmap(30, pixmap);
    pixmap31Days = paintDaysOnPixmap(31, pixmap);
    originalPixmap = pixmap31Days;
    setPixmap(originalPixmap);
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
