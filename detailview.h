#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "rotaryview.h"
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>

class DetailView : public RotaryView
{
    Q_OBJECT
public:
    explicit DetailView(QRect& pageGeometry, QWidget *parent);
    
signals:
    
public slots:
    
};

#endif // LISTVIEW_H
