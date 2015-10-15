#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H

#include <string> 


// Class declaration for GradeBook.
// Add a member variable for the instructor's name, plus some lessons on
// overloading operators.
class GradeBook {
private:
   std::string mCourseName; 
   std::string mInstructorName;

public:
   GradeBook(const std::string &name, const std::string &instructor);

   // As before.
   void PrintGreeting();

   // As before.
   const std::string &GetCourseName() const; 
   void SetCourseName(const std::string &newName);

   // New accessor/mutator for the instructor's name. 
   const std::string &GetInstructorName() const; 
   void SetInstructorName(const std::string &newName);

   // NEW STUFF -- fill this in as lecture progresses
   
   // default constructor with no parameter
	GradeBook();
	

   // copy constructor - will make new object by using existing object
	GradeBook(const GradeBook &rhs); // rhs = right hand side. Always inclduing a single const parameter


   // operator << - A binary operator operates on 2 operans. It can redefine with a custom type. Identify the type involves in the operator. 
   //Print out the object value. Operator = function. Don't need to be long to a specific class, but more globally. 		
	//friend = modify the function of the GradeBook to make it globally																							
	friend std::ostream& operator<< (std::ostream &lhs , const GradeBook &rhs); //Print out onto the screen				
   
   
   // operator == - can redefine with a custom type. Identify the type involves in the operator.
   friend bool operator== (const GradeBook &lhs, const GradeBook &rhs); //Compare equality of 2 objects



   // operator = - Assign already to an existance variable. It can redefine with a custom type. Identify the type involves in the operator.
	GradeBook& operator=(const GradeBook &rhs); //Not a friend, appears to take one parameter, and a secret parameter = the object copying to
	


















};

#endif
