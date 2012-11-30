#include "calendarlistitem.h"

// Instantiate parent and event pointer
CalendarListItem::CalendarListItem(Event* e, const QString &text, QListWidget *parent, int type) :
    QListWidgetItem(text, parent, type), event(e)
{

}
