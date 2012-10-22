#include "addeventwidget.h"

#include <QDebug>

#include <QKeyEvent>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>

AddEventWidget::AddEventWidget(QWidget *parent) :
    QWidget(parent), CalObject()
{
    lastPoint = QPoint(0, 0);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QFormLayout* form = new QFormLayout(this);
    QLabel* addTitle = new QLabel(tr("Add an Event"), this);
    QFont font = addTitle->font();
    font.setBold(true);
    font.setPointSize(12);
    addTitle->setFont(font);
    QGridLayout* centerTitle = new QGridLayout(this);
    centerTitle->addWidget(addTitle);
    form->addRow(centerTitle);

    titleEdit = new QLineEdit(this);
    form->addRow(tr("Title:"), titleEdit);

    locationEdit = new QLineEdit(this);
    form->addRow(tr("Location:"), locationEdit);

    descEdit = new QLineEdit(this);
    form->addRow(tr("Description:"), descEdit);

    QVBoxLayout* sTimeInput = new QVBoxLayout(this);
    QLabel* sTime = new QLabel(tr("Start Time:"), this);
    sTimeEdit = new QDateTimeEdit(this);
    sTimeEdit->setDateTime(QDateTime::currentDateTime());
    sTimeEdit->showMaximized();
    sTimeInput->addWidget(sTime);
    sTimeInput->addWidget(sTimeEdit);
    form->addRow(sTimeInput);

    QVBoxLayout* eTimeInput = new QVBoxLayout(this);
    QLabel* eTime = new QLabel(tr("End Time:"), this);
    eTimeEdit = new QDateTimeEdit(this);
    eTimeEdit->setDateTime(QDateTime::currentDateTime());
    eTimeEdit->showMaximized();
    eTimeInput->addWidget(eTime);
    eTimeInput->addWidget(eTimeEdit);
    form->addRow(eTimeInput);

    QHBoxLayout* buttonLayout = new QHBoxLayout(this);
    QPushButton* addButton = new QPushButton(tr("Add"), this);
    QPushButton* cancelButton = new QPushButton(tr("Cancel"), this);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(form);
    mainLayout->addLayout(buttonLayout);

    connect(addButton, SIGNAL(clicked()), this, SLOT(slotAddClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(slotCancelClicked()));
    mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    setLayout(mainLayout);
}

void AddEventWidget::mouseMoveEvent(QMouseEvent *e)
{
    // Scrolling down or up
    QPoint p = QWidget::mapFromGlobal(QCursor::pos());
    if(p.ry() < lastPoint.ry()) scroll(0, -5);
    else scroll(0, 5);
    lastPoint = p;
    QWidget::mouseMoveEvent(e);
}

void AddEventWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e->key();
    QWidget::keyPressEvent(e);
}

void AddEventWidget::resetInput()
{
    titleEdit->setText(tr(""));
    locationEdit->setText(tr(""));
    descEdit->setText(tr(""));
    sTimeEdit->setDateTime(QDateTime::currentDateTime());
    eTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void AddEventWidget::slotAddClicked()
{
    resetInput();
    emit setScreenIndex(0);
}

void AddEventWidget::slotCancelClicked()
{
    resetInput();
    emit setScreenIndex(0);
}
