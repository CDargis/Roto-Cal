#include "daylabel.h"
#include <QDebug>

// Constructor for objcet. Call base constructor and connect the mouse move signal from the parent
// to catch here in the derived object
DayLabel::DayLabel(QPixmap pixmap, QWidget *parent) :
    RotatableLabel(pixmap, parent)
{
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

// Grab the mouse move signal from the parent object. Get the rotation from the parent object,
// if the rotation falls within a certain range, we want to emulate "snap-into-place" and inform
// the date display object that the day may have changed
void DayLabel::slotGrabMouseMove()
{
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    float mod = fmod(cRotation, rotationRange);
    if(mod < 2 || mod > 8)
    {
        float day = (cRotation / rotationRange) + .5;
        setCurrentRotation((int)day * rotationRange);
        emit dayChanged((int)day + 1);
    }
}

// This function is used to set the date of the wheel. The main steps are:
// 1) Determine the number of events at the current date, also determine
//    the number of events that are in the month
// 2) Determine the "rotation step" to step through in the QConicalGradient
// 3) Loop through the entire month and set the colors for each day
// 4) Loop back through the month and draw the day numbers on the pixmap
void DayLabel::setDate(QDate date, Event_set& eventSet)
{
    // Determine the total number of events in the month
    // Instantiate painting objects
    int totalEvents = eventSet.getNumOfEventsInMonth(date.month(), date.year());
    int daysInMonth = date.daysInMonth();
    double rotationStep = 1.0 / (double)daysInMonth;
    QPixmap originalPixmap(*(this->pixmap()));
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    double rot = 0;

    // Determine the first number and save for later
    int firstNum = eventSet.getNumOfEventsInDay(1, date.month(), date.year());
    QColor firstColor = RotatableLabel::getColorFromRange(firstNum, totalEvents);
    grad.setColorAt(rot, firstColor);
    rot = rotationStep;

    // Loop through the month and set the color for each day
    for(int i = daysInMonth; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInDay(i, date.month(), date.year());
        QColor col = RotatableLabel::getColorFromRange(numEvents, totalEvents);
        grad.setColorAt(rot, col);
        rot += rotationStep;
    }
    grad.setColorAt(rot, firstColor);
    p.setBrush(grad);
    p.drawEllipse(0, 0, originalPixmap.size().width(), originalPixmap.size().height());

    // Calculate the offsets of the numbers
    int xPos = originalPixmap.width() * .04;
    int yPos = originalPixmap.height() / 2;
    int xTranslate = originalPixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::black);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(16);
    f.setStyleStrategy(QFont::ForceOutline);
    p.setBrush(QBrush(QColor(Qt::white)));
    float rotation = 360.00 / (float)daysInMonth;

    // Loop back through the month and draw the day numbers on the pixmap
    for(int i = 1; i <= daysInMonth; i++)
    {
        QPainterPath path;
        path.addText(xPos, yPos + 10, f, QString::number(i));
        p.drawPath(path);
        p.translate(xTranslate, yTranslate);
        p.rotate(rotation);
        p.translate(-xTranslate, -yTranslate);
    }

    // Setting the pixmap
    this->setPixmap(originalPixmap);
    rotationRange = 360.00 / (float)date.daysInMonth();
    setCurrentRotation((date.day() - 1) * rotationRange);
}
