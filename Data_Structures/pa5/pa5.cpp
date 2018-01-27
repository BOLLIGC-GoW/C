/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 5
*/

/*	
		This file implements the begin() and end() member functions for the
		bag4 class

		*I'm putting the Pre-Post Conditions Here Because A Header File is 
		Not Part of the Assignment*

		begin: bag<Item>* 

			Pre-Condition: 	The array of bag4 can/can not be empty.
					If the array is empty, the data* pointer SHOULD be initialized 
					to NULL. 
					
	
			Post Condition:	A (random_access_iterator) bag_iterator pointing to the first element of the dynamic bag array
					is returned from the function. If data* pointer is NULL,
					the iterator will point to NULL.

		end: bag<Item>* 

			Pre-Condition: 	The array of bag4 can/can not be empty.
					If the array is empty, the data* pointer SHOULD be initialized 
					to NULL.
	
			Post Condition:	A (random_access_iterator) bag_iterator pointing to the last element of the dynamic bag array
					is returned from the function. If data* pointer is NULL,
					the iterator will point to NULL
*/


template <typename Item>
bag_iterator bag<Item>::begin()
{
    //Error checking
    if(size() == 0)
	assert(data == NULL);

    //Declare Pointer
    Item *Ptr = NULL;

    //Set the Pointer equal to the memory address of
    //the entry
    Ptr = data;

    //Return a random_access_iterator using the pointer as its argument to the constructor
    return bag_iterator(Ptr);
}

template <typename Item>
bag_iterator iterator bag<Item>::end()
{
    //Error checking
    if(size() == 0)
	assert(data == NULL);

    //Declare Pointer
    Item *Ptr = NULL;

    //Set the Pointer equal to the memory address of
    //the entry
    Ptr = data;
    Ptr += used;

    //Return a random_access_iterator using the pointer as its argument to the constructor
    return bag_iterator(Ptr);
}
