#include "monthlabel.h"
#include <QDebug>

// Const QStrign array for month abbreviations
const QString MonthLabel::months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
                                    "OCT", "NOV", "DEC"};

// Constructor for the wheel. Need to connect the signal from the parent to the derived class to
// catch the user moving their finger
MonthLabel::MonthLabel(QPixmap pixmap, QWidget *parent) : RotatableLabel(pixmap, parent)
{
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotGrabMouseMove()));
}

// Grab the mouse move signal from the parent object. Get the rotation from the parent object,
// if the rotation falls within a certain range, we want to emulate "snap-into-place" and inform
// the date display object that the day may have changed
void MonthLabel::slotGrabMouseMove()
{
    float cRotation = getCurrentRotation();
    if(cRotation < 0)
        cRotation += 360;
    int mod = (int)cRotation % 30;
    if(mod < 5 || mod > 25)
    {
        int month = (int)(round(cRotation / 30));
        setCurrentRotation(month * 30);
        emit monthChanged(month + 1);
    }
}

// This function is used to set the date of the wheel. The main steps are:
// 1) Determine the number of events at the current date, also determine
//    the number of events that are in the entire year
// 2) Determine the "rotation step" to step through in the QConicalGradient
// 3) Loop through the entire year and set the colors for each month
// 4) Loop back through the month and draw the month abbreviations on the pixmap
void MonthLabel::setDate(QDate date, Event_set& eventSet)
{
    // Determine the total number of events in the year
    // Instantiate painting objects
    int totalEvents = eventSet.getNumOfEventsInYear(date.year());
    QPixmap originalPixmap(*(this->pixmap()));
    QPainter p(&originalPixmap);
    QConicalGradient grad(originalPixmap.rect().center(), 180);
    float rot = 0;

    // Determine the number of events from the first month, save for later
    int firstNum = eventSet.getNumOfEventsInMonth(1, date.year());
    QColor firstColor = RotatableLabel::getColorFromRange(firstNum, totalEvents);
    grad.setColorAt(rot, firstColor);
    rot = 0.083333333;

    // Loop through the entire year and set the colors for each month
    for(int i = 12; i > 1; i--)
    {
        int numEvents = eventSet.getNumOfEventsInMonth(i, date.year());
        QColor col = RotatableLabel::getColorFromRange(numEvents, totalEvents);
        grad.setColorAt(rot, col);
        rot += 0.083333333;
    }
    grad.setColorAt(rot, firstColor);
    p.setBrush(grad);
    p.drawEllipse(0, 0, originalPixmap.size().width(), originalPixmap.size().height());

    // Calculate the offsets of the month abbreviations
    int xPos = originalPixmap.width() * .04;
    int yPos = originalPixmap.height() / 2;
    int xTranslate = originalPixmap.width() / 2;
    int yTranslate = yPos;
    QPen wPen(Qt::black);
    p.setPen(wPen);
    QFont f = p.font();
    f.setPointSize(18);
    f.setStyleStrategy(QFont::ForceOutline);
    p.setBrush(QBrush(QColor(Qt::white)));

    // Loop back through the months and draw the month abbrevitions on top of the gradient
    for(int i = 0; i < 12; i++)
    {
        QPainterPath path;
        path.addText(xPos, yPos + 10, f, months[i]);
        p.drawPath(path);
        p.translate(xTranslate, yTranslate);
        p.rotate(30);
        p.translate(-xTranslate, -yTranslate);
    }

    // Setting the pixmap
    this->setPixmap(originalPixmap);
    int month = date.month();
    setCurrentRotation((month - 1) * 30);
}
