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

    //Event set for testing
    Event_set set;

    //Start Days for testing
    Date d1(30,10,2012);
    Date d2(3,15,2012);
    Date d3(4,1,2012);
    Date d4(5,4,2012);
    Date d5(6,7,2012);
    Date d6(7,10,2012);
    Date d7(8,1,2012);
    Date d8(9,12,2012);
    Date d9(10,5,2012);
    Date d10(1,8,2012);

    //Start times for testing
    Time1 t1(5,30,false,true);
    Time1 t2(12,0,true,false);
    Time1 t3(3,30,false,true);
    Time1 t4(8,0,true,false);
    Time1 t5(5,0,true,false);
    Time1 t6(3,0,true,false);
    Time1 t7(2,0,true,false);
    Time1 t8(10,0,true,false);
    Time1 t9(12,0,false,true);
    Time1 t10(11,0,true,false);

    //End days for testing
    Date d11(30,10,2012);
    Date d22(4,15,2012);
    Date d33(5,1,2012);
    Date d44(6,4,2012);
    Date d55(7,7,2012);
    Date d66(8,10,2012);
    Date d77(9,1,2012);
    Date d88(10,12,2012);
    Date d99(11,5,2012);
    Date d100(2,8,2012);


    //End times for testing
    Time1 t11(12,30,false,true);
    Time1 t22(4,0,false,true);
    Time1 t33(4,30,false,true);
    Time1 t44(1,0,false,true);
    Time1 t55(5,30,true,false);
    Time1 t66(3,55,true,false);
    Time1 t77(4,0,true,false);
    Time1 t88(12,0,true,false);
    Time1 t99(2,30,true,false);
    Time1 t100(11,30,true,false);

    //Events for testing
    Event a("Halloween Party", "Downtown", "party", d1,t1,d11,t11);
    Event b("Test Time", "UIC", "test", d2, t2, d22, t22);
    Event c("Math", "UIC", "test", d3, t3, d33, t33);
    Event d("Science", "UIC", "test", d4, t4, d44, t44);
    Event e("History", "UIC", "test", d5, t2, d55, t22);
    Event f("Gym", "UIC", "test", d6, t6, d66, t66);
    Event g("lunch", "UIC", "down the street", d7, t7, d77, t77);
    Event h("basketball game", "alaska", "test", d8, t8, d88, t88);
    Event i("bowling", "earth", "test", d9, t9, d99, t99);
    Event j("whatever", "mars", "test", d10, t10, d100, t100);

    //Event pointers for testing
    Event* ap = &a;
    Event* bp = &b;
    Event* cp = &c;
    Event* dp = &d;
    Event* ep = &e;
    Event* fp = &f;
    Event* gp = &g;
    Event* hp = &h;
    Event* ip = &i;
    Event* jp = &j;

    //Insert Events
    set.insertEvent(ap);
    set.insertEvent(bp);
    set.insertEvent(cp);
    set.insertEvent(dp);
    set.insertEvent(ep);
    set.insertEvent(fp);
    set.insertEvent(gp);
    set.insertEvent(hp);
    set.insertEvent(ip);
    set.insertEvent(jp);


    //Display Events being saved
    qDebug() << "========Saved Events========";
    ap->display();
    bp->display();
    cp->display();
    dp->display();
    ep->display();
    fp->display();
    gp->display();
    hp->display();
    ip->display();
    jp->display();



    //Save Events
    Serialization::save(set.toSerialize());

    //Load Events
    qDebug() << "========Loaded Events========";
    Serialization::load(set);

    //Display events which should match above
    std::multiset<Event *>::iterator it;
    for ( it=set.toSerialize().begin() ; it != set.toSerialize().end(); it++ )
        (*it)->display();
    qDebug() <<  "Done testing.... Like a sir";

    return app.exec();
}
