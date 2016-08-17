// rjhash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#define HASHSIZE 4001
using namespace std;

class node
{
public:
	node(char* k, int v)
	{
		this->key = k;
		this->value = v;

	}
	char* ret_key()
	{
		return key;
	}
	int ret_val()
	{
		return value;
	}
private:
	char* key;
	int value;

};


class hashtable
{
public:
	hashtable(){
		table = new node*[HASHSIZE];
		for (int i = 0; i < HASHSIZE; i++){
			table[i] = NULL;
		}
	}
	int key();

	void update(int key);

	int probes();

	void reset();

	void next();

private:
	node** table;

	int	updates[HASHSIZE];
	int cost[HASHSIZE];
};
int main()
{
	int array_size = 25000; // define the size of character array
	string * array = new string[array_size]; // allocating an array of 1kb
	int position = 0; //this will be used incremently to fill characters in the array 

	ifstream file("RomeoAndJuliet.txt"); //opening an input stream for file test.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
	stream could not be opened.*/
	if (file.is_open())
	{
		//file opened successfully so we are here
		cout << "File Opened successfully!!!. Reading data from file into array" << endl;
		//this loop run until end of file (eof) does not occur
		while (!file.eof() )
		{
			file>>array[position]; //reading one character from file to array
			position++;
		}
	//	array[position - 1] = '\0'; //placing character array terminating character

		cout << "Displaying Array..." << endl << endl;
		//this loop display all the charaters in array till \0 
	//	for (int i = 0; i<position; i++)
		//{
			cout << array[0];
	//	}
	}
	else //file could not be opened
	{
		cout << "File could not be opened." << endl;
	}
	
	system("pause");
	return 0;
}

