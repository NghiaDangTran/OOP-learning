#include "MyNumber.h"
#include <iostream>

using namespace std;

//Constructors:
MyNumber::MyNumber() : value(0) {}
MyNumber::MyNumber(int i) : value(i) {}
		
//Instance variables:
void MyNumber::increment()
{
	value++;
}

void MyNumber::decrement()
{
	value--;
}

void MyNumber::print()
{
	cout << "Value = " << value << endl;
}

