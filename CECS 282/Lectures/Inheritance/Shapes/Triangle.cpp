#ifndef __TRIANGLE_H
#define __TRIANGLE_H
class RightTriangle {
private:
   double mHeight, mBase;

public:
   double GetArea() const {
      return .5 * mHeight * mBase;
   }
};

	~Triangle(){
		std::cout "Destruct Triangle" <:: std::endl;
	}

#endif
