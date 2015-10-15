/*
 * ConnectFourView.h
 *
 *  Created on: May 9, 2015
 *      Author: tom
 */

#ifndef CONNECTFOURVIEW_H_
#define CONNECTFOURVIEW_H_

#include "ConnectFourBoard.h"
#include "GameView.h"
#include <iostream>

// Same code as before; but now you just implement PrintBoard, and not
// operator<<.
class ConnectFourView : public GameView {
private:
	ConnectFourBoard *mConnectFourBoard;
	virtual void PrintBoard(std::ostream &s) const;

public:
   ConnectFourView(GameBoard *b) : mConnectFourBoard(dynamic_cast<ConnectFourBoard*>(b)) {}
};
#endif /* CONNECTFOURVIEW_H_ */
