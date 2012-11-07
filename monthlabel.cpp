#include "monthlabel.h"
#include <QDebug>

const QString MonthLabel::months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
                                    "OCT", "NOV", "DEC"};

MonthLabel::MonthLabel(QPixmap pixmap, QWidget *parent) : RotatableLabel(parent)
{
    QPixmap paintedPixmap = paintMonthsOnPixmap(pixmap);
    originalPixmap = paintedPixmap;
    setPixmap(originalPixmap);
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
    setPixmap(originalPixmap); 
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMovedFromParent()));
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

void MonthLabel::slotGrabMouseMove()
{
    int cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    qDebug() << cRotation ;
    if((cRotation < 5)) emit monthChanged(1);
    else if((cRotation > 25) && (cRotation < 35)) emit monthChanged(2);
    else if((cRotation > 55) && (cRotation < 65)) emit monthChanged(3);
    else if((cRotation > 85) && (cRotation < 95)) emit monthChanged(4);
    else if((cRotation > 115) && (cRotation < 125)) emit monthChanged(5);
    else if((cRotation > 145) && (cRotation < 155)) emit monthChanged(6);
    else if((cRotation > 175) && (cRotation < 185)) emit monthChanged(7);
    else if((cRotation > 205) && (cRotation < 215)) emit monthChanged(8);
    else if((cRotation > 235) && (cRotation < 245)) emit monthChanged(9);
    else if((cRotation > 265) && (cRotation < 275)) emit monthChanged(10);
    else if((cRotation > 295) && (cRotation < 315)) emit monthChanged(11);
    else if((cRotation > 325) && (cRotation < 335)) emit monthChanged(12);
    else if((cRotation > 355)) emit monthChanged(1);   // Rolling around back to january
}
