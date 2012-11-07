#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(const QString& text, QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *ev);
signals:
    void clicked();
signals:
    
public slots:
    
};

#endif // CLICKABLELABEL_H
