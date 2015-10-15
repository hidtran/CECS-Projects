// These functions are global (everyone can use).
// They are compiled into the final program .exe, but other .cpp files can't
// "see" them unless they declare the functions first.

double Average(int num1, int num2) {
   return (num1 + num2) / 2.0;
}

int Abs(int number) {
   return number >= 0 ? number : -number;
}

int Max(int num1, int num2) {
   return num1 >= num2 ? num1 : num2;
}

int Pow(int base, int exponent) { 
   int result = 1;
   for (int i = 0; i < exponent; i++) {
      result *= base;
   }
   return result;
}

<<<<<<< HEAD
int Remainder(int a, int b) {
   return a % b;
}



=======
// Notice that the Ln function from mymath.h is not defined here.
>>>>>>> 9f5dd7c666beebcee297f3198fc79733f977dee9
