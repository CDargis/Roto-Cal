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
    QWidget(parent)
{
    QFormLayout* mainLayout = new QFormLayout(this);
    QLabel* addTitle = new QLabel(tr("Add an Event"), this);
    QFont font = addTitle->font();
    font.setBold(true);
    font.setPointSize(12);
    addTitle->setFont(font);
    QGridLayout* centerTitle = new QGridLayout(this);
    centerTitle->addWidget(addTitle);
    mainLayout->addRow(centerTitle);

    QHBoxLayout* titleInput = new QHBoxLayout(this);
    QLabel* title = new QLabel(tr("Title:"), this);
    titleEdit = new QLineEdit(this);
    titleInput->addWidget(title);
    titleInput->addWidget(titleEdit);
    mainLayout->addRow(titleInput);

    QHBoxLayout* descInput = new QHBoxLayout(this);
    QLabel* desc = new QLabel(tr("Description:"), this);
    descEdit = new QLineEdit(this);
    descInput->addWidget(desc);
    descInput->addWidget(descEdit);
    mainLayout->addRow(descInput);

    QHBoxLayout* sTimeInput = new QHBoxLayout(this);
    QLabel* sTime = new QLabel(tr("Start Time:"), this);
    sTimeEdit = new QDateTimeEdit(this);
    sTimeEdit->setDateTime(QDateTime::currentDateTime());
    sTimeEdit->showMaximized();
    sTimeInput->addWidget(sTime);
    sTimeInput->addWidget(sTimeEdit);
    mainLayout->addRow(sTimeInput);

    QHBoxLayout* eTimeInput = new QHBoxLayout(this);
    QLabel* eTime = new QLabel(tr("End Time:"), this);
    eTimeEdit = new QDateTimeEdit(this);
    eTimeEdit->setDateTime(QDateTime::currentDateTime());
    eTimeEdit->showMaximized();
    eTimeInput->addWidget(eTime);
    eTimeInput->addWidget(eTimeEdit);
    mainLayout->addRow(eTimeInput);

    QHBoxLayout* buttonLayout = new QHBoxLayout(this);
    QPushButton* addButton = new QPushButton(tr("Add"), this);
    QPushButton* cancelButton = new QPushButton(tr("Cancel"), this);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addRow(buttonLayout);
    connect(addButton, SIGNAL(clicked()), this, SLOT(slotAddClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(slotCancelClicked()));

    setLayout(mainLayout);
}

void AddEventWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e->key();
    QWidget::keyPressEvent(e);
}

void AddEventWidget::resetInput()
{
    titleEdit->setText(tr(""));
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
