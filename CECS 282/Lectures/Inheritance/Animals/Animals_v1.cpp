#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Lion {
protected:
   bool mIsKing;
   string mSpecies;

public:
   Lion(bool isKing) : mIsKing(isKing), mSpecies("Lion") {}
   void Roar() {cout << "Roar" << endl;}
   string GetSpecies() {return mSpecies;}
};

class Tiger {
protected:
   int mNumberOfStripes;
   string mSpecies;

public:
   Tiger(int stripes) : mNumberOfStripes(stripes), mSpecies("Tiger") {}
   void Chuff() {cout << "Chuff" << endl;}
   string GetSpecies() {return mSpecies;}
};

class Liger : public Lion, public Tiger {
public:
   Liger() : Lion(true), Tiger(10) {}
   operator string() {
      ostringstream o;
      o << "I am a Liger with " << mNumberOfStripes << " stripes. I am " << 
       (mIsKing ? "the king." : "not the king. ");

<<<<<<< HEAD
		o << mSpecies; //False. Unknown mSpecies.
=======
      o << mSpecies;
>>>>>>> ed507c62e0f0036a510cf73a31b095b83509f197

      return o.str();
   }
};


int _main() {
   Liger a;
   cout << (string)a << endl;
   cout << a.Lion::GetSpecies() << endl;	//Indicate which mSpecies to use by scoping the class.
   //error: Liger::GetSpecies is ambiguous.
   return 0;
}
