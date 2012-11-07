#include "todoview.h"

#include <QLabel>

ToDoView::ToDoView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    QLabel* lab = new QLabel(tr("ToDo list here"), this);
}
