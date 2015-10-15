/*
 * HW2.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: tom
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
   int x = 10;

   // in C and original C++, the value 0 meant "null" for pointers.
   // these days, we use the reserved keyword "nullptr" for "null"
   int *p1 = nullptr, p2; // what type is p2? Hint: not a pointer.


   // to make sure we're on the same page, what is the output of this code?
   p1 = &p2;
   if (*p1 = x++){ // NOTE: =, not ==
      *(&x) = *p1;
   }
   cout << p2 << " " << *p1 << " " << *(&x);
   return 0;
}



