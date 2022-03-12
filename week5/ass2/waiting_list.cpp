#pragma once
#include "Node.cpp"

class waiting_list
{
private:
    Node *head;
    int size;

public:
    waiting_list();
    // void add(menu, int);
    void print();
    Node *getHead();
    void setHead(Node *);
    int getSize();
};
waiting_list::waiting_list()
{
    head = NULL;
    size = 0;
}
Node *waiting_list::getHead()
{
    return head;
}
void waiting_list::setHead(Node *head)
{
    this->head = head;
}

// void waiting_list::add(menu food_ordered, int addedIngredient)
// {
//     Node *newNode = new Node(food_ordered, addedIngredient, NULL);
//     if (head == NULL)
//     {
//         head = newNode;
//     }
//     else
//     {
//         Node *current = head;
//         while (current->getNext() != NULL)
//         {
//             current = current->getNext();
//         }
//         current->setNext(newNode);
//     }
//     size++;
// }
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

class queue : virtual public waiting_list
{
public:
    queue() : waiting_list(){};
    void add(menu food_ordered, int addedIngredient);
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
    q.print();
    return 0;

    // list.print();
}
