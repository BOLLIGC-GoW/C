/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 7
*/
/*		This file defines the DepositException derived class

_____________________
	DepositException class


		public	:
	
			DepositException() : default constructor

				Pre-Condition	:	None

				Post_condition	:	the error message "Error: can't deposit less than zero." is set as the error_message

		Invariance:

			n/a

		Value Semantics:

			the = operator and copy function may be used
*/

#ifndef DEPOSITEXCEPTION_CHARBO
#define DEPOSITEXCEPTION_CHARBO


#include "AccountException.h"

namespace Exception_charbo
{

	class DepositException : public Exception_charbo::AccountException
	{

		public:

			DepositException() : AccountException() {set_message("Error: can't deposit less than zero.");}
			
	};//End class

}//End namespace

#endif