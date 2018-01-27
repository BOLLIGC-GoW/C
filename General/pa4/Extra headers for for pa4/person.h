/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*	This file gives the declarations person class that
        will be used within the pa4 program.
_____________________________
    person class (base class)

        private members:

            name : string
            age : int
            gender : string

        member functions:

            person(char in_name[], int in_age, std::string in_gender) : constructor

                pre-condition: none

                post-condition: the member vars will be initialized with the values
                passed to the function

            person() : default constructor

                pre-condition: none

                post-condition: the member vars will be initialized with
                pre-set values

            Name() const : string

                pre-condition: none

                post-condition: the value stored in name shall be returned from the function

            Age() const : string

                pre-condition: none

                post-condition: the value stored in age shall be returned from the function

            Gender() const : string

                pre-condition: none

                post-condition: the value stored in gender shall be returned from the function

            mod_Name(char []) : void

                pre-condition: a char [] array is passed to the function

                post-condition: the value stored in name shall be modified to the input value

            mod_Age(int) : void

                pre-condition: an int is passed to the function

                post-condition: the value stored in age shall be modified to the input value

            mod_Gender(char []) : void

                pre-condition: a char [] array is passed to the function

                post-condition: the value stored in gender shall be modified to the input value

_______________________
	Value Semantics

        person : The = operator and copy function are allowed, but unused
        as this is a base class and no objects shall be declared of this class



*/

#ifndef PERSON_CHARBO
#define PERSON_CHARBO
#include <cstdlib>
#include <string>


namespace pa4_charbo
{
//Base Class
    class person
    {
        private:

            std::string name;
            int age;
            std::string gender;

        public:

            //Constructor
            person(char in_name[], int in_age, std::string in_gender);
            person();

            //Accessors
            std::string Name() const;
            int Age() const;
            std::string Gender() const;

            //Mutators
            void mod_Name(char in_name[]);
            void mod_Age(int in_age);
            void mod_Gender(char in_gender[]);
    };


}//End namespace

#endif // PERSON_CHARBO
