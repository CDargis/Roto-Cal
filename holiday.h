#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QObject>
#include <QDate>
#include <QMultiMap>
#include <QString>
#include <QVector>
#include <vector>

/**
 * @brief class for holidays (creation and retrieval)
 * @author Jason Moreau
*/

class Holiday : public QObject
{
    Q_OBJECT
public:
    explicit Holiday(QObject *parent = 0);
    /** sets year for holidays
     *  @param e QDate year object
     */
    void setYear(QDate year);
    /** returns monthVector QVector of QLists
     *  @returns QVector of QLists
     */
    QVector< QList<QString> > getMonthVector();
    /** returns map size for debugging
     *  @returns integer of map size
     */
    int getMapSize();
    /** for looking up dates in map
     *  @param e QDate object
     *  @returns QList of holidays in date
     */
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
