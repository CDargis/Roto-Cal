// @authors Chris Dargis
// @Copyright 2012

#ifndef ROTARYVIEW_H
#define ROTARYVIEW_H

#include <QWidget>
#include <QDate>

#include "calobject.h"

class RotaryView : public QWidget, CalObject
{
    Q_OBJECT
public:
    explicit RotaryView(QRect& pageGeometry, Event_set& set, QWidget *parent = 0);
signals:
    
public slots:
    
};

#endif // ROTARYVIEW_H
