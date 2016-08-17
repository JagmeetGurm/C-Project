// hash115.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

#include <string>

using namespace std;

const int HASHSIZE = 4001;

class HashNode{
private:
	char* key;
	int value;

public:
	HashNode(char* key, int value){
		this->key = key;
		this->value = value;
	}

	char* getKey(){
		if (getValue() == 0)
			return NULL;
		else
		return key;
	}

	int getValue(){
		return value;
	}

	void incrementValue(){
		value += 1;
	}
};

class HashTable {

private:
	HashNode **table;

	int sfold(char* key) {
		unsigned int *lkey = (unsigned int *)key;
		int intlength = strlen(key) / 4;
		unsigned int sum = 0;
		for (int i = 0; i<intlength; i++)
			sum += lkey[i];
		// Now deal with the extra chars at the end
		int extra = strlen(key) - intlength * 4;
		string temp[4];
		lkey = (unsigned int *)temp;
		lkey[0] = 0;
		for (int i = 0; i<extra; i++)
			temp[i] = key[intlength * 4 + i];
		sum += lkey[0];
		return sum % HASHSIZE;
	}

	int count;

	int current;

public:

	int access;

	HashTable(){
	//	table = new HashNode*[HASHSIZE];
		count = 0;
		current = -1;
	//	for (int i = 0; i < HASHSIZE; i++){
	//		table[i] = new HashNode(NULL, 0);
		//}
	}

	~HashTable() {
		for (int i = 0; i < HASHSIZE; i++)
		if (table[i] != NULL)
			delete table[i];
		delete[] table;
	}


	int size(){
		return count;
	}

	void hashInsert(char* k) {
		int home;
		int pos = home = sfold(k);
		for (int i = 1; (table[pos])->getKey() != NULL; i++) {
			pos = (home + i) % HASHSIZE;
		}
		count++;
		table[pos] = new HashNode(k, 1);
	}

	int hashSearch(char* k){
		int home;
		int pos = home = sfold(k);

		for (int i = 1; ((table[pos]->getKey() != NULL) && k != (table[pos]->getKey())); i++) {
			access += 2;
			pos = (home + i) % HASHSIZE;
		}
		if (k == (table[pos]->getKey())){
			access++;
			return pos;
		}
		else {
			return -1;
		}
	}

	void update(char* k){
		if (int pos = hashSearch(k) != -1){
			access++;
			table[pos]->incrementValue();
		}
		else{
			hashInsert(k);
		}
	}

	void reset(){
		current = -1;
	}
	void setCurrent(int i){
		current = i;
	}

	int getCurrent(){
		return current;
	}


	void traverseHashTable(){
		reset();

		while (getCurrent() <= HASHSIZE){
			string key = "";
			int val = -1;
			next(key, val);
			std::cout << key << val;
		}
	}

	void next(string &key, int &val){

		for (int i = getCurrent(); i < HASHSIZE; i++){
			if (table[i] != NULL){
				setCurrent(i);
				key = table[i]->getKey();
				val = table[i]->getValue();
				break;
			}
		}
	}

};

int main(){

	HashTable h;
	HT[0]= new HashNode("A",0);
//	HT.update("A");
	//HT.update("B");
	//HT.update("C");
	//HT.update("A");
	//HT.update("A");

	//HT.traverseHashTable();


	return 0;
}