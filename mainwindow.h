// @authors Chris Dargis
// @Copyright 2012

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendarwidget.h"
#include "addeventwidget.h"
#include "event_set.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    // Note that this will only have an effect on Symbian and Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

public slots:
    void slotActionTriggered(QAction* a);
private:
    Ui::MainWindow *ui;
    QStackedWidget* screens;
    CalendarWidget* cWidget;
    AddEventWidget* addEventWidget;
    Event_map eventMap;
};

#endif // MAINWINDOW_H
