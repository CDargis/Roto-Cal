#include "detailview.h"

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>

DetailView::DetailView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    currentEvent = NULL;

    QString fieldStyleSheet, entryStyleSheet;
    fieldStyleSheet = "font-size: 9pt; font-weight: bold;";
    entryStyleSheet = "font-size: 8pt;";

    fieldTitle = new QLabel(tr("Title"), this);
    fieldLocation = new QLabel(tr("Location"), this);
    fieldDescription = new QLabel(tr("Description"), this);
    fieldStartTime = new QLabel(tr("Start Time"), this);
    fieldEndTime = new QLabel(tr("End Time"), this);

    fieldTitle->setStyleSheet(fieldStyleSheet);
    fieldLocation->setStyleSheet(fieldStyleSheet);
    fieldDescription->setStyleSheet(fieldStyleSheet);
    fieldStartTime->setStyleSheet(fieldStyleSheet);
    fieldEndTime->setStyleSheet(fieldStyleSheet);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(40);

    title = new QLabel(tr(""), this);
    location = new QLabel(tr(""), this);
    description = new QLabel(tr(""), this);
    startTime = new QLabel(tr(""), this);
    endTime = new QLabel(tr(""), this);

    title->setStyleSheet(entryStyleSheet);
    location->setStyleSheet(entryStyleSheet);
    description->setStyleSheet(entryStyleSheet);
    startTime->setStyleSheet(entryStyleSheet);
    endTime->setStyleSheet(entryStyleSheet);

    formLayout->addRow(fieldTitle, title);
    formLayout->addRow(fieldLocation, location);
    formLayout->addRow(fieldDescription, description);
    formLayout->addRow(fieldStartTime, startTime);
    formLayout->addRow(fieldEndTime, endTime);

    QPushButton* editButton = new QPushButton(tr("Edit"), this);
    formLayout->addWidget(editButton);
    QPushButton* deleteButton = new QPushButton(tr("Delete"), this);
    formLayout->addWidget(deleteButton);

    connect(editButton, SIGNAL(clicked()), this, SLOT(slotEditClicked()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(slotDeleteClicked()));
}

void DetailView::setCurrentEvent(Event* e)
{
    currentEvent = e;
    if(e == NULL)
    {
        title->setText("");
        location->setText("");
        description->setText("");
        startTime->setText("");
        endTime->setText("");
    }
    else
    {
        QDateTime qdt;

        title->setText(e->getName());
        location->setText(e->getLocation());
        description->setText(e->getDescription());
        startTime->setText(qdt.fromTime_t(e->getStartTime()).\
                           toString(tr("ddd MMM, dd yyyy hh:mm")));
        endTime->setText(qdt.fromTime_t(e->getEndTime()).\
                         toString(tr("ddd MMM, dd yyyy hh:mm")));
    }
}

void DetailView::slotEditClicked()
{
    if(currentEvent)
        emit editEventClicked(currentEvent);
}

void DetailView::slotDeleteClicked()
{
    if(currentEvent == NULL)
        return;

    // Ask the user to confirm
    QMessageBox confirm(this);
    confirm.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    confirm.setText(tr("<p>Are you sure you want to delete this event?</p>"));
    confirm.show();
    QPoint center = this->rect().center();
    center.setX(center.x() - (confirm.width() / 2));
    confirm.move(center);
    int r = confirm.exec();
    if(r == QMessageBox::Cancel)
        return;

    // Carry on and delete the event
    Event_set& set = this->getEventSet();
    set.deleteEvent(currentEvent);
    this->setCurrentEvent(NULL);
}

