/*	Charles Bollig
 *	CSCI 2421 - Spring 2015
 *	Programming Assignment 7
 *	
 */

/*
	The file is the definition of the selectionSort function
	
	
	selectionSort( Item [] , size_t ) : void

	pre-condition:	An array and size of the array are passed to the 
			function

	post-condition: An array of <Item> data type will be sorted
			from smallest -> largest
		
*/

#include <cstdio>

template<typename Item>
void selectionSort(Item array[], size_t size)
{
	Item temp;
	std::size_t sorted, smallest;
	smallest = 0;
	sorted = 0;
	
	while(sorted < size)
	{
		for(size_t current = 0; current < sorted; current++)
		{
			if(array[current] < array[smallest])
			{
				smallest = current;
			}
			array[sorted] = array[smallest];
			temp = array[smallest];
			array[sorted] = array[smallest];
			array[smallest] = temp;
		}		
		
	sorted++;
	}
	
}