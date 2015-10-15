#include <string>
#include <iostream>

#include "GradeBook.h"

using namespace std;

// some functions for later
void PassByValue(GradeBook copy);


int main(int argc, char* argv[]) {
   GradeBook book282("CECS 282", "Neal Terrell");
   cout << book282 << endl;
<<<<<<< HEAD

   cout << endl << endl;
   cout << "Passing by value..." << endl;
   PassByValue(book282);

=======
   
   /*
>>>>>>> ed100c232686ad096d23ec1f293a5d5c5557505d
   GradeBook book228("CECS 228", "Neal Terrell");
   if (!(book282 == book228)) { // what is this doing?
      cout << "The books are equal" << endl;
   }
   else {
      cout << "The books are not equal" << endl;
   }
<<<<<<< HEAD

	GradeBook copy(book282); //Copy of GradeBook  
 
=======
   /*
   GradeBook copy(book282);

   book228 = book282;
   cout << book228
   */
}   /*

cout << endl << endl;
cout << "Passing by value..." << endl;
PassByValue(book282);

>>>>>>> ed100c232686ad096d23ec1f293a5d5c5557505d
   cout << endl << "Assignment operator" << endl;
   book282 = book228;
	cout << book228 << "is now " << book282 << endl;


   if (book282 == book228) {
      cout << "yes" << endl << endl;
   }
   cout << book282 << endl; // what happens?
}*/


void PassByValue(GradeBook copy) {
   cout << copy << endl;
}
