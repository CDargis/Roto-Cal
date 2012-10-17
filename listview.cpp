#include "listview.h"

#include <QLabel>
#include <QPushButton>

ListView::ListView(QRect &pageGeometry, QWidget *parent) :
    RotaryView(pageGeometry, parent)
{
    QAbstractScrollArea* scrollArea = new QAbstractScrollArea(this);
    scrollArea->setStyleSheet("QWidget { background-color: black; }");

    QVBoxLayout* testLayout = new QVBoxLayout(this);
    QLabel* lab = new QLabel(tr("Event 1"), this);
    QLabel* lab2 = new QLabel(tr("Event 2"), this);
    QLabel* lab3 = new QLabel(tr("Event 3"), this);
    testLayout->addWidget(lab);
    testLayout->addWidget(lab2);
    testLayout->addWidget(lab3);
    scrollArea->setLayout(testLayout);

    QHBoxLayout* pageLayout = new QHBoxLayout(this);
    pageLayout->addWidget(scrollArea);
    setLayout(pageLayout);
}
