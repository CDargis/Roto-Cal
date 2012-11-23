// @authors Chris Dargis
// @Copyright 2012

#ifndef ROTARYVIEW_H
#define ROTARYVIEW_H

#include <QWidget>
#include <QDate>

#include "calobject.h"

/**
 * @brief The RotaryView class.
 * This class is used as a base class for each "view" of the calendar.
 * @author Chris Dargis
 */
class RotaryView : public QWidget, CalObject
{
    Q_OBJECT
public:
    /**
     * @brief RotaryView constructor for the object
     * @param pageGeometry the page geometry that the view will use
     * @param set a reference to the current Event_set object
     * @param parent a pointer to the object's parent
     */
    explicit RotaryView(QRect& pageGeometry, Event_set& set, QWidget *parent = 0);
    /**
     * @brief getEventSet get the Event_set reference
     * @return a reference to the Event_set object
     */
    Event_set& getEventSet() { return eventSet; }
signals:
    
public slots:
    
};

#endif // ROTARYVIEW_H
