#pragma once

#include "Sub.h"

class SubSub : public Sub
{
	private:
		int subSubInt;
		
	public:
		//Constructors
		SubSub(int, int, int);
		
		//Instance methods
		void print() override;
};