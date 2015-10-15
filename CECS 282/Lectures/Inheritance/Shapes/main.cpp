#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <string>

using namespace std;

void PrintShape(Shape *s); //Shape-pointer S

int main(int argc, char* argv[]) {
   // Declare some variables of the Shape classes.
   Circle c(0, 0, 5);
<<<<<<< HEAD

   Rectangle r(0, 10, 20, 10);
   // Shape s("Trapezoid", 0, 0);

   Rectangle r(10, 20, 10, 20);

   Shape *c2 = new Triangle(0, 0, 5, 10);

	Shape *t = new Triangle(0, 0, 10, 20);   

   cout << endl << endl << endl;
   
   delete c2;
	delete *t;

   //Rectangle r(0, 10, 20, 10);
>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7
=======
   Rectangle r(0, 10, 20, 10);

   Shape *t = new Triangle(0, 0, 10, 20);

   cout << endl << endl;

   delete t;
>>>>>>> ed507c62e0f0036a510cf73a31b095b83509f197

   // We will now print out some information about a Shape object. Since we want
   // to work with all Shape-derived classes, we take a Shape* parameter via the
   // magic of polymorphism.
<<<<<<< HEAD
   // PrintShape(&c);
   // PrintShape(&r);
   // PrintShape(&s);

	cout << "---" << endl;
	Circle *heap = new Circle(0, 0, 10);
	delete heap;
	cout << "---" << endl;
=======
   //PrintShape(&c);
   //PrintShape(&r);
//   PrintShape(&s);
}
>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7

	cout << "---" << endl;
	Shape *heaps = new Circle(0, 0, 10);
	delete heaps;
	cout << "---" << endl;

// Note that the parameter is of type Shape*. All the compiler knows is that the
// parameter is of a class that derives from Shape, or is a Shape itself.
void PrintShape(Shape *s) {
   // Print the name of the shape and its center point.
   cout << s->GetShapeName() << " at (" << s->GetCenterX() << ", " << 
    s->GetCenterY() << ")";

   // Suppose I now want to print the area of the Shape.
   // Can I just do this?
   // cout << s->GetArea();


   // Since the Shape class does not have a GetArea function, the compiler
   // will not let me call GetArea, even if we *know* that s points to something
   // that DOES have a GetArea.

   /*
   // First attempt at printing the area: downcasting.
   // Ask the shape for its name, and then down-cast the pointer to an 
   // appropriate type.
	/*
;   if (s->GetShapeName() == "Circle") {
      Circle *cPtr = (Circle*)s; // cast s to a Circle pointer (Downcasting)
      cout << "; area " << cPtr->GetArea() << endl;
   }
   else if (s->GetShapeName() == "Rectangle") {
      Rectangle *rPtr = (Rectangle*)s;
      cout << "; area " << rPtr->GetArea() << endl;
   }
   // What are the weaknesses of this approach?
<<<<<<< HEAD
	// Can't access to  new shape. Too much coding.
	// Spelling errors. Wrong shape names.
	*/
=======
   */
>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7









   // Second attempt: add a GetArea function to the Shape class.



   // Now I can call GetArea on a Shape pointer!
   cout << "; area " << s->GetArea() << endl;
   // What is the output? Why?
	// Allow because GetArea() define in Shape Class.
	// Output = 0 because of static binding(bound) of GetArea() in Shape Class.
	// Solution: add the "virtual" keyword into GetArea() in Shape Class.





<<<<<<< HEAD
   // This takes us to virtual functions. Prevents making shape objects.
=======
   // This takes us to virtu  al functions.
>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7
   // 1. Add keyword "virtual" to Shape's GetArea function. What does this mean?
	// Allow the program to choose correct GetArea() at run-time.




<<<<<<< HEAD
   // 2. Now call GetArea on the Shape pointer. Whose GetArea is called? Derived class GetArea().
	//	Don't know which type of shape GetArea() until at run-time.
   cout << "; area " << s->GetArea() << endl;
=======
   // 2. Now call GetArea on the Shape pointer. Whose GetArea is called?
//   cout << "; area " << s->GetArea() << endl;
>>>>>>> d2615f124828159702e05584abb4aacc7e5a5ee7




   // 3. Is there a reasonable default implementation of GetArea? Should generic
   //    Shape objects really have an area? Does it make sense to construct full
   //    objects of type Shape? What can we do about this?
	// GetArea() doesn't have default implementation, and doesn't make sense to construct full objects of type Shape (Pure virtual function).

}
