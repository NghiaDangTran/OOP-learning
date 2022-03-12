#include "SubSub.h"

#include <iostream>
using namespace std;

int main()
{
	Base* b1 = new Sub(5, 55);
	b1->print();
	
	cout << endl;
	
	
	Base* b2 = new SubSub(7, 77, 777);
	b2->print();
	
	cout << endl;
	
    return 0;
	
	//Exercises:
	//1) Remove the virtual keyword from the print method of the Base class and see the effects.
	//2) Add the final keyword to methods and classes in the hierarchy and see the effects.
}
