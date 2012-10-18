#ifndef ADDEVENTWIDGET_H
#define ADDEVENTWIDGET_H

#include "calobject.h"

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTimeEdit>

class AddEventWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    explicit AddEventWidget(QWidget *parent = 0);
protected:
    void keyPressEvent(QKeyEvent *e);
signals:
    void setScreenIndex(int index);
public slots:
    void slotAddClicked();
    void slotCancelClicked();
private:
    void resetInput();

    QLineEdit* titleEdit;
    QLineEdit* descEdit;
    QLineEdit* locationEdit;
    QDateTimeEdit* sTimeEdit;
    QDateTimeEdit* eTimeEdit;
};

#endif // ADDEVENTWIDGET_H
