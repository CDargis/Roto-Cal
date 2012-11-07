#include "detailview.h"

#include <QLabel>
#include <QPushButton>

DetailView::DetailView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    QLabel* lab = new QLabel(tr("Detailed event view here..."), this);
}
