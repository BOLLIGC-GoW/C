/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 1
*/

/*		This file implements the Fish class
*/

#include "fish.h"
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <iostream>
#include <string>

namespace fish_charbo
{

//This var represents the fish population density
const int FISH_DEN = 1000;

//This var represents the fish population that is lost each month of the season
const int FISH_DIE = 100;

//This var represents the number of seasons
const int SEASON = 6;

//This represents the fish intervals between depth measurements
const int INTERVAL = 200;


//////////////////////////////
/*    Fish() Constructor Function

    in:     none

    out:    none

*/
    Fish::Fish()
    {
        volume = 0;
        total = 0;
    }//End function

//////////////////////////////

//////////////////////////////
/*    Volume() Function

    in:     none

    out:    returns volume of lake

*/
    int Fish::Volume()
    {
        return volume;
    }//End function

//////////////////////////////

//////////////////////////////
/*    Total() Function

    in:     none

    out:    returns total number of fish

*/
    int Fish::Total()
    {
        return total;
    }//End function

//////////////////////////////

//////////////////////////////
/*    Set_Volume() Function

    in:     calculated volume

    out:    sets member variable volume

*/
    void Fish::Set_Volume(int vol)
    {
        volume = vol;
    }//End function

//////////////////////////////

//////////////////////////////
/*    Set_Total() Function

    in:     calculated total # of fish

    out:    sets member variable total

*/
    void Fish::Set_Total(int tot)
    {
        total = tot;
    }//End function

//////////////////////////////

//////////////////////////////
/*    calc_vol() Function

    in:     none

    out:    none

*/
    void Fish::calc_vol(char **argv)
    {

        //Data points that represent a count of the number of points
        int pt = 0;

        //Lake Width (calculated after data has been completely read in as pt * 200)
        int width = 0;

        //Area of cross section depth at depth [pt]
        std::vector<int> area;

        //Variables to keep track of the incoming depth data: current_depth  and previous_depth
        int cur_depth = 0, prev_depth = 0;
	std::string dummy;

        std::ifstream infile;

        infile.open(argv[1]);

        if(!infile)        
	{
	    std::cout << "Error reading file. Exiting Program." << std::endl << std::endl;
	    assert(infile);
        }

        while(infile)
        {
	    infile >> std::ws >> cur_depth;

	    //Break out of loop if encountering eof
	    if(infile.eof())
		break;

	    //std::cout << "Awesome!" << std::endl; ---This was used for testing
	    if(infile.fail())
 	    {
		std::cout << "Bad data encountered. Exiting Program." << std::endl << std::endl;
		assert(!std::ifstream::failbit);
	    }

	    //getline(infile, dummy);

	    assert(cur_depth >= 0);

            area.push_back(std::max(cur_depth, prev_depth)*200);

            pt++;
            prev_depth = cur_depth; //Change the current depth to previous depth for new incoming data


	}//End loop

        infile.close();

        if(pt <= 1)        
	{
	    std::cout << "Not enough valid measurements. Exiting Program." << std::endl << std::endl;
	    assert(pt > 1);
        }



        //width calculation
        width = (pt-1) * INTERVAL;

        //temporary variable for adding volumes cross sections of volume towards total
        int cross_vol = 0;

        //Temporary Volume var for total volume
        int vol = 0;

        //Class member variable volume of lake calculation which will be used to calculate the total # of fish
        for(int i = 0; i < pt; i++)
        {
            cross_vol = area[i]*width;

            vol += cross_vol;
        }

        Set_Volume(vol);

    }//End function

//////////////////////////////

//////////////////////////////
/*    cacl_total() Function

    in:     none

    out:    none

*/
    void Fish::calc_total()
    {
        //Temporary total var for total # of fish
        int tot = 0;

        tot = Volume() / FISH_DEN;

        Set_Total(tot);
    }//End function

//////////////////////////////

//////////////////////////////
/*    write_total() Function

    in:     none

    out:    none

*/
    void Fish::write_total()
    {
        std::ofstream outfile("total_fish.txt");

        outfile << Total();

        outfile.close();
    }//End function

//////////////////////////////

//////////////////////////////
/*    write_pop_decrease() Function

    in:     none

    out:    none

*/
    void Fish::write_pop_decrease()
    {
        //temporary var to hold the projected decrease in the # of fish over the season
        int tota = (Total()) - FISH_DIE;

        std::ofstream outfile("population_decrease.txt");

        //output to the file (loops are easier and can be easily changed if season goes longer.
        for(int i = 0; i < SEASON; i++)
        {
            outfile << tota << std::endl;
            tota -= FISH_DIE;
        }

        outfile.close();
    }//End function

//////////////////////////////

}//end namespace
