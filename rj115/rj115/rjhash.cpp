// rj115.cpp : Defines the entry point for the console application.
//Jagmeet Gurm

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int HASHSIZE = 4001;

class node {
public:
	
	node(string key, int value)
	{
		this->key = key;
		this->value = value;
	}

	string key;
	int value;
};

class hashtab {

public:
	
	hashtab(){
		
		nodecount = 0;
		probecount = 0;
		current = -1;
		table = new node*[HASHSIZE];
		for (int i = 0; i < HASHSIZE; i++){
			table[i] = NULL;
			updates[i] = 0;
			cost[i] = 0;
		}
	}



	~hashtab() {
		delete []table;
	}


	int sfold(char* key) {
		unsigned int *lkey = (unsigned int *)key;
		int intlength = strlen(key) / 4;
		unsigned int sum = 0;
		for (int i = 0; i<intlength; i++)
			sum += lkey[i];
		// Now deal with the extra chars at the end
		int extra = strlen(key) - intlength * 4;
		char temp[4];
		lkey = (unsigned int *)temp;
		lkey[0] = 0;
		for (int i = 0; i<extra; i++)
			temp[i] = key[intlength * 4 + i];
		sum += lkey[0];
		return sum % HASHSIZE;
	}

	void update(char* k)
	{
		
			probecount = 0;
		int home = sfold(k);
		int pos = home; 
		string key = string(k);

		if (table[pos] == NULL){
			nodecount++;
			table[pos] = new node(key, 1);
			updates[nodecount]++;
			cost[nodecount]++;

		}
		else if (table[pos]->key == key){
			table[pos]->value++;
			updates[nodecount]++;
			cost[nodecount]++;
		}
		else{
			for (int i = 1; (i < HASHSIZE && table[pos] != NULL); i++) {
			if (table[pos]->key == key){
					cost[nodecount]++;
					updates[nodecount]++;
					return;
				}
				else {
					cost[nodecount]++;
					pos = (home + i) % HASHSIZE;
					probecount++;

				}
			}
			nodecount++;
			updates[nodecount]++;
			
			table[pos] = new node(k, 1);
		}
	}
	

	void next(string &key, int &value){
		current++;
		while (current != HASHSIZE && table[current] == NULL){
			current++;
		}
		if (current == HASHSIZE){
			key = "";
			value = -1;
		}
		else{
			key = table[current]->key;
			value = table[current]->value;
		}
	}
	int size(){
		return nodecount;
	}

	void reset(){
		current = -1;
	}

	void extra()
	{
		string s[4001];
		int temp[4001], i = 0;
		reset();
		string key;
		int value;
		while (current != HASHSIZE){
			next(key, value);
			
			s[i] = key;
			temp[i] = value;
			
			i++;


		}

		int a;
		for (a = 0; a < i - 1; a++)
		{
			int small = 0;
			for (int j = 1; j < i - a; j++)
			{
				if (temp[small] > temp[j])
				{
					small = j;
				}
			}
			int t = temp[small];
			temp[small] = temp[i - a - 1];
			temp[i - a - 1] = t;
			string t2 = s[small];
			s[small] = s[i - a - 1];
			s[i - a - 1] = t2;

		}
		for (int b = 0; b < 24; b++)
		{
			cout << s[b] << ": " << temp[b];
			cout << endl;
		}
	}

	void readfile(){
		ifstream file;
		string w;
		file.open("RomeoAndJuliet.txt");
		if (file.is_open()){
			while (file >> w){
				this->update(const_cast<char*>(w.c_str()));
			}
		}
		else cout << "cant open it";
		file.close();
	}
	void traverse(){
		reset();
		string key;
		int value;
		while (current != HASHSIZE){
			next(key, value);
			cout << "Key: " << key << " Value: " << value << endl;
			
		}
	}

	
	

	void print(){
		for (int i = 1; i < HASHSIZE; i++){
			if (updates[i] == 0){
				if (cost[i] != 0){
					cout << "error" << endl << endl;
					break;
				}
				else cout << "0.0, ";
				
			}
			else{
				cout <<fixed<<setprecision(2) << float(cost[i]) / float(updates[i]) << ",";
			}
		}
	}


	int current;
	int nodecount;
	int probecount;
	node **table;
	int updates[HASHSIZE];
	int cost[HASHSIZE];

};


int main()
{

	hashtab h;

	h.readfile();
	cout <<"NO. of unique words: "<< h.size()<<endl;


	//EXTRA CREDIT
	cout << "EXTRA CREDIT: " << endl;
		cout << "the 24 most common words:" << endl;
		h.extra(); cout << endl;
		h.print();
	system("pause");
	return 0;
}


