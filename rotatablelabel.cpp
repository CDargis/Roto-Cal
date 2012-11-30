#include "rotatablelabel.h"

// Base constructor
RotatableLabel::RotatableLabel(QPixmap originalMap, QWidget *parent)
    : QLabel(parent)
{
    // Initialzie instance variables
    currentRotation = 0;
    oldRotation = 0;
    mouseIsDown = false;
    setPixmap(originalMap);

    // Conncet signals and slots to catch mouse events
    connect(this, SIGNAL(mouseDown()), this, SLOT(slotMouseDown()));
    connect(this, SIGNAL(mouseMove()), this, SLOT(slotMouseMoved()));
    connect(this, SIGNAL(mouseUp()), this, SLOT(slotMouseUp()));
}

// Overridden functions to catch mouse events ///////////////////////////////////
void RotatableLabel::mousePressEvent(QMouseEvent *ev)
{
    emit mouseDown();
    QLabel::mousePressEvent(ev);
}

void RotatableLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseMove();
    QLabel::mousePressEvent(ev);
}

void RotatableLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseUp();
    QLabel::mouseReleaseEvent(ev);
}

// Override the paint event. Get the pixmap that needs to be rotated, translate the coordinates to the center
// of that pixmap and rotate it. If the user's finger is down, then draw a "glow" around the object.
// Otherwise just draw a black ellipse.
void RotatableLabel::paintEvent(QPaintEvent *pe)
{
    QPixmap pixmap(*(this->pixmap()));
    QPainter p(this);
    p.translate(pixmap.size().width() / 2, pixmap.size().height() / 2);
    p.rotate(-currentRotation);
    p.translate(-pixmap.size().width() / 2, -pixmap.size().height() / 2);
    p.drawPixmap(0, 0, pixmap);

    QRect r = pixmap.rect();
    if(mouseIsDown)
    {
        p.setPen((QPen(QColor::fromRgb(210, 0, 170), 6)));
        p.drawEllipse(r.center(), (r.width() / 2) * .999, (r.height() / 2) * .999);
    }
    else
    {
        p.setPen((QPen(Qt::black, 9)));
        p.drawEllipse(r.center(), (r.width() / 2), (r.height() / 2));
    }
}

// SLOT FUNCTIONS /////////////////////////////////////////////////////////////////

// Catch the mouse down event. Inform the object that the user has pressed their finger down,
// initialize the point to the position of their finger, and remember the rotation from this point
void RotatableLabel::slotMouseDown()
{
    mouseIsDown = true;
    mouseDownPoint = QWidget::mapFromGlobal(QCursor::pos());
    oldRotation = -currentRotation;
    update();
}

// Catch the user moving their finger. Capture the current point and set the rotation as: the
// mouse down angle minus the current angle. Call update() to queue up paint events
void RotatableLabel::slotMouseMoved()
{
    QPoint point = QWidget::mapFromGlobal(QCursor::pos());
    float currentAngle = this->getAngle(point);
    float originalAngle = this->getAngle(mouseDownPoint);
    currentRotation = currentAngle - originalAngle;
    currentRotation += oldRotation;
    currentRotation = fmod(currentRotation, 360.00);
    currentRotation = -currentRotation;
    update();
}

// Catch the user lifting their finger. Inform the object that the finger was lifted and call
// update() to queue up a paint event (need to remove the glow)
void RotatableLabel::slotMouseUp()
{
    mouseIsDown = false;
    update();
}

// Set the current rotation of the object and call the update function to queue up a paint event
void RotatableLabel::setCurrentRotation(float rotation)
{
    currentRotation = rotation;
    update();
}

// Function to return an angle from the x-axis to the point where the user's finger is pressed
// Need to translate the coordinate system to a unit circle's coordinate system
float RotatableLabel::getAngle(QPoint point)
{
    QPixmap originalPixmap(*(this->pixmap()));
    float x = (float)(point.rx() - (originalPixmap.width() / 2));
    float y = (float)((originalPixmap.height() / 2) - point.ry());
    return atan2(x, y) * (180 / PI);
}

// This is a static function that returns the "in" paramater scaled from the range [oldMin, oldMax] to
// the range [newMin, newMax]
float RotatableLabel::scaleRange(float in, float oldMin, float oldMax, float newMin, float newMax)
{
    return (((newMax - newMin) * (in - oldMin)) / (oldMax - oldMin)) + newMin;
}

// Return a QColor object based on x scaled from totalEvents
QColor RotatableLabel::getColorFromRange(float x, float totalEvents)
{
    if(x == 0 || totalEvents == 0) return QColor::fromRgb(50, 165, 240);   // Base shade of blue
    float perc = x / totalEvents;
    perc *= 100;
    if(perc < 5) return QColor::fromRgb(0, 255, 255); // Cyan
    if(perc < 25) return QColor::fromRgb(255, 255, 0); // yellow
    return QColor::fromRgb(255, 0, 25);       // red
}
