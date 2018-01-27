/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 7
*/
/*		This file defines the AccountException base class


_____________________
	AccountException class

		private : 

			error_message : string

		public	:
	
			AccountException() : default constructor

				Pre-Condition	:	None

				Post_condition	:	error_message is set to "Default"

			set_message() : string

				Pre-Condition	:	a value of type string is passed to the function

				Post_condition	:	error_message is changed to the value of the string passed to the function

			set_message() : void

				Pre-Condition	:	none

				Post_condition	:	the error_message is displayed

		Invariance:

			error_message represents the particular error that is associated with the class (mostly derived classes)

		Value Semantics:

			the = operator and copy function may be used
*/

#ifndef ACCOUNTEXCEPTION_CHARBO
#define ACCOUNTEXCEPTION_CHARBO


#include <iostream>
#include <cstring>

namespace Exception_charbo
{

	class AccountException
	{

		private:
		
			std::string error_message;
		
		public:

			AccountException() {error_message = "Default";}

			//Mutator
			void set_message(std::string input) {error_message = input;}

			//Accessor
			void display_message() {std::cout << error_message << std::endl;}
			
	};



}//End namespace

#endif