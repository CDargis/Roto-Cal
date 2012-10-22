#include "rotatablelabel.h"

RotatableLabel::RotatableLabel(QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;
}

void RotatableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit mouseDown();
    QLabel::mousePressEvent(ev);
}

void RotatableLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseMove();
    QLabel::mousePressEvent(ev);
}

void RotatableLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseUp();
    QLabel::mouseReleaseEvent(ev);
}

void RotatableLabel::slotMouseDown()
{
    startPoint = QWidget::mapFromGlobal(QCursor::pos());
}

void RotatableLabel::slotMouseMoved()
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    double y = point.ry();
    if(y < startPoint.ry()) currentRotation -= 2;
    else currentRotation += 2;
    currentRotation %= 360;
    startPoint = point;
    update();
}

void RotatableLabel::slotMouseUp()
{
    startPoint = QPoint(0,0);
}

void RotatableLabel::paintEvent(QPaintEvent *pe)
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

void RotatableLabel::setCurrentRotation(int rotation)
{
    currentRotation = rotation;
    update();
}
