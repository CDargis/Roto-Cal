#include "mainwindow.h"

#include <QApplication>

#include "serialization.h" //For testing purposes

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setOrientation(MainWindow::ScreenOrientationLockPortrait);
    //mainWindow.setOrientation(MainWindow::ScreenOrientationAuto);
    mainWindow.showExpanded();

    return app.exec();
}
