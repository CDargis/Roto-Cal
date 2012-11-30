#include "rotaryview.h"
#include "rotatablelabel.h"

// Initialize the parent objects and set the geometry of the view
RotaryView::RotaryView(QRect& pageGeometry, Event_set &set, QWidget *parent) : QWidget(parent), CalObject(set)
{
    setGeometry(pageGeometry);
}
