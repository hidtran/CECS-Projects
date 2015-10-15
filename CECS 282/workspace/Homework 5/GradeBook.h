/*
 * GradeBook.h
 *
 *  Created on: Feb 26, 2015
 *      Author: tom
 */

#ifndef GRADEBOOK_H_
#define GRADEBOOK_H_

#include <string>

class GradeBook {

private:
	std::string courseName;
	std::string instructName;
public:
	GradeBook(std::string course, std::string instructor);
	void printGreeting(std::string course, std::string instructor);
	void setCourseName(std::string name);
	std::string getCourseName() const;
	void setInstructorName(std::string instructor);
	std::string getInstructorName() const;

};

#endif /* GRADEBOOK_H_ */
