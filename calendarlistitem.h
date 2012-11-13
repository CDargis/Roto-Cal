#ifndef CALENDARLISTITEM_H
#define CALENDARLISTITEM_H

#include "event.h"

#include <QListWidgetItem>

class CalendarListItem : public QListWidgetItem
{
public:
    explicit CalendarListItem(Event* e, const QString& text, QListWidget *parent = 0, int type = Type);
    Event* event;
signals:
    
public slots:
    
private:

};

#endif // CALENDARLISTITEM_H
