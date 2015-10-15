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

	Rational r2(2, 3);	//New Constructor

	Rational copy(r2); //Copy Constructor

	//Printing a rational number
	cout << "R2: " << r2.toString() << endl;
	//Setting new numerator for default constructor
	r1.setNumerator(3);
	//Setting new denominator for default constructor
	r1.setDenominator(4);
	//Printing a rational number
	cout << "R1: " << r1.toString() << endl;
	//Checking equality between rational numbers
	cout << "R1 Equals R2: " << r1.equals(r2) << endl;
	//Adding two rational numbers
	cout << "R1 add R2: " << r1.add(r2).toString() << endl;
	cout << "R1 + R2: " << (r1 + r2).toString() << endl;
	//Negation of a rational number
	cout << "-R1: " << (-r1).toString() << endl;
	//Subtracting two rational numbers
	cout << "R1 - R2: " << (r1 - r2).toString() << endl;
	//Multiplying two rational numbers
	cout << "R1 * R2: " << (r1 * r2).toString() << endl;
	//Dividing two rational numbers
	cout << "R1 / R2: " << (r1 / r2).toString() << endl;
	//Comparing inequalities between two rational numbers
	cout << "R1 < R2: " << (r1 < r2) << endl;		//Less than
	cout << "R1 <= R2: " << (r1 <= r2) << endl;	//Less than or equal
	cout << "R1 > R2: " << (r1 > r2) << endl;		//Greater than
	cout << "R1 >= R2: " << (r1 >= r2) << endl;	//Greater than or equal
	cout << "R1 == R2: " << (r1 == r2) << endl;	//Equal
	cout << "R1 != R2: " << (r1 != r2) << endl;	//Not equal
	//A copy of a rational number
	cout << "R2 copy: " << copy.toString() << endl;

	cout << r2 << endl;
}
