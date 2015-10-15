/*
 * TicTacToe.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: Hieu Tran
 *
 *  A multidimensional array TicTacToe game that will
 *  alternate turns between two players
 */
#include <iostream>
#include "TicTacToe.h"

using namespace std;
//Constant Board Size
const int BOARD_SIZE = 3;
//Max Move for TicTacToe
const int MAX_MOVE = 9;

int main(int argc, char* argv[]){
	//3x3 TicTacToe board size
	char boardArray[BOARD_SIZE][BOARD_SIZE] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}};

	//Exiting the game if move > 9
	bool exit = false;

	while (!exit){
		//Keep track of the moves
		int count;

		cout << "Current state of the board" << endl << endl;
		//Display current board state
		PrintBoard(boardArray);
		//Row and Column of the board
		int row, column;
		//Determine if it's player 1
		bool player1 = false;
		//Determine if it's player 2
		bool player2 = false;

		while (!player2){
			if(WinnerExists(boardArray)){
				cout << "Winner: " << endl;
				exit = true;
				break;
			}
			cout << "X's turn: ";
			//Player 1's turn
			GetMove(&row, &column);
			//Make sure player's move is valid
			if (!MoveIsValid(boardArray, row, column)){

				cout << "Invalid Move" << endl;

			}

			else{
				//Store player 1's input into a specific area
				//of the board
				boardArray[row][column] = 1;
				//Display the updated board
				PrintBoard(boardArray);

				count++;
				//End player 1's turn
				player2 = true;
			}
		}
		//Player 2's move
		while (!player1){
			if (WinnerExists(boardArray)){
					exit = true;
					break;
			}
			//End if max move > 9
			if (count >= MAX_MOVE){

				cout << "Game over. No more moves" << endl;

				exit = true;

				break;

			}

			cout << "O's turn: ";
			//Player 2's turn
			GetMove(&row, &column);
			//Move is invalid if an area of board is not empty
			if (!MoveIsValid(boardArray, row, column)){

				cout << "Invalid Move" << endl;

			}

			else{
				//Update board with player 2's input
				boardArray[row][column] = -1;
				//Display updated board
				PrintBoard(boardArray);

				count++;
				//End player 2's turn
				player1 = true;
			}
		}
	}

	cout << "Thank you for playing." << endl;
	//Game end
	return 0;
}

/**
 * Display TicTacToe board
 */
void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]){

	for (int row = 0; row < BOARD_SIZE ; row++){

		for (int column = 0; column < BOARD_SIZE; column++){

			if (board[row][column] == 0){
				cout << " . |"; //Display empty space
			}

			else if (board[row][column] == 1){
				cout << " X |"; //Display player 1's input
			}

			else if (board[row][column] == -1){
				cout << " O |"; //Display player 2's input
			}
		}

		cout << endl;
	}

	cout << endl;

}

/**
 * Read the user's choice for where to
 * move next on the board
 */
void GetMove(int *row, int *col){

	char comma;

	cin >> *row >> comma >> *col; //Read user's input

	cin.get(comma); //Discard comma character
}

/**
 * Check for valid board move from user's input
 */
bool MoveIsValid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col){

	while ((row >= 0 && row < BOARD_SIZE) && (col >= 0 && col < BOARD_SIZE)){

		if (board[row][col] == 0){

			return true;	//return true if board is empty
		}

		else{

			return false; //return false if board is not empty
		}
	}

	return false; //return false if invalid move
}

bool WinnerExists(char board[BOARD_SIZE][BOARD_SIZE]){
	char winner;

	for(int index = 0; index < BOARD_SIZE; index++){
		int column = 0;
		if((board[index][column] != 0)){
			if((board[index][column] == board[index][column + 1]) &&
				(board[index][column + 1] == board[index][column + 2])){
				winner = board[index][column];
				cout << "Horizontal Winner: " << winner << endl;
			}
		}
	}

	for(int index = 0; index < BOARD_SIZE; index++){
		int row = 0;
		if((board[row][index] != 0)){
			if((board[row][index] == board[row + 1][index]) &&
				(board[row + 1][index] == board[row + 2][index])){
					row = index;
					winner = board[row][index];
			}
		}
	}

	if(board[0][0] != 0 || board[0][2] != 0){
		if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
			winner = board[0][0];
		}
		else if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
			winner = board[0][2];
		}
	}


	switch(winner){
		case 1:
			cout << "Player 1 wins!" << endl;
			return true;
			break;
		case -1:
			cout << "Player 2 wins!" << endl;
			return true;
			break;
		default:
			return false;
			break;
	}
}

