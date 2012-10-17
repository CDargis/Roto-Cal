#include "rotatablelabel.h"

RotatableLabel::RotatableLabel(QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
    currentRotation = 0;

    grabGesture(Qt::SwipeGesture);
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

bool RotatableLabel::event(QEvent *e)
{
    if(e->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(e));
    else return QLabel::event(e);
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

bool RotatableLabel::gestureEvent(QGestureEvent *event)
{
    QMessageBox box;
    box.setText("gesture event");
    box.exec();
    if(QGesture* swipe = event->gesture(Qt::SwipeGesture))
        swipeTriggered(static_cast<QSwipeGesture*>(swipe));
    return true;
}

void RotatableLabel::swipeTriggered(QSwipeGesture *gesture)
{
    currentRotation = 200;
    update();
    qDebug() << "swipe has been triggered yo!";
    QMessageBox box;
    box.setText("swipe has been triggered yo!");
    box.exec();
}

void RotatableLabel::setCurrentRotation(int rotation)
{
    currentRotation = rotation;
    update();
}
