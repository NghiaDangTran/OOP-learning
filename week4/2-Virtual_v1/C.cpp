#include "C.h"

#include <iostream>

using namespace std;

C::C()
{
	number = 3;
}

void C::print()
{
	cout << "In class C, and number = " << number << endl;
}