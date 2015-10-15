/*
 * ConnectFourMove.cpp
 *
 *  Created on: May 15, 2015
 *      Author: tom
 */
#include <iostream>
#include <sstream>
#include <string>
#include "ConnectFourMove.h"
#include "ConnectFourBoard.h"
#include "GameMove.h"

using namespace std;

int ConnectFourMove::mOnHeap = 0;

ConnectFourMove::ConnectFourMove() : mRow(0), mCol(0) {
}

ConnectFourMove::ConnectFourMove(int row, int column) : mRow(row), mCol(column) {
}

GameMove &ConnectFourMove::operator =(const string &input) {

	istringstream iString(input);

	char lParen, rParen, comma;

	iString >> lParen >> mRow >> comma >> mCol >> rParen;

	if (!(ConnectFourBoard::InBounds(mRow, mCol))) {

		throw GameException("Move is out of bounds");

	}

	return *this;
}

bool ConnectFourMove::Equals(const GameMove &other) const {

	const ConnectFourMove &move = dynamic_cast<const ConnectFourMove &> (other);

	return this -> mRow == move.mRow && this -> mCol == move.mCol;

}


ConnectFourMove::operator string() const {

	ostringstream coord;

	coord << "(" << mRow << "," << mCol << ")";

	return coord.str();

}
