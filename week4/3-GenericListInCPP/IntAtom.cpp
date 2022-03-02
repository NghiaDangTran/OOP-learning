#include "IntAtom.h"

#include <iostream>
using namespace std;

//Constructors
IntAtom::IntAtom() : data(0) {}
IntAtom::IntAtom(int i) : data(i) {}

//Instance methods
void IntAtom::print()
{
	cout << data << " ";
}