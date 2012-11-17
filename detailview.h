#ifndef DETAILVIEW_H
#define DETAILVIEW_H

#include "rotaryview.h"
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>

#include "event.h"

class DetailView : public RotaryView
{
    Q_OBJECT
public:
    explicit DetailView(QRect& pageGeometry, Event_set& set, QWidget *parent);
signals:
    void editEventClicked(Event* e);
public slots:
    void setCurrentEvent(Event* e);
    void slotEditClicked();
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
