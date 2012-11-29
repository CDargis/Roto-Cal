#include "cdlineedit.h"

CDLineEdit::CDLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

// Catch if the user is pressing the "done" button from the
// virtual keyboard, if so clear the focus, otherwise continue as normal
void CDLineEdit::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Return)
        this->clearFocus();
    else QLineEdit::keyPressEvent(e);
}
