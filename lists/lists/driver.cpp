#include "stdafx.h"
#include "List.h"
#include <iostream>
#include "lists.cpp"

using namespace std;

int main()
{
	LList<int> ll;
	
	cout << "appending:" << endl;
	for (int i = 5; i<20; i++){
	ll.append(i);
	}
	ll.print();

	cout << "prepending:" << endl;
	for (int j = 4; j>0; j--){
		ll.prepend(j);
	}

	
	
	
	

	ll.print();

	cout << "So, Test passed for both appending and prepending" << endl<<endl;
	
	
	
	ll.moveToStart();
	cout << "moving to sTart:" << endl;
	cout << "now printing current value:" << endl;
	cout << "Current points to element :" << ll.getValue() << endl;

	cout << "So, Test  passed for moveToStart but passed for getvalue" << endl << endl;

	cout << "No of elements in free list :" << ll.numFree() << endl;
	cout << "No of elements in linked list including head  :" << ll.numActive() << endl;
	cout << "So, Test passed for both numfree and numActive" << endl;
	
	if (ll.next()){
		cout << "If there a next to this element, then its value is :" << ll.getValue() << endl;
	}

	
		cout << "Clearing list: " << endl;
		ll.clear();
		cout << "No of elements in free list :" << ll.numFree() << endl;

		cout << "No of elements in linked list including head :" << ll.numActive() << endl;

		cout << "So, Test passed for next(), getvalue(), clear(), numFree(), numActive()" << endl << endl;

		cout << "now again appending:" << endl;
		for (int i = 1; i<5; i++){
			ll.append(i);
		}
		
		ll.print();
		cout << "No of elements in free list :" << ll.numFree() << endl;
		cout << "No of elements in linked list including head :" << ll.numActive() << endl;
		cout << "So, Test passed for append(), numFree(), and numActive()" << endl << endl;

	
	system("pause");
}

