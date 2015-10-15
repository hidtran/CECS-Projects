/*
 * OthelloMove.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Hieu Tran
 *
 *      Encapsulating information associated with single move on the board
 */
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "OthelloMove.h"
#include "OthelloExceptions.h"
#include "OthelloBoard.h"

using namespace std;

const string PASS = "pass";

int OthelloMove::mOnHeap = 0;

/*
 * Default constructor as a pass
 */
OthelloMove::OthelloMove(): mRow(-1), mCol(-1){
}

/*
 * Constructor initializes the move with a row and column
 */
OthelloMove::OthelloMove(int row, int col): mRow(row), mCol(col){
}

/*
 * Adds a FlipSet to the move's vector of sets. Used to keep track of how many
 * enemy pieces were flipped in each direction when this move was applied.
 */
OthelloMove& OthelloMove::operator= (const string &name){

	//A pass move
	if(name == "pass") {
		//Row is a pass
		mRow = -1;
		//Column is a pass
		mCol = -1;

	}
	//Not a pass move
	else {
		//Read input from user input
		istringstream iString(name);

		char lParen, rParen, comma;
		//Store user input
		iString >> lParen >> mRow >> comma >> mCol >> rParen;

		if(!(OthelloBoard::InBounds(mRow, mCol))){

			throw OthelloException("Move is out of bounds");
		}
	}
	//Return new move
	return *this;
}

/*
 * Compares two OthelloMove objects for equality (if rows and cols are same)
 */
bool operator== (const OthelloMove &lhs, const OthelloMove &rhs){
	//Return true if two moves are equal
	return lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol;

}

/*
 * Converts the OthelloMove into a string representation, one that could be
 * used correctly with operator=(string). Returns "pass" if move is a pass
 */
OthelloMove::operator std::string() const{

	if(IsPass()){
		//Move is a pass
		return PASS;

	}

	ostringstream coord;
	//Display new move
	coord << "(" << std::to_string(mRow) << "," << std::to_string(mCol) << ") ";
	//Return new move coordinate
	return coord.str();

}
