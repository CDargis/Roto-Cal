// @authors Chris Dargis
// @Copyright 2012

#ifndef ROTATABLELABEL_H
#define ROTATABLELABEL_H

#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <qmath.h>
#include <QtGui>

class QGestureEvent;
class QSwipeGesture;

class RotatableLabel : public QLabel
{
Q_OBJECT
public:
    static const int PI = 3.14159265;
    explicit RotatableLabel(QWidget *parent = 0);
    void setCurrentRotation(float rotation);
    float getCurrentRotation() { return currentRotation; }
    float getAngle(QPoint point);
signals:
    void mouseDown();
    void mouseMove();
    void mouseUp();
public slots:
    void slotMouseDown();
    void slotMouseMoved();
    void slotMouseUp();
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *pe);
    QPixmap originalPixmap;
private:
    QPoint mouseDownPoint;
    float currentRotation;
    float oldRotation;
    bool mouseIsDown;
};

#endif // ROTATABLELABEL_H
