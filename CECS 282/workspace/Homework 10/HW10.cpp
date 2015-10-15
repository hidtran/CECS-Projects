/*
 * HW10.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: tom
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Rational.h"

using namespace std;

void fileStream();

int main(int argc, char* argv[]) {

	string s = "Hello.My.World:CSULB";
	char c = s.at(6);
	string substr = s.substr(2, 6);
	int length = s.length();
	int index = s.find_first_of(':');
	reverse(s.begin(), s.end());
	replace(s.begin(), s.end(), '.', '+');

	fileStream();

	ofstream file;
	file.open("output.txt", ios::out);
	Rational rat(1, 3);
	(file) << rat;
	file.close();

}

void fileStream() {

	ifstream file;
	file.open("numbers.txt", ios::in);
	int read;
	int mean = 0;
	int sum = 0;
	int index = 0;

	while(!file.fail()){

		cout << "Read Integer: " << read << endl;
		file >> read;
		sum += read;
		index++;
	}
	sum -= read;
	mean = (sum) / (index - 1);

	cout << "Mean: " << mean << endl;

	file.close();
}

