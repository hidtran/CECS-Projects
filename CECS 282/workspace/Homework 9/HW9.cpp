/*
 * HW9.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: tom
 */
#include <iostream>
#include <vector>
#include "Rational.h"

using namespace std;

int main(int argc, char* argv[]){

	vector <Rational *> v;
   v.push_back(new Rational(1, 3));
   v.push_back(new Rational(3, 3));
   v.push_back(new Rational(3, 3));
   v.push_back(new Rational(4, 3));
   v.push_back(new Rational(5, 3));

   for (vector <Rational *>::iterator itr = v.begin(); itr != v.end(); ++itr){
      delete *itr;
   }

   v.clear();

}
