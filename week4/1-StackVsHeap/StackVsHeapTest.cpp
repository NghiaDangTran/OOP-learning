#include "MyNumber.h"
#include <iostream>

using namespace std;

int main()
{
	//Heap-based
	MyNumber* myVar1 = new MyNumber;
	myVar1->print();
	myVar1->decrement();
	myVar1->print();
	myVar1->decrement();
	(*myVar1).print();
	cout << endl;
	
	//Stack-based
	MyNumber myVar2;
	myVar2.increment();
	myVar2.print();
	myVar2.decrement();
	myVar2.print();
	
	cout << endl;
	
	MyNumber myVar3(55);
	myVar3.print();
	
	return 0;
}