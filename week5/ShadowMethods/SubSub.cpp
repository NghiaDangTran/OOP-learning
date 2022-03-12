#include "SubSub.h"

#include <iostream>
using namespace std;

//Constructors
SubSub::SubSub(int baseI, int subI, int subSubI) : Sub(baseI, subI), subSubInt(subSubI) {}  //calling the super constructor in the initializer

//Instance methods
void SubSub::print()
{
	//This is refinement!
	Sub::print();
	cout << "subSubInt = " << subSubInt << endl;
}