//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, _TCHAR* argv[])
{
	string mystr;
	cout << "enter line: ";
	getline(cin, mystr);


	int i = 1;
	for(char c = 'a'; c <= 'z'; c++)
	{
		i++;
		if (mystr[0] == c)
		{
		//	cout << "var is ok" << endl;
			break;
		}
		
	//	else cout << "variable expected" << endl;
	}
	//
	if (i==27&&mystr[0]!='z')
		cout << "variable expected" << endl;

	

	if (mystr[1] != '=')
		cout << " '=' expected" << endl;
	if (mystr.length() <= 1)
		goto done;

	if (mystr[2] == '+' || mystr[2] == '-' || mystr[2] == '^' || mystr[2] == '*'||mystr[2]=='=')
		cout << "variable or number expected" << endl;
	for (int i = 2; i < mystr.length() - 1; i++)
	{
		if (mystr[i] == '^')
		{
			for (char c = 'a'; c <= 'z'; c++)

			{
				if (mystr[i + 1] == c)
				{
					cout << "integer expected" << endl;
					break;
				}
			}

		}
	}


	for (int i = 2; i < mystr.length()-2; i++)
	{
	if (mystr[i] == '1' || mystr[i] == '2' || mystr[i] == '3' || mystr[i] == '4' || mystr[i] == '5' || mystr[i] == '6' || mystr[i] == '7' || mystr[i] == '8' || mystr[i] == '9' || mystr[i] == '0')
	{
		if (mystr[i + 1] == ' ')
			{
				
					if (mystr[i + 2] == '1' || mystr[i+2] == '2' || mystr[i+2] == '3' || mystr[i+2] == '4' || mystr[i+2] == '5' || mystr[i+2] == '6' || mystr[i+2] == '7' || mystr[i+2] == '8' || mystr[i+2] == '9' || mystr[i+2] == '0')
						cout << "operator expected" << endl;
					//x++;
				
			}
		}

	}


	
	for (int i = 2; i < mystr.length() - 2; i++)
	{
		if (mystr[i] == '1' || mystr[i] == '2' || mystr[i] == '3' || mystr[i] == '4' || mystr[i] == '5' || mystr[i] == '6' || mystr[i] == '7' || mystr[i] == '8' || mystr[i] == '9' || mystr[i] == '0')

		{
			if (mystr[i + 1] == ' ')
			{
				for (int c = 'a'; c <= 'z'; c++)
				{

					if (mystr[i + 2] == c)
						cout << "end of line expected" << endl;
				}
			}
		}
	}
	
done:
//	cout << token << endl;
	system("pause");
	return 0;
}

