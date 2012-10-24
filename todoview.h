#ifndef TODOVIEW_H
#define TODOVIEW_H

#include "rotaryview.h"

class ToDoView : public RotaryView
{
    Q_OBJECT
public:
    explicit ToDoView(QRect& pageGeometry, Event_map& map, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // TODOVIEW_H
