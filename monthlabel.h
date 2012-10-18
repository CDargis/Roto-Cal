// @authors Chris Dargis
// @Copyright 2012

#ifndef MONTHLABEL_H
#define MONTHLABEL_H

#include "rotatablelabel.h"

class MonthLabel : public RotatableLabel
{
    Q_OBJECT
public:
    explicit MonthLabel(QPixmap pixmap,QWidget *parent = 0);
    static QPixmap paintMonthsOnPixmap(QPixmap pixmap);

    static const QString months[12];
signals:
    void monthChanged(int month);
public slots:

protected:
    void paintEvent(QPaintEvent *pe);
};

#endif // MONTHLABEL_H
