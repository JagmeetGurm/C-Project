// linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "node.h"
#include "linkedlist.h"
#include <iostream>
#include <math.h>

using namespace std;

linkedlist::linkedlist() //constructor gets called when a linked list is created
{ //it initializes head and tail to null.
	head = NULL; 
	tail = NULL;
	count = 0; //counter, total and avg is initialized to 0.
	total = 0;
	avg = 0;

}
linkedlist::~linkedlist() //destructor
{
	node *t;
	
		t = head;  //t pointer to front
		while (t != NULL)
		{                            //loop for "t" pointer traversing the whole list
			head = head->next;   // moving the head to the head's next element
			delete t;   // old front being deleted in each iteration of loop as pointed by "t"
			t = head;   // assingning new head to t

		}
	}

void linkedlist::create(float value)// create function to create nodes to store the data values entered.
{
	node *nn;
	nn = new node; //a new node being created
	nn->data = value; //

	if (head==NULL ) //when list is empty
	{
		nn->next = NULL; //node's next 
		nn->prev = NULL; //and prev pointing to NULL
		head = nn; //new node which is the only node
		tail = nn; //becomes the head and the tail
		
		count++; //increment the counter

	}
	else //when list is non-empty
	{
		nn->next = NULL; //new node's next points to null
		nn->prev = tail; //new node's prev points to the tail of the linked list
		tail->next = nn; //tail's next points to the new node created
		tail = nn; //new node becomes the new tail of the linked list.
		count++; //increment the counter

	}
}

float linkedlist::mean()
{ //mean function to calculate the mean of the real numbers 
	
	
	
	node *t;
	t = head; //temporary node will traverse the whole list starting from head.
	if (head == NULL) //when list is empty
	{
		cout << "sorry list empty.";
		return 0;
	}
	else //when list is non-empty
	{

		while (t != NULL) //traverse till end of list
		{
			total = total + t->data ; //accumulate the total
			t = t->next; //move to the next node
		}
		avg = total / count; //calculate the average
		return avg; //return the avg.
	}
}

float linkedlist::SD() //function to calculate standard deviation fo real numbers
{
	node *t;
	t = head; //temporary pointer for traversing the list.
	float a = 0;
	if (head == NULL) //when list is empty
	{
		cout << "sorry, list empty.";
		return 0;

	}
	else
	{
                   //when list is non-empty

		while (t != NULL) //traversing the list till the end of list
		{
			a = a + (t->data - avg)*(t->data-avg);
			t = t->next;

		}
				return sqrt(a / (count - 1)); //returning the Standard Deviation of the list.
	}

}