/*	Charles Bollig
 *	CSCI 2421 - Spring 2015
 *	Homework/Programming Assignment 6
 *	taxonomyTree Class
 */

/*	This file impements the taxonomyTree class
*/

#include "node.h"
#include "taxonomyTree.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <new>

using namespace lewis_ucd_hw_pa6;

namespace taxonomyTree_charbo
{
    taxonomyTree::taxonomyTree()
    {
	current_node = NULL;
	construct_Tree();
    }

    void taxonomyTree::construct_Tree()
    {

	//Non-Extinct Animals Branch

	
	try
	{
	//leaf1

		node* leaf1 = new node("A Dog", NULL, NULL);
		leaf1->setIsLeaf(true);

	//leaf2

		lewis_ucd_hw_pa6::node* leaf2= new node("A Cat", NULL, NULL);
		leaf2->setIsLeaf(true);

	//node1 for leaf1 and leaf2

		lewis_ucd_hw_pa6::node* node1= new node("Do you like your owner?", leaf1, leaf2);
		node1->setIsLeaf(false);

	//leaf3

		lewis_ucd_hw_pa6::node* leaf3= new node("A Liar!!!", NULL, NULL);
		leaf3->setIsLeaf(true);

	//leaf4

		lewis_ucd_hw_pa6::node* leaf4= new node("Probably a Human considering you can read this.", NULL, NULL);
		leaf4->setIsLeaf(true);


	//node2 for leaf3 and leaf4

		lewis_ucd_hw_pa6::node* node2= new node("Can you beat Chuck Norris in a brawl?", leaf3, leaf4);
		node2->setIsLeaf(false);

	//node2 for node1 and node2

		lewis_ucd_hw_pa6::node* node5= new node("Are you a household pet?", node1, node2);
		node5->setIsLeaf(false);

	//leaf5

		lewis_ucd_hw_pa6::node* leaf5= new node("A Lobster/Crab/Tentacled Monstrosity!", NULL, NULL);
		leaf5->setIsLeaf(true);

	//leaf6

		lewis_ucd_hw_pa6::node* leaf6= new node("A Fish or Shellfish; and, therefore, edible.", NULL, NULL);
		leaf6->setIsLeaf(true);


	//node3 for leaf5 and leaf6

		lewis_ucd_hw_pa6::node* node3= new node("Do you have legs?", leaf5, leaf6);
		node3->setIsLeaf(false);

	//leaf7

		lewis_ucd_hw_pa6::node* leaf7= new node("An Insect of some sort. Gross.", NULL, NULL);
		leaf7->setIsLeaf(true);

	//leaf8

		lewis_ucd_hw_pa6::node* leaf8= new node("A Colony of Bacteria that was manufactured with the sole intention of"
					" wiping out humanity!! Or, you're just a snake. Whatever....", NULL, NULL);
		leaf8->setIsLeaf(true);

	//node4 for leaf7 and leaf8

		lewis_ucd_hw_pa6::node* node4= new node("Do you have legs?", leaf7, leaf8);
		node4->setIsLeaf(false);

	//node6 for node3 and node4

		lewis_ucd_hw_pa6::node* node6= new node("Do you exist in the water?", node3, node4);
		node6->setIsLeaf(false);
	
	//node7 for node5 and node6

		lewis_ucd_hw_pa6::node* node7= new node("Are you a mammal?", node5, node6);
		node7->setIsLeaf(false);
	
	//Extinct Animals Branch


	//leafA

		lewis_ucd_hw_pa6::node* leafA = new node("A Sabre-Tooth Tiger", NULL, NULL);
		leafA->setIsLeaf(true);

	//leafB

		lewis_ucd_hw_pa6::node* leafB= new node("A Dire Wolf", NULL, NULL);
		leafB->setIsLeaf(true);

	//nodeA for leafA and leafB

		lewis_ucd_hw_pa6::node* nodeA= new node("Do you have overly large canine teeth?", leafA, leafB);
		nodeA->setIsLeaf(false);

	//leafC

		lewis_ucd_hw_pa6::node* leafC= new node("A Giant Sloth", NULL, NULL);
		leafC->setIsLeaf(true);

	//leafD

		lewis_ucd_hw_pa6::node* leafD= new node("A Woolly Rhino", NULL, NULL);
		leafD->setIsLeaf(true);

	//nodeB for leafC and leafD

		lewis_ucd_hw_pa6::node* nodeB= new node("Are you a 'giant?'", leafC, leafD);
		nodeB->setIsLeaf(false);

	//nodeE for nodeA and nodeB

		lewis_ucd_hw_pa6::node* nodeE= new node("Are you a carnivore?", nodeA, nodeB);
		nodeE->setIsLeaf(false);

	//leafE

		lewis_ucd_hw_pa6::node* leafE= new node("A T-Rex", NULL, NULL);
		leafE->setIsLeaf(true);

	//leafF

		lewis_ucd_hw_pa6::node* leafF= new node("A Velociraptor", NULL, NULL);
		leafF->setIsLeaf(true);

	//nodeC for leafE and leafF

		lewis_ucd_hw_pa6::node* nodeC= new node("Do you have little, useless arms?", leafE, leafF);
		nodeC->setIsLeaf(false);

	//leafG

		lewis_ucd_hw_pa6::node* leafG= new node("A Brachiosaurus", NULL, NULL);
		leafG->setIsLeaf(true);

	//leafH

		lewis_ucd_hw_pa6::node* leafH= new node("A Triceratops", NULL, NULL);
		leafH->setIsLeaf(true);

	//nodeD for leafG and leafH

		lewis_ucd_hw_pa6::node* nodeD= new node("Do you have a long neck?", leafG, leafH);
		nodeD->setIsLeaf(false);

	//nodeF for nodeC and nodeD

		lewis_ucd_hw_pa6::node* nodeF= new node("Are you a carnivore?", nodeC, nodeD);
		nodeF->setIsLeaf(false);
	
	//nodeG for nodeE and nodeF

		lewis_ucd_hw_pa6::node* nodeG= new node("Are you a mammal?", nodeE, nodeF);
		nodeG->setIsLeaf(false);

	//Top node for node7 and node G
		lewis_ucd_hw_pa6::node* top= new node("Are you or have you ever been extinct?", nodeG, node7);
		top->setIsLeaf(false);

		current_node= top;

	}
	catch(std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
	}

    }//End function


    void taxonomyTree::traverse_Tree()
    {
	while(!current_node->getIsLeaf())
	{
		//Temp vars
		char input;
		std::string dummy;

		if(!current_node->getIsLeaf())
			std::cout << current_node->getPayload() << " Enter [Y] or [N]." << std::endl;
		
		//Read user input
		std::cin >> input;
		std::getline(std::cin, dummy);
		
		if(tolower(input) == 'y')
			current_node = current_node->getLeftLink();
		else if(tolower(input) == 'n')
			current_node = current_node->getRightLink();

		if(current_node->getIsLeaf())
			{std::cout <<  std::endl << "You are " << current_node->getPayload() << std::endl << std::endl;
			exit;}


	}//End whileloop

    }//End function
    


}//End namespace
