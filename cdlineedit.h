#ifndef CDLINEEDIT_H
#define CDLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

/**
 * @brief The CDLineEdit class derived from QLineEdit for the sole * purpose of catching the "Done" key event
 * @author Chris Dargis
 */
class CDLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    /**
     * @brief CDLineEdit constructor
     * @param parent a pointer to this object's parent
     */
    explicit CDLineEdit(QWidget* parent = 0);

protected:
    /**
     * @brief keyPressEvent overriding keyPressEvent to filter key press events
     * @param e the triggered event object
     */
    virtual void keyPressEvent(QKeyEvent* e);
signals:
    
public slots:
    
};

#endif // CDLINEEDIT_H
