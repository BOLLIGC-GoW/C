/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 1
*/

/*		This driver file creates the class object and calls the 4 main function required for the program
        Also, there is code left behind that was used for testing.

        This program will calculate the total volume of a lake based on incoming data from a file given as
        argv[1]. The total # of fish in the lake is calculated by dividing the total volume by 1000 sq ft.
        This data is output to two files: 1) containing the total number of fish calculated. 2) ints that
        show the population decrease of the fish during the 6 mo season at a loss of 100/mo.
*/

#include "fish.h"
#include <iostream>
#include <assert.h>

using namespace fish_charbo;

int main(int argc, char **argv)
{
    assert((argc > 0) && (argc < 3));

    Fish Nw_Fish;

    Nw_Fish.calc_vol(argv);

    Nw_Fish.calc_total();

    Nw_Fish.write_total();

    /*    This whole block was used to test the program's two outputs

    std::cout << "Total Fish: " << Nw_Fish.Total() << std::endl;

    int tota = Nw_Fish.Total();
    std::cout << tota << std::endl;
    tota -= 100;
    std::cout << tota << std::endl;
    tota -= 100;
    std::cout << tota << std::endl;
    tota -= 100;
    std::cout << tota << std::endl;
    tota -= 100;
    std::cout << tota << std::endl;
    tota -= 100;
    std::cout << tota << std::endl; */


    Nw_Fish.write_pop_decrease();

    return 0;
}//End main
