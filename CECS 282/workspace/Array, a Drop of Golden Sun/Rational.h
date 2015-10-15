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
	int mNumerator;
	int mDenominator;
	void normalize(int num, int denom);
public:
	Rational();
	Rational (int num, int denom);
	Rational (const Rational &copy);
	void setNumerator(int num);
	int getNumerator() const;
	void setDenominator(int num);
	int getDenominator() const;
	int gcd(int num, int denom);
	bool equals(const Rational &other) const;
	Rational add(const Rational &other) const;
	std::string toString() const;
	Rational& operator= (const Rational &other);
	friend Rational operator+ (const Rational &lhs, const Rational &rhs);
	friend Rational operator- (const Rational &negation);
	friend Rational operator- (const Rational &lhs, const Rational &rhs);
	friend Rational operator* (const Rational &lhs, const Rational &rhs);
	friend Rational operator/ (const Rational &lhs, const Rational &rhs);
	friend bool operator== (const Rational &lhs, const Rational &rhs);
	friend bool operator!= (const Rational &lhs, const Rational &rhs);
	friend bool operator< (const Rational &lhs, const Rational &rhs);
	friend bool operator<= (const Rational &lhs, const Rational &rhs);
	friend bool operator> (const Rational &lhs, const Rational &rhs);
	friend bool operator>= (const Rational &lhs, const Rational &rhs);
	friend std::ostream &operator<< (std::ostream &lhs, const Rational &rhs);
};

#endif /* RATIONAL_H_ */
