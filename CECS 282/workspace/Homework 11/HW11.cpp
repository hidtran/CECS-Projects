/*
 * HW11.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: tom
 */
#include <iostream>
#include "Animals.h"

using namespace std;


int main(int argc, char* argv[]){

	Animals *a = new Cat();
	a -> Speak();
	delete a;

	//Animals *b = new Animals();
	//Cat *c = new Animals();
	//Dog *d = new Cat();
	Cat *e = new Cat();
	Animals *ptr = new Dog();
	static_cast<Dog *> (ptr)->Beg();

	return 0;
}



