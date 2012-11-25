#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QObject>
#include <QDate>
#include <QMultiMap>
#include <QString>
#include <QVector>
#include <vector>

class Holiday : public QObject
{
    Q_OBJECT
public:
    explicit Holiday(QObject *parent = 0);
    void setYear(QDate year);
    QVector< QList<QString> > getMonthVector();
    int getMapSize();
    QList<QString> hDayLookup(QDate date);
private:
    void initVector();

    void newYearsDay(QDate year);
    void mlkDay(QDate year);
    void presDay(QDate year);
    void memDay(QDate year);
    void indepDay(QDate year);
    void labDay(QDate year);
    void columDay(QDate year);
    void vetDay(QDate year);
    void thanksDay(QDate year);
    void xmasDay(QDate year);

    QString holidayTitle;
    QDate holidayDate;
    QMultiMap <QDate, QString> dayMap;
    QVector< QList<QString> > monthVector;
};

#endif // HOLIDAY_H
