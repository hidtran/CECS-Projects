#include "LinkedQueue.h"
#include <iostream>
using namespace std;


int mains() {
   // Demonstrate that our LinkedQueue works.
   LinkedQueue numbers;

   numbers.Add(4);
   numbers.Add(8);
   numbers.Add(15);
   numbers.Add(16);
   numbers.Add(23);
   numbers.Add(42);

   while (numbers.Size() > 0) {
      int data = numbers.Remove();
      cout << "Removed " << data << endl;
   }
   // This seems to work! Yay!
   // But there are sinister bugs hidden from view...


   // First, what happened to the Nodes that got unlinked from the queue? Declare a temporary linkedqueue variable



   // Second, what happens if I Remove from an empty queue? return -9999



   // Now that we've fixed those errors...
   // Third, what's up with this code?
   LinkedQueue second;
   second.Add(1);

   LinkedQueue copy(second); // make a copy of second
   copy.Add(2);
   cout << second.Size() << endl; // output: 1
   cout << copy.Size() << endl;   // output: 2
	
	//Double deletion will crash the program, Aka "A shallow copy"
	//Need to do a deep copy by writing a new copy contructor.
   second.Remove();
   copy.Remove();
   // whoops! What happened?





   // One final bug:
   if (true) {
      LinkedQueue third;
      third.Add(5);
      third.Add(6);

<<<<<<< HEAD
      // What happens when third goes out of scope? The last node goes back to the first node.
      



      // What do we need to fix this? Create a destructor.
	
   }

	//Catching empty linkedqueue
	LinkedQueue empty;
	try{	
		empty.Remove();
		cout << "This shouldn't print" << endl;
	}

	catch (std::out_of_range &ex){
		//what() - what went wrong with the code
		cout << "Caught the exception, with message" << ex.what() << endl;
	}
	
	//Compare pass by value to pass by reference
	cout << endl << endl;
	LinkedQueue primes;
	primes.Add(2);
	primes.Add(3);
	primes.Add(5);
	primes.Add(7);
	primes.Add(11);
	PassByValue(primes);

	cout << endl << "Now pass by reference" << endl;
	PassByReference(primes);

	cout << endl << endl << "THERE IS ONE FINAL BUG IN THE QUEUE" << endl;
	empty = primes;	//What is this calling? Did we define it? Assignment operator=. Empty & primes both have memory already. Compiler 
							//generate automatic when deep constructor & assignment operator= have not been created. Shallow copy by default
	empty.Remove();	//Double deletion = error.
	primes.Remove();
	return 0;

}

void PassByValue(LinkedQueue param){
	//Don't modify the original linkedqueue variable object
	//Slow process than PassByReference()	
	cout << param.Size() << endl;
}

void PassByReference(const LinkedQueue &param){
	//Destructor of linkedqueue didn't called since primes still on the stack
	cout << param.Size() << endl;

}
=======
      // What happens when third goes out of scope?
      // What do we need to fix this?
   }

   for (int i = 0; i < 0; i++) {
      LinkedQueue temp;
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
      temp.Add(1);
   }

   LinkedQueue empty;
   cout << empty.Remove();
   return 0;
}
>>>>>>> fe7b745c7d6660c025dd5da914234ef1d22d8a35
