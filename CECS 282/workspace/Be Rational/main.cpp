/*
 * main.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: Hieu Tran
 *
 *      Running Rational number class
 */
#include <iostream>
#include "Rational.h"

using namespace std;

int main(int argc, char* argv[]){

	Rational r1; 			//Default constructor

	Rational r2(5, 12);	//New Constructor
	//Printing r2 rational number
	cout << "R2: " << r2.toString() << endl;
	//Setting new numerator for default constructor
	r1.setNumerator(48);
	//Setting new denominator for default constructor
	r1.setDenominator(36);
	//Printing r1 numerator
	cout << "R1 Numerator: " << r1.getNumerator() << endl;
	//Printing r2 denominator
	cout << "R1 Denominator: " << r1.getDenominator() << endl;
	//Checking equality of r1 & r2
	cout << "R1 Equals R2: " << r1.equals(r2) << endl;
	//Adding two rational numbers
	cout << "R1 add R2: " << r1.add(r2).toString() << endl;

}
