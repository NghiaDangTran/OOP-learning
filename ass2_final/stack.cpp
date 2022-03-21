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
 *        this will make a stack object
 */

// ==========================================================
// stack class
//
//
//
//
// PURPOSE: this is the stack object
//
// ==========================================================
class stack : virtual public queue
{
public:
    stack() : waiting_list(){};                                 // constructor
    Node *remove() override;                                             // remove the food from the list
                                        // set the id of the list
    //    menu get();
};



// ==========================================================
// stack remove
//
//
//
//
// PURPOSE: override the remove method from the queue class
//
// ==========================================================
Node *stack::remove()
{
    Node *current = getHead();
    Node *previous = NULL;
    while (current->getNext() != NULL)
    {
        previous = current;
        current = current->getNext();
    }
    if (previous == NULL)
    {
        setHead(NULL);
    }
    else
    {
        previous->setNext(NULL);
    }
    return current;
    //  return current;
}
