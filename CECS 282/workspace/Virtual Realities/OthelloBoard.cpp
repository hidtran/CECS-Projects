#include <iostream>
#include <vector>
#include "OthelloBoard.h"
#include "OthelloMove.h"
#include "GameMove.h"

using namespace std;

OthelloBoard::OthelloBoard() : mBoard(), mPassCount(EMPTY) {

	mBoard[(O_SIZE / 2) - 1][(O_SIZE / 2) - 1] = WHITE;

	mBoard[(O_SIZE / 2) - 1][O_SIZE / 2] = BLACK;

	mBoard[O_SIZE / 2][(O_SIZE / 2) - 1] = BLACK;

	mBoard[O_SIZE / 2][O_SIZE / 2] = WHITE;

}

void OthelloBoard::GetPossibleMoves(vector<GameMove *> *list) const {

	for (int row = EMPTY; row < O_SIZE; row++) {

		for (int column = EMPTY; column < O_SIZE; column++) {

			if (mBoard[row][column] == EMPTY) {

				bool found = false;

				for (int i = -1; i <= BLACK; i++) {

					for (int j = -1; j <= BLACK; j++) {

						int enemy = 0;

						int movRow = row;

						int movColumn = column;

						while (InBounds(movRow, movColumn)) {

							movRow += i;

							movColumn += j;

							if (InBounds(movRow, movColumn)) {

								if (mBoard[movRow][movColumn] == EMPTY) {

									break;

								}

								else if (mBoard[movRow][movColumn] == mNextPlayer) {

									while (enemy > EMPTY && !found) {

										movRow -= i;

										movColumn -= j;

										list->push_back(new OthelloMove(row, column));

										enemy--;

										found = true;

									}

									break;

								}

								else {

									enemy++;

								}

							}

						}

					}

				}

			}

		}

	}

	if (list->empty()) {

		list->push_back(new OthelloMove(WHITE, WHITE));

	}

}

void OthelloBoard::ApplyMove(GameMove *move) {

	OthelloMove *mov = dynamic_cast<OthelloMove *>(move);

	if (mov == nullptr) {

		throw GameException("Invalid Othello Move");

	}

	mHistory.push_back(mov);

	if (mov ->IsPass()) {

		mPassCount++;

	}

	else {

		//Reset pass count
		mPassCount = EMPTY;
		//Add new move to the board
		mBoard[mov->mRow][mov->mCol] = mNextPlayer;
		//Updating current board value
		mValue += mNextPlayer;

		for (int i = WHITE; i <= BLACK; i++) {

			for (int j = WHITE; j <= BLACK; j++) {
				//Enemy
				int enemy = 0;
				//Current move row
				int movRow = mov -> mRow;
				//Current move column
				int movColumn = mov -> mCol;
				//Check for current location in bounds
				while (InBounds(movRow, movColumn)) {
					//Change direction of row movement
					movRow = movRow + i;
					//Change direction of column movement
					movColumn = movColumn + j;
					//Check for current location in bounds
					if (InBounds(movRow, movColumn)) {
						//Valid move
						if (mBoard[movRow][movColumn] == EMPTY) {
							//Current board location is empty
							break;

						}
						//Check for ally piece
						else if (mBoard[movRow][movColumn] == mNextPlayer) {
							//Keep track all flip enemies movement direction
							mov -> AddFlipSet(OthelloMove::FlipSet(enemy, i, j));
							//Check for enemy pieces
							while (enemy > EMPTY) {
								//Reverse row movement direction
								movRow -= i;
								//Reverse column movement direction
								movColumn -= j;
								//Flip board piece
								mBoard[movRow][movColumn] = mNextPlayer;
								//Updating current board value
								mValue += mNextPlayer * (BLACK + BLACK);
								//next enemy piece
								enemy--;
							}
							//No enemy pieces
							break;

						}

						else {
							//Found an enemy
							enemy++;

						}

					}

				}
			}
		}
	}

	mNextPlayer = -mNextPlayer;
}

void OthelloBoard::UndoLastMove(){
	//Latest movement
	OthelloMove *move = dynamic_cast<OthelloMove *> (mHistory.back());

	if (move == nullptr) {

		throw GameException("Invalid Othello Move");

	}

	//Undo last move
	mBoard[move->mRow][move->mCol] = EMPTY;
	//Updating board value
	mValue += mNextPlayer;
	//Check for last move enemy flip pieces
	for (OthelloMove::FlipSet &flip : move->mFlips) {
		//Last row movement
		int movRow = move->mRow;
		//Last column movement
		int movCol = move->mCol;
		//Check for all enemy flip pieces
		while (flip.switched > EMPTY) {
			//Change direction of row movement
			movRow += flip.rowDelta;
			//Change direction of row movement
			movCol += flip.colDelta;
			//Undo last move
			mBoard[movRow][movCol] = mNextPlayer;
			//Updating board value
			mValue += mNextPlayer * (BLACK + BLACK);
			//Next flip enemy
			flip.switched--;
		}
	}
	//Next player
	mNextPlayer = -mNextPlayer;
	//Reset pass count
	mPassCount = EMPTY;
	//Next latest move
	mHistory.pop_back();
	//Remove latest move
	delete move;

}
