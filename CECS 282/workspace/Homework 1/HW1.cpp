/*
 * HW1.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Hieu
 *      Generate an integer in the range of 5 to 15
 *      Ask user to input integers one at a time repeating
 *      until they enter 0 to stop
 *
 */
#include <iostream>
#include <random>

using namespace std;
int main(int argc, char* argv[]){

   //For question #2 in HW #1
   random_device rand;

   default_random_engine engine(rand());

   uniform_int_distribution<int> distr(5, 15);

   int choice = distr(engine);

   cout << "Generate number between 5 to 15: " << choice << endl;

   //For question #6 in HW #6
   cout << "Enter integers (0 to stop)" << endl;

   bool stop = false;

   double smallest, largest;
   double average;
   int count = 0;

   while(!stop){
	   int input;
	   cin >> input;
	   average += input;
	   count++;
	   if(count == 1){
		   largest = input;
		   smallest = input;
	   }
	   else {
		   if(input != 0){
			   if(input > largest)
				   largest = input;
			   else if(input < smallest)
				   smallest = input;
			   else{
				   average -= input;
				   count--;
			   }
		   }
		   else{
			   stop = true;
			   count--;
			   break;
		   }
	   }
   }

   average = (average - smallest - largest) / (count - 2);

   cout << "After discarding the low and the high, the average: " << average << endl;
}



