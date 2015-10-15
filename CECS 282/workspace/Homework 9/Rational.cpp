/*
 * Rational.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Hieu Tran
 *
 *      Constructing and expressing in term of
 *      Rational number expression
 */
#include <iostream>
#include "Rational.h"
#include <cmath>
#include <string>

using std::string;
using namespace std;

/*
 * Default Constructor
 */
Rational::Rational() : numerator(0), denominator(1) {
}

/*
 * Constructor with 2 parameters
 * num - numerator pass by value
 * denom - denominator pass by value
 */
Rational::Rational(int num, int denom)
			  : numerator(num), denominator(denom) {

	normalize(numerator, denominator);

}

/*
 * Setting Numerator
 * &number - numerator pass by reference
 */
void Rational::setNumerator(const int &number){

	numerator = number;

}

/*
 * Getting Numerator
 */
int Rational::getNumerator() const{

	return numerator;

}

/*
 * Setting Denominator
 * &number - Denominator pass by reference
 */
void Rational::setDenominator(const int &number){

	denominator = number;

}

/*
 * Getting Denominator
 */
int Rational::getDenominator() const{

	return denominator;

}

/*
 * Normalize rational number expression to lowest form
 * num - numerator pass by vale
 * denom - denominator pass by value
 */
void Rational::normalize(int num, int denom){

	//Setting denominator to positive & numerator to negative
	if(denominator < 0 && numerator > 0){

		numerator = -numerator;

		denominator = abs(denominator);

	}

	//Setting numerator & denominator to positive
	else if(denominator < 0 && numerator < 0){

		numerator = abs(numerator);

		denominator = abs(denominator);

	}
	//Getting greatest common denominator
	int commonFactor = gcd(numerator, denominator);
	//Reduce numerator to lowest form
	numerator /= commonFactor;
	//Reduce denominator to lowest form
	denominator /= commonFactor;

}

/*
 * Getting greatest common denominator
 * num - numerator pass by value
 * denom - denominator pass by value
 */
int Rational::gcd(int num, int denom){

	int factor = 0;	//Common Factor

	for(int index = 1; index <= num || index <= denom; index++){
		//Determining greatest common denominator
		if(num % index == 0 && denom % index == 0){

				factor = index;	//Greatest common denominator

		}
	}

	return factor;

}

/*
 * Checking equality of rational numbers
 * &other - Rational number pass by reference
 */
bool Rational::equals(const Rational &other) const{

	return numerator == other.numerator
	 && denominator == other.denominator ? true:false;

}

/*
 * Adding two rational number
 * &other - Rational number pass by reference
 */
Rational Rational::add(const Rational &other) const{
	//Getting new numerator
	int num = (numerator * other.denominator) +
	 (other.numerator * denominator);
	//Getting new denominator
	int denom = (denominator * other.denominator);
	//Construct new rational number
	Rational newRational(num, denom);
	//Return new rational number
	return newRational;
}

/*
 * Printing rational expression
 */
string Rational::toString() const{

	//Printing only numerator if denominator is 0
	if (denominator == 0){

		return std::to_string(numerator);

	}
	//Printing rational expression
	return std::to_string(numerator) + "/" + std::to_string(denominator);

}
