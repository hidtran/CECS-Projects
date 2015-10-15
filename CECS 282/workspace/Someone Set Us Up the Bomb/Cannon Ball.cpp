/*
 * Cannon Ball.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Hieu Tran
 *This program design to simulate a game of continuously shooting cannon
 *bombs until it hits the target
 */
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;
int main(int argc, char* argv[]){
	//Gravity constant
	const double GRAVITY = 9.8;
	//PI constant
	const double PI = 3.141592653589793238463;
	//Gunpowder velocity constant
	const double GUNPOWDER_VELOCITY = 30;
	//Radian conversion constant
	const double RADIAN = PI / 180;
	//Max meter constant
	const int METER = 1000;
	//Right angle constant
	const int RIGHT_ANGLE = 90;
	//A variable to exit the game
	bool exit = false;
	//User seed input variable
	int seedInput;

	while (!exit){
		//Ask user to input a positive integer seed value
		cout << "Please enter a positive integer seed value: " << endl;
		//User seed input
		cin >> seedInput;
		//Ask user to re-enter seed value if the input is not positive integer
		while (seedInput <= 0){

			cout << "Please enter a positive integer seed value: " << endl;

			cin >> seedInput;
		}
		//Using Linux GCC Compiler-chosen "good" random seed input
		default_random_engine engine(seedInput);
		//Takes output from Linux GCC Compiler-chosen engine
		//maps it to a uniform real distribution
		uniform_real_distribution<double> distanceDistr(1, METER);
		//Calling the distribution to get random target distance
		double targetDistance = distanceDistr(engine);
		//Display target distance to 2 decimal numbers
		cout << "Target distance away: " << fixed << setprecision(2);

		cout << targetDistance << endl;
		//target variable
		double target = -1;
		//Getting the cannon bombs to hit the target
		while (target < 0 || target >= 2){
			//Ask user to input the angle of the cannon
			cout << "Choose an angle between 0 and 90 degrees: " << endl;
			//Angle & gunpowder variable
			double angle, gunpowder;
			//User input an angle
			cin >> angle;
			//Ask user to re-enter the angle if it's not between 0 & 90 degrees
			while (angle < 0 || angle > RIGHT_ANGLE){

				cout << "Choose an angle between 0 and 90 degrees: " << endl;

				cin >> angle;
			}
			//Ask user to input the amount of gunpowder
			cout << "Enter an amount of gunpowder in kilograms: " << endl;
			//User input amount of gunpowder
			cin >> gunpowder;
			//Getting initial velocity of the gunpowder
			double initialVelocity = gunpowder * GUNPOWDER_VELOCITY;
			//Getting horizontal initial velocity
			double xVelocity = initialVelocity * cos(angle * RADIAN);
			//Getting vertical initial velocity
			double yVelocity = initialVelocity * sin(angle * RADIAN);
			//Getting the total time of hitting the target
			double time = 2 * (yVelocity / GRAVITY);
			//Getting the total distance the bomb travels
			double distance = (xVelocity * time);
			//Getting the distance differential between the bomb and the target
			target = targetDistance - distance;
			//Determine if the bomb is shorter away from the target
			if (target > 1){
				cout << "Target is " << target << " short." << endl << endl;
			}
			//Determine if the bomb is further away from the target
			else if (target < -1){
				cout << "Target is " << target << " long." << endl << endl;
			}
		}
		//Show the bomb hits the target
		cout << "Target hits! " << endl << endl;
		//Ask user if he/she wants to play the game again
		cout << "Would you like to play again (y/n)?" << endl;
		//User answer variable
		char answer;
		//User answer choice with either yes/no
		cin >> answer;
		//End the game if user answered no
		if (answer == 'n'){
			exit = true;
		}
	}
	//Thank the user for playing the game
	cout << "Thank you for playing." << endl;
}



