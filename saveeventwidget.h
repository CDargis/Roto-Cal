#ifndef ADDEVENTWIDGET_H
#define ADDEVENTWIDGET_H

#include "calobject.h"
#include "calendarwidget.h"

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QScrollArea>

class SaveEventWidget : public QWidget, CalObject
{
    Q_OBJECT
public:
    explicit SaveEventWidget(Event_set& set, CalendarWidget& widget, QWidget *parent = 0);
protected:
    void keyPressEvent(QKeyEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void setScreenIndex(int index);
public slots:
    void slotSaveClicked();
    void slotCancelClicked();
private:
    void resetInput();

    QLineEdit* titleEdit;
    QLineEdit* descEdit;
    QLineEdit* locationEdit;
    QDateTimeEdit* sTimeEdit;
    QDateTimeEdit* eTimeEdit;
    QPoint lastPoint;

    CalendarWidget& cWidget;
};

#endif // ADDEVENTWIDGET_H