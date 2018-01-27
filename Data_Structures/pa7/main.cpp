/*	Charles Bollig
 *	CSCI 2421 - Spring 2015
 *	Homework/Programming Assignment 7
 *	
 */

/* 	This is the driver file to test the sortSelection
	function
*/

#include <cstdio>
#include <iostream>

template<typename Item>
void selectionSort(Item array[], std::size_t size)
{
	Item temp;
	std::size_t sorted, smallest;
	smallest = 0;
	sorted = 0;
	
	while(sorted < size)
	{
		for(size_t current = 0; current < size; current++)
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

int main()
{
	int arr[5] = {2,5,6,1,9};
	selectionSort(arr, 5);

	for(int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		std::cout << arr[i];
	}
	std::cout << std::endl;
	return 0;
}