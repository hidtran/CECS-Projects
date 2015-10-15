/*
 * Othello.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Hieu Tran
 *
 *      An implementation to create an 8x8 text based version game
 *      of Othello. The game will alternate turns between users.
 *      The game will end when both users consecutively passes their
 *      turn.
 */
#include <iostream>
#include "Othello.h"

using namespace std;

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
	//Printing horizontal column header
	cout << endl << "- 0 1 2 3 4 5 6 7" << endl;

	for (int row = 0; row < BOARD_SIZE; row++) {

		for (int column = 0; column <= BOARD_SIZE; column++) {

			if (column == 0) {
				//Printing vertical row header
				cout << row << " ";

			}


			if (board[row][column] == 0 || column == BOARD_SIZE) {
				//Empty square
				cout << ". ";

			}

			else if (board[row][column] == 1) {
				//Contains Black's user
				cout << "B ";

			}

			else if (board[row][column] == -1) {
				//Contains White's user
				cout << "W ";

			}
		}

		cout << endl;

	}

	cout << endl;

}

/*
 * Check for specified position is within the
 * inbounds area of 8x8 game board
 */
bool InBounds(int row, int col) {
	//Return false if out of bounds, otherwise return true
	return (row >= BOARD_SIZE || row < 0 ||
	 col >= BOARD_SIZE || col < 0) ? false:true;

}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {

	return InBounds(row, col) && board[row][col] == 0
	 || row == -1 && col == -1 ? true: false;
}

/*
 * Ask for user move
 */
void GetMove(int *row, int *col) {

	char comma, lparen, rparen;
	//User input
	cin >> lparen >> *row >> comma >> *col >> rparen;

}

/*
 * Apply user move to the board
 */
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col,
		char player) {

	for (int i = -1; i < 2; i++){

		for (int j = -1; j < 2; j++) {
			//Enemy counts
			int enemy = 0;
			//Move back to original row location
			int movRow = row;
			//Move back to original column location
			int movColumn = col;

			while (InBounds(movRow, movColumn)) {
				//Moving in a horizontal direction
				movRow = movRow + i;
				//Moving in a vertical direction
				movColumn = movColumn + j;

				if (board[movRow][movColumn] == 0) {

					break;	//Empty space

				}

				else if(board[movRow][movColumn] == player) {

					while (enemy > 0) {
						//Moving back one horizontal direction
						movRow = movRow - i;
						//Moving back one vertical direction
						movColumn = movColumn - j;
						//Setting the board to current user
						board[movRow][movColumn] = player;

						enemy--;	//One less enemy

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

/*
 * Determining a winner
 */
int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {

	int total = 0;

	for (int row = 0; row < BOARD_SIZE; row++) {

		for (int column = 0; column < BOARD_SIZE; column++) {
			//Keep track of number of pieces
			total += board[row][column];

		}

	}

	return total;	//Return a winner
}



