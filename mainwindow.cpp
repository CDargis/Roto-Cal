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

    Event* e11 = new Event("Dentist","location here","description here",Create_time_t::createTime(1,12,2012,3,4,true),Create_time_t::createTime(1,12,2012,3,5,true));
    Event* e12 = new Event("Chem 101","location here","description here",Create_time_t::createTime(2,5,2012,6,7,false),Create_time_t::createTime(2,5,2012,6,8,false));
    Event* e13 = new Event("Mark Bday","location here","description here",Create_time_t::createTime(27,2,2012,50,5,true),Create_time_t::createTime(27,2,2012,0,6,true));
    Event* e14 = new Event("Lunch","location here","description here",Create_time_t::createTime(3,3,2012,3,3,false),Create_time_t::createTime(3,3,2012,3,4,false));
    Event* e15 = new Event("Digging Dirt","location here","description here",Create_time_t::createTime(3,10,2012,0,11,false),Create_time_t::createTime(3,10,2012,0,12,true));
    Event* e16 = new Event("Day off","location here","description here",Create_time_t::createTime(4,4,2012,4,4,true),Create_time_t::createTime(4,4,2012,4,5,true));
    Event* e17 = new Event("Party","location here","description here",Create_time_t::createTime(5,4,2012,30,8,true),Create_time_t::createTime(5,4,2012,30,9,true));
    Event* e18 = new Event("Charity","location here","description here",Create_time_t::createTime(5,10,2012,0,3,false),Create_time_t::createTime(5,10,2012,0,4,false));
    Event* e19 = new Event("Blues Clues","location here","description here",Create_time_t::createTime(5,10,2012,20,12,false),Create_time_t::createTime(5,10,2012,20,1,true));
    Event* e20 = new Event("James Brown","location here","description here",Create_time_t::createTime(5,9,2012,10,7,false),Create_time_t::createTime(5,9,2012,10,8,false));

    Event* e21 = new Event("Dr. Doom","location here","description here",Create_time_t::createTime(6,6,2012,10,6,true),Create_time_t::createTime(6,6,2012,10,7,true));
    Event* e22 = new Event("Math 101","location here","description here",Create_time_t::createTime(6,6,2012,8,9,false),Create_time_t::createTime(6,6,2012,8,10,false));
    Event* e23 = new Event("Chris Birthday","location here","description here",Create_time_t::createTime(7,7,2012,10,2,false),Create_time_t::createTime(7,7,2012,10,3,false));
    Event* e24 = new Event("Gerron Birthday","location here","description here",Create_time_t::createTime(9,1,2012,0,12,false),Create_time_t::createTime(9,1,2012,0,0,true));
    Event* e25 = new Event("Jay Birthday","location here","description here",Create_time_t::createTime(11,11,2012,0,12,false),Create_time_t::createTime(11,11,2012,0,12,true));
    Event* e26 = new Event("Movie Night","location here","description here",Create_time_t::createTime(8,1,2012,0,6,true),Create_time_t::createTime(8,1,2012,0,7,true));
    Event* e27 = new Event("4th of July","location here","description here",Create_time_t::createTime(29,7,2012,30,7,false),Create_time_t::createTime(29,7,2012,30,8,false));
    Event* e28 = new Event("Christmas","location here","description here",Create_time_t::createTime(30,12,2012,3,4,true),Create_time_t::createTime(30,12,2012,3,5,true));
    Event* e29 = new Event("Thanksgiving","location here","description here",Create_time_t::createTime(5,5,2012,10,5,false),Create_time_t::createTime(5,5,2012,10,5,false));
    Event* e30 = new Event("Black Friday","location here","description here",Create_time_t::createTime(10,5,2012,6,7,false),Create_time_t::createTime(10,5,2012,6,8,false));

    Event* e31 = new Event("Doctor","location here","description here",Create_time_t::createTime(11,11,2012,3,3,true),Create_time_t::createTime(11,11,2012,3,4,true));
    Event* e32 = new Event("Gym","location here","description here",Create_time_t::createTime(7,7,2012,0,2,true),Create_time_t::createTime(7,7,2012,0,3,true));
    Event* e33 = new Event("PPV fight","location here","description here",Create_time_t::createTime(30,7,2012,40,7,false),Create_time_t::createTime(30,7,2012,40,7,false));
    Event* e34 = new Event("Heat vs Lakers","location here","description here",Create_time_t::createTime(2,2,2012,20,4,true),Create_time_t::createTime(2,2,2012,20,5,true));
    Event* e35 = new Event("Magic Show","location here","description here",Create_time_t::createTime(12,12,2012,25,6,true),Create_time_t::createTime(12,12,2012,25,7,true));
    Event* e36 = new Event("Book reading","location here","description here",Create_time_t::createTime(26,6,2012,45,5,true),Create_time_t::createTime(26,6,2012,45,6,true));
    Event* e37 = new Event("Speech","location here","description here",Create_time_t::createTime(30,10,2012,15,6,true),Create_time_t::createTime(30,10,2012,30,6,true));
    Event* e38 = new Event("Final exam","location here","description here",Create_time_t::createTime(3,3,2012,50,8,false),Create_time_t::createTime(3,3,2012,50,9,false));
    Event* e39 = new Event("Finals","location here","description here",Create_time_t::createTime(3,10,2012,40,5,true),Create_time_t::createTime(3,10,2012,40,3,true));
    Event* e40 = new Event("Shopping","location here","description here",Create_time_t::createTime(1,1,2012,10,1,true),Create_time_t::createTime(1,1,2012,10,2,true));

    //Events to fill current date to check scrolling.
    Event* e41 = new Event;
    Event* e42 = new Event;
    Event* e43 = new Event;
    Event* e44 = new Event;
    Event* e45 = new Event;
    Event* e46 = new Event;
    Event* e47 = new Event;
    Event* e48 = new Event;
    Event* e49 = new Event;
    Event* e50 = new Event;

    e1->setName(tr("Dr. Who"));
    e2->setName(tr("BIO 101"));
    e3->setName(tr("Gaz B-day"));
    e4->setName(tr("Dinner Date"));
    e5->setName(tr("Meet The Feebles"));
    e6->setName(tr("Naked Lunch"));
    e7->setName(tr("Dinner Date"));
    e8->setName(tr("Tom Yum"));
    e9->setName(tr("Candy Bar"));
    e10->setName(tr("Animal Farm"));

    e41->setName(tr("Pacos"));
    e42->setName(tr("Hockey"));
    e43->setName(tr("Bears"));
    e44->setName(tr("Sale"));
    e45->setName(tr("Meet The Fock"));
    e46->setName(tr("Return 1"));
    e47->setName(tr("Infinite Loop"));
    e48->setName(tr("Stack overflow"));
    e49->setName(tr("Rejection"));
    e50->setName(tr("Butterfinger"));

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
    e41->setStartTime(QDateTime::currentDateTime().toTime_t());
    e41->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e42->setStartTime(QDateTime::currentDateTime().addSecs(3600).toTime_t());
    e42->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e43->setStartTime(QDateTime::currentDateTime().addSecs(7200).toTime_t());
    e43->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e44->setStartTime(QDateTime::currentDateTime().addSecs(11800).toTime_t());
    e44->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e45->setStartTime(QDateTime::currentDateTime().addSecs(15400).toTime_t());
    e45->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e46->setStartTime(QDateTime::currentDateTime().addDays(19000).toTime_t());
    e46->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e47->setStartTime(QDateTime::currentDateTime().addDays(1).toTime_t());
    e47->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e48->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(7200).toTime_t());
    e48->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e49->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(11800).toTime_t());
    e49->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());
    e50->setStartTime(QDateTime::currentDateTime().addDays(1).addSecs(15400).toTime_t());
    e50->setEndTime(QDateTime::currentDateTime().addSecs(60*60).toTime_t());

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

    eventSet.insertEvent(e11);
    eventSet.insertEvent(e12);
    eventSet.insertEvent(e13);
    eventSet.insertEvent(e14);
    eventSet.insertEvent(e15);
    eventSet.insertEvent(e16);
    eventSet.insertEvent(e17);
    eventSet.insertEvent(e18);
    eventSet.insertEvent(e19);
    eventSet.insertEvent(e20);
    eventSet.insertEvent(e21);
    eventSet.insertEvent(e22);
    eventSet.insertEvent(e23);
    eventSet.insertEvent(e24);
    eventSet.insertEvent(e25);
    eventSet.insertEvent(e26);
    eventSet.insertEvent(e27);
    eventSet.insertEvent(e28);
    eventSet.insertEvent(e29);
    eventSet.insertEvent(e30);
    eventSet.insertEvent(e31);
    eventSet.insertEvent(e32);
    eventSet.insertEvent(e33);
    eventSet.insertEvent(e34);
    eventSet.insertEvent(e35);
    eventSet.insertEvent(e36);
    eventSet.insertEvent(e37);
    eventSet.insertEvent(e38);
    eventSet.insertEvent(e39);
    eventSet.insertEvent(e40);

    eventSet.insertEvent(e41);
    eventSet.insertEvent(e42);
    eventSet.insertEvent(e43);
    eventSet.insertEvent(e44);
    eventSet.insertEvent(e45);
    eventSet.insertEvent(e46);
    eventSet.insertEvent(e47);
    eventSet.insertEvent(e48);
    eventSet.insertEvent(e49);
    eventSet.insertEvent(e50);

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
