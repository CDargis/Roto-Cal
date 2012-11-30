#include "clickablelabel.h"

// Clickable label class inherits from QLabel.
ClickableLabel::ClickableLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
}

// Emit the clicked() signal when this label is clicked by the user
void ClickableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
    QLabel::mousePressEvent(ev);
}
