#include "menu.cpp"
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this will make a node object
 */

// ==========================================================
// Node class
//
//
//
//
// PURPOSE: this is where I create the nbode
// and also
// ==========================================================
class Node
{
private:
	menu food_ordered;	 // name of the food
	int addedIngredient; // number of ingredient
	Node *next;			 // next node
	static int id;		 // id of the node
	int node_id;		 // id of the node
	int exprire_time;	 // time to expire

public:
	// Constructors
	Node(int exprire_time, menu, int, Node *);

	// Instance methods
	Node *getNext();
	void setNext(Node *);
	void print();
	int getId();
	menu getFood();
	int getAddedIngredient();
	double getPrice();
	int getTime();
	int getExprireTime();
	void setId(int);
	void staticInt();
};

// ==========================================================
// Node constructor
//
//
//
//
// PURPOSE: this will declare the node
// ==========================================================

Node::Node(int exprire_time, menu food_ordered, int addedIngredient, Node *next) : exprire_time(exprire_time), food_ordered(food_ordered), addedIngredient(addedIngredient), next(next), node_id(id++)
{
}
int Node::id = 1;

// ==========================================================
// Node staticInt
//
//
//
//
// PURPOSE: this will pruto force confirgure the static int
// ==========================================================
void Node::staticInt()
{
	id--;
}
// ==========================================================
// Node setId
//
//
//
//
// PURPOSE: this will set the id of the node
// ==========================================================
void Node::setId(int id)
{
	this->node_id = id;
}
// ==========================================================
// Node getExprireTime
//
//
//
//
// PURPOSE: this will get the exprir time of the node
// ==========================================================
int Node::getExprireTime()
{
	return exprire_time;
}

// ==========================================================
// Node getTime
//
//
//
//
// PURPOSE: this will get total time to do the order
// ==========================================================
int Node::getTime()
{
	return food_ordered.getPrepTime() + addedIngredient;
}

// ==========================================================
// Node getPrice
//
//
//
//
// PURPOSE: this will get the price of the food include the ingredient
// ==========================================================
double Node::getPrice()
{
	return food_ordered.getPrice() + addedIngredient;
}
// ==========================================================
// Node getFood
//
//
//
//
// PURPOSE: this will get the food of the node
// ==========================================================
menu Node::getFood()
{
	return food_ordered;
}

// ==========================================================
// Node getAddedIngredient
//
//
//
//
// PURPOSE: this will get the number of ingredient
// ==========================================================

int Node::getAddedIngredient()
{
	return addedIngredient;
}
// ==========================================================
// Node getNext
//
//
//
//
// PURPOSE: this will get the next node
// ==========================================================
Node *Node::getNext()
{
	return next;
}
// ==========================================================
// Node settNext
//
//
//
//
// PURPOSE: this will get set the next node
// ==========================================================
void Node::setNext(Node *next)
{
	this->next = next;
}
// ==========================================================
// Node getid
//
//
//
//
// PURPOSE: this will get the id of the node
// ==========================================================
int Node::getId()
{
	return node_id;
}
// ==========================================================
// Node print
//
//
//
//
// PURPOSE: this will print the node (mainly for debugging)
// ==========================================================
void Node::print()
{
	cout << "Food Name: " << food_ordered.getFoodName() << endl;
	cout << "Prep Time: " << food_ordered.getPrepTime() << endl;
	cout << "Price: " << food_ordered.getPrice() << endl;
	cout << "ID " << node_id << endl;
	cout << "Added Ingredient: " << addedIngredient << endl;
	cout << "Total Price: " << food_ordered.getPrice() + addedIngredient << endl;
}

