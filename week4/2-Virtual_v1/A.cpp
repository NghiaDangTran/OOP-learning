#include "A.h"

#include <iostream>

using namespace std;

A::A() : number(1) {}

void A::print()
{
	cout << "In class A, and number = " << number << endl;
}