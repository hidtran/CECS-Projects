/*
 * HW3.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: tom
 */
#include <iostream>
#include <cmath>

using namespace std;

double Blah(int *p){
	*p = *p + 5;
	double local = *p / 2;
	return local;
}

void DoubleLarger(int &x, int &y, int &z){
	if(x > y || x > z){
		x *= 2;
	}
	else if(y > x || y > z){
		y *= 2;
	}

	else if(z > x || z > y){
		z *= 2;
	}
}

double SolveQuadratic(double a, double b, double c, double *result1, double *result2){

	double insideSqrt = (b*b) - (4*a*c);
	*result1 = (-b + sqrt(insideSqrt)) / (2 * a);
	*result2 = (-b - sqrt(insideSqrt)) / (2 * a);
	double solution;

	if (insideSqrt > 0){
		if(*result1 == *result2){
			solution = 1;
		}
		else if(*result1 != *result2){
			solution = 2;
		}
	}
	else{
		*result1 = 0;
		*result2 = 0;
		solution = 0;
	}

	return solution;

}


int main(int argc, char* argv[]){

	double solution1, solution2;
	double x = 1, y = 0, z = 1;
	int result = SolveQuadratic(x, y, z, &solution1, &solution2);
	cout << "Number of Solutions: " << result;
	cout << "\tSolution 1: " << solution1;
	cout << "\tSolution 2: " << solution2 << endl;
	return 0;
}




