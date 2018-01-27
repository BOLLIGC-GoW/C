/*	Charles Bollig
 *	CSCI 2421 - Spring 2015
 *	Homework/Programming Assignment 6
 *	taxonomyTree Class
 */
/*

		This file declares the taxonomyTree class
_____________________________
    taxonomyTree class 

        private members:

            current_node * : a node pointer to the current node

        member functions:

            taxonomyTree() : constructor

                pre-condition: none

                post-condition: current_node member variable will, initially, be initialized to NULL.
				the constructor will call the member function construct_Tree().

            construct_Tree() : void

                pre-condition: none

                post-condition: This member function will create a binary tree that is hardcoded
				into the class using nodes from the node class that is defined
				in "node.h". All of the nodes are dynamically allocated.
				Dynamic allocation is tested within a try-catch block to check for
				bad_alloc flags. After the binary tree is created, the member variable
				current_node is assigned to the top tree.

            traverse_Tree()  : void

                pre-condition: none

                post-condition: This member function will traverse the tree by prompting the user
				to respond to a question that is contained within the payload member
				variable of each node. Depending on how the user answers (yes or no)
				the current_pointer will move to the right node or left node
				that the current node's pointer points towards. If the user reaches a 
				'leaf' node, the program will display what the user is and exit.

            Current_Node()  : node *

                pre-condition: none

                post-condition: This member function returns the member variable
				current_node

            Set_Current_Node( node* )  :  void

                pre-condition: a node pointer is passed to the function

                post-condition: This member function sets the member varialbe current_node
				to the position pointed to by the node pointer passed
				to the function

_______________________
	Value Semantics

        The = operator and copy function are not allowed as each node
	uses pointers. 

_______________________
	Invariance

	current_node is a pointer that will point to a node contained within the tree
*/



#ifndef TAXONOMYTREE_CHARBO
#define TAXONOMYTREE_CHARBO

#include "node.h"


namespace taxonomyTree_charbo
{
    class taxonomyTree
    {
	private:
		
		lewis_ucd_hw_pa6::node * current_node;

	public:
	
		taxonomyTree();

		void construct_Tree();

		void traverse_Tree();

		//accessor
		lewis_ucd_hw_pa6::node * Current_Node() {return current_node;}

		//mutator
		void Set_Current_Node(lewis_ucd_hw_pa6::node * setPtr) {current_node = setPtr;}

	
    };//End class


}//End namespace

#endif 