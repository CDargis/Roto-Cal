#include "gdatetimeedit.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>
#include <QDebug>
#include <QApplication>

GDateTimeEdit::GDateTimeEdit(QWidget *parent) :
    QWidget(parent)
{

    //layouts
    QHBoxLayout* main = new QHBoxLayout; //entire widget
    QVBoxLayout* vbox1 = new QVBoxLayout; //month box
    QVBoxLayout* vbox2 = new QVBoxLayout; //day box
    QVBoxLayout* vbox3 = new QVBoxLayout; //year box
    QVBoxLayout* vbox4 = new QVBoxLayout; //hour box
    QVBoxLayout* vbox5 = new QVBoxLayout; //minute box
    QVBoxLayout* vbox6 = new QVBoxLayout; //slash box
    QVBoxLayout* vbox7 = new QVBoxLayout; //2nd slash box
    QVBoxLayout* vbox8 = new QVBoxLayout; //colon box

    //fonts
    QFont font;
    font.setBold(true);
    font.setPointSize(11);

    QFont font2;
    font2.setBold(true);
    font2.setPointSize(10);

    //Create a scalar from widget size
    int wHeight = geometry().height()*0.90;
    int wWidth = geometry().width()*0.90;

    //pixmaps
    QPixmap downArrow(tr(":/images/downArrow.png"));
    downArrow = downArrow.scaled(wWidth*0.71,wHeight*1.35);
    QPixmap upArrow(tr(":/images/upArrow.png"));
    upArrow = upArrow.scaled(wWidth*0.71,wHeight*1.35);

    //VBox Contents for vbox1
    monthUpArrow = new ClickableLabel("",this);
    monthUpArrow->setPixmap(upArrow);
    //monthUpArrow->setFixedWidth(wWidth*0.70);
    vbox1->addWidget(monthUpArrow,0,Qt::AlignHCenter);

    month = new QLabel(this);
    month->setFont(font2);
    month->setStyleSheet("QLabel { color : white; }");
    vbox1->addWidget(month,0,Qt::AlignHCenter);

    monthDownArrow = new ClickableLabel("",this);
    monthDownArrow->setPixmap(downArrow);
    //monthDownArrow->setFixedWidth(wWidth*0.70);
    vbox1->addWidget(monthDownArrow,0,Qt::AlignHCenter);

    //VBox Contents for vbox2
    dayUpArrow = new ClickableLabel("",this);
    dayUpArrow->setPixmap(upArrow);
    //dayUpArrow->setFixedWidth(wWidth*0.71);
    vbox2->addWidget(dayUpArrow,0,Qt::AlignHCenter);

    day = new QLabel(this);
    day->setFont(font2);
    day->setStyleSheet("QLabel { color: white; }");
    vbox2->addWidget(day,0,Qt::AlignHCenter);

    dayDownArrow = new ClickableLabel("",this);
    dayDownArrow->setPixmap(downArrow);
    //dayDownArrow->setFixedWidth(wWidth*0.71);
    vbox2->addWidget(dayDownArrow,0,Qt::AlignHCenter);

    //VBox Contents for vbox3
    yearUpArrow = new ClickableLabel("",this);
    yearUpArrow->setPixmap(upArrow);
    //yearUpArrow->setFixedWidth(wWidth*0.71);
    vbox3->addWidget(yearUpArrow,0,Qt::AlignHCenter);

    year = new QLabel(this);
    year->setFont(font2);
    year->setStyleSheet("QLabel { color: white; }");
    vbox3->addWidget(year,0,Qt::AlignHCenter);

    yearDownArrow = new ClickableLabel("",this);
    yearDownArrow->setPixmap(downArrow);
    //yearDownArrow->setFixedWidth(wWidth*0.71);
    vbox3->addWidget(yearDownArrow,0,Qt::AlignHCenter);

    //VBox Contents for vbox4
    hourUpArrow = new ClickableLabel("",this);
    hourUpArrow->setPixmap(upArrow);
    //hourUpArrow->setFixedWidth(wWidth*0.71);
    vbox4->addWidget(hourUpArrow,0,Qt::AlignHCenter);

    hour= new QLabel(this);
    hour->setFont(font2);
    hour->setStyleSheet("QLabel { color: white; }");
    vbox4->addWidget(hour,0,Qt::AlignHCenter);

    hourDownArrow = new ClickableLabel("",this);
    hourDownArrow->setPixmap(downArrow);
    //hourDownArrow->setFixedWidth(wWidth*0.71);
    vbox4->addWidget(hourDownArrow,0,Qt::AlignHCenter);

    //VBox Contents for vbox5
    minuteUpArrow = new ClickableLabel("",this);
    minuteUpArrow->setPixmap(upArrow);
    //minuteUpArrow->setFixedWidth(wWidth*0.71);
    vbox5->addWidget(minuteUpArrow,0,Qt::AlignHCenter);

    minute = new QLabel(this);
    minute->setFont(font2);
    minute->setStyleSheet("QLabel { color: white; }");
    vbox5->addWidget(minute,0,Qt::AlignHCenter);

    minuteDownArrow = new ClickableLabel("",this);
    minuteDownArrow->setPixmap(downArrow);
    //minuteDownArrow->setFixedWidth(wWidth*0.71);
    vbox5->addWidget(minuteDownArrow,0,Qt::AlignHCenter);

    //vertical line
    line = new QFrame(this);
    line->setFixedHeight(wHeight*1.75);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    //vbox9->addWidget(line,0,Qt::AlignVCenter);

    //Colon
    colon = new QLabel(this);
    colon->setFont(font);
    colon->setStyleSheet("QLabel { color : white;}");
    colon->setText(":");
    vbox8->addWidget(colon,0,Qt::AlignVCenter);

    //Forward Slashes
    slash = new QLabel(this);
    slash->setFont(font);
    slash->setStyleSheet("QLabel { color : white;}");
    slash->setText("/");
    vbox6->addWidget(slash,0,Qt::AlignVCenter);

    slash2 = new QLabel(this);
    slash2->setFont(font);
    slash2->setStyleSheet("QLabel { color : white;}");
    slash2->setText("/");
    vbox7->addWidget(slash2,0,Qt::AlignVCenter);

    //Signals
    connect(monthUpArrow, SIGNAL(clicked()), this, SLOT(monthUpSlot()));
    connect(monthDownArrow, SIGNAL(clicked()), this, SLOT(monthDownSlot()));
    connect(dayUpArrow, SIGNAL(clicked()), this, SLOT(dayUpSlot()));
    connect(dayDownArrow, SIGNAL(clicked()), this, SLOT(dayDownSlot()));
    connect(yearUpArrow, SIGNAL(clicked()), this, SLOT(yearUpSlot()));
    connect(yearDownArrow, SIGNAL(clicked()), this, SLOT(yearDownSlot()));
    connect(hourUpArrow, SIGNAL(clicked()), this, SLOT(hourUpSlot()));
    connect(hourDownArrow, SIGNAL(clicked()), this, SLOT(hourDownSlot()));
    connect(minuteUpArrow, SIGNAL(clicked()), this, SLOT(minuteUpSlot()));
    connect(minuteDownArrow, SIGNAL(clicked()), this, SLOT(minuteDownSlot()));

    //Add vboxes to the main horizontal box & spacing
    main->addLayout(vbox1);
    main->addLayout(vbox6);
    main->addLayout(vbox2);
    main->addLayout(vbox7);
    main->addLayout(vbox3);
    main->addWidget(line,1);
    main->addLayout(vbox4);
    main->addLayout(vbox8);
    main->addLayout(vbox5);

    //Set the layout to main
    this->setLayout(main);
}

