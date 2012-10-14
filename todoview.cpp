#include "todoview.h"

#include <QLabel>

ToDoView::ToDoView(QRect &pageGeometry, QWidget *parent) :
    RotaryView(pageGeometry, parent)
{
    QLabel* lab = new QLabel(tr("ToDo list here"), this);
}
