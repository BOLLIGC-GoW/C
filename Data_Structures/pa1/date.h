/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 1
*/

/*		This file defines the date class

		Data Members:
			
        		month 	int
	        	day	int
	        	year	int

		Member functions:

			date() (*constructor*)
				
				Pre-Condition:
					none

				Post-Condition:
					Date will be set to 1/1/2001

			date(int in_day, int in_month, int in_year) (*constructor*)
				
				Pre-Condition:
					in_day will be entered as a num 1-31
					in_month will be entered as a num 1-12
					in_year will be entered as a num in the number format xxxxx
						ex: 1999

				Post-Condition:
					an object will be constructed with the values
					day = in_day
					month = in_month
					year = in_year

			void increment_day() 
				
				Pre-Condition:
					none

				Post-Condition:
					the date will be incremented by 1 day

			void date_num() const 	(*friend function*)
				
				Pre-Condition:
					none

				Post-Condition:
					the date will be displayed in numerical format

			void date_word() const 	(*friend function*)
				
				Pre-Condition:
					none

				Post-Condition:
					the date will be displayed in word format
*/



#ifndef DATE_CB
#define DATE_CB

#include<iostream>

namespace date_cb
{
	
	class date
   	{
    		private:
        		int month;
	        	int day;
	        	int year;
		public:
			date();
			date(int in_day, int in_month, int in_year);
	        	void increment_day();
			friend void date_num(date calendar);
	        	friend void date_word(date calendar);
	   
	};//End class
};//End namespace

#endif // DATE_CB
