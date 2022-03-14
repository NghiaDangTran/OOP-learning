#pragma once
#include "waiting_list.cpp"
class queue : virtual public waiting_list
{
public:
    queue() : waiting_list(){};
    void add(menu food_ordered, int addedIngredient);
    Node *remove();

    menu get();
};

void queue::add(menu food_ordered, int addedIngredient)
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

Node *queue::remove()
{
    Node *current = getHead();
    setHead(current->getNext());
    return current;
}

int main()
{
    // waiting_list list;
    // list.add(burger(), 10);
    // list.add(pizza(), 10);
    // list.add(stew(), 10);
    queue q;
    q.add(burger(), 10);
    q.add(pizza(), 10);
    q.add(stew(), 10);
    q.add(burger(), 10);
    q.add(pizza(), 10);

    q.remove();
    q.add(pizza(), 10);
    q.print();
    return 0;

    // list.print();
}
