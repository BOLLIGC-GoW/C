/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 3
*/

/*		This file defines the piglatin class

		Data Members:
			
			eng_string: char array
			pig_string: char_array

		Global Vars:
		
			STRING_SIZE: 	the maximum size of the char_array
			VOWEL_SIZE: 	the chars to be tested to satisfy 
					pig-latin conversion


		Member functions:

            piglatin(char*): (custom constructor) - char

                	Pre-Condition:	a char* array is passed to the function

                	Post-Condition:	The eng_string member var is initialized to 
					the c-string stored in the char * array

            get_eng: -char*

                	Pre-Condition:	none

                	Post-Condition:	The eng_string member var returned

            get_pig: -char*

                	Pre-Condition:	none

                	Post-Condition:	The pig_string member var returned

            coverter: -void

                	Pre-Condition:	none

                	Post-Condition:	The eng_string member var is converted
					to the pig_string member var using the
					rules of converting from English to 
					Pig-Latin; i.e. find first vowel, truncate 
					before vowel and add -ay, then add truncation to 
					end of word
					ex: christmas -> istmas-chray

		Member friends:

            << operator: -&ostream

                	Pre-Condition:	an object of type piglatin is passed to the operator

                	Post-Condition:	The operator will display both the eng_string
					and pig_string along with identifying strings


*/

#ifndef PIGLATIN_CHARBO
#define PIGLATIN_CHARBO
#include <iostream>

const unsigned int STRING_SIZE = 30;
const unsigned int VOWEL_SIZE = 13;


namespace piglatin_charbo
{
    class piglatin
    {

	    friend std::ostream& operator <<(std::ostream &, const piglatin &);

        private:

            char eng_string[STRING_SIZE];
            char pig_string[STRING_SIZE];

        public:

            piglatin(char *);

            char* get_eng();
            char* get_pig();
	    void converter();



    };//End class


}//End namespace

#endif