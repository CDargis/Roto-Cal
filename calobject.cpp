#include "calobject.h"

CalObject::CalObject()
{
}

void CalObject::setDate(QDate date)
{
    this->date = date;
}

QDate CalObject::getDate()
{
    return date;
}
