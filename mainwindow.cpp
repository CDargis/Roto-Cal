#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>
#include <QDesktopWidget>

#include <time.h>

#include "rotaryview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      cWidget(new CalendarWidget(qApp->desktop()->screenGeometry(), eventSet, this))
{
    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->addAction(tr("Add Event"));
    menuBar->addAction(tr("Add To-Do"));
    setMenuBar(menuBar);
    connect(menuBar, SIGNAL(triggered(QAction*)), this, SLOT(slotActionTriggered(QAction*)));

    screens = new QStackedWidget(this);
    screens->addWidget(cWidget);
    saveEventWidget = new SaveEventWidget(eventSet, *cWidget,this);
    screens->addWidget(saveEventWidget);
    connect(cWidget, SIGNAL(setScreenIndex(int)), screens, SLOT(setCurrentIndex(int)));
    connect(saveEventWidget, SIGNAL(setScreenIndex(int)), screens, SLOT(setCurrentIndex(int)));

    Event* e1 = new Event;
    Event* e2 = new Event;
    Event* e3 = new Event;
    Event* e4 = new Event;
    Event* e5 = new Event;
    Event* e6 = new Event;
    Event* e7 = new Event;
    Event* e8 = new Event;
    Event* e9 = new Event;
    Event* e10 = new Event;

    e1->setName(tr("Dr. Who"));
    e2->setName(tr("BIO 101"));
    e3->setName(tr("Gaz B-day"));
    e4->setName(tr("Dinner Date"));
    e5->setName(tr("Meet The Feebles"));
    e6->setName(tr("Naked Lunch"));
    e7->setName(tr("Dinner Date"));
    e8->setName(tr("Tom Yum"));
    e9->setName(tr("Candy Bar"));
    e9->setName(tr("Little Richard"));
    e10->setName(tr("Animal Farm"));

    e1->setStartTime(QDateTime::currentDateTime().toTime_t());
    e1->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e2->setStartTime(QDateTime::currentDateTime().addSecs(3600).toTime_t());
    e2->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e3->setStartTime(QDateTime::currentDateTime().addSecs(7200).toTime_t());
    e3->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e4->setStartTime(QDateTime::currentDateTime().addSecs(11800).toTime_t());
    e4->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e5->setStartTime(QDateTime::currentDateTime().addSecs(15400).toTime_t());
    e5->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e6->setStartTime(QDateTime::currentDateTime().addDays(19000).toTime_t());
    e6->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e7->setStartTime(QDateTime::currentDateTime().addDays(1).toTime_t());
    e7->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e8->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(7200).toTime_t());
    e8->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e9->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(11800).toTime_t());
    e9->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e10->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(15400).toTime_t());
    e10->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());

    eventSet.insertEvent(e1);
    eventSet.insertEvent(e2);
    eventSet.insertEvent(e3);
    eventSet.insertEvent(e4);
    eventSet.insertEvent(e5);
    eventSet.insertEvent(e6);
    eventSet.insertEvent(e7);
    eventSet.insertEvent(e8);
    eventSet.insertEvent(e9);
    eventSet.insertEvent(e10);

    setCentralWidget(screens);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotActionTriggered(QAction *a)
{
    if(a->text().compare(tr("Add Event")) == 0)
        screens->setCurrentIndex(1);
    else if(a->text().compare(tr("Add To-Do")) == 0)
        return;
}

//---------------------------------------------------------------------------------------------------
// BEGIN Qt GENERATED CODE
//---------------------------------------------------------------------------------------------------

void MainWindow::setOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromLatin1(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void MainWindow::showExpanded()
{
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    showFullScreen();
#elif defined(Q_WS_MAEMO_5)
    showMaximized();
#else
    show();
#endif
}

//----------------------------------------------------------------------------------------------------
// END Qt GENERATED CODE
//----------------------------------------------------------------------------------------------------
