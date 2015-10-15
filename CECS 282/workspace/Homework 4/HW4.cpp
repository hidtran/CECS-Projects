/*
 * HW4.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: tom
 */
#include <iostream>

using namespace std;

void mystery1(char *, const char*);
int mystery2(const char*);

int main(int argc, char* argv[]){
	unsigned value [5] = {2, 4, 6, 8, 10};
	unsigned int *vPtr;

	for (int index = 0; index < 5; index++){
		cout <<"value [" << index << "]: " << value[index] << endl;
	}

	vPtr = value;
	vPtr = &value[0];

	for (int index = 0; index < 5; index++){
		cout << "*(value + " << index << "): " << *(value+index) << endl;
	}

	for (int index = 0; index < 5; index++){
		cout << "*(vPtr + " << index << "): " << *(vPtr+index) << endl;
	}

	for (int index = 0; index < 5; index++){
		cout << "vPtr[" << index << "]: " << vPtr[index] << endl;
	}

	value[5];
	*(value + 5);
	vPtr[5];
	*(vPtr + 5);

	 char string1[ 80 ];
	 char string2[ 80 ];

	 cout << "Enter two strings: ";
	 cin >> string1 >> string2;
	 mystery1(string1, string2 );
	 cout << string1 << endl;

	 char string3 [80];

	 cout << "Enter a string: ";
	 cin >> string3;

	 cout << mystery2(string3) << endl;
}
	// What does this function do?
void mystery1( char *s1, const char *s2 )
{
	while ( *s1 != '\0' )
		++s1;

	for ( ; ( *s1   = *s2 ); ++s1, ++s2 )
		; // empty statement
} // end function mystery1


int mystery2( const char *s ){
	unsigned int x;

	for ( x = 0; *s != '\0'; ++s )
		++x;

	return x;
} // end function mystery2


