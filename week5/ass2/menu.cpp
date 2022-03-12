#include <iostream>
using namespace std;

class menu
{
protected:
    /* data */
    string foodName;
    int prepTime;
    double  price;

public:
    menu(string, int, double);
    double  getPrice();
    int getPrepTime();
    string getFoodName();
    void print();
};

menu::menu(string foodName1, int prepTime1, double  price1) : foodName(foodName1), prepTime(prepTime1), price(price1)
{
}

double  menu::getPrice()
{
    return price;
}

int menu::getPrepTime()
{
    return prepTime;
}

string menu::getFoodName()
{
    return foodName;
}

void menu::print()
{
    cout << "Food Name: "<< foodName << endl;
    cout << "Prep Time: " << prepTime << endl;
    cout << "Price: " << price << endl;
}
class salad : virtual public menu
{
public:
    salad(string name = "Salad", int Prep_time = 3, double  Price = 6.99) : menu(name, Prep_time, Price){};
};

class pizza : virtual public menu
{

public:
    pizza(string name = "pizza", int Prep_time = 6, double  Price = 12.99) : menu(name, Prep_time, Price){};
    // what 12.99 for a pizza???
};

class burger : virtual public menu
{

public:
    burger(string name = "burger", int Prep_time = 4, double  Price = 8.99) : menu(name, Prep_time, Price){};
};
class stew : virtual public menu
{

public:
    stew(string name = "stew", int Prep_time = 3, double  Price = 14.99) : menu(name, Prep_time, Price){};
};

// class watting_list
// {
// private:
//     int size;
//     int *arr;

// public:
//     watting_list(int size);
//     void add(int);
//     void remove(int);
//     void print();
// };
