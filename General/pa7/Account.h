/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 7
*/
/*		This file defines the Account class


_____________________
	Account class

		private : 

			balance : double

		public	:
	
			Account() : default constructor

				Pre-Condition	:	None

				Post_condition	:	balance is set to 0

			Account(double) : custom constructor

				Pre-Condition	:	a value of data type double is passed to the function

				Post_condition	:	balance is set to the the value of the variable passed to the function

			getBalance() : double

				Pre-Condition	:	None

				Post_condition	:	the current balance is returned from the function

			deposit() : double

				Pre-Condition	:	a value of data type double is passed to the function that is greater than 0

				Post_condition	:	the value passed to the function is added to the current balance. If less than zero, an
							error is thrown.

			withdraw() : double

				Pre-Condition	:	a value of data type double is passed to the function that is greater than 0 and less than the balance

				Post_condition	:	the value passed to the function is subtracted the current balance. If less than zero or greater than
							balance, an error is thrown.
*/

#ifndef ACCOUNT_CHARBO
#define ACCOUNT_CHARBO

#include "DepositException.h"
#include "WithdrawlException.h"

namespace Account_charbo
{
	class Account
	{
		private:
			
			double balance;
		public:
				
			
			Account()
			{
				balance = 0;
			}
			Account( double initialDeposit)
			{
				balance = initialDeposit;
			}
			double getBalance()
			{
				return balance;
			}
			
			// returns new balance or throws a DepositException if error
			double deposit( double amount) throw (Exception_charbo::DepositException)
			{
				if (amount > 0)
					balance += amount;
				else
					throw Exception_charbo::DepositException(); 
				return balance;
			}
			
			// returns new balance or throws a WithdrawlException if invalid amount
			double withdraw( double amount) throw(Exception_charbo::WithdrawlException)
			{
				if ((amount > balance) || (amount < 0))
					throw Exception_charbo::WithdrawlException();
				else
					balance -= amount;
				return balance;
			}
		 
	};//End class

}//End namespace

#endif