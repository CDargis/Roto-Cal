#include "detailview.h"

#include <QLabel>
#include <QPushButton>

DetailView::DetailView(QRect &pageGeometry, Event_map &map, QWidget *parent) :
    RotaryView(pageGeometry, map, parent)
{
    QLabel* lab = new QLabel(tr("Detailed event view here..."), this);
}
