/*
 * Rational.h
 *
 *  Created on: Mar 3, 2015
 *      Author: Hieu Tran
 *
 *      File header for Rational class
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <string>

class Rational {
private:
	int numerator;
	int denominator;
	void normalize(int num, int denom);
public:
	Rational();
	Rational (int num, int denom);
	void setNumerator(const int &num);
	int getNumerator() const;
	void setDenominator(const int &num);
	int getDenominator() const;
	int gcd(int num, int denom);
	bool equals(const Rational &other) const;
	Rational add(const Rational &other) const;
	std::string toString() const;
};

#endif /* RATIONAL_H_ */
