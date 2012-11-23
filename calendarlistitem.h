#ifndef CALENDARLISTITEM_H
#define CALENDARLISTITEM_H

#include "event.h"

#include <QListWidgetItem>

/**
 * @brief The CalendarListItem class.
 *        Subclassed from QListWidgetItem.
 *        Used to tie a pointer to an event to a item in a QListWidget.
 */
class CalendarListItem : public QListWidgetItem
{
public:
    /**
     * @brief CalendarListItem constructor
     * @param e a pointer to an event
     * @param text a string that represents the event
     * @param parent parent of the widget item
     * @param type type of list widget item
     */
    explicit CalendarListItem(Event* e, const QString& text, QListWidget *parent = 0, int type = Type);
    /**
     * @brief event a pointer to an event that the List Item is tied to
     */
    Event* event;
signals:
    
public slots:
    
private:

};

#endif // CALENDARLISTITEM_H
