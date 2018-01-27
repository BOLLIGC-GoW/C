/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 1
*/

/*		This file implements a date class

*/

#include<string>
#include<iostream>
#include "date.h"

namespace date_cb
{
//////////////////////////////////////////////////////////////////////////
/*      date function (default)

    purpose:This function will set the date

    in:     none

    out:    none
*/
/////////////////////////////////////////////////////////////////////////
    date::date()
    {
        day = 1;
        month = 1;
        year = 2001;
    }

//////////////////////////////////////////////////////////////////////////
/*      date function

    purpose:This function will set the date

    in:     in_day, in_month, in_year

    out:    none
*/
/////////////////////////////////////////////////////////////////////////
    date::date(int in_day, int in_month, int in_year)
    {
        day = in_day;
        month = in_month;
        year = in_year;
    }

/////////////////////////////////////////////////////////////////////////
/*      increment_day function

    purpose:This function will increment the date by one day

    in:     none

    out:    none
*/
/////////////////////////////////////////////////////////////////////////
    void date::increment_day()
    {
        day++;

	if(day > 31)
	{
		month++;
		day = 1;
		if(month > 12)
		{
			year++;
			month = 1;
		}
	}
    }

////////////////////////////////////////////////////////////////////////
/*      date_num function

    purpose:This function will display the date in number format

    in:     none

    out:    none
*/
///////////////////////////////////////////////////////////////////////
    void date_num(date calendar)
    {
        std::cout << "The date is " << calendar.month << " / " << calendar.day << " / " << calendar.year << std::endl;
    }

////////////////////////////////////////////////////////////////////////
/*      date_word function

    purpose:This function will display the date in word format

    in:     none

    out:    none
*/
///////////////////////////////////////////////////////////////////////
    void date_word(date calendar)
    {

        std::string month_word;
        switch(calendar.month)
        {
        case 1:
            {
                month_word = "January";
                break;
            }
        case 2:
            {
                month_word = "February";
                break;
            }
        case 3:
            {
                month_word = "March";
                break;
            }
        case 4:
            {
                month_word = "April";
                break;
            }
        case 5:
            {
                month_word = "May";
                break;
            }
        case 6:
            {
                month_word = "June";
                break;
            }
        case 7:
            {
                month_word = "July";
                break;
            }
        case 8:
            {
                month_word = "August";
                break;
            }
        case 9:
            {
                month_word = "September";
                break;
            }
        case 10:
            {
                month_word = "October";
                break;
            }
        case 11:
            {
                month_word = "November";
                break;
            }
        case 12:
            {
                month_word = "December";
                break;
            }

        }//End Switch

        std::cout << "The date is " << month_word << " " << calendar.day << ", " << calendar.year << std::endl;
    }

};//End namespace