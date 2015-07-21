// TemplateExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b){
	return(a > b ? a : b);

}

int main()
{
	cout<<"int max: "<<Max(3, 5)<<endl;
	cout << "double max: " << Max(4.5, 9.8) << endl;
	cout << "string max: " << Max("jim", "abcd")<<endl;

	//template example for class 
	//
	system("pause");
	return 0;
}

