#include "CharAtom.h"

#include <iostream>
using namespace std;

//Constructors
CharAtom::CharAtom() : data('-') {}
CharAtom::CharAtom(char c) : data(c) {} 

//Instance methods
void CharAtom::print()
{
	cout << "*" << data << "* ";
}