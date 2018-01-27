/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 3
*/

/*		This file implements the piglatin class
*/

#include "piglatin.h"
#include <iostream>
#include <cstring>
#include <assert.h>


namespace piglatin_charbo
{

//////////////////////////////
/*    piglatin() Constructor Function (custom)

    in:     C-string of STRING_SIZE elements

    out:    none

*/
    piglatin::piglatin(char* in_string)
    {
        strncpy(eng_string, in_string, strlen(in_string)+1);

    }//End function

//////////////////////////////

//////////////////////////////
/*    get_eng() Function

    in:     none

    out:    eng_string array pointer

*/
    char* piglatin::get_eng() 
    {
        return eng_string;

    }//End function

//////////////////////////////

//////////////////////////////
/*    get_pig() Function

    in:     none

    out:    pig_string array pointer

*/
    char* piglatin::get_pig() 
    {
        return pig_string;

    }//End function

//////////////////////////////

//////////////////////////////
/*    << Overloaded Operator

    in:     object of class piglatin

    out:    c_string

*/
    std::ostream& operator<<(std::ostream& output, const piglatin& pig_obj)
    {
            //Display the c-string
            output << "English: " << pig_obj.eng_string << "  Pig_latin: " << pig_obj.pig_string;

            return output;

    }//End function

//////////////////////////////

//////////////////////////////
/*    converter() Function

    in:     none

    out:    none

*/
    void piglatin::converter() 
    {
        //Vowels
	char key[VOWEL_SIZE] = "aeiouyAEIOUY";

	//temp char arrays
	char temp[STRING_SIZE];			//This holds the first part of the word
	char temp2[STRING_SIZE];		//This holds the first part of the word

	char *charPtr;

	//counter
	unsigned int i = 0;
		
	//value to hold count to determine how many letters before vowel
	int count = 0;

	//Position Pointer in eng_string
	charPtr = strpbrk(eng_string, key);

	//Find count of first occurence of key, used for strncpy
	count = strcspn(eng_string, key);

	//If no vowels
	if(charPtr == NULL)
	{
		std::cout << "Warning: Standard English words must contain a vowel. This is a terrible word...\nNot Exiting, but.... c'mon..." << std::endl;
		strncpy(pig_string, eng_string, strlen(eng_string)+1);
		strcat(pig_string, "-way");
		return;
	}

	//If vowel begins word
	if(count == 0)
	{
		strncpy(pig_string, eng_string, strlen(eng_string)+1);
		strcat(pig_string, "-way");
		return;
	}

		
	for(i = 0; i < strlen(eng_string); i++)
	{
		temp[i] = *(charPtr + i);
	}	
	
//Format the pig_string from eng_string

	strcat(temp, "-");

	strncpy(temp2, eng_string, count);
	temp2[count] = '\0';

	strcat(temp2, "ay");

	strcat(temp, temp2);

	strcpy(pig_string, temp);

//End formatting for pig_string


    }//End function

//////////////////////////////



}//End namespace
