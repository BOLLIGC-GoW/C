/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*		This file gives the implementation of the utility functions
        that will be used within the pa4 program.
*/

#include "utils.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>

const int GPA_SCALE =4.0;

const double A = 3.7;
const double A_minus = 3.3;
const double B_plus = 3.0;
const double B = 2.8;
const double B_minus = 2.5;
const double C_plus = 2.3;
const double C = 2.0;
const double C_minus = 1.8;
const double D_plus = 1.6;
const double D = 1.4;
const double D_minus = 1.2;

namespace pa4_charbo
{
    void compute_data(double obtained, double possible, std::string &letter_grade, double &gpa)
    {
        //temporary var
        double total_percentage = obtained / possible;

        //Compute GPA
        gpa = total_percentage * GPA_SCALE;

        //Obtained letter_grade based on GPA
        //A
        if(gpa > A)
            {letter_grade = "A\0";}
        if(gpa < A && gpa >= A_minus)
            {letter_grade = "A-\0";}
        //B
        if(gpa < A_minus && gpa >= B_plus)
            {letter_grade = "B+\0";}
        if(gpa < B_plus && gpa >= B)
            {letter_grade = "B\0";}
        if(gpa < B && gpa >= B_minus)
            {letter_grade = "B-\0";}
        //C
        if(gpa < B_minus && gpa >= C_plus)
            {letter_grade = "C+\0";}
        if(gpa < C_plus && gpa >= C)
            {letter_grade = "C\0";}
        if(gpa < C && gpa >= C_minus)
            {letter_grade = "C-\0";}

        //D
        if(gpa < C_minus && gpa >= D_plus)
            {letter_grade = "D+\0";}
        if(gpa < D_plus && gpa >= D)
            {letter_grade = "D\0";}
        if(gpa < D && gpa >= D_minus)
            {letter_grade = "D-\0";}

        //F
        if(gpa < D_minus)
            letter_grade = "F\0";


    }//End function

    void read_data(std::ifstream &inData, Bag &all_student)
    {

        //Read data from file
        while(inData.peek() != EOF)
        {

            //Vars to go into constructor for college_person class
            char dummy[STRING_SIZE] = "Def";
            char name[STRING_SIZE] = "Def";
            int age = 0;
            char gender_buff[STRING_SIZE] = "Def";
            std::string gender = "Def";
            char university[STRING_SIZE] = "Def";
            char college[STRING_SIZE] = "Def";
            char id[STRING_SIZE] = "Error:ID";
            std::string letter_grade;
            double gpa = 0.0;
            //Temporary vars to compute gpa and letter_grade
            double possible = 0.0, possible_in = 0.0;
            double obtained = 0.0, obtained_in = 0.0;

            inData.getline(name, STRING_SIZE, ',');
            inData >> age;
            inData.ignore();
            inData.getline(gender_buff, STRING_SIZE, ',');
            inData.getline(university, STRING_SIZE, ',');
            inData.getline(college, STRING_SIZE, ',');
            if(inData.peek() == '8')
                {inData.getline(id, ID_SIZE, '\n');}
            else
                {inData.getline(dummy, ID_SIZE, '\n');}

	

	    while(inData.peek() != '\n')
	    {
		if(inData.peek() == EOF)
			break;
		inData.getline(dummy, STRING_SIZE, ',');		// dumps comma from file;
            	inData >> obtained_in;
            	obtained += obtained_in;
            	inData.ignore();
            	inData >> possible_in;
            	possible += possible_in;
		inData.ignore();
		inData.clear();

            	if(inData.eof())
			break;
	     }

	    if(inData.peek() == '\n')
		   {inData.getline(dummy, ID_SIZE, '\n');}

            //Compute GPA and letter_grade
            compute_data(obtained, possible, letter_grade, gpa);

            //Convert gender to single char
            if(tolower(gender_buff[0]) == 'f')
                {gender = "F";}
            else if(tolower(gender_buff[0]) == 'm')
                {gender = "M";}
            else if(tolower(gender_buff[0]) != 'm' || 'f')
                {gender = "N/A";}

            //Create a new college_person object
            college_person temp_student(name, age, gender, university, college, id, letter_grade, gpa);

            //Insert new college_person object into dynamic array
            all_student.insert(temp_student);
        }
    }//End function

