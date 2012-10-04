#ifndef DATEDISPLAY_H
#define DATEDISPLAY_H

#include <QLabel>

class DateDisplay : public QLabel
{
    Q_OBJECT
public:
    explicit DateDisplay(int xOffset, int yOffset, int width, int height, QWidget* parent = 0);
signals:
    
public slots:

private:
};

#endif // DATEDISPLAY_H
