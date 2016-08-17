#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

class linkedlist
{
public:
	linkedlist();
	~linkedlist();
	void create(float value);
	float mean();
	float SD();

private:
	node *head; //a pointer which will point to the first node or the first element of the list.
	node *tail;// a pointer which will point to the last element of the list.
	int count; //will act as counter keeping track of the no. of elements of the list.
	float total, avg; //variables to store total of real numbers and their average.
};
#endif