/*
 * TicTacToeView.h
 *
 *  Created on: May 5, 2015
 *      Author: tom
 */

#ifndef TICTACTOEVIEW_H_
#define TICTACTOEVIEW_H_
#include "TicTacToeBoard.h"
#include "GameView.h"
#include <iostream>

// Same code as before; but now you just implement PrintBoard, and not
// operator<<.
class TicTacToeView : public GameView {
private:
	TicTacToeBoard *mTicTacToeBoard;
	virtual void PrintBoard(std::ostream &s) const;

public:
   TicTacToeView(GameBoard *b) : mTicTacToeBoard(dynamic_cast<TicTacToeBoard*>(b)) {}
};
#endif /* TICTACTOEVIEW_H_ */
