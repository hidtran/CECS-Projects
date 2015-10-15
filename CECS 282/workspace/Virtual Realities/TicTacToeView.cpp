/*
 * TicTacToeView.cpp
 *
 *  Created on: May 7, 2015
 *      Author: tom
 */
#include <iostream>
#include "TicTacToeView.h"

using namespace std;

void TicTacToeView::PrintBoard(ostream &print) const {

	print << endl << "- 0 1 2" << endl;

	for (int row = 0; row < T_SIZE; row++) {

		for (int column = 0; column < T_SIZE; column++) {

			if (column == 0) {
				//Printing vertical row
				print << row << " ";

			}

			if (mTicTacToeBoard -> mBoard[row][column] == mTicTacToeBoard -> EMPTY) {

				print << ". ";

			}

			else if (mTicTacToeBoard -> mBoard[row][column] == mTicTacToeBoard -> X) {

				print << "X ";

			}

			else if (mTicTacToeBoard -> mBoard[row][column] == mTicTacToeBoard -> O) {

				print << "O ";

			}

		}

		print << endl;

	}

	print << endl;

}
