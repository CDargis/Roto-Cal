#ifndef CALENDARLABEL_H
#define CALENDARLABEL_H

#include <QLabel>
#include <QPainter>
#include <math.h>

class CalendarLabel : public QLabel
{
    Q_OBJECT
public:
    static const int PI = 3.14159265;
    explicit CalendarLabel(QWidget *parent = 0);

signals:
    void mouseMove();
    void mouseUp();
public slots:
    void slotMouseMoved();
    void slotMouseUp();
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *pe);
    QSize sizeHint() { return QSize(this->pixmap()->width(), this->pixmap()->height()); }
    QSize minimumSizeHint() { return sizeHint(); }
private:
    QPixmap originalPixmap;
    double currentRotation;
    
};

#endif // CALENDARLABEL_H
