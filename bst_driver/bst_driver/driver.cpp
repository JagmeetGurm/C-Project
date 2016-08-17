// bst_driver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "BST.h"
using namespace std;

int main()

//all these tests verify that functions have been implemented successfully
{
	int cnt = 0;
	char c='y';
	int n;
	bst b; 

	node* nn;
	while (true)
	{
		if (c == 'n')
			goto exit;
		cout << "please enter the BST key: ";
		cin >> n;

		if (cnt == 0)
		{
			b.rr = nn = new node(n, NULL, NULL); cnt++;
		}
		else{
			nn = new node(n, NULL, NULL);
		}	b.insert(b.root, nn);
		
		cout << "\npress any key to continue, n to exit: ";
			cin >> c;
	}
exit: 
	cout << "\n print in order between 2 nodes:";
	cout <<"\nnodes visited: "<< b.print(b.rr, 3, 6);
	
	cout<<endl<<"6th smallest element: "<<b.findkthsmallest(b.rr, 6)<<endl;
	cout << endl << "4th smallest element: " << b.findkthsmallest(b.rr, 4) << endl;

	cout << "adding a new node:10" << endl;
	nn = new node(10, NULL, NULL);
	b.insert(b.root, nn);
	cout << "adding a new node:12" << endl;
	nn = new node(12, NULL, NULL);
	b.insert(b.root, nn);
	b.count=0;
	cout << "\nprint in order between 2 nodes:";
	cout << "\nnodes visited: " << b.print(b.rr, 2, 10);

	cout << endl << "7th smallest element: " << b.findkthsmallest(b.rr, 7) << endl;
	cout << "adding a new node:15" << endl;
	nn = new node(15, NULL, NULL);
	b.insert(b.root, nn);
	b.count = 0;
	cout << "\nprint in order between 2 nodes:";
	cout << "\nnodes visited: " << b.print(b.rr, 2, 15);

	cout << endl << "3rd smallest element: " << b.findkthsmallest(b.rr, 3) << endl;
	system("pause");
	
	return 0;
}

