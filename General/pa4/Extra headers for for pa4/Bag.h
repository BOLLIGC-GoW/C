/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*	This file gives the declarations of the bag class
        that will be used within the pa4 program.

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

#ifndef BAG_CHARBO
#define BAG_CHARBO
#include <cstdlib>
#include <string>
#include "college_person.h"

namespace pa4_charbo
{

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

#endif // BAG_CHARBO