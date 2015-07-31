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
//function to count length of string without using length method
int lengthString2(string myString2){
	//char c=myString2[0];
	int i = 0;
	while (myString2[i] != '\0'){
		i++;

	}
	return i;

}
int main()
{
	string s;
	s = "jim is great";
cout<<"the length of string is: "<<	lengthString(s)<<endl;
cout << "lenght of string using 2nd way, not using the length method: " << lengthString2(s) << endl;

system("pause");
	return 0;
}

