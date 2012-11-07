#include "rotaryview.h"
#include "rotatablelabel.h"

RotaryView::RotaryView(QRect& pageGeometry, Event_set &set, QWidget *parent) : QWidget(parent), CalObject(set)
{
    setGeometry(pageGeometry);
}
