/*
 * date.cpp
 *
 *  Created on: Sep 13, 2012
 *      Author: Gerron
 */

#include "date.h"
#include <iostream>
#include <string>
#include <sstream>

Date::Date(){

}

Date::Date(int day, int month, int year){
	this->day=day;
	this->month=month;
	this->year=year;
}

void Date::editDate(int day, int month, int year){
	this->day=day;
	this->month=month;
	this->year=year;
}

std::string Date::displayDate(bool numeric){
	std::stringstream date;
    if(numeric){
		date << this->month << "/" << this->day << "/" << this->year;
		return date.str();
	}
	else{
		std::string months[12] = {"January","February","March","April","May","June",
				"July","August","September","October","November","December"};
		date << months[this->month] << " " << this->day << ", " << this->year;
		return date.str();
	}
}
