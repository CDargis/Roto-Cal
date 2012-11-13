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

SaveEventWidget::SaveEventWidget(Event_set &set, CalendarWidget& widget, QWidget *parent) :
	QWidget(parent), CalObject(set), cWidget(widget)
{
	lastPoint = QPoint(0, 0);
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	QFormLayout* form = new QFormLayout(this);
	QLabel* addTitle = new QLabel(tr("Save an Event"), this);
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
	sTimeEdit->setDisplayFormat(tr("d MMM yyyy HH:mm"));
	sTimeEdit->showMaximized();
	sTimeInput->addWidget(sTime);
	sTimeInput->addWidget(sTimeEdit);
	form->addRow(sTimeInput);

	QVBoxLayout* eTimeInput = new QVBoxLayout(this);
	QLabel* eTime = new QLabel(tr("End Time:"), this);
	eTimeEdit = new QDateTimeEdit(this);
	eTimeEdit->setDisplayFormat(tr("d MMM yyyy HH:mm"));
	eTimeEdit->showMaximized();
	eTimeInput->addWidget(eTime);
	eTimeInput->addWidget(eTimeEdit);
	form->addRow(eTimeInput);

	QHBoxLayout* buttonLayout = new QHBoxLayout(this);
	QPushButton* saveButton = new QPushButton(tr("Save"), this);
	QPushButton* cancelButton = new QPushButton(tr("Cancel"), this);
	buttonLayout->addWidget(saveButton);
	buttonLayout->addWidget(cancelButton);

	mainLayout->addLayout(form);
	mainLayout->addLayout(buttonLayout);

	connect(saveButton, SIGNAL(clicked()), this, SLOT(slotSaveClicked()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(slotCancelClicked()));
	mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

	resetInput();
	setLayout(mainLayout);
}

void SaveEventWidget::mouseMoveEvent(QMouseEvent *e)
{
	// Scrolling down or up
	//QPoint p = QWidget::mapFromGlobal(QCursor::pos());
	//if(p.ry() < lastPoint.ry()) scroll(0, -5);
	//else scroll(0, 5);
	//lastPoint = p;
	QWidget::mouseMoveEvent(e);
}

void SaveEventWidget::keyPressEvent(QKeyEvent *e)
{
	qDebug() << e->key();
	QWidget::keyPressEvent(e);
}

void SaveEventWidget::resetInput()
{
	titleEdit->setText(tr(""));
	locationEdit->setText(tr(""));
	descEdit->setText(tr(""));
	sTimeEdit->setDateTime(cWidget.getCurrentDateTime());
	eTimeEdit->setDateTime(cWidget.getCurrentDateTime().addSecs(60*60));
}

void SaveEventWidget::slotSaveClicked()
{
	Event* e;                                                                   
	bool notDup;                                                                

	if (titleEdit->text().isEmpty()) {                                          
		QMessageBox mBox;                                                       
		mBox.setText("Enter a Title");                                          
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
		e->setStartTime(sTimeEdit->dateTime().toTime_t());                      
		e->setEndTime(eTimeEdit->dateTime().toTime_t());

		notDup = eventSet.insertEvent(e);                                       
		if (!notDup) {                                                          
			QMessageBox mBox;                                                   
			mBox.setText("Duplicate Event");                                    
			mBox.show();                                                        
			mBox.move( this->width() / 2 - mBox.width() / 2, this->height() / 2\
					- mBox.height() / 2 );                                   
			mBox.exec();                                                        
			delete(e); // delete event since identical already exists           
		} else {                                                                
			qDebug() << "Event " << e->getName() << " Added,"<< "Starts at" << \
				e->getHour() << ":" << e->getMinute() << "w/set size = " << eventSet.getSize();                                                     
            emit closeScreen();
		}                                                                       
	}
}

void SaveEventWidget::slotCancelClicked()
{
    emit closeScreen();
}

void SaveEventWidget::setInput(QDateTime start, QDateTime end, QString title,
                               QString location, QString description)
{
    titleEdit->setText(title);
    locationEdit->setText(location);
    descEdit->setText(description);
    sTimeEdit->setDateTime(start);
    eTimeEdit->setDateTime(end);
}
