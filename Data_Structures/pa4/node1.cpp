/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 4
*/

// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
	node *insert_ptr;

	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	const node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }
//////////////////////////////FUNCTION PA4/////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
    void split_list(const node::value_type splitting_value, node* Original_List, node* Less_List, node* More_List)
    {
        //assert that there is an actual list
        assert(Original_List != NULL);

        //Declare local pointers and assign them to the pointers brought in
        //through the parameter list
        node* Original_Ptr = Original_List;     //Initialize to *Original List
        node* Less_Ptr = Less_List;             //Initialize to *Less List (even if it is null)
        node* More_Ptr = More_List;             //Initialize to *More List (even if it is null)
	node* New_Ptr = NULL;			//This pointer holds dynamically allocated memory locations. It is needed to hold the location before setting the previous
						//    node's link_field to the new dynamically allocated node. It'll get tossed around a lot.


        while(Original_Ptr != NULL)
        {
            //Test if data_field member variable is less than splitting value
            //data() member function is called to return the value
            if(Original_Ptr->data() <= splitting_value)
            {
	       New_Ptr = new node;
               Less_Ptr->set_link(New_Ptr);
               Less_Ptr = Less_Ptr->link();
               Less_Ptr->set_data(Original_Ptr->data());
               Less_Ptr->set_link(NULL);
            }
            //If data field is greater than splitting value
            //data() member function is called to return the value
            else if(Original_Ptr->data() > splitting_value)
            {
	       New_Ptr = new node;
               More_Ptr->set_link(New_Ptr);
               More_List = Less_Ptr->link();
               More_Ptr->set_data(Original_Ptr->data());
               More_Ptr->set_link(NULL);
            }
            //This is the case that the Less_List has nothing in it yet, i.e. Less_List pointer pointing to null
            else if((Original_Ptr->data() <= splitting_value) && (Less_Ptr == NULL))
            {
               Less_List = new node;
               Less_Ptr->set_data(Original_Ptr->data());
               Less_Ptr->set_link(NULL);
            }
            //This is the case that the More_List has nothing in it yet, i.e. More List pointer points to null
            else if((Original_Ptr->data() > splitting_value) && (More_Ptr == NULL))
            {
               More_List = new node;
               More_Ptr->set_data(Original_Ptr->data());
               More_Ptr->set_link(NULL);
            }

            //This is crucial. The Original_Ptr will
            //be pointing at a node on the original list
            //In order to cycle through the list,
            //The address the node points to must be
            //reassigned to the next node
            //This is how we cycle through the original linked list.
            Original_Ptr = Original_Ptr->link();

        }//End loop


    }//End function

}

