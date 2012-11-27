#ifndef ROTATABLELABEL_H
#define ROTATABLELABEL_H

#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <qmath.h>
#include <QtGui>
#include "event_set.h"

/**
 * @brief The RotatableLabel class.
 * This class represents a label that can be rotated by moving your finger over the object.
 * @author Chris Dargis
 */
class RotatableLabel : public QLabel
{
Q_OBJECT
public:
    /**
     * @brief RotatableLabel constructor for the object
     * @param parent a pointer to the parent of the object
     */
    explicit RotatableLabel(QWidget *parent = 0);
    /**
     * @brief setCurrentRotation set the current rotation of the label
     * @param rotation to be set
     */
    void setCurrentRotation(float rotation);
    /**
     * @brief getCurrentRotation get the current rotation of the label
     * @return the label's current rotation
     */
    float getCurrentRotation() { return currentRotation; }
    /**
     * @brief getAngle get the angle from coord (0, 0) to point
     * @param point the point on the label to measure the angle to
     * @return an angle in degrees
     */
    float getAngle(QPoint point);
    /**
     * @brief setDate Pure virtual: set the date of the view
     * @param date the date to be set
     * @param eventSet a reference to the current Event_set object
     */
    virtual void setDate(QDate date, Event_set& eventSet) = 0;
    /**
     * @brief scaleRange scale the input to a specific range
     * @param in the number to be scaled
     * @param oldMin the minimum value of in
     * @param oldMax the maximum value of in
     * @param newMin the new minimum value for in
     * @param newMax the new maximum value for in
     * @return in scaled from [oldMin, oldMax] to [newMin, newMax]
     */
    static float scaleRange(float in, float oldMin, float oldMax, float newMin, float newMax);
    static QColor getColorFromRange(float x, float totalEvents);
    /**
     * @brief PI 3.14...
     */
    static const int PI = 3.14159265;
signals:
    /**
     * @brief mouseDown emited when the user presses finger down
     */
    void mouseDown();
    /**
     * @brief mouseMove emited when the user moves finger
     */
    void mouseMove();
    /**
     * @brief mouseUp emited when the user lifts finger up
     */
    void mouseUp();
public slots:
    /**
     * @brief slotMouseDown slot called when the user puts finger down
     */
    void slotMouseDown();
    /**
     * @brief slotMouseMoved slot called when the user moves finger
     */
    void slotMouseMoved();
    /**
     * @brief slotMouseUp slot called when user lifts finger up
     */
    void slotMouseUp();
protected:
    /**
     * @brief mousePressEvent event fired when the mouse is pressed down
     * @param ev
     */
    void mousePressEvent(QMouseEvent *ev);
    /**
     * @brief mouseMoveEvent event fired when user moves the "mouse"
     * @param ev
     */
    void mouseMoveEvent(QMouseEvent *ev);
    /**
     * @brief mouseReleaseEvent event fired when the mouse is released
     * @param ev
     */
    void mouseReleaseEvent(QMouseEvent *ev);
    /**
     * @brief paintEvent event fired when the object needs to be painted
     * @param pe
     */
    void paintEvent(QPaintEvent *pe);
    /**
     * @brief originalPixmap represents the original (unrotated) pixmap of the label
     */
    QPixmap originalPixmap;
private:
    QPoint mouseDownPoint;
    float currentRotation;
    float oldRotation;
    bool mouseIsDown;
};

#endif // ROTATABLELABEL_H
