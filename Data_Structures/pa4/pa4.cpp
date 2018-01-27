/*		Charles Bollig
		CSCI 2421 - 001 Spr 15
		PA 4
*/

/*	
		This file implements the split_list function for the
		node class

		*I'm putting the Pre-Post Conditions Here Because A Header File is 
		Not Part of the Assignment*

		split_list: void 

			Pre-Condition: 	a value_type argument is passed to the function that represents the value that data must be greater or less than
					a pointer to the original list's first node is passed as an arugment. This pointer must not be pointing to NULL, or the program will terminate.
					a pointer to the less_than list's first node is passed as an arugment (it is okay if it is pointing to NULL)
					a pointer to the greater_than list's first node is passed as an arugment (it is okay if it is pointing to NULL)
	
			Post Condition:	The function divides the original nodes into two linked lists: 
					1) One contaning all the nodes that contain an item less than or equal to the splitting value
					2) And one containing all the other nodes
					If the original linked list had any repeated integers, they will be represented in the two split lists.
					The original linked list will be preserved, -NOT- destroyed.
*/

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
            //Test if data_field member variable is less than or equal to splitting value
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
