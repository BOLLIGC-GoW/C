#include <cstdlib>
#if _DEBUG
#include <iostream>
#endif
//#include "darray.h"
#include <cstdlib>

#if _DEBUG
using std::cout;
using std::endl;
#endif

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
