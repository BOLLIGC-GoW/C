/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 7
*/
/*		This file is the driver file to display the exception handling
		for pa7
*/

#include "Account.h"
#include <iostream>

const double DEPOSIT_POS = 55;
const double DEPOSIT_NEG = -10;
const double WITHDRAWL_GOOD = 10;
const double WITHDRAWL_BAD = 55;

using namespace Exception_charbo;

int main()
{
	//Declare test object
	Account_charbo::Account Acc1;

	//Show that the deposit function work fine under pre-condition
	std::cout << "Now attempting to deposit a positive amount (" << DEPOSIT_POS << ") into account." << std::endl;
	Acc1.deposit(DEPOSIT_POS);
	std::cout << "Current balance is: " << Acc1.getBalance() << std::endl;

	//Show the error catching when violating pre-condition
	try
	{
		std::cout << "Now attempting to deposit a negative (" << DEPOSIT_NEG << ") amount into account." << std::endl;
		Acc1.deposit(DEPOSIT_NEG);

	}
	catch(DepositException)
	{
		Exception_charbo::DepositException* Ptr1 = new Exception_charbo::DepositException;
		Ptr1->display_message();
		std::cout << std::endl;
		std::cout << "Current balance is: " << Acc1.getBalance() << std::endl;
		std::cout << std::endl;
		delete Ptr1;
	}

	//Show that the withdrawl function work fine under pre-condition
	std::cout << "Now attempting to withdraw an amount (" << WITHDRAWL_GOOD << ") less than total \nbalance out of account." << std::endl;
	Acc1.withdraw(WITHDRAWL_GOOD);
	std::cout << "Current balance is: " << Acc1.getBalance() << std::endl;

	//Show the error catching when violating pre-condition
	try
	{
		std::cout << "Now attempting to withdraw an amount (" << WITHDRAWL_BAD << ") greater than total \nbalance out of account." << std::endl;
		Acc1.withdraw(WITHDRAWL_BAD);
	}
	catch(WithdrawlException)
	{
		Exception_charbo::WithdrawlException* Ptr2 = new Exception_charbo::WithdrawlException;
		Ptr2->display_message();
		std::cout << std::endl;
		std::cout << "Current balance is: " << Acc1.getBalance() << std::endl;
		std::cout << std::endl;
		delete Ptr2;
		
	}

	//Show the error catching when violating pre-condition
	try
	{
		std::cout << "Now attempting to withdraw a negative (" << DEPOSIT_NEG << ") amount out of account." << std::endl;
		Acc1.withdraw(DEPOSIT_NEG);
	}
	catch(WithdrawlException)
	{
		Exception_charbo::WithdrawlException* Ptr2 = new Exception_charbo::WithdrawlException;
		Ptr2->display_message();
		std::cout << std::endl;
		std::cout << "Current balance is: " << Acc1.getBalance() << std::endl;
		std::cout << std::endl;
		delete Ptr2;
		
	}

	std::cout << "\nEnd of test exception cases. Now ending program." << std::endl;

	return 0;

}

