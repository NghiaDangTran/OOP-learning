#pragma once
#include "waiting_list.cpp"
class stack : virtual public waiting_list
{
public:
    stack() : waiting_list(){};
    void add(menu food_ordered, int addedIngredient);
    void remove();
    //    menu get();
};

void stack::add(menu food_ordered, int addedIngredient)
{
    Node *newNode = new Node(food_ordered, addedIngredient, NULL);

    if (getHead() == NULL)
    {
        setHead(newNode);
    }
    else
    {
        Node *current = getHead();
        while (current->getNext() != NULL)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}
void stack::remove()
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
    //  return current;
}

// int main()
// {
//     // waiting_list list;
//     // list.add(burger(), 10);
//     // list.add(pizza(), 10);
//     // list.add(stew(), 10);
//     stack q;
//     q.add(burger(), 10);
//     q.add(pizza(), 10);
//     q.add(stew(), 10);
//     q.add(burger(), 10);
//     q.add(pizza(), 10);

//     q.remove();
//     q.add(pizza(), 10);
//     q.print();
//     return 0;

//     // list.print();
// }
