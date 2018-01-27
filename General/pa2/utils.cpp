/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 2
*/
/*		This file implements the functions prototypes contained in the utils.h file
*/
#include "utils.h"
#include <iostream>
#include <cstdlib>


namespace utils_charbo
{


//////////////////////////////
/*    user_quadratic() Function

    in:     none

    out:    none (all values are modified through pointers)

*/
    void user_quadratic(double *a, double *b, double *c)
    {
	//Prompt user for output and error check each value 1-by-1. Exit program if encounter bad input.

        std::cout << "Please enter coefficient values for a, b, and c in a quadratic equation." << std::endl; 
	std::cout << "Press 'enter' after each entry." << std::endl << std::endl;
	if(!(std::cin >> *a))
	{
		std::cout << "That is not good input. Exiting Program." << std::endl <<std::endl;
		exit(EXIT_FAILURE);
	}
	if(*a == 0)
	{
		std::cout << "That is not good input. A quadratic equation must have a" <<std::endl;
		std::cout << "non-zero value for the 'a' coefficient. Exiting Program." << std::endl <<std::endl;
		exit(EXIT_FAILURE);
	}
	if(!(std::cin >> *b))
	{
		std::cout << "That is not good input. Exiting Program." << std::endl <<std::endl;
		exit(EXIT_FAILURE);
	}

	if(!(std::cin >> *c))
	{
		std::cout << "That is not good input. Exiting Program." << std::endl <<std::endl;
		exit(EXIT_FAILURE);
	}        

    }//End function

//////////////////////////////

//////////////////////////////
/*    user_x() Function

    in:     none

    out:    none (value modified through pointers)

*/
    void user_x(double *x)
    {
	//Prompt user for output and error check value. Exit program if encounter bad input.

        std::cout << "Please enter a number value for x followed by enter." << std::endl;
        if(!(std::cin >> *x))
	{
		std::cout << "That is not good input. Exiting Program." << std::endl <<std::endl;
		exit(EXIT_FAILURE);
	}
    }//End function

//////////////////////////////

//////////////////////////////
/*    intro1() Function

    in:     none

    out:    none 

*/
    void intro1()
    {
	//Display banner for Quad 1
    	std::cout << "*******************" << std::endl;
    	std::cout <<  "Quadratic #1" << std::endl;
    	std::cout << "*******************" << std::endl << std::endl;

    }//End function

//////////////////////////////

//////////////////////////////
/*    intro2() Function

    in:     none

    out:    none 

*/
    void intro2()
    {
	//Display banner for Quad 2
    	std::cout << "*******************" << std::endl;
    	std::cout <<  "Quadratic #2" << std::endl;
    	std::cout << "*******************" << std::endl << std::endl;

    }//End function

//////////////////////////////

//////////////////////////////
/*    greeting() Function

    in:     none

    out:    none 

*/
    void greeting()
    {
	//Display banner for Welcome
    	std::cout << "\n****** Welcome to Quadratic Assignment pa2! ******" << std::endl << std::endl;


    }//End function

//////////////////////////////

}

