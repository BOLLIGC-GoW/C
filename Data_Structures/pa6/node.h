/*	Jason Lewis
 *	CSCI 2421 - Spring 2015
 *	Homework/Programming Assignment 6
 *	Node Class
 */

 /*
  * node
  *		Pre-Condition:	iPayload is either a question or a result of the taxonomy tree
  *						iLeft is either null or a link to the "yes" answer
  *						iRight is either null or a link to the "no" answer
  *		Post-Condition:	none
  * setPayload
  * 	Pre-Condition:	iPayload is either a question or a result of the taxonomy tree
  *		Post-Condition:	none
  *	setLeftLink
  * 	Pre-Condition:	input is either null or link to the "yes" answer
  *		Post-Condition:	none
  *	setRightLink
  * 	Pre-Condition:	input is either null or link to the "no" answer
  *		Post-Condition:	none
  *	getPayLoad
  * 	Pre-Condition:	none
  *		Post-Condition:	none
  *	getLeftLink
  * 	Pre-Condition:	none
  *		Post-Condition:	none
  *	getRightLink	
  * 	Pre-Condition:	none
  *		Post-Condition:	none
  */
#ifndef lewis_ucd_hw_pa6_h
#define lewis_ucd_hw_pa6_h
#include <string>
 namespace lewis_ucd_hw_pa6
 {
	class node
	{
		private:
			std::string payload;		// Holds either a question or a result
			node * right;		// Link to the right node
			node * left;		// Link to the left node
			bool isLeaf;		// flag to indicate if the node is a link or not
		public:
			node(std::string iPayload, node* iLeft, node* iRight)
			{
				payload = iPayload;
				left = iLeft;
				right = iRight;
			}// End constructor

			void setPayload(std::string input)
			{
				payload = input;
			}// End setPayload

			void setRightLink(node * input)
			{
				right = input;
			}// End setRightLink

			void setIsLeaf(bool input)
			{
				isLeaf = input;
			}

			void setLeftLink(node * input)
			{
				left = input;
			}// End setLeftLink
			
			std::string getPayload()
			{
				return payload;
			}// End getPayload

			node * getLeftLink()
			{
				return left;
			}// End getLeftLink

			node * getRightLink()
			{
				return right;
			}

			bool getIsLeaf()
			{
				return isLeaf;
			}

	}; // End Node Class
 } // End Namespace
#endif