#include "C.h"

#include <iostream>

using namespace std;

int main()
{
	A* var1 = new C;
	( var1)->print();
	A* var2 = new B;
	( var2)->print();
	
	C* VAR3 = dynamic_cast<C*>(var1);
	if (VAR3!=nullptr)
	{
		VAR3->print();

	}
	return 0;
}