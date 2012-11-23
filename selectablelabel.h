// @authors Chris Dargis
// @Copyright 2012

#ifndef SELECTABLELABEL_H
#define SELECTABLELABEL_H

#include "clickablelabel.h"

/**
 * @brief The SelectableLabel class.
 * The class represents a label that is "selectable".
 * Once the label is clicked, it changes a color to indicate it is selected
 */
class SelectableLabel : public ClickableLabel
{
    Q_OBJECT
public:
    /**
     * @brief SelectableLabel constructor for the object
     * @param text a string to be set as the label's text
     * @param parent a pointer to the objects parent
     */
    explicit SelectableLabel(const QString& text, QWidget *parent = 0);
    /**
     * @brief setSelectStyleSheet set the label to be selected or not
     * @param selected true if label is selected, false otherwise
     */
    void setSelectStyleSheet(bool selected = true);
public slots:
    
private:
    static const QString UNSELECTED_STYLE_SHEET;
    static const QString SELECTED_STYLE_SHEET;
};

#endif // SELECTABLELABEL_H
