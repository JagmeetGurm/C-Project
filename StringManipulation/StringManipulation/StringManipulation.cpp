// StringManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
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
	int len = s.length();
	for (int i = 0; i < len-1; i++){
		for (int j = i + 1; j < len; j++){
			if (s[i] == s[j])
			{
				cout << s[i] << endl;
				goto done;
			}
		}
		done:
			;
	}
}

//more efficient function ot print duplicates char in string
void printDuplicateChar2(string s){
	int len = s.length();
	vector<int>v;
	for (int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			if (s[i] == s[j]){
				//later look into it
				for (int k = 0; k <v.size(); k++){
					if (s[i] != v[k]&&k<v.size())
						continue;
					else if (s[i] != v[k] && k + 1 == v.size())
					v.push_back( s[i]);//pushing duplicates into a vector
					else goto back;
				}
			
			}
		}
	back:;

	}
	//prnting out the vector
	for (int i = 0; i < v.size(); i++){
		cout << v.at(i)<<" ";
	}
	
}
//function to check if 2 strings are anagrams
//doesn't work for all cases
//will look into it later on
bool isAnagram(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	for (int i = 0; i, i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (len1 != len2)
				return false;
			else if (s1[i] == s2[j])
			goto done;
			else if ((s1[i] != s2[j]) && (j + 1 == len2) )
				return false;
			else continue;

		}
	done:
		;
	}
	return true;

}
//reverse a string using iteration
string revIteration(string s){
	int len = s.length();
	int i = 0;
	while (i < len / 2){
		char c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
		i++;
	}
	return s;
}

//recursive function to reverse a string
void recursiveRevString(char s[], int firstIndex, int lastIndex){
	//int len = s.length();
	char temp = s[firstIndex];
	s[firstIndex] = s[lastIndex-firstIndex];
	s[lastIndex] = temp;
	if (firstIndex==lastIndex/2 ) //base case added
		return ;
	recursiveRevString(s, firstIndex + 1, lastIndex );
		//return s;
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
cout << "printing duplicate chars: ";
//simple cases
printDuplicateChar("java");
//little border line cases
printDuplicateChar("hhabj");
printDuplicateChar("habcdh");
printDuplicateChar("abcdee");
// edge cases 
printDuplicateChar("b");
//null case
printDuplicateChar("");
printDuplicateChar(" ");
cout <<"this shd work fine:" << endl;
printDuplicateChar2("abcbeb");
cout<<endl;
cout << "is anagram: " << isAnagram("army", "mary");//simple test case
cout << "is anagram: " << isAnagram("army", "marsy"); //test case
cout << "is anagram: " << isAnagram("jim", "img");
cout << "is: " << isAnagram("abc", "abcd");
cout << "is anagram: " << isAnagram("mummy", "ummyt");//will look later into it
cout << "is: " << isAnagram("abc", "abcde");
cout << "is: " << isAnagram("abc", "ab");
cout << "is anagram: " << isAnagram("ab", "ba");
cout << "reverse iteratively: " << revIteration("jagmeet Singh");
cout << endl;
cout << "test case: " << revIteration("Jim is Great")<<endl;
char strng[] = "I'm good!";
// strng = "yes seems right!";
cout << "rev recursion: ";
recursiveRevString(strng, 0, strlen(strng) - 1);
cout << strng << endl;//simple test case
 char strng2[] = "yes seems right!";
recursiveRevString(strng2, 0, strlen(strng2) - 1);
cout << strng2 << endl;
system("pause");
	return 0;
}

