/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 2
*/
/*		This is the driver file for the quadratic class.
		This file creates objects of type quadratic
		and calls associated functions from utils and 
		quadratic. 

		Also, it uses the << insertion operator 
		to display the tuple form of the quadratic because
		...the assignment required it. Normally, I wouldn't 
		put this in the main() driver file. 
*/

#include "utils.h"
#include "quadratic.h"
#include <iostream>

using namespace quadratic_charbo;
using namespace utils_charbo;

int main()
{
    
    greeting();

    double a = 0, b = 0, c = 0, x = 0;

    user_quadratic(&a, &b, &c);

    quadratic Prob1(a, b, c);

    user_quadratic(&a, &b, &c);

    quadratic Prob2(a, b, c);

    user_x(&x);

    intro1();

    std::cout << Prob1 << std::endl; 
    Prob1.eval(x);
    Prob1.roots();

    intro2();

    std::cout << Prob2 << std::endl; 
    Prob2.eval(x);
    Prob2.roots();

    quadratic tempQuad;

    tempQuad = Prob1 + Prob2;

    tempQuad = Prob1 - Prob2;

    Prob1 * Prob2;

    return 0;
}
