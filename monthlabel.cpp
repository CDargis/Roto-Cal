#include "monthlabel.h"

const QString MonthLabel::months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
                                    "OCT", "NOV", "DEC"};

MonthLabel::MonthLabel(QPixmap pixmap, QWidget *parent) : RotatableLabel(parent)
{
    QPixmap paintedPixmap = paintMonthsOnPixmap(pixmap);
    originalPixmap = paintedPixmap;
    setPixmap(originalPixmap);
}

QPixmap MonthLabel::paintMonthsOnPixmap(QPixmap pixmap)
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
    for(int i = 0; i < 12; i++)
    {
        p.drawText(xPos, yPos, months[i]);
        p.translate(xTranslate, yTranslate);
        p.rotate(30);
        p.translate(-xTranslate, -yTranslate);
    }
    return labeledMap;
}

void MonthLabel::paintEvent(QPaintEvent *pe)
{
    int currentRotation = getCurrentRotation();
    if(currentRotation < 30) emit monthChanged(1);
    else if(currentRotation < 60) emit monthChanged(2);
    else if(currentRotation < 90) emit monthChanged(3);
    else if(currentRotation < 120) emit monthChanged(4);
    else if(currentRotation < 150) emit monthChanged(5);
    else if(currentRotation < 180) emit monthChanged(6);
    else if(currentRotation < 210) emit monthChanged(7);
    else if(currentRotation < 240) emit monthChanged(8);
    else if(currentRotation < 270) emit monthChanged(9);
    else if(currentRotation < 300) emit monthChanged(10);
    else if(currentRotation < 330) emit monthChanged(11);
    else if(currentRotation < 360) emit monthChanged(12);
    RotatableLabel::paintEvent(pe);
}
