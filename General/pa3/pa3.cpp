/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 3
*/

/*		This is the driver file for the pa3 program.
		It collects a c-string from the user and
		displays the result in pig latin.		
*/

#include "piglatin.h"
#include "utils.h"
#include <iostream>


using namespace utils_charbo;
using namespace piglatin_charbo;

int main()
{
	display();
	
	//char pointer
	char * charPtr = new char [STRING_SIZE];

	get_input(charPtr, STRING_SIZE);
	
	piglatin piggy(charPtr);

	delete [] charPtr;

	piggy.converter();
	
	std::cout << std::endl << piggy << std::endl <<std::endl;

	return 0;

}