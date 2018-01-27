/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 6
*/

/*		This file defines the provided DynamicArray class
		as a templatized class with templatized functions

__________________________
	DynamicArray Class <template ITEM>

	private:
		
		a : ITEM
		size: size_t
		n: size_t
	
		Expand() : void

			pre-condition: none

			post-condition:	the array's capacity will be doubled
					and all of the current data will be copied
					to the larger array	
		
		Compress: void	
		
			pre-condition: none

			post-condition:	the array's capacity will be halved
					and all of the current data will be copied
					to the smaller array

	public:

		DynamicArray : (default constructor)

			pre-condition: none

			post-condition:	the member variables are initialized to
			size being the INITIAL_SIZE
			n = 0
			a creating a dynamically allocated array of [size] elements

		GetSize : size_t

			pre-condition: none

			post-condition:	the size of the array is returned 
					from the function

		GetElements : size_t

			pre-condition: none

			post-condition:	the current number of used elements is
					returned from the function

		operator[size_t] : ITEM

			pre-condition: an index that is < than the current n and 
					size of the array is passed to the operator

			post-condition:	the current value of the element number passed
					into the function is returned by the operator


		Print : void

			pre-condition: none

			post-condition:	the array up to n is printed to the screen with size and 
					n

		Insert(ITEM) : void

			pre-condition: a data value of type ITEM (template) is passed to the
					function

			post-condition:	an element of type ITEM is added to the end of the
					array

		Remove(size_t) : void

			pre-condition: an index that is < than the current n and 
					size of the array is passed to the function

			post-condition:	an element of type ITEM is added to the end of the
					array

		Sort: void

			pre-condition: none

			post-condition:	none

	Invariance:
		
		size - represents the current array size (can change)
		a - a pointer to a dynamically allocated array
		n - the current used elements of the array

	Value Semantics:

		The copy constructor and = operator may not be used with this class
		as the class uses pointers as private data

*/

#ifndef __DYNAMIC_ARRAY
#define __DYNAMIC_ARRAY
#include <iostream>
#include <iomanip>

#include <cstdlib>
#if _DEBUG
#include <iostream>
#endif
#include <cassert>

#if _DEBUG
using std::cout;
using std::endl;
#endif


using std::cout;
using std::endl;

const size_t INITIAL_SIZE = 1;

//Template Class

template<typename ITEM>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();

	// Return the current capacity
	size_t GetSize();

	// Return the current number of elements
	size_t GetElements();

	// Overloaded index operator
	ITEM & operator [] (std::size_t x);

	// Dump the contents of the darray to the screen
	void Print();

	// Insert an element
	void Insert(ITEM x);

	// Remove the ith element
	void Remove(std::size_t i);

	// Sort the elements
	void Sort();

private:
	ITEM *a;		// The allocated array
	std::size_t size;	// Current size of the allocated array
	std::size_t n;		// Current number of elements in the array

	// Double the capacity of the darray
	void Expand();

	// Cut the capacity of the darray in half
	void Compress();
};

//Template Class Member Functions

template <typename ITEM>
DynamicArray<ITEM>::DynamicArray()
{
	size = INITIAL_SIZE;
	n = 0;
	a = new ITEM(size);
}

template <typename ITEM>
DynamicArray<ITEM>::~DynamicArray()
{
	if (a != NULL) {
		delete [] a;
		a = NULL;
	}
	size = INITIAL_SIZE;
	n = 0;
}

template <typename ITEM>
ITEM & 
DynamicArray<ITEM>::operator[] (std::size_t x)
{
#if _DEBUG
	cout << endl << "precond: a[" << x << "]=" << a[x] << endl;
#endif
	assert(x < n && x < size);
	return a[x];
}

template<typename ITEM>
size_t
DynamicArray<ITEM>::GetElements()
{
	return n;
}

template<typename ITEM>
size_t
DynamicArray<ITEM>::GetSize()
{
	return size;
}

template<typename ITEM>
void
DynamicArray<ITEM>::Expand()
{
	ITEM *a = NULL;
	std::size_t i, size;

	// Allocate a new array that is twice as large as before
	size = this->size << 1;
	a = new ITEM[size];
	if (a == NULL) {
		#if _DEBUG
			cout << endl << "Error allocating memory to expand dynamic array" << endl;
		#endif
		delete [] a;
		return;
	}
	// Record increased capacity
	this->size = size;

	// Copy the contents of the old array into the new array
	for (i = 0; i < this->n; i++)
		a[i] = this->a[i];

	// Free old array replace it with the new array
	delete this->a;
	this->a = a;
}

template<typename ITEM>
void
DynamicArray<ITEM>::Insert(ITEM x)
{
#if _DEBUG
	cout << endl << "Insert " << x << endl;
#endif
	// Insert element
	this->a[n++] = x;

	// Check whether capacity needs to be expanded
	if (n == size)
		this->Expand();
}

template<typename ITEM>
void
DynamicArray<ITEM>::Print()
{
	std::size_t i;

	cout << "size=" << size;
	cout << "  n=" << n;
	if (n == 0) {
		cout << endl;
		return;
	}
	cout << "  [";

	for (i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1)
			cout << ",";
	}
	cout << "]" << endl;
}

template<typename ITEM>
void
DynamicArray<ITEM>::Compress()
{
	ITEM *a;
	std::size_t i, size;

	if (this->size == 1)
		return;

	// Allocate a new array that is half as large as before
        size = this->size >> 1;
        a = new int[size];
        if (a == NULL) {
		#if _DEBUG
			cout << endl << "Error allocating memory to expand dynamic array" << endl;
		#endif
		delete [] a;
		return;
	}
        // Record decreased capacity
	this->size = size;

	// Copy the contents of the old array into the new array
	for (i = 0; i < this->n; i++)
		a[i] = this->a[i];

	// Free old array replace it with the new array
	delete this->a;
	this->a = a;
}

template<typename ITEM>
void
DynamicArray<ITEM>::Remove(std::size_t i)
{
	std::size_t j;

#if _DEBUG
	cout << endl << "Remove a[" << i << "]=" << a[i] << endl;
#endif

	// Range check
	if (i < 0 || i >= n)
		return;

	// Shift the remaining elements down to cover the spot left
	// by the removal
	for (j = i + 1; j < n; j++)
		a[j - 1] = a[j];

	// Reduce the number of elements
	(this->n)--;

	// Check for compression
	if (this->n == (this->size) >> 1)
		this->Compress();
}

template<typename ITEM>
void
DynamicArray<ITEM>::Sort()
{
	return;
}


#endif
