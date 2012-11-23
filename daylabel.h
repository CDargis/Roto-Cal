// @authors Chris Dargis
// @Copyright 2012

#ifndef DAYLABEL_H
#define DAYLABEL_H

#include "rotatablelabel.h"

/**
 * @brief The DayLabel class.
 * This class represents the rotation dial found in the day view
 */
class DayLabel : public RotatableLabel
{
    Q_OBJECT
public:
    /**
     * @brief DayLabel constructor of the object
     * @param pixmap a pixmap used as a base for the object
     * @param parent a pointer to the object's parent
     */
    explicit DayLabel(QPixmap pixmap, QWidget *parent = 0);

    /**
     * @brief setDate set the current date of the object
     * @param date the date to be set
     * @param eventSet a reference to the Event_set object
     */
    void setDate(QDate date, Event_set& eventSet);
    /**
     * @brief getRotationRange get the current rotation range of the object
     * @return the current rotation range that triggers day chagne signals
     */
    float getRotationRange() { return rotationRange; }
signals:
    /**
     * @brief dayChanged emited whenever the wheel is rotated
     * @param day the current day that the label is pointing at
     */
    void dayChanged(int day);
public slots:
    /**
     * @brief slotGrabMouseMove slot used to grab the mouse of event of the parent
     */
    void slotGrabMouseMove();
protected:
    /**
     * @brief rotationRange the rotation range of the object that triggers day change signals
     */
    float rotationRange;

};

#endif // DAYLABEL_H
