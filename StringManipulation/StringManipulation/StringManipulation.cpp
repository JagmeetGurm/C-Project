// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
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

//another way to reverse a string
string revString(string myString){
	int i = 0;
	int j = (myString.length()) - 1;
	while (i <(myString.length() / 2)){
		char c = myString[j];
		myString[j] = myString[i];
//		cout << myString[j];
		myString[i] = c;
		i++;
		j--;
	}
	return myString;
}

//another efficent way
//reverse in place
string revString2(string myString){
	for (int i = 0; i < (myString.length()) / 2; i++){
		swap(myString[i], myString[myString.length() - 1 - i]); //using built-in swap function
	}
	return myString;
}


//rev in place without using in-built swap
string revString3(string myString){
	for (int i = 0; i < myString.length() / 2; i++){
		char c = myString[(myString.length()) - 1 - i]; //using temp char to store and swap
		myString[(myString.length()) - 1 - i] = myString[i];
		myString[i] = c;
	}
	return myString;
}

//function to reverse  a string(stored in array)
char* revStringArray(char str[]){
	//calculating the size of array
	
	for (int i = 0; i<(sizeof(str)/sizeof(*str))/2; i++){
		char c = str[i];
		str[i] = str[(sizeof(str) / sizeof(*str))-1-i];
		str[(sizeof(str) / sizeof(*str))-1-i]=c;

	}
	return str;
}

//function to reverse an aray of strings
//size of array passed as diff argument
void arrayString(string s[], int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < (s[i].length()) / 2; j++){
			char c = s[i][j];
			s[i][j] = s[i][(s[i].length()) - 1 - j];
			s[i][(s[i].length()) - 1 - j] = c;
		}
		cout << s[i] << endl;
	}

}
//function to check if string is palindrome
bool isPalindrome(string myString){
	int i = 0;
	int len = myString.length();
	while (i < len/2){
		if (myString[i] == myString[len - 1 - i])
		{
			i++;
			continue;
		}
		else return false;
		
	}
	return true;
}


//function to print dupicates char in a string
void printDuplicateChar(string s){

}
int main()
{
	string str[3];
	str[0] = "jim gurm";
	str[1] = "harry";
	str[2] = "roses are red";
	char fullName[8]="jimgurm";
	
//	char* name = new char;
//	name = "jimmy gurm";


	string s = "jim is great";
cout<<"the length of string is: "<<	lengthString(s)<<endl;
cout << "lenght of string using 2nd way, not using the length method: " << lengthString2(s) << endl;
cout << "third char: " << findChar(s, 3)<<endl;
cout << "check string part of string: " << returnString(s, "isi")<<endl;
cout << "the reverse string of jagmeet is: ";
reverseString("jagmeet");
cout << "\nreversing string 2nd method: " << revString("harsi");
cout << "\nrev a string efficient way: " << revString2("jimSGurm")<<endl;
cout << "wtihout sing in-built swap: " << revString3("science")<<endl;
cout << "is string palindrome: " << isPalindrome("jij") << endl;
cout << "is this string palindrome: " << isPalindrome("mom i mom")<<endl;
cout << "reverse string: " << revStringArray(fullName);
cout << "\nreverse string of arrays: ";
//passing array of strings and size as arguments
 arrayString(str,3);
cout<< endl;
system("pause");
	return 0;
}

