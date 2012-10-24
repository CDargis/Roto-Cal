#include "todoview.h"

#include <QLabel>

ToDoView::ToDoView(QRect &pageGeometry, Event_map& map, QWidget *parent) :
    RotaryView(pageGeometry, map, parent)
{
    QLabel* lab = new QLabel(tr("ToDo list here"), this);
}
