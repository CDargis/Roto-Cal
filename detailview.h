#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include "rotaryview.h"
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>

#include "event.h"

/**
 * @brief The DetailView class.
 * This class is used to represent the details of an event and present them to the user
 * @author Chris Dargis
 * @author Jason Moreau
 */
class DetailView : public RotaryView
{
    Q_OBJECT
public:
    /**
     * @brief DetailView constructor for the object
     * @param pageGeometry the geometry the object uses
     * @param set a reference to the Event_set object
     * @param parent a pointer to the objets parent
     */
    explicit DetailView(QRect& pageGeometry, Event_set& set, QWidget *parent);
    /**
     * @brief setDate used to set the date of the entire view
     * @param date to be set
     */
    virtual void setDate(QDate date);
signals:
    /**
     * @brief editEventClicked emited when a user clicks the edit event button
     * @param e a pointer to the event to be edited
     */
    void editEventClicked(Event* e);
public slots:
    /**
     * @brief setCurrentEvent slot called when a user clicks an item to be edited
     * @param e a pointer to the event that is to be displayed
     */
    void setCurrentEvent(Event* e);
    /**
     * @brief slotEditClicked slot is called when a user clicks edit
     */
    void slotEditClicked();
    /**
     * @brief slotDeleteClicked slot is called when a user clicks delete
     */
    void slotDeleteClicked();
private:
    QLabel* title;
    QLabel* location;
    QLabel* description;
    QLabel* startTime;
    QLabel* endTime;

    QLabel* fieldTitle;
    QLabel* fieldLocation;
    QLabel* fieldDescription;
    QLabel* fieldStartTime;
    QLabel* fieldEndTime;

    Event* currentEvent;
};

#endif // DETAILVIEW_H
