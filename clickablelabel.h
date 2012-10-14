// @authors Chris Dargis
// @Copyright 2012

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(const QString& text, QWidget *parent = 0);
    void setSelectStyleSheet(bool selected = true);
protected:
    void mousePressEvent(QMouseEvent *ev);
signals:
    void clicked();
public slots:
    
private:
    static const QString UNSELECTED_STYLE_SHEET;
    static const QString SELECTED_STYLE_SHEET;
};

#endif // CLICKABLELABEL_H
