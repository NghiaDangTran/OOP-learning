#pragma once
#include "queue.cpp"
class Priority_Queue :  public queue
{
public:
    Priority_Queue() : queue(){};
    void add(menu food_ordered, int addedIngredient);

};

void Priority_Queue::add(menu food_ordered, int addedIngredient)
{
   double curr_priority = food_ordered.getPrice()+addedIngredient;
   cout << "curr_priority: " << curr_priority << endl;

    Node *newNode = new Node(food_ordered, addedIngredient, NULL);
    Node *current = getHead();


    if (current == NULL)
    {
        setHead(newNode);
    }
    else
    {
        if (curr_priority > current->getFood().getPrice()+current->getAddedIngredient())
        {
            newNode->setNext(current);
            setHead(newNode);
        }
        else
        {
            while (current->getNext() != NULL)
            {
                if (curr_priority > current->getNext()->getFood().getPrice()+current->getNext()->getAddedIngredient())
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

int main()
{
    // waiting_list list;
    // list.add(burger(), 10);
    // list.add(pizza(), 10);
    // list.add(stew(), 10);
    Priority_Queue q;
    q.add(pizza(), 0);//12.99
    q.add(stew(), 0);//14.99
    q.add(burger(), 0);//8.99
    q.add(pizza(), 0);//12.99
    q.add(stew(), 0);//14.99
    q.add(salad(), 0);//6.99
    q.add(pizza(), 0);//12.99
     //q.remove();


    q.print();
    return 0;

    // list.print();
}
 