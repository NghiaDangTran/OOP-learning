#pragma once
#include "waiting_list.cpp"

/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this will make a queue object
 */

// ==========================================================
// queue class
//
//
//
//
// PURPOSE: this is the quue object
//
// ==========================================================
class queue : virtual public waiting_list
{
    // because we use the virtual keyword, we dont need to declare the head 
public:
    queue() : waiting_list(){};// constructor
    void add(int time, menu food_ordered, int addedIngredient);// add the food to the list
    Node *remove();// remove the food from the list
    int getId();// get the id of the list
    void setId(int id);// set the id of the list
};
// ==========================================================
// queue add
//
//
//
//
// PURPOSE: this will add , at time, with the food_ordered and the addedIngredient
//
// ==========================================================
void queue::add(int time, menu food_ordered, int addedIngredient)
{
    Node *newNode = new Node(time, food_ordered, addedIngredient, NULL);
    // travel through the list
    if (getHead() == NULL)
    {
        // if the head is null then set the head to the new node
        setHead(newNode);
    }
    else
    {// orther wise travel through the list
    // to the end of the list
        Node *current = getHead();
        while (current->getNext() != NULL)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

// ==========================================================
// queue setId
//
//
//
//
// PURPOSE: this will set the id of the node last
//
// ==========================================================
void queue::setId(int id)
{
    Node *current = getHead();
    while (current->getNext() != NULL)
    {
        current = current->getNext();
    }
    current->setId(id);
}
// ==========================================================
// queue getId
//
//
//
//
// PURPOSE: this will get the last id of the node
//
// ==========================================================
int queue::getId()
{
    Node *current = getHead();

    while (current->getNext() != NULL)
    {

        current = current->getNext();
    }
    return current->getId();
}
// ==========================================================
// queue remove
//
//
//
//
// PURPOSE: this will remove the first node
// ==========================================================
Node *queue::remove()
{
    Node *current = getHead();
    setHead(current->getNext());
    return current;
}
