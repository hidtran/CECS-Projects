/*
 * HW6.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: tom
 */
#include <iostream>
#include <sstream>

using namespace std;

string toString() const{
	ostringstream output;

	//Printing only numerator if denominator is 0
	if (mDenominator == 0){
		output << mNumerator;
	}

	else{
		//Printing rational expression
		output << mNumerator << "/" << mDenominator;
	}

	return "Rational: " + output.str();

}

int main(int argc, char* argv[]){

	string s = "100 200 300";

	istringstream istring(s);

	int integer1 = 0;
	int integer2 = 0;
	int integer3 = 0;

	istring >> integer1 >> integer2 >> integer3;

	cout << "Integer 1: " << integer1 << "Integer 2: " << integer2 << endl;
}



