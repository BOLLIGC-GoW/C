/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 1
*/

/*		This file defines the Fish class

		Data Members:

            volume int : This variable represents the total calculated volume of the lake (once it is determined)
            total  int : This variable represents the total number of fish allowed by volume / 1000 sq ft

		Member functions:

            Fish() (*constructor*)

				Pre-Condition:
					none

				Post-Condition:
					volume and total are set to 0

			Volume()

				Pre-Condition:
					none

				Post-Condition:
					returns the member value volume
			Total()

				Pre-Condition:
					none

				Post-Condition:
					returns the member value total

			Set_Volume()

				Pre-Condition:
					an positive integer number is entered into the function

				Post-Condition:
					the function will set the member variable volume to the positive integer number passed to
					the function

			Set_Total()

				Pre-Condition:
					an positive integer number is entered into the function

				Post-Condition:
					the function will set the member variable total to the positive integer number passed to
					the function

			calc_vol(char **argv)

				Pre-Condition:
					a file formatted in the proper way (i.e. positive integer numbers delimited by '\n') is passed as a
					parameter to main() as argv[1].
					the depth measurements represented by the integer data points must be equally spaced - 200ft apart.

				Post-Condition:
					the function will calculate an approximation of the total volume of the lake based on the data points.

            calc_total()

				Pre-Condition:
					none

				Post-Condition:
					the function will calculate an approximation of the # of fish in the lake based on the approximation of
					the volume.

            write_total()

				Pre-Condition:
					none

				Post-Condition:
					the function will write the approximated total # of fish to a file named "total_fish.txt"

            write_pop_decrease()

				Pre-Condition:
					none

				Post-Condition:
					the function will the write the # of fish per month over a 6 mo season after a -100/mo
					decrease (using the approximated total # of fish determined by cacl_total() function)to a file named
                    "population_decrease.txt"
*/



#ifndef FISH_CHARBO_INCLUDED
#define FISH_CHARB_INCLUDED

namespace fish_charbo
{
    class Fish
    {
        private:

            int volume;
            int total;

        public:

            Fish();

            int Volume();
            int Total();
            void Set_Volume(int vol);
            void Set_Total(int tot);
            void calc_vol(char **argv);
            void calc_total();
            void write_total();
            void write_pop_decrease();

    };//end class
}//end namespace


#endif // FISH_CHARBO_INCLUDED
