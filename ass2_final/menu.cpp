#pragma once
#include <iostream>
using namespace std;

/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *         this will make a menu object
 */

// ==========================================================
// menu class
//
//
//
//
// PURPOSE: this is where I create the food menu
// and also
// ==========================================================
class menu
{
protected:
    /* data */
    string foodName; // name of the food
    int prepTime;    // time to prepare the food
    double price;    // price of the food

public:
    menu(string, int, double);
    double getPrice();
    int getPrepTime();
    string getFoodName();
    // void print();
};

// ==========================================================
// menu constructor
//
//
//
//
// PURPOSE: this will declare the food menu
// and also
// ==========================================================
menu::menu(string foodName1, int prepTime1, double price1) : foodName(foodName1), prepTime(prepTime1), price(price1)
{
}

// ==========================================================
// getPrice method
//
//
//
//
// PURPOSE: this will get the price of the food
// and also
// ==========================================================

double menu::getPrice()
{
    return price;
}

// ==========================================================
//getPrepTime
//
//
//
//
// PURPOSE: this will get the prep time of the food
// and also
// ==========================================================

int menu::getPrepTime()
{
    return prepTime;
}

// ==========================================================
// getFoodName
//
//
//
//
// PURPOSE:this will get the food name
// and also
// ==========================================================
string menu::getFoodName()
{
    return foodName;
}

// ==========================================================
// salad class
//
//
//
//
// PURPOSE: this will declare the food salda type
// and also
// ==========================================================
class salad : virtual public menu
{
public:
    salad(string name = "Salad", int Prep_time = 3, double Price = 6.99) : menu(name, Prep_time, Price){};
};
// ==========================================================
// pizza class
//
//
//
//
// PURPOSE: this will declare the food pizza type
// and also
// ==========================================================
class pizza : virtual public menu
{

public:
    pizza(string name = "pizza", int Prep_time = 6, double Price = 12.99) : menu(name, Prep_time, Price){};
    // what 12.99 for a pizza???
};
// ==========================================================
// burger class
//
//
//
//
// PURPOSE: this will declare the food burger type
// and also
// ==========================================================
class burger : virtual public menu
{

public:
    burger(string name = "burger", int Prep_time = 4, double Price = 8.99) : menu(name, Prep_time, Price){};
};

// ==========================================================
// stew class
//
//
//
//
// PURPOSE: this will declare the food stew type
// and also
// ==========================================================
class stew : virtual public menu
{

public:
    stew(string name = "stew", int Prep_time = 7, double Price = 14.99) : menu(name, Prep_time, Price){};
};

