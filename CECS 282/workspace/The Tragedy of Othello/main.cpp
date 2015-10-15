/*
 * main.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: Hieu Tran
 *
 *      Main function to run Othello's game
 */
#include <iostream>
#include "Othello.h"

using namespace std;
//Constant Max Moves
const int MAX_MOVES = 64;

int main(int argc, char* argv[]) {
	//Creating new 8x8 board
	char boardArray[BOARD_SIZE][BOARD_SIZE] = {
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, -1, 1, 0, 0, 0,
	 0, 0, 0, 1, -1, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0,};

	cout << "Welcome to Othello!" << endl;

	PrintBoard(boardArray);	//An empty board
	//Initialize local variables
	int count = 0, pass = 0, row = 0, column = 0, player = 1;
	//Determine player's turn
	bool player2 = false;

	while(pass != 2 || count >= MAX_MOVES) {

		if (!player2) {
			//Player 1's turn
			cout << "Black's turn. Please choose a move: ";

			player = 1;

			player2 = true;

		}

		else {
			//Player 2's turn
			cout << "White's turn. Please choose a move: ";

			player = -1;

			player2 = false;

		}
		//Get a move from player
		GetMove(&row, &column);
		//Check for valid move
		while (!IsValidMove(boardArray, row, column)) {

			cout << "Invalid Move. Please choose a move: ";
			//Ask player for new move
			GetMove(&row, &column);

		}

		if (row == -1 && column == -1) {
			//User's pass his/her turn
			pass++;
			//Keep track of moves
			count++;

			continue;
		}

		else {

			if (pass > 0){
				//Passing turn not consecutively
				pass--;

			}
		}
		//Set board to current player's piece
		boardArray[row][column] = player;
		//Apply new move
		ApplyMove(boardArray, row, column, player);
		//Display new board
		PrintBoard(boardArray);
		//Keep track of move
		count++;
	}

	//Get the winner
	int winner = GetValue(boardArray);

	if (winner > 0) {
		//Black player's win
		cout << "Game over. Black wins!" << endl;

	}

	else if (winner < 0) {
		//White player's win
		cout << "Game over. White wins!" << endl;

	}

	else {
		//No winner
		cout << "Game over. We have a tie!" << endl;

	}
}
