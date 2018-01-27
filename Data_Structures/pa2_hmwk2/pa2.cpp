/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 2
*/

/*	
		This file implements the [] overloaded operator of the
		sequence class

		*I'm putting the Pre-Post Conditions Here Because A Header File is 
		Not Part of the Assignment*

		operator []

			Pre-Condition: the index number passed to the function is less
			that the current size of the array (used member var) and is
			less than the total CAPACITY of the array.
	
			Post Condition: the array element at [index] will be returned
			from the function.
*/

#include "sequence.h"
#include <iostream>
#include <cstlib>

//Overloaded [] Operator Implementation/ !!Namespace not included, but acknowledged!!


value_type& sequence::operator[](size_type index)
{
	if(index <= size())	
		return data[index];

	else if(index > size() || index > CAPACITY)
	{
		std::cerr << "Error when trying to access container element " << index << std::endl;
		exit(EXIT_FAILURE);
	
	}//End if statement

}//End function