//Increase the month by 1
void GDateTimeEdit::monthUpSlot()
{
    bool ok;
    int monthN = monthConverter(month->text());
    if(monthN == 12){
        QDate date2 = QDate(year->text().toInt(&ok, 10),1,day->text().toInt(&ok, 10));
        if(date2.isValid()){
            month->setText("Jan");
        }
        else{qDebug() << "Invalid date.";}
    }
    else{
        QDate date = QDate(year->text().toInt(&ok, 10),monthN+1,day->text().toInt(&ok, 10));
        if(date.isValid()){
            month->setText(QDate::shortMonthName(monthN+1));
        }
        else{qDebug() << "Invalid date.";}
    }
}

//Convert the month into int
int GDateTimeEdit::monthConverter(QString m){
    if(m.compare("Jan") == 0){return 1;}
    else if(m.compare("Feb") == 0){return 2;}
    else if(m.compare("Mar") == 0){return 3;}
    else if(m.compare("Apr") == 0){return 4;}
    else if(m.compare("May") == 0){return 5;}
    else if(m.compare("Jun") == 0){return 6;}
    else if(m.compare("Jul") == 0){return 7;}
    else if(m.compare("Aug") == 0){return 8;}
    else if(m.compare("Sep") == 0){return 9;}
    else if(m.compare("Oct") == 0){return 10;}
    else if(m.compare("Nov") == 0){return 11;}
    else if(m.compare("Dec") == 0){return 12;}
    else{
        return 0;
    }
}

