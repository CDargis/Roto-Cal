#ifndef ADDEVENTWIDGET_H
#define ADDEVENTWIDGET_H

#include "calobject.h"
#include "calendarwidget.h"
#include "cdlineedit.h"

#include <QWidget>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QScrollArea>

/**
 * @brief The SaveEventWidget class.
 * This class is used and displayed as a separate "window" when the user wishes to
 * create or edit an event.
 * @author Chris Dargis
 * @author Jason Moreau
 */
class SaveEventWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    /**
     * @brief SaveEventWidget constructor for the object
     * @param set a reference to the current Event_set object
     * @param widget a reference to the current CalendarWidget object
     * @param parent a pointer to the object's parent
     */
    explicit SaveEventWidget(Event_set& set, CalendarWidget& widget, QWidget *parent = 0);
    /**
     * @brief setInput preset the input fields
     * @param start the start time of the event
     * @param end the end time of the event
     * @param title the title of the event
     * @param location the location of the event
     * @param description the description of the event
     */
    void setInput(QDateTime start, QDateTime end, QString title = "",
                  QString location = "", QString description = "");
    /**
     * @brief setCurrentEvent set the current event of the object being edited
     * @param e
     */
    void setCurrentEvent(Event *e) { currentEvent = e; }
    /**
     * @brief createNewEvent function called when the user is creating a new event
     */
    void createNewEvent();
    /**
     * @brief editEvent function called when the user is editing an event
     */
    void editEvent();
    /**
     * @brief setDate used to set the date of the entire view
     * @param date to be set
     */
    void setDate(QDate date);
protected:

signals:
    /**
     * @brief closeScreen emited when the save/edit screen is to be closed
     * @param e a pointer to the Event object that was edited or crated, NULL if user canceled
     */
    void closeScreen(Event* e);
public slots:
    /**
     * @brief slotSaveClicked slot called when a user clicks save
     */
    void slotSaveClicked();
    /**
     * @brief slotCancelClicked slot called when a user clicks cancel
     */
    void slotCancelClicked();
private:
    bool checkStartTime(time_t start, time_t end);

    Event* currentEvent;
    CDLineEdit* titleEdit;
    CDLineEdit* descEdit;
    CDLineEdit* locationEdit;
    QDateTimeEdit* sTimeEdit;
    QDateTimeEdit* eTimeEdit;

    CalendarWidget& cWidget;
};

#endif // ADDEVENTWIDGET_H
