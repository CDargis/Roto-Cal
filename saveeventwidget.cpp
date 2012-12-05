#include "saveeventwidget.h"

#include <QDebug>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>

// Constructor for the save event widget
// Initialize the parent objects. Set the current event to NULL because no event is being edited yet
// Setup all of the layouts and initialize the GUI objects
SaveEventWidget::SaveEventWidget(Event_set &set, CalendarWidget& widget, QWidget *parent) :
    QWidget(parent), CalObject(set), cWidget(widget)
{
    currentEvent = NULL;

    QVBoxLayout* mainLayout = new QVBoxLayout;

    QFormLayout* form = new QFormLayout;
    QLabel* addTitle = new QLabel(tr("Save an Event"), this);
    QFont font = addTitle->font();
    font.setBold(true);
    font.setPointSize(12);
    addTitle->setFont(font);
    QGridLayout* centerTitle = new QGridLayout;
    centerTitle->addWidget(addTitle);
    form->addRow(centerTitle);

    titleEdit = new CDLineEdit(this);
    form->addRow(tr("Title:"), titleEdit);
    locationEdit = new CDLineEdit(this);
    form->addRow(tr("Location:"), locationEdit);
    descEdit = new CDLineEdit(this);
    form->addRow(tr("Description:"), descEdit);

    QVBoxLayout* sTimeInput = new QVBoxLayout;
    QLabel* sTime = new QLabel(tr("Start Time:"), this);

    sGWidget = new GDateTimeEdit(this);
    sTimeInput->addWidget(sTime);
    form->addRow(sTimeInput);
    form->addRow(sGWidget);

    QVBoxLayout* eTimeInput = new QVBoxLayout;
    QLabel* eTime = new QLabel(tr("End Time:"), this);
    eGWidget = new GDateTimeEdit(this);
    eTimeInput->addWidget(eTime);
    form->addRow(eTimeInput);
    form->addRow(eGWidget);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QPushButton* saveButton = new QPushButton(tr("Save"), this);
    QPushButton* cancelButton = new QPushButton(tr("Cancel"), this);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(form);
    mainLayout->addLayout(buttonLayout);

    // Connect the clicked signals from the buttons to their appropriate handlers
    connect(saveButton, SIGNAL(clicked()), this, SLOT(slotSaveClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(slotCancelClicked()));
    mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    setLayout(mainLayout);
}

// slot for the save button being clicked. If the current event object is null, then the
// user is not editing an event and is therefore creating a new one
void SaveEventWidget::slotSaveClicked()
{
    if(currentEvent) editEvent();
    else createNewEvent();
}

// Handler for the cancel button being clicked. Just need to emit the signal to change the screen index
void SaveEventWidget::slotCancelClicked()
{
    emit closeScreen(NULL);
}

// This function presets the input fields to the parameters passed through the function
// Used to either clear the input fields or input a current event object's data into the field
void SaveEventWidget::setInput(QDateTime start, QDateTime end, QString title,
                               QString location, QString description)
{
    titleEdit->setText(title);
    locationEdit->setText(location);
    descEdit->setText(description);
    sGWidget->setDateTime(start);
    eGWidget->setDateTime(end);
}

// This function is called when the user wishes to create a new event
// Do some error checking on the user's input and handle accordingly
void SaveEventWidget::createNewEvent()
{
    Event* e;
    bool duplicate;

    if (titleEdit->text().isEmpty()) {
        QMessageBox mBox;
        mBox.setText("Enter a Title");
        mBox.show();
        mBox.move( this->width() / 2 - mBox.width() / 2, this->height() / 2 -\
                   mBox.height() / 2 );
        mBox.exec();
    } else if (!checkStartTime(sGWidget->getDateTime().toTime_t(),\
                               eGWidget->getDateTime().toTime_t())){
        QMessageBox mBox;
        mBox.setText("Start Time occurs after End Time");
        mBox.show();
        mBox.move( this->width() / 2 - mBox.width() / 2, this->height() / 2 -\
                   mBox.height() / 2 );
        mBox.exec();
    } else {
        e = new Event;
        /* insert field data from widget to event object */
        e->setName(titleEdit->text());
        e->setDescription(descEdit->text());
        e->setLocation(locationEdit->text());
        e->setStartTime(sGWidget->getDateTime().toTime_t());
        e->setEndTime(eGWidget->getDateTime().toTime_t());

        duplicate = eventSet.insertEvent(e);
        if (duplicate) {
            QMessageBox mBox;
            mBox.setText("Duplicate Event");
            mBox.show();
            mBox.move( this->width() / 2 - mBox.width() / 2, this->height() / 2\
                       - mBox.height() / 2 );
            mBox.exec();
            delete(e); // delete event since identical already exists
        } else {
            qDebug() << "size after new" << eventSet.getSize();
            emit closeScreen(NULL);
        }
    }
}

// This function is called when a user wishes to edit an event
// Do some error checking on the user's input and handle accordingly
void SaveEventWidget::editEvent()
{
    bool duplicate = false;

    /* populate event with editeventwidget data fields */
    Event* tmpEvent = new Event(titleEdit->text(), locationEdit->text(),\
                                descEdit->text(), sGWidget->getDateTime().toTime_t(),
                                eGWidget->getDateTime().toTime_t());

    /* check start/end time for conflicts */
    if (!checkStartTime(tmpEvent->getStartTime(),\
                        tmpEvent->getEndTime())) {
        QMessageBox mBox;
        mBox.setText("Start Time occurs after End Time");
        mBox.show();
        mBox.move( this->width() / 2 - mBox.width() / 2, this->height() / 2 -\
                   mBox.height() / 2 );
        mBox.exec();
        delete(tmpEvent); // delete tmp (no need to update data structure)

    /* title or starttime changed */
    } else if (currentEvent->getName() != tmpEvent->getName() ||\
               currentEvent->getStartTime() != tmpEvent->getStartTime()) {
        /* if duplicate of another event */
        if ((duplicate = eventSet.editEvent(currentEvent, tmpEvent))) {
            QMessageBox mBox;
            mBox.setText("Edited event duplicate of existing event");
            mBox.show();
            mBox.move(this->width() / 2 - mBox.width() / 2, this->height() / 2\
                      - mBox.height() / 2);
            mBox.exec();
            delete(tmpEvent); // delete tmp (no need to update data structure)
            emit closeScreen(currentEvent);
        /* insert successful */
        } else {
            emit closeScreen(tmpEvent);
        }
    /* title/starttime untouched but location/description/endtime touched */
    } else if (currentEvent->getLocation() != tmpEvent->getLocation() ||\
               currentEvent->getDescription() != tmpEvent->getDescription() ||\
               currentEvent->getEndTime() != tmpEvent->getEndTime()) {
        /* change event, no need to access data structure */
        currentEvent->setLocation(tmpEvent->getLocation());
        currentEvent->setDescription(tmpEvent->getDescription());
        currentEvent->setEndTime(tmpEvent->getEndTime());
        delete(tmpEvent); // delete temp event
        emit closeScreen(currentEvent);
    /* if here, save clicked but nothing edited */
    } else {
        QMessageBox mBox;
        mBox.setText("No changes made to event");
        mBox.show();
        mBox.move(this->width() / 2 - mBox.width() / 2, this->height() / 2\
                  - mBox.height() / 2);
        mBox.exec();
        delete(tmpEvent); // delete tmp (no need to update data structure)
        emit closeScreen(currentEvent);
    }
}

// This function checks whether or not the end time occurs before the start time
bool SaveEventWidget::checkStartTime(time_t start, time_t end) {
    if (end < start)
        return false;
    return true;
}

void SaveEventWidget::setDate(QDate date)
{
    // This function is currently not being used
}
