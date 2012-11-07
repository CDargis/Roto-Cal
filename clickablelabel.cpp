#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
}

void ClickableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
    QLabel::mousePressEvent(ev);
}
