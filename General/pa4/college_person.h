/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/
/*		This file gives the declarations of the person class, college_person class
		and Bag class that will be used within the pa4 program.
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


_______________________________________
    college_person class (derived class)

        private members:

            university : string
            college : string
            id : string
            letter_grade : string
            gpa : double

        member functions:

            college_person(char in_name[], int in_age, std::string in_gender, char in_university[], char in_college[], char in_id[], std::string in_letter_grade, double in_gpa) : constructor

                pre-condition: none

                post-condition: the member vars will be initialized with the values
                passed to the function

            college_person() : default constructor

                pre-condition: none

                post-condition: the member vars will be initialized with
                pre-set values

            University() const : string

                pre-condition: none

                post-condition: the value stored in university shall be returned from the function

            College() const : string

                pre-condition: none

                post-condition: the value stored in college shall be returned from the function

            Id() const : string

                pre-condition: none

                post-condition: the value stored in id shall be returned from the function

            Letter_Grade() const : string

                pre-condition: none

                post-condition: the value stored in letter_grade shall be returned from the function

            GPA() const : double

                pre-condition: none

                post-condition: the value stored in gpa shall be returned from the function

            mod_University(char []) : void

                pre-condition: a char [] array is passed to the function

                post-condition: the value stored in university shall be modified to the input value

            mod_College(int) : void

                pre-condition: an int is passed to the function


                post-condition: the value stored in college shall be modified to the input value

            mod_Id(char []) : void

                pre-condition: a char [] array is passed to the function

                post-condition: the value stored in id shall be modified to the input value

            mod_Letter_Grade(char []) : void

                pre-condition: a char [] array is passed to the function

                post-condition: the value stored in letter_grade shall be modified to the input value

            mod_Letter_Grade(double) : void

                pre-condition: a double value is passed to the function

                post-condition: the value stored in gpa shall be modified to the input value
____________________
    Value Semantics:

	college_person : The = operator and copy function are allowed

_____________________________
    Bag Class (dynamic array)

            static const STRING_SIZE : the max size for the larger char inputs
            static const ID_SIZE : the max size for the id char input

        private members:

            data : value_type (college_person)
            used : size_type (size_t)
            capacity : size_type (size_t)

        member functions:

            Bag(size_type initial_capacity = DEFAULT_CAPACITY) : default constructor argument

                pre-condition: none

                post-condition: The bag is set with a default capacity of 5 (Which can be changed in this .h file)

            Bag() : default constructor

                pre-condition: none

                post-condition: the member vars will be initialized with
                pre-set values

            ~Bag() : destructor

                pre-condition: none

                post-condition: the data that was dynamically allocated in the object
                will be deleted

            Used() : unsigned int

                pre-condition: none

                post-condition: the data that is stored in used will be returned

            Capacity() : unsigned int

                pre-condition: none

                post-condition: the data that is stored in capacity will be returned

            reserve(size_type) : void

                pre-condition: The size of the array +1 is passed to the function

                post-condition: This function checks the size of the dynamic array to insure that
                it can fit the amount of items that are stored. If not, more space is allocated.

            insert(const value_type (college_person)) : void

                pre-condition: a college_person object is passed to the function

                post-condition: This function will add the object the the current used location
                of the data array

        member operators:

            [](size_type index) : college_person

                pre-condition: the index location that is to be accessed is passed to the function

                post-condition: This function returns that object at the index's location

____________________
    Value Semantics:

        Bag : The = operator and copy function are not allowed as the bag
        uses pointers

*/

#ifndef COLLEGE_PERSON_CHARBO
#define COLLEGE_PERSON_CHARBO
#include <cstdlib>
#include <string>

namespace pa4_charbo
{
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

class college_person : public person
    {
        private:

            std::string university;
            std::string college;
            std::string id;
            std::string letter_grade;
            double gpa;

        public:

            //Constructor
            college_person(char in_name[], int in_age, std::string in_gender, char in_university[], char in_college[], char in_id[], std::string in_letter_grade, double in_gpa);
            college_person();

            //Accessors
            std::string University() const;
            std::string College() const;
            std::string Id() const;
            std::string Letter_Grade() const;
            double GPA() const;

            //Mutators
            void mod_University(char in_university[]);
            void mod_College(char in_college[]);
            void mod_Id(char in_id[]);
            void mod_Letter_Grade(char in_letter_grade[]);
            void mod_GPA(double in_gpa);
    	};

class Bag
    {
        public:

            typedef std::size_t size_type;
            typedef college_person value_type;
            static const size_type DEFAULT_CAPACITY = 5;

            Bag(size_type initial_capacity = DEFAULT_CAPACITY);
            ~Bag();

            //Accessor
            unsigned int Used() const;
            unsigned int Capacity() const;

            //Member functions
            void reserve(size_type new_capacity);
            void insert(const value_type& entry);

            //Mutator
            void update_Used(size_type count);

            //Member Operator
            college_person operator[](size_type index);

        private:

            value_type *data;
            size_type used;
            size_type capacity;

    };



}//End namespace

#endif // COLLEGE_PERSON_CHARBO
