#include <vector>
#include <iostream>

#include "GradeBook.h"

using namespace std;

int main(int argc, char* argv[]) {
   // Suppose you want a vector of variables created on the heap.
   // Why would you want this?




   // Let's go with a vector of 
   vector<GradeBook *> books; // a vector of pointers to books on the heap.
   books.push_back(new GradeBook("CECS 282", "Neal Terrell", 10));
   books.push_back(new GradeBook(*books[0])); // ?
   books.push_back(new GradeBook("CECS 579", "Mehrdad Aliasgari", 20));
   
   // two ways to access these elements:

   cout << endl << "With iterators" << endl;
   for (vector<GradeBook *>::iterator itr = books.begin(); itr != books.end();
    itr++) {
      cout << **itr << endl; // ** ??Go to iterator and follow the first pointer and iterate throughout the array of pointers.




   }

   cout << endl << "With enhanced for loop" << endl;
   for (GradeBook *b : books) {
      cout << *b << endl;
   }


   // what happens if I clear this vector?
   // books.clear();	//A loop of keep calling pop back until it's empty except it's on the heap. It will be dangerous if 





   GradeBook *last = books.back();	//Pointer to the last item of the Gradebook
   delete last;
   books.pop_back();	//Delete the last pointer of the array.


   // so how do I safely clear a vector of heap pointers?
	//	Loop through whole array of pointers to delete if it's on the heap.
   for (GradeBook *b : books) {
      delete b;
   }
   books.clear();


   


}
