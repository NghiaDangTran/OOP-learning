#pragma once
#include "Node.cpp"
/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *        this will make the abstract class  for all type od list that we will use
 */

// ==========================================================
// waiting_list class
//
//
//
//
// PURPOSE: this is the  object that contain all the information of the list
// 
// ==========================================================
class waiting_list
{
private:
    Node *head;// head of the list

public:
    waiting_list();// constructor
    virtual void add(int, menu, int) = 0;// polyphormic method
    virtual Node *remove() = 0;// polyphormic method
    void print();// print the list
    Node *getHead();// get the head of the list
    void setHead(Node *);// set the head of the list
    int getSize();// get the size of the list 
    bool isEmpty();// check if the list is empty
    virtual int getId() = 0;// get the id of the list
};

// ==========================================================
// waiting_list constructor
//
//
//
//
// PURPOSE: this will declare the waiting list
// 
// ==========================================================
waiting_list::waiting_list()
{
    head = NULL;
}
// ==========================================================
// waiting_list getHead method
//
//
//
//
// PURPOSE: this get the head of the list
// 
// ==========================================================
Node *waiting_list::getHead()
{
    return head;
}

// ==========================================================
// waiting_list setHead method
//
//
//
//
// PURPOSE: this set the head of the list
// 
// ==========================================================
void waiting_list::setHead(Node *head)
{
    this->head = head;
}

// ==========================================================
// waiting_list isEmpty method
//
//
//
//
// PURPOSE: this will check if the list is empty
// 
// ==========================================================
bool waiting_list::isEmpty()
{
    return head == NULL;
}

// ==========================================================
// waiting_list print method
//
//
//
//
// PURPOSE: this will print out the data (mainly for debugging)
// 
// ==========================================================
void waiting_list::print()
{
    Node *current = head;
    while (current != NULL)
    {
        current->print();
        cout << endl;
        current = current->getNext();
    }
}
