/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*		This file gives the implementation of the college_person class
        that will be used within the pa4 program.
*/
#include<cassert>
#include <string>
#include "college_person.h"

namespace pa4_charbo
{
    college_person::college_person(char in_name[], int in_age, std::string in_gender, char in_university[], char in_college[], char in_id[], std::string in_letter_grade, double in_gpa)
    :person(in_name, in_age, in_gender) //Base class constructor
    {
        university = in_university;
        college = in_college;
        id = in_id;
        letter_grade = in_letter_grade;
        gpa = in_gpa;
    }//End college_person constructor
    college_person::college_person()
    {
        person();
        university = "University";
        college = "College";
        id = "ID";
        letter_grade = "F-";
        gpa = 0.5;
    }//End college_person constructor
    std::string college_person::University() const             //Accessors
    {
        return university;
    }//End function
    std::string college_person::College() const
    {
        return college;
    }//End function
    std::string college_person::Id() const
    {
        return id;
    }//End function
    std::string college_person::Letter_Grade() const
    {
        return letter_grade;
    }//End function
    double college_person::GPA() const
    {
        return gpa;
    }//End function

    void college_person::mod_University(char in_university[])   //Mutators
    {
        university = in_university;
    }//End function
    void college_person::mod_College(char in_college[])
    {
        college = in_college;
    }//End function
    void college_person::mod_Id(char in_id[])
    {
        id = in_id;
    }//End function
    void college_person::mod_Letter_Grade(char in_letter_grade[])
    {
        letter_grade = in_letter_grade;
    }//End function
    void college_person::mod_GPA(double in_gpa)
    {
        gpa = in_gpa;
    }//End function


}//End namespace
