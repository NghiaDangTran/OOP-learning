#include "Base.h"

#include <iostream>
using namespace std;

//Constructors
Base::Base(int i) : baseInt(i) {} 

//Instance methods
void Base::print()
{
	cout << "baseInt = " << baseInt << endl;
}
