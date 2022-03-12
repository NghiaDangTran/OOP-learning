#include "Counter.h"

#include <iostream>
using namespace std;


int Counter::count=0; //initializing the static variable inside the cpp file (necessary!)

//Doing the same for class constants:
const int Counter::DAYS_IN_WEEK = 7;  //class constant
const float Counter::TAX_RATE = 12.5; //another class constant

void Counter::setCount(int i) 
{ 
	count=i; 
}

void Counter::printCount() 
{ 
	cout << count << " " << endl; 
}

void Counter::printConstants()
{
	cout << "Days in a week: " << DAYS_IN_WEEK << endl;
	cout << "Tax rate: " << TAX_RATE << "%" << endl;
}


