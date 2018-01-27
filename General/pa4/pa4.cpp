/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*		This is the driver file for the pa4 program. It opens files,
		calls functions, and calls asserts.
*/

#include "college_person.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace pa4_charbo;

int main (int argc, char ** argv)
{
    assert(argc == 3);
    assert(argv[1]);
    std::ifstream inData;
    inData.open(argv[1]);

    Bag all_students;

    read_data(inData, all_students);

    inData.close();

    //Bags for different schools
    Bag Metro_Bag;
    Bag UCD_Bag;
    Bag Other_Bag;

    separate_Bag(all_students, Metro_Bag, UCD_Bag, Other_Bag);

    assert(argv[2]);
    std::ofstream outData;
    outData.open(argv[2]);

    write_data(outData, Metro_Bag, UCD_Bag, Other_Bag);

    outData.close();

    return 0;
}
