#include "GenericList.h"

#include "Node.h"

#include <iostream>
using namespace std;

//Constructors
GenericList::GenericList() : first(nullptr) {}

//Instance methods
void GenericList::addFront(ListItem* li)
{
	Node* newNode = new Node(li, first);
	first = newNode;
}


void GenericList::print()
{
	Node* current = first;
	
	cout << "<< ";
	
	while (current != nullptr)
	{
		current->print();
		current = current->getNext();
	}
	
	cout << ">> ";
}