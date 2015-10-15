/*
 * TicTacToeMove.cpp
 *
 *  Created on: May 6, 2015
 *      Author: tom
 */
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "TicTacToeMove.h"
#include "TicTacToeBoard.h"
#include "GameMove.h"
#include "GameExceptions.h"

using namespace std;

int TicTacToeMove::mOnHeap = 0;

TicTacToeMove::TicTacToeMove() : mRow(0), mCol(0) {
}

TicTacToeMove::TicTacToeMove(int row, int column) : mRow(row), mCol(column) {
}

GameMove& TicTacToeMove::operator=(const string &input) {

	istringstream iString(input);

	char lParen, rParen, comma;

	iString >> lParen >> mRow >> comma >> mCol >> rParen;

	if (!(TicTacToeBoard::InBounds(mRow, mCol))) {

		throw GameException("Move is out of bounds");

	}

	return *this;

}

bool TicTacToeMove::Equals(const GameMove &other) const {

	const TicTacToeMove &move = dynamic_cast<const TicTacToeMove &>(other);

	return this->mRow == move.mRow && this->mCol == move.mCol;

}

TicTacToeMove::operator string() const {

	ostringstream coord;

	coord << "(" << mRow << "," << mCol << ")";

	return coord.str();

}

