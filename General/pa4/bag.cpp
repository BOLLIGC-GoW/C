/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 4
*/

/*		This file gives the implementation of the bag class
        that will be used within the pa4 program.
*/
#include "college_person.h"
#include<algorithm>
#include<cassert>
#include <iostream>

namespace pa4_charbo
{
    Bag::Bag(size_type initial_capacity)
    {
        data = new college_person [initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }//End Bag constructor

    Bag::~Bag()
    {
        delete [] data;
    }//End Bag destructor

    unsigned int Bag::Used() const
    {
        return used;
    }

    unsigned int Bag::Capacity() const
    {
        return capacity;
    }

    void Bag::update_Used(size_type count)
    {
        used = count;
    }

    void Bag::reserve(size_type new_capacity)
    {
        if(new_capacity == capacity)
            return;
        if(new_capacity < used)
            new_capacity = used;

        college_person *larger_array = new college_person[new_capacity];
        std::copy(data, data + used, larger_array);
        delete [] data;
        data = larger_array;
        capacity = new_capacity;

    }

    void Bag::insert(const college_person& entry)
    {
        if(used == capacity)
            reserve(used + 1);
        data[used] = entry;
        used++;
    }

    college_person Bag::operator[](size_type index)
    {
        assert(index <= used);
        return data[index];
    }
}//End namespace
