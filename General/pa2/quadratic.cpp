/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 2
*/

/*		This file implements the quadratic class
*/

#include "quadratic.h"
#include <iostream>
#include <cmath>
#include <iomanip>

namespace quadratic_charbo
{
//////////////////////////////
/*    quadratic() Constructor Function (default)

    in:     none

    out:    none

*/
    quadratic::quadratic()
    {
        a = 0;
        b = 0;
        c = 0;
    }//End function

//////////////////////////////

//////////////////////////////
/*    quadratic() Constructor Function (with arguments)

    in:     none

    out:    none

*/
    quadratic::quadratic(double A, double B, double C)
    {
        a = A;
        b = B;
        c = C;
    }//End function

//////////////////////////////

//////////////////////////////
/*    A()Function

    in:     none

    out:    value of a

*/
    double quadratic::A() const
    {
        return a;
    }//End function

//////////////////////////////

//////////////////////////////
/*    B()Function

    in:     none

    out:    value of b

*/
    double quadratic::B() const
    {
        return b;
    }//End function

//////////////////////////////

//////////////////////////////
/*    C()Function

    in:     none

    out:    value of c

*/
    double quadratic::C() const
    {
        return c;
    }//End function

//////////////////////////////

//////////////////////////////
/*    A_mod()Function

    in:     double value

    out:    none

*/
    void quadratic::A_mod(double A)
    {
        a = A;
    }//End function

//////////////////////////////

//////////////////////////////
/*    B_mod()Function

    in:     double value

    out:    none

*/
    void quadratic::B_mod(double B)
    {
        b = B;
    }//End function

//////////////////////////////

//////////////////////////////
/*    C_mod()Function

    in:     double value

    out:    none

*/
    void quadratic::C_mod(double C)
    {
        c = C;
    }//End function

//////////////////////////////

//////////////////////////////
/*    << operator

    in:     memory location of a quadratic object

    out:    none

*/
    std::ostream& operator<<(std::ostream &output, const quadratic &quad)
    {
        //Display the tuple format of the quadratic
        output << "(" << quad.A() << ", " << quad.B() << ", " << quad.C() << ")";
        
	return output;

    }//End function   

//////////////////////////////


//////////////////////////////
/*    eval()Function

    in:     double value

    out:    none

*/
    void quadratic::eval(double x) const
    {
        //Variable that holds the value of the quadratic evaluated for x
        double val = 0;

        //Calculation to evaluate the quadratic at x
        val = ((A())*(x*x))+((B())*(x))+(C());

        //display output
        std::cout <<  "The quadratic evaluated at x is: " << val << std::endl;

    }//End function

//////////////////////////////

//////////////////////////////
/*    roots()Function

    in:     none

    out:    none

*/
    void quadratic::roots() const
    {
        //Variables that hold the root values
        double val1, val2, val3, val4;

        //Variable to test for imaginary numbers. If negative, then the answer is imaginary
        double tester;

        tester = (pow(B(), 2.0)) - (4*(A() * C()));

        //Quadratic Equation

        if(tester >= 0)
	{
		val1 = (-(B()) + std::sqrt(tester))/ (2 * A());
        	val2 = (-(B()) - std::sqrt(tester))/ (2 *A());
	}
	else
	{
		val3 = (-(B()) + std::sqrt((-1)*tester))/ (2 * A());
        	val4 = (-(B()) - std::sqrt((-1)*tester))/ (2 *A());
	}


        //display output
        if(tester >= 0)
	{
            std::cout << std::setprecision(4) << "The roots for the quadratic are: " << val1 << " and " << val2 << std::endl << std::endl;
	}
        else
	{
            std::cout << std::setprecision(4) << "The roots do not exist. The imaginary roots are: " << val3 << "i and " << val4 << "i" << std::endl << std::endl;
	}

    }//End function

//////////////////////////////

//////////////////////////////
/*    + Operator

    in:     memory location of a quadratic object

    out:    none

*/
    quadratic quadratic::operator+(const quadratic& quad)
    {
        //Declare temporary variables
        double a_var = 0, b_var = 0, c_var = 0;

        //Conduct math with pointers between objects
        a_var = this->A() + quad.A();
        b_var = this->B() + quad.B();
        c_var = this->C() + quad.C();

        //Declare object to display
        quadratic temp(a_var, b_var, c_var);

        //display quadratic
	std::cout << "*******************" << std::endl;
        std::cout << "Quadratic #1 + Quadratic #2 " << std::endl;
	std::cout << "*******************" << std::endl << std::endl;
	std::cout << temp << std::endl << std::endl;

	//Return
	return temp;

    }//End function 

//////////////////////////////

//////////////////////////////
/*    - Operator

    in:     memory location of a quadratic object

    out:    none

*/
    quadratic quadratic::operator-(const quadratic& quad)
    {
        //Declare temporary variables
        double a_var = 0, b_var = 0, c_var = 0;

        //Conduct math with pointers between objects
        a_var = this->A() - quad.A();
        b_var = this->B() - quad.B();
        c_var = this->C() - quad.C();

        //Declare object to return
        quadratic temp(a_var, b_var, c_var);

        //display quadratic
	std::cout << "*******************" << std::endl;
        std::cout << "Quadratic #1 - Quadratic #2 " << std::endl;
	std::cout << "*******************" << std::endl << std::endl;
	if(temp.A() == 0)
	{
		std::cout << "Technically, this is not a quadratic." << std::endl;
	}
	std::cout << temp << std::endl << std::endl;

        //Conduct math with pointers between objects
        a_var = quad.A() - this->A();
        b_var = quad.B() - this->B();
        c_var = quad.C() - this->C();

        //modify temp
        temp.A_mod(a_var);
        temp.B_mod(b_var);
        temp.C_mod(c_var);

        //display quadratic
	std::cout << "*******************" << std::endl;
        std::cout << "Quadratic #2 - Quadratic #1 " << std::endl;
	std::cout << "*******************" << std::endl << std::endl;
	if(temp.A() == 0)
	{
		std::cout << "Technically, this is not a quadratic." << std::endl;
	}
	std::cout << temp << std::endl << std::endl;

	//Return
	return temp;

    }//End function 

//////////////////////////////

//////////////////////////////
/*    * Operator

    in:     memory location of a quadratic object

    out:    none

*/
    quadratic quadratic::operator*(const quadratic& quad)
    {
        //Declare temporary variables
        double a_var = 0, b_var = 0, c_var = 0, d_var = 0, e_var = 0;

        //Conduct math with pointers between objects
        a_var = (this->A() * quad.A());
        b_var = (this->A() * quad.B()) + (this->B() * quad.A());
        c_var = (this->A() * quad.C()) + (this->B() * quad.B()) + (this->C() * quad.A());
        d_var = (this->B() * quad.C()) + (this->C() * quad.B());
        e_var = (this->C() * quad.C());
	
    //display output with multiplication
	std::cout << "*******************" << std::endl;
    	std::cout <<  "Quadratic #1 * Quadratic #2" << std::endl; 
	std::cout << "*******************" << std::endl << std::endl;
	std::cout << "(" << a_var << ", " << b_var << ", " << c_var << ", " << d_var << ", " << e_var << ")" << std::endl << std::endl;    

	//Return
	return quad;
	
    }//End function 

//////////////////////////////

}//End namespace
