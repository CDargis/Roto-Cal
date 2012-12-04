#ifndef GDATETIMEEDIT_H
#define GDATETIMEEDIT_H

#include <QWidget>
#include "clickablelabel.h"
#include <QFrame>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 * @brief The GDateTimeEdit class.
 *        Used as input in the saveEventWidget for an Event's day,month,year,hour, and minute.
 * @author Gerron Thurman
 */
class GDateTimeEdit : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief GDateTimeEdit constructor
     * @param e a pointer to QWidget parent
     */
    explicit GDateTimeEdit(QWidget *parent = 0);
    //methods
    /**
     * @brief sets the input field's to that of the Event's date and time
     * @param QDateTime from Event
     */
    void setDateTime(QDateTime dt);
    /**
     * @brief Used to retrieve input from widget to save or edit an Event
     * @returns QDateTime
     */
    QDateTime getDateTime();

private:

    //Frame
    QFrame* line;   /**< line seperator between date and time */

    //Arrows
    ClickableLabel* monthUpArrow;       /**< Clickable arrow for month increasing */
    ClickableLabel* dayUpArrow;         /**< Clickable arrow for day increasing*/
    ClickableLabel* yearUpArrow;        /**< Clickable arrow for year increasing */
    ClickableLabel* hourUpArrow;        /**< Clickable arrow for hour increasing */
    ClickableLabel* minuteUpArrow;      /**< Clickable arrow for minute increasing */
    ClickableLabel* monthDownArrow;     /**< Clickable arrow for month decreasing */
    ClickableLabel* dayDownArrow;       /**< Clickable arrow for day decreasing */
    ClickableLabel* yearDownArrow;      /**< Clickable arrow for year decreasing */
    ClickableLabel* hourDownArrow;      /**< Clickable arrow for hour decreasing */
    ClickableLabel* minuteDownArrow;    /**< Clickable arrow for minute decreasing */

    //Text Area
    QLabel* month;      /**< QLabel to display minute increasing */
    QLabel* day;        /**< QLabel to display increasing */
    QLabel* year;       /**< QLabel to display minute increasing */
    QLabel* hour;       /**< QLabel to display minute increasing */
    QLabel* minute;     /**< QLabel to display minute increasing */
    QLabel* colon;      /**< QLabel to display minute increasing */
    QLabel* slash;      /**< QLabel to display minute increasing */
    QLabel* slash2;     /**< QLabel to display minute increasing */

    //layouts
    QHBoxLayout* main;      /**< Main QHBoxLayout containing all the widgets */
    QVBoxLayout* vbox1;     /**< QVBoxLayout containing the month contents  */
    QVBoxLayout* vbox2;     /**< QVBoxLayout containing the day contents */
    QVBoxLayout* vbox3;     /**< QVBoxLayout containing the year contents */
    QVBoxLayout* vbox4;     /**< QVBoxLayout containing the hour contents */
    QVBoxLayout* vbox5;     /**< QVBoxLayout containing the minute contents */
    QVBoxLayout* vbox6;     /**< QVBoxLayout containing the slash */
    QVBoxLayout* vbox7;     /**< QVBoxLayout containing the slash2 */
    QVBoxLayout* vbox8;     /**< QVBoxLayout containing the colon */

    //Methods
    /**
     * @brief Used to convert a month string into an int
     * @returns an Int correlating to a month
     */
    int monthConverter(QString m);



signals:

public slots:
    /**
     * @brief monthUpSlot slot called when a user clicks monthUpArrow
     */
    void monthUpSlot();

    /**
     * @brief monthDownSlot slot called when a user clicks monthDownArrow
     */
    void monthDownSlot();

    /**
     * @brief dayUpSlot slot called when a user clicks dayUpArrow
     */
    void dayUpSlot();

    /**
     * @brief dayDownSlot slot called when a user clicks dayDownArrow
     */
    void dayDownSlot();

    /**
     * @brief yearUpSlot slot called when a user clicks yearUpArrow
     */
    void yearUpSlot();

    /**
     * @brief yearDownSlot slot called when a user clicks yearDownArrow
     */
    void yearDownSlot();

    /**
     * @brief hourUpSlot slot called when a user clicks hourUpArrow
     */
    void hourUpSlot();

    /**
     * @brief hourDownSlot slot called when a user clicks hourDownArrow
     */
    void hourDownSlot();

    /**
     * @brief minuteUpSlot slot called when a user clicks minuteUpArrow
     */

    void minuteDownSlot();

    /**
     * @brief minuteDownSlot slot called when a user clicks minuteDownArrow
     */
    void minuteUpSlot();


};

#endif // GDATETIMEEDIT_H
