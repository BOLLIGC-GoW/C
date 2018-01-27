/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 7
*/
/*		This file defines the WithdrawlException derived class

_____________________
	withdrawlException class


		public	:
	
			WithdrawlException() : default constructor

				Pre-Condition	:	None

				Post_condition	:	the error message "Error: can't withdraw more than balance in account." is set as the error_message

		Invariance:

			n/a

		Value Semantics:

			the = operator and copy function may be used
*/

#ifndef WITHDRAWLEXCEPTION_CHARBO
#define WITHDRAWLEXCEPTION_CHARBO


#include "AccountException.h"

namespace Exception_charbo
{

	class WithdrawlException : public Exception_charbo::AccountException
	{

		public:

			WithdrawlException() : AccountException() {set_message("Error(1): can't withdraw more than balance in account.\nor\nError(2): can't withdraw less than zero...");}
	
	};//End class

}//End namespace

#endif