#include "calendarlabel.h"
#include <QDebug>

CalendarLabel::CalendarLabel(QWidget *parent) :
    QLabel(parent)
{
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;
    QPixmap map(":images/dial.png");
    originalPixmap = map;
    setFixedSize(map.width(), map.height());
    //this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setPixmap(map);
}

void CalendarLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseMove();
}

void CalendarLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseUp();
}

void CalendarLabel::slotMouseMoved()
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    double x = (double)(point.rx() - (originalPixmap.width() / 2));
    double y = (double)((originalPixmap.height() / 2) - point.ry());

    double param = (y / x);
    currentRotation = atan(param) * (180 / PI);
    if(x < 0) currentRotation += 180.00;
    qDebug() << "x: " << x << " y: " << y << " rotation: " << currentRotation;
    update();
}

void CalendarLabel::slotMouseUp()
{

}

void CalendarLabel::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap(originalPixmap);
    QPixmap rotatedMap(pixmap.size());
    QPainter p(&rotatedMap);
    p.translate(pixmap.size().width() / 2, pixmap.size().height() / 2);
    p.rotate(-currentRotation);
    p.translate(-pixmap.size().width() / 2, -pixmap.size().height() / 2);
    p.drawPixmap(0, 0, pixmap);
    this->setPixmap(rotatedMap);
    QLabel::paintEvent(pe);
}
