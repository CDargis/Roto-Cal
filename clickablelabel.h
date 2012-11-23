#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

/**
 * @brief The ClickableLabel class.
 * Subclass of QLabel.
 * Emits a clicked() signal
 * @author Chris Dargis
 */
class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    /**
     * @brief ClickableLabel constructor
     * @param text a string to be the labels text
     * @param parent a pointer to the object's parent
     */
    explicit ClickableLabel(const QString& text, QWidget *parent = 0);
protected:
    /**
     * @brief mousePressEvent overidden to catch the user pressing the object
     * @param ev event representing the click
     */
    void mousePressEvent(QMouseEvent *ev);
signals:
    /**
     * @brief clicked emited when a user presses the label
     */
    void clicked();
signals:
    
public slots:
    
};

#endif // CLICKABLELABEL_H
