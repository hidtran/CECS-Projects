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
Rational::Rational() : mNumerator(0), mDenominator(1) {
}

/*
 * Constructor with 2 parameters
 * num - numerator pass by value
 * denom - denominator pass by value
 */
Rational::Rational(int num, int denom)
			  : mNumerator(num), mDenominator(denom) {

	normalize(mNumerator, mDenominator);

}

/*
 * Making a copy of rational number
 */
Rational::Rational(const Rational &copy)
			  : mNumerator(copy.mNumerator), mDenominator(copy.mDenominator){
}

/*
 * Setting Numerator
 * &number - numerator pass by reference
 */
void Rational::setNumerator(int number){

	mNumerator = number;

}

/*
 * Getting Numerator
 */
int Rational::getNumerator() const{

	return mNumerator;

}

/*
 * Setting Denominator
 * &number - Denominator pass by reference
 */
void Rational::setDenominator(int number){

	mDenominator = number;

}

/*
 * Getting Denominator
 */
int Rational::getDenominator() const{
	return mDenominator;

}

/*
 * Normalize rational number expression to lowest form
 * num - numerator pass by vale
 * denom - denominator pass by value
 */
void Rational::normalize(int num, int denom){

	//Setting denominator to positive & numerator to negative
	if(mDenominator < 0 && mNumerator > 0){

		mNumerator = -mNumerator;

		mDenominator = abs(mDenominator);

	}

	//Setting numerator & denominator to positive
	else if(mDenominator < 0 && mNumerator < 0){

		mNumerator = abs(mNumerator);

		mDenominator = abs(mDenominator);

	}
	//Getting greatest common denominator
	int commonFactor = gcd(mNumerator, mDenominator);
	//Reduce numerator to lowest form
	mNumerator /= commonFactor;
	//Reduce denominator to lowest form
	mDenominator /= commonFactor;

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
bool Rational::equals(const Rational &other) const {

	return mNumerator == other.mNumerator
	 && mDenominator == other.mDenominator ? true:false;

}

/*
 * Adding two rational number
 * &other - Rational number pass by reference
 */
Rational Rational::add(const Rational &other) const{
	//Getting new numerator
	int num = (mNumerator * other.mDenominator) +
	 (other.mNumerator * mDenominator);
	//Getting new denominator
	int denom = (mDenominator * other.mDenominator);
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
	if (mDenominator == 0){

		return std::to_string(mNumerator);

	}
	//Printing rational expression
	return std::to_string(mNumerator) + "/" + std::to_string(mDenominator);

}

/*
 * Overloading assignment operator "="
 */
Rational& Rational::operator= (const Rational &other){
	//Setting rational numerator to another rational numerator
	mNumerator = other.mNumerator;
	//Setting rational denominator to another rational denominator
	mDenominator = other.mDenominator;

	return *this;
}

/*
 * Overloading assignment operator "+"
 */
Rational operator+ (const Rational &lhs, const Rational &rhs){

	return lhs.add(rhs); // Add one rational to another rational
}

/*
 * Overloading assignment unary operator "-"
 */
Rational operator- (const Rational &other){
	//Negation of rational number
	Rational newRational(-other.mNumerator, other.mDenominator);

	return newRational;

}

/*
 * Overloading assignment binary operator "-"
 */
Rational operator- (const Rational &lhs, const Rational &rhs){

	//Subtracting between two rational numbers
	return lhs.add(-rhs);
}

/*
 * Overloading assignment operator "*"
 */
Rational operator* (const Rational &lhs, const Rational &rhs){
	//Multiplying between two rational numbers
	Rational newRational(lhs.mNumerator * rhs.mNumerator, lhs.mDenominator * rhs.mDenominator);

	return newRational;
}

/*
 * Overloading assignment operator "/"
 */
Rational operator/ (const Rational &lhs, const Rational &rhs){
	//Dividing between two rational numbers
	Rational newRational(lhs.mNumerator * rhs.mDenominator, lhs.mDenominator * rhs.mNumerator);

	return newRational;
}

/*
 * Overloading assignment operator "=="
 */
bool operator== (const Rational &lhs, const Rational &rhs){
	//Comparing if two rational numbers are equal
	return lhs.mNumerator == rhs.mNumerator &&
	 lhs.mDenominator == rhs.mDenominator ? true: false;
}

/*
 * Overloading assignment operator "!="
 */
bool operator!= (const Rational &lhs, const Rational &rhs){
	//Comparing if two rational numbers are not equal
	return !(lhs == rhs);
}

/*
 * Overloading assignment operator "<"
 */
bool operator< (const Rational &lhs, const Rational &rhs){
	//Comparing if one rational number < another rational number
	return lhs.mNumerator < rhs.mNumerator &&
	 lhs.mDenominator < rhs.mDenominator ? true:false;
}

/*
 * Overloading assignment operator "<="
 */
bool operator<= (const Rational &lhs, const Rational &rhs){
	//Comparing if one rational number <= another rational number
	return lhs < rhs || lhs == rhs;
}

/*
 * Overloading assignment operator ">"
 */
bool operator> (const Rational &lhs, const Rational &rhs){
	//Comparing if one rational number > another rational number
	return lhs.mNumerator > rhs.mNumerator &&
	 lhs.mDenominator > rhs.mDenominator ? true: false;
}

/*
 * Overloading assignment operator ">="
 */
bool operator>= (const Rational &lhs, const Rational &rhs){
	//Comparing if one rational number >= another rational number
	return lhs > rhs || lhs == rhs;
}

/*
 * Overloading assignment operator "<<"
 */
ostream &operator<< (ostream &lhs, const Rational &rhs){
	//Stream insertion using lhs instead of cout
	lhs << rhs.toString();

	return lhs;

}
