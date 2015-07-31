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

//extracting a particular char from a string
char findChar(string myString, int i){

	return myString[i - 1];
}

//checking a string from a string
bool returnString(string myString, string retString){
	for (int i = 0; i < myString.length(); i++){
		
		if (retString[0] == myString[i]){
			int c = i;
			for (int j = 0; j < retString.length()-1; j++){
				c++;
				if (retString[j+1] == myString[c])
					continue;
				else goto start;

					
			}
			return true;
		}
		start://
		
		;
	}
	return false;
}


//function to reverse a string
void reverseString(string myString){
	string original = myString;
	char* rev=new char[myString.length()];
	int i = 0;
	int j = myString.length();
	j--;
	while (j >=0){
		rev[i] = original[j];
		i++;
		j--;
	}
	for (int i = 0; i < myString.length();i++)
	cout<< rev[i];
}

int main()
{
	string s;
	s = "jim is great";
cout<<"the length of string is: "<<	lengthString(s)<<endl;
cout << "lenght of string using 2nd way, not using the length method: " << lengthString2(s) << endl;
cout << "third char: " << findChar(s, 3)<<endl;
cout << "check string part of string: " << returnString(s, "isi")<<endl;
cout << "the reverse string of jagmeet is: ";
reverseString("jagmeet");
system("pause");
	return 0;
}

