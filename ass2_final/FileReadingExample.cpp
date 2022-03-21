#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
#include "menu.cpp"
#include "waiting_list.cpp"
#include "queue.cpp"
#include "stack.cpp"
#include "Priority_Queue.cpp"
using namespace std;

/**
 * DangNghiaA1
 *
 * Comp 2150 Section A02 Assignment: 2
 *
 * @author Nghia Dang( 7863117)
 *
 *
 *         this will do all the hard work
 * from reading the txt to creating the menu to process the data
 */

// ==========================================================
// String_meal
//
//
//
//
// PURPOSE:this is just a custom method that will take a string and return a menu object
// ==========================================================
menu String_meal(string meal)
{

	if (meal == "Salad")
	{
		return salad();
	}
	else if (meal == "Pizza")
	{
		return pizza();
	}
	else if (meal == "Burger")
	{
		return burger();
	}
	else 	{
		return stew();
	}
}
int main(int argc, char *argv[])
{

	// reading is just the same with the provided code
	if (argc != 3)
	{
		cout << "USAGE: FileReadingExample.exe filename simulationType" << endl;
		cout << "where simulationType is either 1, 2 or 3." << endl;
		return 0;
	}

	string filename = argv[1];
	string version = argv[2];

	cout << "The filename is: " << filename << endl;
	cout << "The version selected is: " << version << endl;

	//
	// Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	// variable to process
	int chefTime = 0;		// this to modify the time of the chef
	int chefProessTime = 0; // this is the actual time that the chef will be free
	int totalorder = 0;		// this is the total number of order
	double totalrev = 0;	// this is the total revenue
	waiting_list *list;		// abstact class list to store the order
	queue prepared;			// quue to process the food
	int toatalLine = 0;
	//////////////////////
	// first check the version the user want to do then up casting to the right version
	if (stoi(version) == 1)
	{
		queue q;
		list = &q;
	}
	else if (stoi(version) == 2)
	{
		stack s;
		list = &s;
	}
	else
	{
		Priority_Queue p;
		list = &p;
	}

	ifstream inputFile;
	inputFile.open(filename); // opening the file for reading
	string line;

	/*
	 * First of all let we talk about the logic I use to process the data
	 * first of all I use the same logic with my java implementation for file reading from class 2140
	 *
	 * the idea is if the current line is not the eof then we will take all the token of that string and process it into the waitng list
	 * and then we will read the next line
	 * and if some conditions are met than we will process the order and add it to the prepared queue
	 *
	 */
	cout << "Reading the file..." << endl;

	do
	{								  // read at least first line
		if (getline(inputFile, line)) // gets the next line from the file and saves it in 'line', if there is one
		{
			stringstream sst(line); // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
			string token;
			int counter = 0;
			int time = 0;
			int expiry = 0;
			string meal = "";
			int numIngredients = 0;

			while (sst >> token) // grabing one token at a time, until there is no token left
			{
				if (counter == 0) // reading time
					time = stoi(token);
				else if (counter == 1) // reading expiry
					expiry = stoi(token);
				else if (counter == 2) // reading meal type
					meal = token;
				else // counting ingredients from here (if counter > 2)
				{
					numIngredients++;
				}
				counter++;
			}
			// To show that we grabbed all the relevant information:
			/// add this into the waiting list
			menu toAdd = String_meal(meal);
			// create the order
			list->add(expiry, toAdd, numIngredients);
			cout << "Time: " << time << ", FoodOrder " << list->getId() << " arrives -> Expiry: " << expiry << " - Meal: "
				 << meal << " - Ingredients: " << numIngredients << " - Prep.time:" << toAdd.getPrepTime() + numIngredients << " - Price: " << toAdd.getPrice() + numIngredients << endl;
			// add this to the list
			chefTime = time;
			toatalLine++;
		}

		while (list->isEmpty() == 0)
		{ // as long as the list is not empty
			// we will remove the first order from the list
			Node *current = list->remove();

			if (chefProessTime <= current->getExprireTime())
			{
				// if the time when the chef is free is less than the order time expiry
				// then we add this customer in to the prepared queue to cooklater
				current->staticInt(); // this is manipulating the order of customer come
				prepared.add(current->getExprireTime(), current->getFood(), current->getAddedIngredient());
				prepared.setId(current->getId());

				cout << "TIME: " << chefTime << " - FoodOrder " << current->getId() << " is getting prepared" << endl;
				chefProessTime = chefTime + current->getTime();
				// update the new time for the chef
			}

			// if list is empty bu the next line is not eof then add the next line to the list
			while (getline(inputFile, line)) // gets the next line from the file and saves it in 'line', if there is one
			{
				stringstream sst(line); // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
				string token;
				int counter = 0;
				int time = 0;
				int expiry = 0;
				string meal = "";
				int numIngredients = 0;
				toatalLine++;
				while (sst >> token) // grabing one token at a time, until there is no token left
				{
					if (counter == 0) // reading time
						time = stoi(token);
					else if (counter == 1) // reading expiry
						expiry = stoi(token);
					else if (counter == 2) // reading meal type
						meal = token;
					else // counting ingredients from here (if counter > 2)
					{
						numIngredients++;
					}
					counter++;
				}
				// and as long the line we read have enough data
				if (time < chefProessTime)
				{ // and also the current time must smaller than the time when the chef is free
					// then we will add this in to the list
					menu toAdd = String_meal(meal);
					list->add(expiry, toAdd, numIngredients);

					// list->print();
					cout << "Time: " << time << ", FoodOrder " << list->getId() << " arrives -> Expiry: " << expiry << " - Meal: "
						 << meal << " - Ingredients: " << numIngredients << " - Prep.time:" << toAdd.getPrepTime() + numIngredients << " - Price: " << toAdd.getPrice() + numIngredients << endl;

					chefTime = time;
				}
				else
				{
					//  this is where the trick that java do better
					// in java we can mark the buffer and comback to that line in the txt file
					// but in c++ we can not do that
					// so we do the hard way
					// we will read the file again and we will skip the line that we have already read
					inputFile.close();
					inputFile.open(filename);
					for (int i = 0; i < toatalLine - 1; i++)
					{
						getline(inputFile, line);
					}
					// but remmber dont decrement the counter
					toatalLine--;
					break;
				}

				// insert this into the waiting list
				// 	update time
			}

			if (!prepared.isEmpty())
			{ // if the prepared list is not empty
				// then make the chef cook that order
				Node *current = prepared.remove();

				chefTime = chefProessTime;
				cout << "Time: " << chefTime << " - FoodOrder " << current->getId() << " is served ! Revenue grew by:" << current->getPrice() << endl;
				totalorder++;
				// update the new time for the chef
				// and update total order
				// and update the revenue
				totalrev += current->getPrice();
			}
			if (list->isEmpty() && prepared.isEmpty() && inputFile.eof() == 0)
			{
				// special case hapen when we process all the orders
				// but the order still not end of the file
				// reammber we already read one line in the while loop
				// now just read from where we left from the orther loop and add it to the list
				inputFile.close();
				inputFile.open(filename);
				for (int i = 0; i < toatalLine; i++)
				{
					getline(inputFile, line);
				}
				// toatalLine++;
			}
		}
		// then we  loop again untill the file is end
	} while (inputFile.eof() == 0);

	cout << "Total order: " << totalorder << endl;
	cout << "Total revenue: " << totalrev << endl;
}