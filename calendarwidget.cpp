#include "calendarwidget.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QRectF>
#include <QVBoxLayout>
#include <QGraphicsItem>
#include <QPixmap>

CalendarWidget::CalendarWidget(QRect screenRes, QWidget *parent) :
    QWidget(parent), screen(screenRes), menu(new CalendarMenu(screenRes, this))
{

    //454545
    //BFBFBF

    /**
    QGraphicsView* view = new QGraphicsView(this);
    view->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    view->setGeometry(screen.width() / 2, 0, screen.width(), screen.height());
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsPixmapItem* item =
            new QGraphicsPixmapItem(QPixmap(":/images/dial.png").scaled(screen.height(), screen.height()));
    scene->addItem(item);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    item->setPos(140, 0);
    view->setAlignment(Qt::AlignLeft);
    view->show();
    */
}
