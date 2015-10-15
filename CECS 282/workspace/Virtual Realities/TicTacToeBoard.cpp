/*
 * TicTacToeBoard.cpp
 *
 *  Created on: May 6, 2015
 *      Author: tom
 */
#include <iostream>
#include <vector>
#include "TicTacToeBoard.h"
#include "TicTacToeMove.h"
#include "GameMove.h"

using namespace std;

TicTacToeBoard::TicTacToeBoard() : mBoard() {
}

void TicTacToeBoard::GetPossibleMoves(vector<GameMove *> *list) const {

	for (int row = EMPTY; row < T_SIZE; row++) {

		for (int column = EMPTY; column < T_SIZE; column++) {

			if (InBounds(row, column)) {

				if (mBoard[row][column] == EMPTY) {

					list->push_back(new TicTacToeMove(row, column));

				}
			}
		}
	}

	if (list -> empty()) {

		const_cast<int &> (mValue) += mNextPlayer;

	}
}

void TicTacToeBoard::ApplyMove(GameMove *move) {

	TicTacToeMove *mov = dynamic_cast<TicTacToeMove *>(move);

	if (mov == nullptr) {

		throw GameException("Invalid Tic Tac Toe Move");

	}

	mHistory.push_back(mov);

	mBoard[mov->mRow][mov->mCol] = mNextPlayer;

	mValue += mNextPlayer;

	mNextPlayer = -mNextPlayer;

}

void TicTacToeBoard::UndoLastMove() {

	TicTacToeMove *move = dynamic_cast<TicTacToeMove *>(mHistory.back());

	if (move == nullptr) {

		throw GameException("Invalid Tic Tac Toe Move");

	}

	mBoard[move->mRow][move->mCol] = EMPTY;

	mValue += mNextPlayer;

	mNextPlayer = -mNextPlayer;

	mHistory.pop_back();

	delete move;

}

bool TicTacToeBoard::IsFinished() const {

	int &boardValue = const_cast<int &> (mValue);

	for (int index = 0; index < T_SIZE; index++) {

		int column = 0;

		if ((mBoard[index][column] != 0 && InBounds(index, column))) {

			if ((mBoard[index][column] == mBoard[index][column + 1]) &&
				(mBoard[index][column + 1] == mBoard[index][column + 2])) {

				boardValue -= mNextPlayer;

				return true;

			}
		}
	}

	for (int index = 0; index < T_SIZE; index++) {

		int row = 0;

		if ((mBoard[row][index] != 0) && InBounds(row, index)) {

			if ((mBoard[row][index] == mBoard[row + 1][index]) &&
				(mBoard[row + 1][index] == mBoard[row + 2][index])) {

				boardValue -= mNextPlayer;

				return true;

			}
		}
	}

	if (mBoard[0][0] != 0) {

		if ((mBoard[0][0] == mBoard[1][1]) && (mBoard[1][1] == mBoard[2][2])) {

			boardValue -= mNextPlayer;

			return true;

		}

	}

	if (mBoard[0][2] != 0) {

		if ((mBoard[0][2] == mBoard[1][1]) && (mBoard[1][1] == mBoard[2][0])) {

			boardValue -= mNextPlayer;

			return true;

		}

	}

	return false;

}

/*
	for (;;) {
		x += row;
		y += column;
		if (mBoard[x][y] == mNextPlayer) {
			pConsec++;
			cConsec = 0;
			std::cout << "pcONSEC" << pConsec;
			if (pConsec == 3) {
				mPassCount = 2;
				break;
			}
			break;
		}
		if (mBoard[x][y] == flip) {
			cConsec++;
			pConsec = 0;
			std::cout << "cConsec" << cConsec;
			if (cConsec == 3) {
				mPassCount = 2;
				break;
			}
			break;
		}
		if (mBoard[x][y] == EMPTY || !(InBounds(x, y))) {

			cConsec = 0;
			pConsec = 0;
			break;
		}
		*/
