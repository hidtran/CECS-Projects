// This example shows multi-file Class definitions, using the standard 
// organization REQUIRED in this course.

#ifndef __GRADEBOOK_H
#define __GRADEBOOK_H
// these are called "include guards" -- ? *Prevent files from copy and paste into more targets at once*.


/*
A C++ class is usually split into two files: a .h containing its DECLARATION, 
and a .cpp containing its DEFINITION/implementation. Like a function
prototype, a declaration will inform the compiler about WHAT a class "can do",
but not necessarily HOW it works.The implementation of the class will come in 
another file.
*/


// Every file is compiled separately and needs to #include any relevant files
#include <string> // for string variable type.


// Class declaration for GradeBook. 
class GradeBook {
private:
   std::string mCourseName; // *Do NOT USE NAMESPACES IN .H FILES*; SCOPE INSTEAD

public:
   // For methods, we no longer have the body of the method in this file.
   // Only the method header goes here.
   void PrintGreeting(); //No body into PrintGreeting().

   // Same for constructors.

   // Note the parameter now. Why const? Why reference? *Referencing to original variable while not changing any values*. 
   // *Use for speed (reference) and safety (const)*
   GradeBook(const std::string &name);
   




   const std::string &GetCourseName() const; // What is this const doing here? See class notebook.



   void SetCourseName(const std::string &newName);
}; //*";" is important

#endif //Must have to pair with #ifndef
