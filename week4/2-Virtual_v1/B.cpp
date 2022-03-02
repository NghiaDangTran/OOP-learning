#include "B.h"

#include <iostream>

using namespace std;

B::B()
{
	number = 2;
}

void B::print()
{
	cout << "In class B, and number = " << number << endl;
}