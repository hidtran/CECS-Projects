/*
 * Date.h
 *
 *  Created on: Feb 26, 2015
 *      Author: tom
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(int lunes, int dias, int anos);
	void displayDate();
	void setMonth(int input);
	int getMonth() const;
	void setDay(int input);
	int getDay() const;
	void setYear(int input);
	int getYear() const;
};

#endif /* DATE_H_ */
