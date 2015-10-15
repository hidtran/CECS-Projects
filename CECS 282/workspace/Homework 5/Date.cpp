/*
 * Date.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: tom
 */

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int lunes, int dias, int anos){
	setMonth(lunes);
	setDay(dias);
	setYear(anos);
}

void Date::displayDate(){

	cout << "Welcome to CSULB Calendar!" << endl;
	cout << "Today's Date: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}

void Date::setMonth(int input){

	if(input >= 1 && input <= 12){
		month = input;
	}
	else{
		month = 1;
		cerr << input << " Exceeds the maximum month limit (12).\n"
		 << "Limiting month to the first 12. Month will set to 1 if exceeds 12." << endl;
	}
}

int Date::getMonth() const{
	return month;
}

void Date::setDay(int input){
	day = input;
}

int Date::getDay() const{
	return day;
}

void Date::setYear(int input){
	year = input;
}

int Date::getYear() const{
	return year;
}

int main(int argc, char* arg[]){

	Date calendar1(2, 27, 2015);
	calendar1.displayDate();
	Date calendar2(13, 28, 2015);
	cout << "Previous Date: " << calendar2.getMonth() << "/" << calendar2.getDay();
	cout << "/" << calendar2.getYear() << endl;
}
