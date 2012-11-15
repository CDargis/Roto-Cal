#include "rotatablelabel.h"

RotatableLabel::RotatableLabel(QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;
    oldRotation = 0;
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
    mouseDownPoint = QWidget::mapFromGlobal(QCursor::pos());
    oldRotation = -currentRotation;
}

void RotatableLabel::slotMouseMoved()
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    float currentAngle = this->getAngle(point);
    float originalAngle = this->getAngle(mouseDownPoint);
    currentRotation = currentAngle - originalAngle;
    currentRotation += oldRotation;
    currentRotation = fmod(currentRotation, 360.00);
    currentRotation = -currentRotation;
    update();
}

void RotatableLabel::slotMouseUp()
{
    //mouseDownPoint = QPoint(0, 0);
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

void RotatableLabel::setCurrentRotation(float rotation)
{
    currentRotation = rotation;
    update();
}

float RotatableLabel::getAngle(QPoint point)
{
    float x = (float)(point.rx() - (originalPixmap.width() / 2));
    float y = (float)((originalPixmap.height() / 2) - point.ry());
    return atan2(x, y) * (180 / PI);
}
