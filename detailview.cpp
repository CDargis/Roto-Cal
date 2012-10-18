#include "detailview.h"

#include <QLabel>
#include <QPushButton>

DetailView::DetailView(QRect &pageGeometry, QWidget *parent) :
    RotaryView(pageGeometry, parent)
{
    QLabel* lab = new QLabel(tr("Detailed event view here..."), this);
}
