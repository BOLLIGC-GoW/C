/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 2
*/

/*		This file defines the quadratic class

		Data Members:


		Member functions:

		quadratic: no return -default

			Pre-Condition: none

			Post-Condition: This function will given member variables a, b, and c
			default values of 0, 0, and 0

		quadratic: no return -custom

			Pre-Condition: 3 acceptable values of double data type are passed
			to the function

			Post-Condition: This function will given member variables a, b, and c
			default values of the passed values A, B, and C

		A: double

			Pre-Condition: none

			Post-Condition: This function will return the member var value of a

		B: double

			Pre-Condition: none

			Post-Condition: This function will return the member var value of b

		C: double

			Pre-Condition: none

			Post-Condition: This function will return the member var value of c

		A_mod: none

			Pre-Condition: an acceptable double value is passed to the function

			Post-Condition: This function will modify the member variable a

		B_mod: none

			Pre-Condition: an acceptable double value is passed to the function

			Post-Condition: This function will modify the member variable b

		C_mod: none

			Pre-Condition: an acceptable double value is passed to the function

			Post-Condition: This function will modify the member variable c

		eval: none

			Pre-Condition: an object of quadratic type and a double value are passed to the function

			Post-Condition: This function will display the quadratic evaluated at the double value
			that is passed to the function

		roots: none

			Pre-Condition: an object of quadratic type is passed to the function

			Post-Condition: This function will display the roots of the quadratic 
			equation. If the roots are imaginary, the function will state so, and display 
			the imaginary roots

		<<: &ostream -friend

			Pre-Condition: an object of quadratic type is placed after the operator 

			Post-Condition: This operator will display the quadratic in tuple format (a, b, c)

		+: quadratic

			Pre-Condition: objects of quadratic type are placed before and after the operator 

			Post-Condition: The operator will add the a values together, b values together, and
			c values together, respectively. Then the results will be displayed using the << overloaded
			operator.

		-: quadratic

			Pre-Condition: objects of quadratic type are placed before and after the operator 

			Post-Condition: The operator will subtract the a values together, b values together, and
			c values together, respectively. Then the results will be displayed using the << overloaded
			operator.

		*: quadratic

			Pre-Condition: objects of quadratic type are placed before and after the operator 

			Post-Condition: The operator will multiply the quadratic equations (a, b, c) * (a, b, c)
			and display the respective result of the multiplication. NOTE: The << operator
			cannot be used to display the results because the results cannot guaranteed to be able to
			be displayed in (a, b, c) tuple format. They format may require more variables.
*/

#ifndef QUADRACTIC_CHARBO
#define QUADRACTIC_CHARBO
#include <iostream>



namespace quadratic_charbo
{
    class quadratic
    {


	    friend std::ostream& operator<<(std::ostream &, const quadratic&);

        private:

            double a;
            double b;
            double c;

        public:

            quadratic();
            quadratic(double A, double B, double C);

            double A() const;
            double B() const;
            double C() const;
            void A_mod(double);
            void B_mod(double);
            void C_mod(double);

            void eval(double) const;
            void roots() const;
            quadratic operator+(const quadratic&);
            quadratic operator-(const quadratic&);
            quadratic operator*(const quadratic&);

    };//End class


}//End namespace

#endif  
