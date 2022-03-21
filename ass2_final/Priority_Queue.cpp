#pragma once
#include "queue.cpp"
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *         this will make a Priority_Queue object
 */

// ==========================================================
// menu class
//
//
//
//
// PURPOSE: this is where I create the Priority_Queue
// and also
// ==========================================================
class Priority_Queue : public queue
{
public:
    Priority_Queue() : queue(){};                               // constructor
    void add(int time, menu food_ordered, int addedIngredient); // only nedd to modify the add function
};
// ==========================================================
// add
//
//
//
//
// PURPOSE: this will add based on the cost of the food
// ==========================================================
void Priority_Queue::add(int time, menu food_ordered, int addedIngredient)
{
    double curr_priority = food_ordered.getPrice() + addedIngredient;

    Node *newNode = new Node(time, food_ordered, addedIngredient, NULL);
    Node *current = getHead();

    if (current == NULL)
    {
        // if the head is null then set the head to the new node
        setHead(newNode);
    }
    else
    {
        // orther wise travel through the list
        if (curr_priority > current->getFood().getPrice() + current->getAddedIngredient())
        { // if the priority is higher then set the new node to the head
            newNode->setNext(current);
            setHead(newNode);
        }
        else
        {// orther wise travel through the list
        // and find the perfect location to add
            while (current->getNext() != NULL)
            {
                if (curr_priority > current->getNext()->getFood().getPrice() + current->getNext()->getAddedIngredient())
                {
                    newNode->setNext(current->getNext());
                    current->setNext(newNode);
                    break;
                }
                current = current->getNext();
            }
            if (current->getNext() == NULL)
            {
                current->setNext(newNode);
            }
        }
    }
}
