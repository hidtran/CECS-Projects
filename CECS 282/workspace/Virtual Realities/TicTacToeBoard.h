/*
 * TicTacToeBoard.h
 *
 *  Created on: May 5, 2015
 *      Author: tom
 */

#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

#include <vector>
#include "TicTacToeMove.h"
#include "GameBoard.h"
#include "GameMove.h"

const int T_SIZE = 3;

/*
A TicTacToeBoard encapsulates data needed to represent a single game of TicTacToe.
This includes the state of the board, tracking the current player, and keeping
a history of moves on the board.
*/
class TicTacToeBoard : public GameBoard {

public:
	enum Player {EMPTY = 0, X = 1, O = -1};

   // Default constructor initializes the board to its starting "new game" state
	TicTacToeBoard();

   /*
   Fills in a vector with all possible moves on the current board state for
   the current player. The moves should be ordered based first on row, then on
   column. Example ordering: (0, 5) (0, 7) (1, 0) (2, 0) (2, 2) (7, 7).

   Precondition: the vector is empty.
   Postcondition: the vector contains all valid moves for the current player.
   */
   virtual void GetPossibleMoves(std::vector<GameMove *> *list) const;

   /*
   Applies a valid move to the board, updating the board state accordingly.
   You may assume that this move is valid, and is consistent with the list
   of possible moves returned by GetAllMoves.
   */
   virtual void ApplyMove(GameMove *move);

   /*
   Undoes the last move applied to the board, restoring it to the state it was
   in prior to the most recent move.
   */
   virtual void UndoLastMove();

   /*
   Creates a TicTacToeMove object on the heap. Whoever calls this method is
   responsible for managing the move's lifetime (or transferring that task to
   someone else.)
   */
   virtual GameMove *CreateMove() const {return new TicTacToeMove;}

   inline static bool InBounds(int row, int col) {
      return row >= 0 && row < T_SIZE && col >= 0 && col < T_SIZE;
   }

   // Returns true if the game is finished.
   virtual bool IsFinished() const;

   /*
   Returns a string representation for the given player value. For most games
   this should be "Black" or "White", but this can be customized, e.g. for
   Tic-Tac-Toe.
   */
   virtual std::string GetPlayerString(char player) {
      return (player == 1 ? "X" : "O");
   }

private:
	friend class TicTacToeView;

   // NOTE: we inherit mNextPlayer, mValue, and mHistory from GameBoard.
   char mBoard[T_SIZE][T_SIZE];
};

#endif /* TICTACTOEBOARD_H_ */