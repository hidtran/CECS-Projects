/*
 * OthelloView.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Hieu Tran
 *
 *      An MVC "View" class for printing the model of the Othello board.
 *      Acts as a "wrapper" around an OthelloBoard pointer and handles
 *      requests to print that board to a stream by overloading operator<<.
 */
#include <iostream>
#include <sstream>
#include "OthelloView.h"

using namespace std;

/*
 * Printing Othello's board game
 */
void OthelloView::PrintBoard(ostream &print) const{

	print << endl << "- 0 1 2 3 4 5 6 7" << endl;

	for (int row = 0; row < BOARD_SIZE; row++){

		for (int column = 0; column < BOARD_SIZE; column++){

			if (column == 0){
				//Printing vertical row
				print << row << " ";

			}

			if (mOthelloBoard -> mBoard[row][column] == 0 ||
				column == BOARD_SIZE) {

				//Empty square
				print << ". ";

			}

			else if (mOthelloBoard -> mBoard[row][column] ==
				mOthelloBoard -> BLACK) {
				//Contain Black's move
				print << "B ";

			}

			else if (mOthelloBoard -> mBoard[row][column] ==
				mOthelloBoard -> WHITE) {
				//Contain White's move
				print << "W ";

			}
		}
		//New line
		print << endl;

	}
	//New line
	print << endl;

}

/*
 * Overloading operator<< to use to use cout the game results
 */
ostream& operator<< (ostream &lhs, const OthelloView &rhs){
	//Display game board
	rhs.PrintBoard(lhs);
	//return new game board
	return lhs;

}


