#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendarwidget.h"
#include "saveeventwidget.h"
#include "event_set.h"

namespace Ui {
    class MainWindow;
}

/**
 * @brief The MainWindow class
 * The main window of the application
 * @author Chris Dargis
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    /**
     * @brief MainWindow constructor for the object
     * @param parent a pointer to the object's parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief ~MainWindow destructor of the object
     */
    virtual ~MainWindow();

    // Note that this will only have an effect on Symbian and Fremantle.
    /**
     * @brief setOrientation auto-generated by Qt Creator
     * @param orientation
     */
    void setOrientation(ScreenOrientation orientation);

    /**
     * @brief showExpanded auto-generated by Qt Creator
     */
    void showExpanded();

public slots:
    /**
     * @brief slotActionTriggered slot called when an action has been triggered (menu)
     * @param a
     */
    void slotActionTriggered(QAction* a);
    /**
     * @brief slotAddWidgetClose slot is called when the save event widget wants to close
     * @param e
     */
    void slotAddWidgetClose(Event *e);
    /**
     * @brief slotEditEventClicked slot is called when an event is clicked and is to be edited
     * @param e
     */
    void slotEditEventClicked(Event* e);
private:
    Ui::MainWindow *ui;
    QStackedWidget* screens;
    CalendarWidget* cWidget;
    SaveEventWidget* saveEventWidget;
    Event_set eventSet;
};

#endif // MAINWINDOW_H
