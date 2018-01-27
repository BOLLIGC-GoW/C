#include <cstdlib>
#if _DEBUG
#include <iostream>
#endif
//#include "darray.h"
#include <cassert>

#if _DEBUG
using std::cout;
using std::endl;
#endif

const size_t INITIAL_SIZE = 1;

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
