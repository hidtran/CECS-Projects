/*
 * RationalArray.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Hieu Tran
 *      Creating a Rational dynamic-sized array
 */
#include <iostream>
#include <stdexcept>
#include "Rational.h"
#include "RationalArray.h"

using namespace std;

/*
 * Constructing a dynamic size array
 * size - maximum size of array
 */
RationalArray::RationalArray(int size) : mSize(size) {
	//Dynamic size array
	mArray = new Rational[mSize];

}

/*
 * Constructing a deep copy of a Rational array
 * &other - Rational Array
 */
RationalArray::RationalArray(const RationalArray &other)
	: mSize(other.mSize), mArray(new Rational[mSize]) {

	for (int index = 0; index < mSize; index++) {
		//Copying an array
		mArray[index] = other.mArray[index];

	}

}

/*
 * Cleaning up any Rational array memory which allocated on the heap
 */
RationalArray::~RationalArray() {
	//Deleting array memory on the heap
	delete[] mArray;

}

/*
 * Creating a deep assignment of an existence Rational array
 * into another existing Rational array
 * &rhs - Rational Array
 */
RationalArray& RationalArray::operator= (const RationalArray &rhs) {
	//Avoiding self-assignment
	if (&rhs != this) {
		//Unequal size array
		if (mSize != rhs.mSize) {
			//Deallocate old array
			delete[] mArray;
			//Getting correct array size
			mSize = rhs.mSize;
			//Allocate new array with correct size
			mArray = new Rational[mSize];

		}

		for (int index = 0; index < mSize; index++) {
			//Deep copy of right side array into left side array
			mArray[index] = rhs.mArray[index];

		}

	}
	//Return new array
	return *this;
}

/*
 * Overloading operator[] for Rational array
 * rhs - index of a Rational array
 */
Rational& RationalArray::operator[] (int rhs) {

	if (rhs < 0 || rhs >= mSize) {
		//Detect out of bounds array
		throw out_of_range ("Array is out of bounds");
	}
	//Return current Rational array elements
	return mArray[rhs];

}
