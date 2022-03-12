#include "Sub.h"

#include <iostream>
using namespace std;

//Constructors
Sub::Sub(int baseI, int subI) : Base(baseI), subInt(subI) {}  //calling the super constructor (Base) in the initializer

//Instance methods
void Sub::print()
{
	//This is refinement!
	Base::print();
	cout << "subInt = " << subInt << endl;
}