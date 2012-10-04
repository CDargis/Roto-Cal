#ifndef ROTATABLELABEL_H
#define ROTATABLELABEL_H

#include <QLabel>
#include <QPainter>
#include <qmath.h>

class RotatableLabel : public QLabel
{
Q_OBJECT
public:
    static const int PI = 3.14159265;
    explicit RotatableLabel(QPixmap pixmap, QWidget *parent = 0);

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
private:
    QPixmap originalPixmap;
    double currentRotation;
    double testRotation;
    QPoint startPoint;
};

#endif // ROTATABLELABEL_H
