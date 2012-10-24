// @authors Chris Dargis
// @Copyright 2012

#ifndef CALOBJECT_H
#define CALOBJECT_H

#include <QDate>
#include "event_set.h"

class CalObject
{
public:
    //explicit CalObject();
    explicit CalObject(Event_set& set);
    virtual void setDate(QDate date);
protected:
    Event_set& eventSet;
signals:
    void setScreenIndex(int index);
public slots:

};

#endif // CALOBJECT_H
