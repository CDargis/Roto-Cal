#include "detailview.h"

#include <QLabel>
#include <QPushButton>

DetailView::DetailView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    lab = new QLabel(tr("Detailed event view here..."), this);
}

void DetailView::setCurrentEvent(Event* e)
{
    currentEvent = e;
    lab->setText(e->getName());
}
