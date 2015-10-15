/*
 * main.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: tom
 */
#include <string>
#include <iostream>
#include "DungeonRoom.h"

using namespace std;

int main(int argc, char* argv[]){

	cout << "Welcome to our Rogue-like game. Let's begin!" << endl;

	DungeonRoom *currentRoom = new DungeonRoom();

	while(true){
		cout << endl << endl << "You enter " << currentRoom -> GetRoomName() << endl;
		cout << currentRoom -> GetDescription() << endl;
		cout << "Continue? y/n";

		char yesNo;
		cin >> yesNo;

		if (yesNo == 'n')
				break;

		DungeonRoom *nextRoom = currentRoom -> GetNextRoom();
		delete currentRoom;
		currentRoom = nextRoom;

	}
}
