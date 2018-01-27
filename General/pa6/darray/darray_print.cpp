#include <iostream>
//#include "darray.h"
#include <cstdlib>

using std::cout;
using std::endl;

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