    void separate_Bag(Bag &orig_Bag, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag)
    {
        size_t index = 0;
        while(index < orig_Bag.Used())
        {
            if(orig_Bag[index].University() == "Metro State")
            {
                Metro_Bag.insert(orig_Bag[index]);
            }
            else if(orig_Bag[index].University() == "UCD")
            {
                UCD_Bag.insert(orig_Bag[index]);
            }
            else if(orig_Bag[index].University() != "UCD" || "Metro State")        //This is the default in the case there is a school besides UCD or Metro State
            {
                Other_Bag.insert(orig_Bag[index]);
            }
            index++;
        }
    }

    void write_data(std::ofstream &outData, Bag &Metro_Bag, Bag &UCD_Bag, Bag &Other_Bag)
    {
        //count vars
        size_t index_UCD = 0;
        size_t index_Metro = 0;
        size_t index_Other = 0;

        //formatted output
        outData << "UCD" << std::endl << std::left << std::setw(17) << "Name" << std::setw(5) << "Age" <<  std::setw(9) << "Gender" << std::setw(10) << "ID" << std::setw(17) << "College" << std::setw(8) << "GPA" << std::setw(5) << "Grade" << std::endl;
        while(index_UCD < UCD_Bag.Used())
        {
            outData << std::setprecision(3) << std::left << std::setw(17) << UCD_Bag[index_UCD].Name() << std::setw(5) << UCD_Bag[index_UCD].Age() << std::setw(9) << UCD_Bag[index_UCD].Gender() << std::setw(10) << UCD_Bag[index_UCD].Id() << std::setw(17) << UCD_Bag[index_UCD].College() << std::setw(8) << UCD_Bag[index_UCD].GPA() << std::setw(5) << UCD_Bag[index_UCD].Letter_Grade() << std::endl;
            index_UCD++;
        }
        outData << std::endl;
        outData << "METRO STATE" << std::endl << std::left << std::setw(17) << "Name" << std::setw(5) << "Age" <<  std::setw(9) << "Gender" << std::setw(10) << "ID" << std::setw(17) << "College" << std::setw(8) << "GPA" << std::setw(5) << "Grade" << std::endl;
        while(index_Metro < Metro_Bag.Used())
        {
            outData << std::setprecision(3) << std::left << std::setw(17) << Metro_Bag[index_Metro].Name() << std::setw(5) << Metro_Bag[index_Metro].Age() << std::setw(9) << Metro_Bag[index_Metro].Gender() << std::setw(10) << Metro_Bag[index_Metro].Id() << std::setw(17) << Metro_Bag[index_Metro].College() << std::setw(8) << Metro_Bag[index_Metro].GPA() << std::setw(5) << Metro_Bag[index_Metro].Letter_Grade() << std::endl;
            index_Metro++;
        }
        outData << std::endl;
        outData << "UNIDENTIFIED UNIVERSITY" << std::endl << std::left << std::setw(17) << "Name" << std::setw(5) << "Age" <<  std::setw(9) << "Gender" << std::setw(10) << "ID" << std::setw(17) << "College" << std::setw(8) << "GPA" << std::setw(5) << "Grade" << std::endl;
        while(index_Other < Other_Bag.Used())
        {
            outData << std::setprecision(3) << std::left << std::setw(17) << Other_Bag[index_Other].Name() << std::setw(5) << Other_Bag[index_Other].Age() << std::setw(9) << Other_Bag[index_Other].Gender() << std::setw(10) << Other_Bag[index_Other].Id() << std::setw(17) << Other_Bag[index_Other].College() << std::setw(8) << Other_Bag[index_Other].GPA() << std::setw(5) << Other_Bag[index_Other].Letter_Grade() << std::endl;
            index_Other++;
        }

    }//End function
}
