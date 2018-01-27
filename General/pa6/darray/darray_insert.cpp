//#include <cstdlib>
#if _DEBUG
#include <iostream>
#endif
#include "darray.h"
#include <cstdlib>

#if _DEBUG
using std::cout;
using std::endl;
#endif

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
