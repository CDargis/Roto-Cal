#include "datedisplay.h"

#include <QDate>
#include <QStyle>

DateDisplay::DateDisplay(int xOffset, int yOffset, int width, int height, QWidget *parent)
    : QLabel(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setGeometry(xOffset, yOffset, width, height);
    QDate today = QDate::currentDate();
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QLabel { color: qlineargradient(x1: 0, y1: 0, x2: .5, y2: 1,"
                  "stop: 0 #3016B0, stop: 1 #3C2D84); "
                  "border: 1px solid white;"
                  "font-size: 24px; }");
    setText(today.toString());
}
