/*
 * Animals.h
 *
 *  Created on: Apr 28, 2015
 *      Author: tom
 */

#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <iostream>

class Animals{

public:
	Animals() {std::cout << "Construct Animal" << std::endl;}

	virtual ~Animals() {std::cout << "Destruct Animal" << std::endl;}

	virtual void Speak() = 0;
};

class Dog : public Animals{

public:
	Dog(): Animals(){std::cout << "Construct Cat" << std::endl;}

	virtual ~Dog() {std::cout << "Destruct Cat" << std::endl;}

	virtual void Speak() {std::cout << "Woof" << std::endl;}

	void Beg() {std::cout << "Feed Me!" << std::endl;}
};

class Cat : public Animals{

public:
	Cat(): Animals(){std::cout << "Construct Cat" << std::endl;}

	virtual ~Cat() {std::cout << "Destruct Cat" << std::endl;}

	virtual void Speak() {std::cout << "Woof" << std::endl;}

};

#endif /* ANIMALS_H_ */
