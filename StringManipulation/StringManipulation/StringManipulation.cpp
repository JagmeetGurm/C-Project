// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//function to find the length of the string using length method of string
int lengthString(string myString){
	return myString.length();

}
int main()
{
	string s;
	s = "jim is great";
cout<<"the length of string is: "<<	lengthString(s)<<endl;

system("pause");
	return 0;
}

