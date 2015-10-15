/*
 * GradeBook.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: tom
 */
#include <iostream>
#include <string>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string course, string instructor)
				: courseName(course), instructName(instructor){
}

void GradeBook::printGreeting(string course, string instructor){
	cout << "Welcome to the Grade Book for " << course << endl;
	cout << "This course is presented by:  " << instructor << endl;
}

void GradeBook::setCourseName(string name){
	courseName = name;
}

string GradeBook::getCourseName() const{
	return courseName;
}

void GradeBook::setInstructorName(string instructor){
	instructName = instructor;
}

string GradeBook::getInstructorName() const{
	return instructName;
}

int mains(int argc, char* argv[]){
	GradeBook course1 ("CECS 282", "Neal Terrel");

	cout << "Your current course: " << course1.getCourseName() << endl;
	cout << "Your current professor: " << course1.getInstructorName() << endl;

}

