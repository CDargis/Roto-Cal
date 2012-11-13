#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include "rotaryview.h"
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>

class DetailView : public RotaryView
{
    Q_OBJECT
public:
    explicit DetailView(QRect& pageGeometry, Event_set& set, QWidget *parent);
signals:
    
public slots:
    void setCurrentEvent(Event* e);
private:
    QLabel* lab;
    Event* currentEvent;
};

#endif // DETAILVIEW_H
