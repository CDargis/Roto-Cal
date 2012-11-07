/*
 * time1.cpp
 *
 *  Created on: Sep 13, 2012
 *      Author: Gerron
 */

#include "time1.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QDebug>

Time1::Time1(){

}

Time1::Time1(int hour, int minute, bool am, bool pm){
    this->hour = hour;
	this->minute = minute;
	this->am = am;
	this->pm = pm;
}

void Time1::editTime(int hour, int minute, bool am, bool pm){
    this->hour = hour;
    this->minute = minute;
	this->am = am;
	this->pm = pm;
}

std::string Time1::displayTime(){
	std::stringstream time;
    std::string meridiem;
    if(this->am){
        meridiem = "AM";
    }
    else{
        meridiem = "PM";
    }
    time << this->hour << ":" << this->minute << " " << meridiem ;
	return time.str();
}




