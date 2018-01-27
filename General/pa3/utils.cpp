/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 3
*/

/*		This file implements the function from utils.h
*/

#ifndef UTILS_CHARBO
#define UTILS_CHARBO
#include <iostream>
#include <cctype>
#include <cstdio>
#include <assert.h>
#include <cstring>
#include "utils.h"


namespace utils_charbo
{
//////////////////////////////
/*    get_input() Function

    in:     C-string of STRING_SIZE elements

    out:    none

*/
    void get_input(char input [], unsigned int size)
    {

	if(input == NULL)
	{
		std::cout << "Error: Memory could not be allocated. Exiting." << std::endl << std::endl;
		assert(input != NULL);
	}

	//Local count
	unsigned int i= 0;

	//Message
	std::cout << "Enter a string of chars: ";

	std::scanf("%s", input);

	//Error checking
	if(strlen(input) > size)
	{
		std::cout << "Error: Size of input too large. Exiting." << std::endl << std::endl;
		assert(strlen(input) < size);
	}


	//Reset i
	i = 0;
	
	for (i = 0; i < strlen(input); i++)
	{
		if(input[i] == '\n')
		{		
			input[i] = '\0';
			return;
		}
		//Error checking
		if(!(isalpha(input[i])))
		{		
			std::cout << "Error. Non-Alphabetic Input. Exiting." << std::endl << std::endl;
			assert(isalpha(input[i]));
		}
	}
	

    }//End function

//////////////////////////////

//////////////////////////////
/*    display() Function

    in:     none

    out:    none

*/
    void display()
    {
	std::cout << std::endl << "Welcome to the Pig Latin conversion program!" << std::endl << std::endl;	

    }//End function

//////////////////////////////
}
#endif  