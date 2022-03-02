#pragma once

#include "Node.h"

class Node;  //forward reference

class GenericList : public ListItem
{
	private:
		Node* first;
		
	public:
		//Constructors
		GenericList();
		
		//Instance methods
		void addFront(ListItem*);
		void print() override;
};