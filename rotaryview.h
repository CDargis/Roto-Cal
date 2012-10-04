#ifndef ROTARYVIEW_H
#define ROTARYVIEW_H

#include <QWidget>

class RotaryView : public QWidget
{
    Q_OBJECT
public:
    explicit RotaryView(const QString& imgPath, int& pageHeight,
                        int& screenWidth, QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ROTARYVIEW_H
