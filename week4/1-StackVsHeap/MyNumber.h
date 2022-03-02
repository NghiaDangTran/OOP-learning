#pragma once

class MyNumber
{
	private: 
		int value;
		
	public:
		//Constructors:
		MyNumber();
		MyNumber(int);
		
		//Instance methods:
		void increment();
		void decrement();
		void print();
};