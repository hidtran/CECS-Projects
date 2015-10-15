/*
 * OthelloBoard.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Hieu Tran
 *
 *      Collection of all information needed to represent
 *      the state of the game board
 *
 */
#include <iostream>
#include <vector>
#include "OthelloBoard.h"

using namespace std;

/*
 * Creating empty board of 8x8
 */
OthelloBoard::OthelloBoard() : mBoard(), mNextPlayer(BLACK), mValue(EMPTY), mPassCount(EMPTY) {
	// mBoard[3][3] = W
	mBoard[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2) - 1] = WHITE;
	//	mBoard[3][4] = B
	mBoard[(BOARD_SIZE / 2) - 1][BOARD_SIZE / 2] = BLACK;
	// mBoard[4][3] = B
	mBoard[BOARD_SIZE / 2][(BOARD_SIZE / 2) - 1] = BLACK;
	//mBoard[4][4] = W
	mBoard[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;

}

/*
 *  Fills in a vector with all possible moves on the current board state
 *  for the current player. The moves should be ordered based first on row,
 *  then on column. Example ordering: (0, 5) (0, 7) (1, 0) (2, 0) (2, 2)
 *  (7, 7). If no moves are possible, then a single OthelloMove representing
 *  is a Pass put in the vector.
 */
void OthelloBoard::GetPossibleMoves(vector<OthelloMove *> *list) const {
	//Traverse through all the boards
	for (int row = EMPTY; row < BOARD_SIZE; row++) {

		for (int column = EMPTY; column < BOARD_SIZE; column++) {
			//Current board location is empty
			if (mBoard[row][column] == EMPTY) {
				//Flag for finding an enemy in one direction
				bool found = false;
				// Walking 3x3 square from current board location
				for (int i = WHITE; i <= BLACK; i++) {

					for (int j = WHITE; j <= BLACK; j++) {
						//Enemy
						int enemy = EMPTY;
						//Current move row
						int movRow = row;
						//Current move column
						int movColumn = column;
						//Check for current location in bounds
						while (InBounds(movRow, movColumn)) {
							//Change current move row direction
							movRow = movRow + i;
							//Change current move column direction
							movColumn = movColumn + j;
							//Check for current location in bounds
							if (InBounds(movRow, movColumn)) {

								if (mBoard[movRow][movColumn] == EMPTY) {
									//Current board location is empty
									break;
								}
								//Check for ally piece
								else if (mBoard[movRow][movColumn] == mNextPlayer) {
									//Check for enemy
									while (enemy > EMPTY && !found) {
										//Reverse current board row
										movRow -= i;
										//Reverse current board column
										movColumn -= j;
										//Creating new possible moves
										list->push_back(new OthelloMove(row, column));
										//Get next enemy
										enemy--;
										//One direction of enemy being flip is found
										found = true;
									}

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
		}
	}

	if (list->empty()) {
		//No possible move found
		list->push_back(new OthelloMove(WHITE, WHITE));

	}

}

/*
 * Applies a valid move to the board, updating the board state accordingly.
 */
void OthelloBoard::ApplyMove(OthelloMove *move) {
	//Add new move to history record
	mHistory.push_back(move);

	if (move->IsPass()) {
		//Move is a pass
		mPassCount++;
	}

	else {
		//Reset pass count
		mPassCount = EMPTY;
		//Add new move to the board
		mBoard[move->mRow][move->mCol] = mNextPlayer;

		//Updating current board value
		mValue += mNextPlayer;
		//Find all enemies to flip with new move
		for (int i = WHITE; i <= BLACK; i++) {

			for (int j = WHITE; j <= BLACK; j++) {
				//Enemy
				int enemy = 0;
				//Current move row
				int movRow = move -> mRow;
				//Current move column
				int movColumn = move ->mCol;
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
							move->AddFlipSet(OthelloMove::FlipSet(enemy, i, j));
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
	//Next player
	mNextPlayer = -mNextPlayer;
}

/*
 *  Undoes the last move applied to the board, restoring it to the state it
 *  was in prior to the most recent move (including whose turn it is, what
 *  the board value is, and what the pass count is).
 */
void OthelloBoard::UndoLastMove() {
	//Latest movement
	OthelloMove *move = mHistory.back();
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
