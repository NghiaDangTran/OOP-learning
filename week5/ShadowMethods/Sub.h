#pragma once

#include "Base.h"

class Sub : public Base
{
	private:
		int subInt;
		
	public:
		//Constructors
		Sub(int, int);
		
		//Instance methods
		void print() override;
};