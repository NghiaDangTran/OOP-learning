#include "Counter.h"

#include <iostream>
using namespace std;

int main() 
{
	//Good practice is to call static methods on the class name
	Counter::setCount(12);
	cout << "Count is: ";
	Counter::printCount();
	
	Counter::printConstants();
	
	cout << endl;
	
	//Technically, you can also call them on an instance, but it's not recommended -->
	//Calling from the class name makes it obvious that it's a static member!
	Counter c;  //Stack-based
	c.setCount(24);
	c.printCount();
	
	Counter* c2 = new Counter;  //heap-based
	c2->setCount(36);
	c2->printCount();
	
	cout << endl;
	
	Counter::printCount();

	cout << endl << "End of processing\n";
  
	return 0;
}