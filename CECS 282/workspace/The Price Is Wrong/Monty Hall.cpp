/*
 * Monty Hall.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Hieu Tran
 *      This program produces a game to solve "Monty Hall problem"
 */
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[]){
	//Constant door and prize variable
   const int DOOR_POSSIBLE = 3;
   const int PRIZE_POSSIBLE = 5;

   //Boolean variable for while loop
   bool exit = false;

   //While loop to continue to run the game
   while(!exit){
	   // A random_device helps to "seed" a number generator.
	   random_device rand;

	   // a compiler-chosen "good" random number generator.
	   default_random_engine engine(rand());

	   // Takes output of engine and maps it to a uniform distribution
	   uniform_int_distribution<int> doordistr(1, DOOR_POSSIBLE);
	   uniform_int_distribution<int> prizedistr(1, PRIZE_POSSIBLE);

	   //Calling the distribution to get winning door number
	   int winDoor = doordistr(engine);

	   //Ask user to choose a door
	   cout << "Please choose a door: " << endl;

	   //User door variable
	   int userDoor;

	   //User door number input
	   cin >> userDoor;

	   //Calling the distribution to get the host door number
	   int hostDoor = doordistr(engine);

	   //Getting a door number that is a goat and not user door number input
	   while(hostDoor == winDoor || hostDoor == userDoor){
		   hostDoor = doordistr(engine);
	   }

	   //Showing a door that has a goat
	   cout << "Door " << hostDoor << " is a goat" << endl;

	   //Ask user if he/she likes to switch to the last remaining door
	   cout << "Would you like to switch to the last door (y / n)?" << endl;

	   //User answer variable
	   char answer;

	   //User answer input with either yes/no
	   cin >> answer;

	   //Switch user to the last remaining door if answered yes
	   if(answer == 'y'){
		   //Calling the distribution to get the switch door number
		   int switchDoor = doordistr(engine);
		   //Getting the last remaining door
		   while(switchDoor == hostDoor || switchDoor == userDoor)
		   {
			   switchDoor = doordistr(engine);
		   }
		   //Set the switch door to the user door choice
		   userDoor = switchDoor;
		   //Showing user new door
		   cout << "Your New Door: " << userDoor << endl;
	   }

	   //Randomly pick winning prize if user wins
	   if(userDoor == winDoor){
		   cout << "You Win!" << endl;
		   //Calling the distribution to get the prize choice
		   int prize = prizedistr(engine);
		   //Five different prize choices
		   switch(prize){
			   case 1:
				   cout << "Your prize is an IPod" << endl;
				   break;
			   case 2:
				   cout << "Your prize is an IPad " << endl;
				   break;
			   case 3:
				   cout << "Your prize is an IPhone 5" << endl;
				   break;
			   case 4:
				   cout << "Your prize is a laptop" << endl;
				   break;
			   case 5:
				   cout << "Your prize is a bicycle" << endl;
				   break;
			   default:
				   break;
		   }
	   }
	   else{
		   //User lost the game with incorrect door choices
		   cout << "You Lose :(" << endl;
	   }

	   //Ask user if he/she would like to continue the game
	   cout << "Would you like to play again (y/n)?" << endl;

	   //User answer choice with either yes or no
	   cin >> answer;

	   //End the game if user answered no
	   if(answer == 'n')
		   exit = true;
   }

   //Thank the user for playing the game
   cout << "Thank you for playing" << endl;

   //Program is completed
   return 0;
}



