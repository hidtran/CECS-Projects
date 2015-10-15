/*
 * DungeonRoom.h
 *
 *  Created on: Apr 16, 2015
 *      Author: tom
 */

#ifndef DUNGEONROOM_H_
#define DUNGEONROOM_H_

#include <string>
#include <random>

class DungeonRoom{
protected:
		static std::default_random_engine mRandom;
		static const int NUMBER_OF_ROOM_TYPES = 2;

public:
	DungeonRoom();

	virtual std::string GetRoomName() const;
	virtual std::string GetDescription() const;

};

#endif /* DUNGEONROOM_H_ */
