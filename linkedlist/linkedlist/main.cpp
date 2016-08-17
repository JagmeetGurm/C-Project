//This LinkedList project is done by Jagmeet Singh Gurm as part of PSP assignment1 for CSCI 250 
//assigned by Dr. Brent Auernheimer. The project uses linked list to store real numbers entered
//by the user from keyboard and returns their mean and standard deviatin.

#include "stdafx.h"
#include "node.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;

int main()
{
	
	float val;
	int n ;
	linkedlist ll;
	
	
		int i = 0;
		cout << "enter the number of values you want to enter: ";
		cin >> n;
		while (i < n)
		{
			cout << endl<<"enter val " << i + 1 << " : ";
			cin >> val;
			ll.create(val);
			i++;
		}
		
	cout<<endl<<"The mean of the values entered is : "<<ll.mean(); //calling mean function
	cout << endl<<"The standard deviation of the values entered is : " << ll.SD()<<endl; //calling Standard Deviation function
	system("pause");
	return 0;
}