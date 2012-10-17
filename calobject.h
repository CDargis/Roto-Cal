// @authors Chris Dargis
// @Copyright 2012

#ifndef CALOBJECT_H
#define CALOBJECT_H

#include <QDate>

class CalObject
{
public:
    explicit CalObject();
    virtual void setDate(QDate date);
protected:

signals:
    void setScreenIndex(int index);
public slots:
    
};

#endif // CALOBJECT_H
