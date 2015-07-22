// TemplateExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include <string>

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
	//stack declaration
	try{
		Stack<int> intStack; //stack of ints
		Stack<string>stringStack;//stack of strings
		intStack.push(5);
		cout << "is empty?: " << intStack.empty() << endl;
		cout << "top element: " << intStack.top() << endl;
		cout << "remove top ";
		intStack.pop();cout << endl;
		cout << "is empty?: " << intStack.empty() << endl;

		//string stack
		stringStack.push("jim doing great!"); //pushing string
		cout << "top element:";
		cout<<stringStack.top() << endl; //returning the top element
		stringStack.pop() ;
		cout << "is empty?: " << stringStack.empty()<<endl;

	}
	catch (exception const& ex){
		cout << ex.what() << endl;

	}
	system("pause");
	return 0;
}

