#include "rotaryview.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QRectF>
#include <QGraphicsItem>
#include <QPixmap>

#include "rotatablelabel.h"

RotaryView::RotaryView(const QString& imgPath, int& pageHeight,
                       int& screenWidth, QWidget *parent) : QWidget(parent)
{
    QPixmap pixmap(imgPath);
    RotatableLabel* label = new RotatableLabel(pixmap.scaled(pageHeight, pageHeight), this);
    label->setGeometry(screenWidth / 2, 0, screenWidth, pageHeight);
}
