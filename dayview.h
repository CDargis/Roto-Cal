#ifndef DAYVIEW_H
#define DAYVIEW_H

#include "rotaryview.h"
#include "daylabel.h"
#include "clickablelabel.h"
#include "event.h"

class DayView : public RotaryView
{
    Q_OBJECT
public:
    explicit DayView(QRect& pageGeometry, Event_set& set, QWidget *parent = 0);
    DayLabel* dayLabel;
    QLabel* glowMap;
    bool active;
signals:
    void eventClicked(Event* e);
public slots:
    void setDate(QDate date);
    void slotDateChanged(QDateTime dateTime);
    void slotListItemClicked(QListWidgetItem* item);
private:
    QListWidget* listWidget;
};

#endif // DAYVIEW_H
