#pragma once

#include "ListItem.h"

class CharAtom : public ListItem
{
	private:
		char data;
		
	public:
		//Constructors
		CharAtom();
		CharAtom(char);
		
		//Instance methods
		void print() override;
};