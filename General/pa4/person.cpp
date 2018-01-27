/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*		This file gives the implementation of the person class
        that will be used within the pa4 program.
*/
#include<cassert>
#include <string>
#include "person.h"

namespace pa4_charbo
{
    person::person(char in_name[], int in_age, std::string in_gender)
    {
        name = in_name;
        age = in_age;
        gender = in_gender;
    }//End person constructor
    person::person()
    {
        name = "Default";
        age = 11;
        gender = "None";
    }//End person constructor

    std::string person::Name() const             //Accessors
    {
        return name;
    }//End function
    int person::Age() const
    {
        return age;
    }//End function
    std::string person::Gender() const
    {
        return gender;
    }//End function

    void person::mod_Name(char in_name[])   //Mutators
    {
        name = in_name;
    }//End function
    void person::mod_Age(int in_age)
    {
        age = in_age;
    }//End function
    void person::mod_Gender(char in_gender[])
    {
        gender = in_gender;
    }//End function

}//End namespace
