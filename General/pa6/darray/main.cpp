/*		Charles Bollig
		CSCI 2312 - 001 Spr 15
		PA 6
*/

#include <iostream>
#include "darray.h"

using std::cout;
using std::endl;

int
main(int argc, char **argv)
{
	DynamicArray<int> a;

	std::cout << "Dynamic array<int>" << std::endl;
	a.Print();

	a.Insert(4);
	a.Print();

	a.Insert(3);
	a.Print();

	a.Insert(2);
	a.Print();

	a.Insert(1);
	a.Print();

	a.Insert(0);
	a.Print();

	cout << "3rd element = " << a[2] << endl;

	a[2] = 10;
	a.Print();

	a.Remove(1);
	a.Print();

	a.Remove(2);
	a.Print();

	a.Remove(1);
	a.Print();

	a.Remove(0);
	a.Print();

	a.Remove(0);
	a.Print();

	DynamicArray<double> b;

	std::cout << "Dynamic array<double>" << std::endl;
	a.Print();

	a.Insert(4.0);
	a.Print();

	a.Insert(3.0);
	a.Print();

	a.Insert(2.0);
	a.Print();

	a.Insert(1.0);
	a.Print();

	a.Insert(0);
	a.Print();

	cout << "3rd element = " << a[2] << endl;

	a[2] = 10.0;
	a.Print();

	a.Remove(1);
	a.Print();

	a.Remove(2);
	a.Print();

	a.Remove(1);
	a.Print();

	a.Remove(0);
	a.Print();

	a.Remove(0);
	a.Print();

}
