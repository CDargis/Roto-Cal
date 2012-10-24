#include "rotaryview.h"
#include "rotatablelabel.h"

RotaryView::RotaryView(QRect& pageGeometry, Event_map &map, QWidget *parent) : QWidget(parent), CalObject(map)
{
    setGeometry(pageGeometry);
}
