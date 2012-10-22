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
    if(cRotation < 30) emit monthChanged(1);
    else if(cRotation < 60) emit monthChanged(2);
    else if(cRotation < 90) emit monthChanged(3);
    else if(cRotation < 120) emit monthChanged(4);
    else if(cRotation < 150) emit monthChanged(5);
    else if(cRotation < 180) emit monthChanged(6);
    else if(cRotation < 210) emit monthChanged(7);
    else if(cRotation < 240) emit monthChanged(8);
    else if(cRotation < 270) emit monthChanged(9);
    else if(cRotation < 300) emit monthChanged(10);
    else if(cRotation < 330) emit monthChanged(11);
    else if(cRotation < 360) emit monthChanged(12);
}
