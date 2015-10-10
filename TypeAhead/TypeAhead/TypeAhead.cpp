// TypeAhead.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

//hard code text in program
string text = "Mary had a little lamb its fleece was white as snow And everywhere that Mary went the lamb was sure to go It followed her to school one day which was against the rule It made the children laugh and play to see a lamb at school And so the teacher turned it out but still it lingered near And waited patiently about till Mary did appear Why does the lamb love Mary so? the eager children cry Why Mary loves the lamb, you know the teacher did reply";
string* myString=new string[text.length()];

int main(int argc, _TCHAR* argv[])
{
	//myString.push_back(text[0]);

	for (int i = 0, j=0; i < text.length(); i = i + 2, j++){
		myString[j]=text[i];
	}
	system("pause");
	return 0;
}

