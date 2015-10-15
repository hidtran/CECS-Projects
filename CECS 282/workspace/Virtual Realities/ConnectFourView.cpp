/*
 * ConnectFourView.cpp
 *
 *  Created on: May 15, 2015
 *      Author: tom
 */
#include <iostream>
#include "ConnectFourView.h"

using namespace std;

void ConnectFourView::PrintBoard(ostream &print) const {

	print << endl << "- 0 1 2 3 4 5 6" << endl;

	for (int row = 0; row < R_SIZE; row++) {

		for (int column = 0; column < C_SIZE; column++) {

			if (column == 0) {
				//Printing vertical row
				print << row << " ";

			}

			if (mConnectFourBoard -> mBoard[row][column] == mConnectFourBoard -> EMPTY) {

				print << ". ";

			}

			else if (mConnectFourBoard -> mBoard[row][column] == mConnectFourBoard -> YELLOW) {

				print << "Y ";

			}

			else if (mConnectFourBoard -> mBoard[row][column] == mConnectFourBoard -> RED) {

				print << "R ";

			}

		}

		print << endl;

	}

	print << endl;

}



