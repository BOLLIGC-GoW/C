#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H

#include <cstdlib>

namespace main_savitch_3
{

class sequence
{
	public:

		typedef double value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;

		sequence();

		size_type size() const;
		bool is_item() const;
		value_type current() const;

		value_type& operator[](size_type);


	private:
		
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;

};//End class

}//End namespace


#endif