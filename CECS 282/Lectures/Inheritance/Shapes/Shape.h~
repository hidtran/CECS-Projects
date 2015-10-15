#ifndef __SHAPE_H
#define __SHAPE_H

#include <iostream>
#include <string>

// A simple base class for representing 2-dimensional shapes.
class Shape {
private:
   // every Shape has a center coordinate, and a name describing the shape.
   double mCenterX;
   double mCenterY;
   std::string mShapeName;

public:
   // The base class constructor initializes the center location and the name.
   Shape(const std::string &shapeName, double centerX, double centerY) :
    mShapeName(shapeName), mCenterX(centerX), mCenterY(centerY) {
       std::cout << "Construct Shape" << std::endl;
   }

	virtual ~Shape(){
		std::cout "Destruct Shape" <:: std::endl;
	}

   // Simple accessors.
   double GetCenterX() const {
      return mCenterX;
   }

   double GetCenterY() const {
      return mCenterY;
   }

   std::string GetShapeName() const {
      return mShapeName;
   }

   // We will add things here later.
<<<<<<< HEAD
	
	//Don't know which GetArea() class will get called at compile time until at run-time.
	// Pure virtual function is without any implementation(body).
	virtual double GetArea() const = 0;
=======
   virtual double GetArea() const = 0;
   
   virtual ~Shape() {
      std::cout << "Destruct Shape" << std::endl;
   }















>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7

};

#endif
