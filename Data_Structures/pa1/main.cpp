/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 1
*/

/*	

		This main file is used to test the date class
		It will prompt you for input. Then, it will display the date in num format, increment the
		day, and re-display in word format.

*/


#include <assert.h>
#include <string>
#include <iostream>
#include "date.h"

using namespace date_cb;

int main()
{
    	//vars
	std::cout << "Enter Day, Month, and Year. Separate by enter or whitespace." << std::endl;
	int in_day, in_month, in_year;
	std::cin >> in_day >> in_month >> in_year;
	
	//Error Checking
	assert(in_day > 0);
	assert(in_day < 32);
	assert(in_month > 0);
	assert(in_month < 13);

	//Create Object
	date calendar(in_day, in_month, in_year);

	//Testing
	date_num(calendar);
	calendar.increment_day();
	date_word(calendar);

    	return 0;
}
