// lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

template <typename E> class Link {
private:
	static Link<E>* freelist; // Reference to freelist head
	static int  num_active; //no. of nodes in linked list
	static int num_free;//no. of nodes in free list

public:
	E element; // Value for this node
	Link* next; // Point to next node in list

	// Constructors
	Link(const E& elemval, Link* nextval = NULL)
	{
		element = elemval; 
		next = nextval;
	}

	Link(Link* nextval = NULL)
	{ next = nextval;
	}

	void* operator new(size_t){ // Overloaded new operator
		if (freelist == NULL) {
			num_active++; return ::new Link;
		} // Create space
		
		else {
			Link<E>* temp = freelist; // Can take from start of freelist
			freelist = freelist->next;
			num_free--;
			num_active++;
			return temp; // Return the link
		
		}
		
	}
	// Overloaded delete operator
	void operator delete(void* ptr) {
		((Link<E>*)ptr)->next = freelist; // Put on freelist
		freelist = (Link<E>*)ptr;
		num_free++;
		num_active--;


	}

	int freecount(){
		return num_free;
		
	}

	int activecount(){
		return num_active;
		
	}
};
// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;

template <typename E>
int Link<E>::num_free = 0;
template <typename E>
int Link<E>::num_active = 0;




// Linked list implementation
template <typename E> class LList : public List<E> , public Link<E>{
private:
	Link<E>* head; // Pointer to list header
	Link<E>* tail; // Pointer to last element
	Link<E>* curr; // Access to current element
	int cnt; // Size of list
	void init() { // Intialization helper method
		curr = tail = head = new Link<E>;
		cnt = 0;
	//	num_active = 0;
	//	num_free = 0;
	}

	void removeall() { // Return link nodes to free store
		while (head != NULL) {
			curr = head;
			head = head->next;
			 delete curr ;
			//num_active--;
		}
	}

public:
	LList() { init(); } // Constructor

	~LList() { removeall(); } // Destructor

	
	void print() // Print list contents
		{
			Link<E>* temp = head->next;
			while (temp != NULL)
			{
				cout << temp->element << "-->";
				temp = temp->next;
			}
			cout << endl;

		} 

	void clear() { removeall(); init(); } // Clear list

	// Insert "it" at current position
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);
		if (tail == curr) tail = curr->next; // New tail
		cnt++;
	}
	void append(const E& it) { // Append "it" to list
		tail = tail->next = new Link<E>(it, NULL);
		cnt++;
	}
	
	void prepend(const E& it)
	{
		Link<E> *temp = new Link<E>(it, NULL);
		temp->next = head->next;
		head->next = temp;
		//head = temp;
		cnt++;
	}
	
	// Remove and return current element
	E remove() {
	//	Assert(curr->next != NULL, "No element");
		E it = curr->next->element; // Remember value
		Link<E>* ltemp = curr->next; // Remember link node
		if (tail == curr->next) tail = curr; // Reset tail
		curr->next = curr->next->next; // Remove from list
		delete ltemp; // Reclaim space
	//	cnt--; // Decrement the count
		return it;
	}


	void moveToStart() // Place curr at list start
	{
		curr = head;


	}
	
	// Move curr one step right; no change if already at end
	bool next()
	{
		if (curr != tail)
		{
			curr = curr->next;
			return true;
		}
		else return false;
	}

//	int length() const { return cnt; } // Return length
	
	
	
	
	const E& getValue() const { // Return current element
		if(curr->next != NULL);
		return curr->next->element;
	}
	int numFree(){

		return freecount();
		
	}
	int numActive(){

		return activecount();

	}
};