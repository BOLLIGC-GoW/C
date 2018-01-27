/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*	This file gives the declarations global functions that
        will be used within the pa4 program.

____________________
    Global Functions

            compute_data(double obtained, double possible, std::string &letter_grade, double &gpa) : void

                pre-condition: the amount of points obtained, the amount of points possible, the
                letter grade's memory location, and the gpa's memory location (local vars) are passed to the function

                post-condition: This function calculate the gpa and letter grade possible based on
                the points obtained vs the points possible

            read_data(std::ifstream&, Bag&) : void

                pre-condition: the ifstream object and memory location of a bag are passed to the function

                post-condition: The bag will parse the data stored in the file that is used as an argument to the
                program argv[1]. After the information is parsed, a dynamic bag will be created which holds the unorganized
                information

            separate_bag(Bag &orig_Bag, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag) : void

                pre-condition: 4 memory locations of Bag objects are passed to the function, representing the original bag of students,
                the bag of students that study at UCD, the bag of students that study at Metro State, and the bag
                of students that do not apply to either

                post-condition: The original bag will be separated into the various categories explained above.
                The original bag will not be destroyed after usage.

            write_data(std::ofstream&, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag) : void

                pre-condition: the ofstream object and memory location of the 3 category bags are passed to the function

                post-condition: a file will be written to (designated by argv[2]) that is formatted along the guidelines.
                The bags will be separated by category.

GPA Scale
GPA_SCALE =4.0;

A = 3.7;
A_minus = 3.3;
B_plus = 3.0;
B = 2.8;
B_minus = 2.5;
C_plus = 2.3;
C = 2.0;
C_minus = 1.8;
D_plus = 1.6;
D = 1.4;
D_minus = 1.2;

*/


#ifndef UTILS_CHARBO
#define UTILS_CHARBO
#include <cstdlib>
#include <string>
#include "college_person.h"

int const STRING_SIZE = 16;
int const ID_SIZE = 4;

namespace pa4_charbo
{

    void compute_data(double obtained, double possible, std::string &letter_grade, double &gpa);
    void read_data(std::ifstream&, Bag&);
    void separate_Bag(Bag &orig_Bag, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag);
    void write_data(std::ofstream&, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag);

}//End namespace

#endif // UTILS_CHARBO