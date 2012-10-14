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
    void setCurrentRotation(int rotation);
    const int& getCurrentRotation() { return currentRotation; }
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
    bool event(QEvent *e);
    QPixmap originalPixmap;
private:
    bool gestureEvent(QGestureEvent* event);
    void swipeTriggered(QSwipeGesture* gesture);

    QPoint startPoint;
    int currentRotation;
};

#endif // ROTATABLELABEL_H
