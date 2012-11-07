// @authors Chris Dargis
// @Copyright 2012

#ifndef SELECTABLELABEL_H
#define SELECTABLELABEL_H

#include "clickablelabel.h"

class SelectableLabel : public ClickableLabel
{
    Q_OBJECT
public:
    explicit SelectableLabel(const QString& text, QWidget *parent = 0);
    void setSelectStyleSheet(bool selected = true);
public slots:
    
private:
    static const QString UNSELECTED_STYLE_SHEET;
    static const QString SELECTED_STYLE_SHEET;
};

#endif // SELECTABLELABEL_H
