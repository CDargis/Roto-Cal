#include "clickablelabel.h"

const QString ClickableLabel::UNSELECTED_STYLE_SHEET = "QLabel { background-color: qlineargradient(x1: 0, y1: 0, x2: .5, y2: 1,"
                                                     "stop: 0 #595757, stop: 1 #474747);"
                                                     "color: qlineargradient(x1: 0, y1: 0, x2: .5, y2: 1,"
                                                     "stop: 0 #3016B0, stop: 1 #3C2D84);"
                                                     "border-right: 3px solid black;"
                                                     "border-bottom: 3px solid black;"
                                                     "border-style: outset; }";

const QString ClickableLabel::SELECTED_STYLE_SHEET = "QLabel { background-color: qlineargradient(x1: 0, y1: 0, x2: .5, y2: 1,"
                                                   "stop: 0 #3016B0, stop: 1 #3C2D84);"
                                                   "color: qlineargradient(x1: 0, y1: 0, x2: .5, y2: 1,"
                                                   "stop: 0 #595757, stop: 1 #474747);"
                                                   "border-right: 3px solid black;"
                                                   "border-bottom: 3px solid black;"
                                                   "border-style: outset; }";

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
}

void ClickableLabel::setSelectStyleSheet(bool selected)
{
    if(selected)
    {
        setStyleSheet(SELECTED_STYLE_SHEET);
    }
    else setStyleSheet(UNSELECTED_STYLE_SHEET);
}

void ClickableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
    QLabel::mousePressEvent(ev);
}
