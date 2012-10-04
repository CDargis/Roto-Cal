#include "rotatablelabel.h"
#include <QDebug>

RotatableLabel::RotatableLabel(QPixmap pixmap, QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;
    originalPixmap = pixmap;
    setPixmap(originalPixmap);
}

void RotatableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit mouseDown();
}

void RotatableLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseMove();
}

void RotatableLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseUp();
}

void RotatableLabel::slotMouseDown()
{
    startPoint = QWidget::mapFromGlobal(QCursor::pos());
}

void RotatableLabel::slotMouseMoved()
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    double x = point.rx();
    double y = point.ry();
    if(x < startPoint.rx() || y < startPoint.ry()) currentRotation--;
    else currentRotation++;
    startPoint = point;
    update();

    /**
    double numerator = (x*startPoint.rx()) + (y*startPoint.ry());
    double magA = sqrt(x*x + y*y);
    double magB = sqrt(startPoint.rx()*startPoint.rx() + startPoint.ry()*startPoint.ry());
    double demoninator = magA*magB;
    double theta = acos(numerator / demoninator) * (180.00 / PI);

    if(x < startPoint.rx() | y < startPoint.ry()) theta = -theta;

    currentRotation += theta;
    update();
    startPoint = point;

//    qDebug() << "origin: " << startPoint.x() << ", " << startPoint.y() << " current: "
  //           << x << ", " << y << " angle: " << theta;
  */
}

void RotatableLabel::slotMouseUp()
{

}

void RotatableLabel::paintEvent(QPaintEvent *pe)
{
    qDebug() << currentRotation;
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
