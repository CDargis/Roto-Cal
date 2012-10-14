#include "listview.h"

#include <QLabel>

ListView::ListView(QRect &pageGeometry, QWidget *parent) :
    RotaryView(pageGeometry, parent)
{
    QLabel* lab = new QLabel(tr("List events here"), this);
}
