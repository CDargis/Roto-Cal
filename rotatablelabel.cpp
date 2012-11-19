#include "rotatablelabel.h"

RotatableLabel::RotatableLabel(QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;
    oldRotation = 0;
    mouseIsDown = false;
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
    mouseIsDown = true;
    mouseDownPoint = QWidget::mapFromGlobal(QCursor::pos());
    oldRotation = -currentRotation;
    update();
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
    mouseIsDown = false;
    update();
    // As soon as the mouse is up, start physics

}

void RotatableLabel::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap(originalPixmap);
    QPainter p(this);
    p.translate(pixmap.size().width() / 2, pixmap.size().height() / 2);
    p.rotate(-currentRotation);
    p.translate(-pixmap.size().width() / 2, -pixmap.size().height() / 2);
    p.drawPixmap(0, 0, pixmap);

    QRect r = pixmap.rect();
    if(mouseIsDown)
    {
        p.setPen((QPen(Qt::blue, 5)));
        p.drawEllipse(r.center(), (r.width() / 2) * .999, (r.height() / 2) * .999);
    }
    else
    {
        p.setPen((QPen(Qt::black, 5)));
        p.drawEllipse(r.center(), (r.width() / 2), (r.height() / 2));
    }
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
