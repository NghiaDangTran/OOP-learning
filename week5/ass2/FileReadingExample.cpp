#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"USAGE: FileReadingExample.exe filename simulationType"<<endl;
		cout<<"where simulationType is either 1, 2 or 3."<<endl;
		return 0;
	}

	string filename = argv[1];
	string version = argv[2];
	
	cout << "The filename is: " << filename << endl;
	cout << "The version selected is: " << version <<endl;
	
	//
	//Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	ifstream inputFile;
	inputFile.open(filename);  // opening the file for reading
	string line;
	if(getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
	{
		stringstream sst(line);  //stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		string token;
		int counter = 0;
		int time = 0;
		int expiry = 0;
		string meal = "";
		int numIngredients = 0;
		
		while(sst >> token)  //grabing one token at a time, until there is no token left
		{
			if(counter == 0) //reading time
				time = stoi(token);
			else if(counter == 1) //reading expiry
				expiry = stoi(token);
			else if(counter == 2) //reading meal type
				meal = token;
			else //counting ingredients from here (if counter > 2)
			{
				numIngredients++;
			}
			counter++;
		}
		//To show that we grabbed all the relevant information:
		cout << "time=" << time << " expiry=" << expiry << " meal=" << meal << " numIngredients=" << numIngredients << endl;
	}
}
