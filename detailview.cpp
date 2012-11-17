#include "detailview.h"

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

DetailView::DetailView(QRect &pageGeometry, Event_set &set, QWidget *parent) :
    RotaryView(pageGeometry, set, parent)
{
    currentEvent = NULL;

    QFont fieldFnt;
    QFont fnt;

    fieldFnt.setPointSize(10);
    fnt.setPointSize(8);

    fieldTitle = new QLabel(tr("Title"), this);
    fieldDescription = new QLabel(tr("Description"), this);
    fieldLocation = new QLabel(tr("Location"), this);
    fieldStartTime = new QLabel(tr("Start Time"), this);
    fieldEndTime = new QLabel(tr("End Time"), this);

    fieldTitle->setFont(fieldFnt);
    fieldDescription->setFont(fieldFnt);
    fieldLocation->setFont(fieldFnt);
    fieldStartTime->setFont(fieldFnt);
    fieldEndTime->setFont(fieldFnt);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->setSpacing(70);

    title = new QLabel(tr(""), this);
    description = new QLabel(tr(""), this);
    location = new QLabel(tr(""), this);
    startTime = new QLabel(tr(""), this);
    endTime = new QLabel(tr(""), this);

    title->setFont(fnt);
    description->setFont(fnt);
    location->setFont(fnt);
    startTime->setFont(fnt);
    endTime->setFont(fnt);

    formLayout->addRow(fieldTitle, title);
    formLayout->addRow(fieldDescription, description);
    formLayout->addRow(fieldLocation, location);
    formLayout->addRow(fieldStartTime, startTime);
    formLayout->addRow(fieldEndTime, endTime);

    QPushButton* editButton = new QPushButton(tr("Edit"), this);
    formLayout->addWidget(editButton);

    connect(editButton, SIGNAL(clicked()), this, SLOT(slotEditClicked()));
}

void DetailView::setCurrentEvent(Event* e)
{
    currentEvent = e;

    QDateTime qdt;

    title->setText(e->getName());
    description->setText(e->getDescription());
    location->setText(e->getLocation());
    startTime->setText(qdt.fromTime_t(e->getStartTime()).\
                       toString(tr("ddd MMM yyyy hh:mm")));
    endTime->setText(qdt.fromTime_t(e->getEndTime()).\
                     toString(tr("ddd MMM yyyy hh:mm")));
}

void DetailView::slotEditClicked()
{
    if(currentEvent)
        emit editEventClicked(currentEvent);
}