//Decrease the month by 1
void GDateTimeEdit::monthDownSlot()
{
    bool ok;
    int monthN = monthConverter(month->text());
    if(monthN == 1){
        QDate date2 = QDate(year->text().toInt(&ok, 10),12,day->text().toInt(&ok, 10));
        if(date2.isValid()){
            month->setText("Dec");
        }
        else{qDebug() << "Invalid date.";}
    }
    else{
        QDate date = QDate(year->text().toInt(&ok, 10),monthN-1,day->text().toInt(&ok, 10));
        if(date.isValid()){
            month->setText(QDate::shortMonthName(monthN-1));
        }
        else{qDebug() << "Invalid date.";}
    }
}

//Increase the day by 1
void GDateTimeEdit::dayUpSlot()
{
    bool ok;
    int dayN = day->text().toInt(&ok, 10);
    if(dayN == 27 || dayN == 28 || dayN == 29 || dayN == 30 || dayN == 31 ){
        QDate date2 = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),dayN+1);
        if(date2.isValid()){
            day->setNum(dayN+1);
        }
        else{day->setNum(1);}
    }
    else{
        QDate date = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),dayN+1);
        if(date.isValid()){
            day->setNum(dayN+1);
        }
    }
}

//Decrease the day by 1
void GDateTimeEdit::dayDownSlot()
{
    bool ok;
    int dayN = day->text().toInt(&ok, 10);
    if(dayN == 1){
        QDate date2 = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),31);
        QDate date3 = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),30);
        QDate date4 = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),29);
        QDate date5 = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),28);
        if(date2.isValid()){
            day->setNum(31);
        }
        else if(date3.isValid()){
            day->setNum(30);
        }
        else if(date4.isValid()){
            day->setNum(29);
        }
        else if(date5.isValid()){
            day->setNum(28);
        }
    }
    else{
        QDate date = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),dayN-1);
        if(date.isValid()){
            day->setNum(dayN-1);
        }
    }
}

//Increase the year by 1
void GDateTimeEdit::yearUpSlot()
{
    bool ok;
    int yearN = year->text().toInt(&ok, 10);
    QDate date = QDate(yearN+1,monthConverter(month->text()),day->text().toInt(&ok, 10));
    if(date.isValid()){
        if(yearN == 2037){
            year->setNum(2037);
        }
        else{
            year->setNum(yearN+1);
           }
    }
    else{qDebug() << "Invalid Date";}
}

//Decrease the year by 1
void GDateTimeEdit::yearDownSlot()
{
    bool ok;
    int yearN = year->text().toInt(&ok, 10);
    QDate date = QDate(yearN-1,monthConverter(month->text()),day->text().toInt(&ok, 10));
    if(date.isValid()){
        if(yearN == 1970){
            year->setNum(1970);
        }
        else{
            year->setNum(yearN-1);
        }
    }
    else{qDebug() << "Invalid Date";}
}

//Increase the hour by 1
void GDateTimeEdit::hourUpSlot()
{
    bool ok;
    int hourN = hour->text().toInt(&ok, 10);
    if(hourN == 23){
        hour->setNum(0);
    }
    else{
        hour->setNum(hourN+1);
    }
}

//Decrease the year by 1
void GDateTimeEdit::hourDownSlot()
{
    bool ok;
    int hourN = hour->text().toInt(&ok, 10);
    if(hourN == 0){
        hour->setNum(23);
    }
    else{
        hour->setNum(hourN-1);
    }
}

//Increase the minute by 1
void GDateTimeEdit::minuteUpSlot()
{
    bool ok;
    int minuteN = minute->text().toInt(&ok, 10);
    if(minuteN == 59){
        minute->setNum(0);
    }
    else{
        minute->setNum(minuteN+1);
    }
}

//Decrease the minute by 1
void GDateTimeEdit::minuteDownSlot()
{
    bool ok;
    int minuteN = minute->text().toInt(&ok, 10);
    if(minuteN == 0){
        minute->setNum(59);
    }
    else{
        minute->setNum(minuteN-1);
    }
}

//Set the default values to the current events
void GDateTimeEdit::setDateTime(QDateTime dt){
        month->setText(QDate::shortMonthName(dt.date().month()));
        day->setNum(dt.date().day());
        year->setNum(dt.date().year());
        hour->setNum(dt.time().hour());
        minute->setNum(dt.time().minute());
}

//Create QDateTime used for editing or creating event from input
QDateTime GDateTimeEdit::getDateTime(){
    bool ok;
    QDate date = QDate(year->text().toInt(&ok, 10),monthConverter(month->text()),day->text().toInt(&ok, 10));
    QTime time = QTime(hour->text().toInt(&ok, 10),minute->text().toInt(&ok, 10));
    QDateTime dt = QDateTime(date,time);

    if(dt.isValid()){
        qDebug() << "Valid";
        qDebug() << date.toString() << " " << time.toString();
        return dt;
    }
    else{
        qDebug() << "Invalid";
        return QDateTime::QDateTime ();
    }
}

