// @authors Chris Dargis
// @Copyright 2012

#ifndef MONTHLABEL_H
#define MONTHLABEL_H

#include "rotatablelabel.h"
#include "event_set.h"

/**
 * @brief The MonthLabel class.
 * This class represents the rotation dial found in the month view
 */
class MonthLabel : public RotatableLabel
{
    Q_OBJECT
public:
    /**
     * @brief MonthLabel constructor for a MonthLabel object
     * @param pixmap a pixmap used as a base for the object
     * @param parent a pointer to the object's parent
     */
    explicit MonthLabel(QPixmap pixmap,QWidget *parent = 0);

    /**
     * @brief setDate set the current date of the object
     * @param date the date to be set
     * @param eventSet a reference to the Event_set object
     */
    void setDate(QDate date, Event_set& eventSet);
    /**
     * @brief months array representing the months in a year
     */
    static const QString months[12];
signals:
    /**
     * @brief monthChanged emited whenever the dial is rotated
     * @param month the current month the object is pointing at
     */
    void monthChanged(int month);
public slots:
    /**
     * @brief slotGrabMouseMove grabs the mouse move event from the parent
     */
    void slotGrabMouseMove();
protected:
};

#endif // MONTHLABEL_H
