#include "sequence.h"
#include <iostream>
#include <cstlib>

namespace main_savitch_3
{

//Constructor Funct
sequence::sequence()
{
	data[0] = 1;
	data[1] = 2;
	data[2] = 3;
	data[3] = 4;
}


//Overloaded Operator 

value_type& sequence::operator[](size_type index)
{
	if(index <= current())	
		return data[index];

	if(index > size() || index > CAPACITY)
	{
		cerr << "Error when trying to access container element " << index << std::endl;
		exit(EXIT_FAILURE);

	}
}


}//End namespace