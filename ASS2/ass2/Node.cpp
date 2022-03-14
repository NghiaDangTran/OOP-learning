#pragma once
#include "menu.cpp"

class Node
{
private:
	menu food_ordered;
	int addedIngredient;
	Node *next;
	static int id;
	int node_id;


public:
	// Constructors
	Node(menu, int, Node *);

	// Instance methods
	Node *getNext();
	void setNext(Node *);
	void print();
	int getId();
	menu getFood();
	int getAddedIngredient();
	float getPrice();
};

Node::Node(menu food_ordered, int addedIngredient, Node *next) : food_ordered(food_ordered), addedIngredient(addedIngredient), next(next) , node_id(id++)
{
	
}

	
Node *Node::getNext()
{
	return next;
}
float Node::getPrice()
{
	return food_ordered.getPrice() + addedIngredient;
}
menu Node::getFood()
{
	return food_ordered;
}

int Node::getAddedIngredient()
{
	return addedIngredient;
}


int Node::id = 1;

Node *Node::getNext()
{
	return next;
}
void Node::setNext(Node *next)
{
	this->next = next;
}
int Node::getId()
{
	return node_id;
}

void Node::print()
{
	cout << "Food Name: " << food_ordered.getFoodName() << endl;
	cout << "Prep Time: " << food_ordered.getPrepTime() << endl;
	cout << "Price: " << food_ordered.getPrice() << endl;
	cout << "ID " << node_id << endl;
	cout << "Added Ingredient: " << addedIngredient << endl;
	cout << "Total Price: " << food_ordered.getPrice() + addedIngredient << endl;
}


// int main()
// {
//    Node *head = new Node(menu("pizza", 10, 10), 10, NULL);
//    Node *next= new Node(menu("burger", 10, 10), 10, NULL);
//    head->setNext(next);

//    head->print();
//    head=head->getNext();
//    head->print();
// }
