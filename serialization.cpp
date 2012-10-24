#include "serialization.h"


void Serialization::save(std::multiset<Event *, Cmp_event_day> &events)
{
    //Save file to disk
    QFile file("events.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open file";
        return;
    }

    //create output stream
    QDataStream out (&file);
    //set output version
    out.setVersion(QDataStream::Qt_4_8);

    //iteration
    std::multiset<Event *>::iterator it;
    for ( it=events.begin() ; it != events.end(); it++ )
        out << **it;

    //Finito! flush the stream to the file and close
    file.flush();
    file.close();
}

bool Serialization::load(Event_set &set)
{

    //Open the Qfile & error check
    QFile file("events.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file";
        return false;
    }

    //create datastream
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_8);
    while(!in.atEnd())
    {
        Event * e = new Event;
        in >> *e;
        set.insertEvent(e);
    }

    file.close();
    return true;
}



