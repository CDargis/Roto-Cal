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
    int xPos = pixmap.width() * .04;
    int yPos = pixmap.height() / 2;
    int xTranslate = pixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::white);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(16);
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
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    int mod = (int)cRotation % 30;
    if(mod < 5 || mod >25)
    {
        int month = (int)(round(cRotation / 30));
        setCurrentRotation(month * 30);
        emit monthChanged(month + 1);
    }
}

void MonthLabel::setDate(QDate date)
{
    int month = date.month();
    setCurrentRotation((month - 1) * 30);
}
