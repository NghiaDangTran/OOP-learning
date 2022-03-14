#pragma once
#include "Node.cpp"

class waiting_list
{
private:
    Node *head;
    int size;

public:
    waiting_list();
    virtual void add(menu, int) = 0;
    virtual Node *remove() = 0;
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
