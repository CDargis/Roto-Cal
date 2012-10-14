#include "rotaryview.h"
#include "rotatablelabel.h"

RotaryView::RotaryView(QRect& pageGeometry, QWidget *parent) : QWidget(parent), CalObject()
{
    setGeometry(pageGeometry);
}
