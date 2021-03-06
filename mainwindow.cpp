#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>
#include <QDesktopWidget>

#include <time.h>

#include "rotaryview.h"
#include "QDebug"

#include "create_time_t.h"
#include "serialization.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      cWidget(new CalendarWidget(qApp->desktop()->screenGeometry(), eventSet, this))
{
    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->addAction(tr("Add Event"));
    setMenuBar(menuBar);
    connect(menuBar, SIGNAL(triggered(QAction*)), this, SLOT(slotActionTriggered(QAction*)));

    screens = new QStackedWidget(this);
    screens->addWidget(cWidget);
    saveEventWidget = new SaveEventWidget(eventSet, *cWidget,this);
    screens->addWidget(saveEventWidget);
    connect(saveEventWidget, SIGNAL(closeScreen(Event*)), this, SLOT(slotAddWidgetClose(Event*)));
    connect(cWidget, SIGNAL(editEvent(Event*)), this, SLOT(slotEditEventClicked(Event*)));

    //Deserialization of events
    Serialization::load(eventSet);

    setCentralWidget(screens);

    cWidget->pokeDateChange();
}

MainWindow::~MainWindow()
{

    //Serialization of events
    Serialization::save(eventSet.toSerialize());

    // Memory cleanup!
    eventSet.deleteSets();
    delete ui;
}

void MainWindow::slotActionTriggered(QAction *a)
{
    if(a->text().compare(tr("Add Event")) == 0)
    {
        saveEventWidget->setCurrentEvent(NULL);
        saveEventWidget->setInput(cWidget->getCurrentDateTime(),
                                  cWidget->getCurrentDateTime().addSecs(60*60));
        screens->setCurrentIndex(1);
    }
}

// When closing the Save Event Widget, need to check if an event was edited or created
// and handle accordingly
void MainWindow::slotAddWidgetClose(Event *e)
{
    if(e)
    {
        cWidget->emitEventEditedSignal(e);
    }
    cWidget->pokeDateChange();
    screens->setCurrentIndex(0);
}

void MainWindow::slotEditEventClicked(Event *e)
{
    QDateTime start = QDateTime::fromTime_t(e->getStartTime());
    QDateTime end = QDateTime::fromTime_t(e->getEndTime());
    saveEventWidget->setInput(start, end, e->getName(), e->getLocation(), e->getDescription());
    saveEventWidget->setCurrentEvent(e);
    screens->setCurrentIndex(1);
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
