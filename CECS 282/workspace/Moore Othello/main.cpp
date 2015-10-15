/*
 * main.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Hieu Tran
 *
 *      An object-oriented Othello game simulation
 */
#include <iostream>
#include <vector>
#include <string>
#include "OthelloExceptions.h"
#include "OthelloBoard.h"
#include "OthelloView.h"

using namespace std;

int main(int argc, char* argv[]){
	//Welcome message
	cout << "Welcome to Othello!" << endl;
	//OthelloBoard class object
	OthelloBoard board;
	//OthelloView class object
	OthelloView view(&board);
	//Vector move pointer
	vector<OthelloMove *> move;
	//User input
	string input;

	while (!(board.IsFinished())) {
		//Display current board
		cout << view << endl;
		//Get all possible moves
		board.GetPossibleMoves(&move);
		//Possible moves variable
		string possibleMoves;

		for(OthelloMove *mov: move){
			//Retrieving all possible moves
			possibleMoves += *mov;
			//Removing all possible moves from the heap
			delete mov;

		}
		//Clear all move vector pointers
		move.clear();

		if (board.GetNextPlayer() == board.BLACK) {
			//Black's move
			cout << "\nBlack's turn" << endl;

		}

		else {
			//White's move
			cout << "\nWhite's turn" << endl;

		}
		//Display all possible moves
		cout << "Possible moves:\n" << possibleMoves << endl;

		cout << "Enter a command: ";
		//Get user input
		getline(cin, input);

		cout << endl;
		//Command input
		string choice;
		//new move position
		int position = board.EMPTY;

		for (int index = board.EMPTY; index < input.length(); index++){

			if (input[index] == ' ') {
				//Retrieving new move position
				position = index + 1;

				break;

			}
			//Retrieving command input
			choice += input[index];

		}

		if (choice == "move") {
			//Creating new move
			OthelloMove *newMove = board.CreateMove();

			try {
				//Retrieving new move
				(*newMove) = input.substr(position);

			}

			catch(OthelloException &error) {
				//Invalid new move
				cout << error.what() << endl;

				delete newMove;

			}
			//Get all new possible moves
			board.GetPossibleMoves(&move);

			bool equal = false;

			for (vector<OthelloMove *>::iterator itr = move.begin();
				itr != move.end(); ++itr){
				//Store all possible new moves
				OthelloMove *temp = *itr;

				if (*newMove == *temp && !equal) {
					//Apply new move onto the board
					board.ApplyMove(newMove);
					//Valid new move
					equal = true;

				}
				//Removing all possible moves on the heap
				delete temp;
			}

			if (!equal) {

				cout << "\nInvalid input" << endl;

				//Removing invalid new move
				delete newMove;

			}
			//Clear all move vector pointers
			move.clear();

		}


		else if (choice == "undo") {
			//Number of undoes
			int number = stoi(input.substr(position));

			if (number > board.GetMoveCount()){
				//Max number of undoes
				number = board.GetMoveCount();

			}

			while(number > board.EMPTY) {
				//Undo latest move
				board.UndoLastMove();
				//Next undo move
				number--;

			}
		}

		else if (choice == "showValue") {
			//Display current board value
			cout << "Board Value: " << board.GetValue() << endl;

		}

		else if (choice == "showHistory") {
			//History of all moves apply
			const vector<OthelloMove *> *mov = board.GetMoveHistory();
			//Number moves applied to the board
			int index = board.GetMoveCount();

			for (vector<OthelloMove *>::const_reverse_iterator temp =
				mov->crbegin(); temp != mov -> crend(); ++temp){
				//Getting latest move's history
				OthelloMove *m = *temp;

				if (index % (board.BLACK + board.BLACK) == 0) {
					//White history movement
					cout << "White: " << (string) *m << endl;
				}

				else {
					//Black history movement
					cout << "Black: " << (string) *m << endl;

				}
				//Next player's history movement
				index--;
			}

		}

		else {
			//Exit the game
			cout << "Thank you for playing" << endl;

			break;

		}

	}

	if (board.GetValue() > board.EMPTY) {
		//Black won the game
		cout << "\nBlack wins!" << endl;

	}

	else if (board.GetValue() < board.EMPTY){
		//White won the game
		cout << "\nWhite wins!" << endl;
	}

	else {
		//Tie game
		cout << "\nIt's a tie!" << endl;

	}

}
