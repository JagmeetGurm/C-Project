// reverse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string art;
	cout << "enter your string" << endl;
	cin >> art;
	for (int i = art.length(); i >= 0;i--)
	{
		cout << art[i];
	}
	system("pause");
	return 0;
}

