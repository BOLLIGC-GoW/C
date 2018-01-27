/*	Charles Bollig
	CSCI 2421 - 001 Spr 15
	PA3
*/
/*	This file is used to test the palindrome function
*/

#include "bag.h"
#include <iostream>

using namespace bag_charbo;
using namespace std;

int main()
{
	bag bag_tst;
	bag_tst.insert(1);
	bag_tst.insert(2);
	bag_tst.insert(3);
	bag_tst.insert(4);
	bag_tst.insert(5);
	
	
	bag * bagPtr = NULL;
	bagPtr = palindrome(bag_tst);


}//End main