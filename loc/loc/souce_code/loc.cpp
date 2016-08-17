// loc.cpp : Defines the entry point for the console application.
//

// LOC.cpp : Defines the entry point for the console application.
///******************************************************************/
/* Program Assignment: PSP assignment 2 */
/* Name: Jagmeet Singh Gurm */
/* Date: 9/28/14 */
/* Description: The program is supposed to calculate the:
•	 LOC, that is, the entire program size. 
•	 total size of each of the program’s parts, say  functions etc. And also, 
•	 number of items in each part of the program. 
 */
/******************************************************************/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include <string>

using namespace std;

class loc
{
public:
/**/	loc()
	{
		count = 0;
		counter = 0;
		counter2 = 0;
		counter3=0;
	}

/**/	~loc()
	{

	}
/********************** /
/* The program sectioncalculates the total program size- */

/******************************************************************/
/**/void program_size()
{
	ifstream myfile("loc.cpp");
		string line;
		if (!myfile.is_open())
		{
			cout << "Cannot open that file, try again." << endl;
		}

		else
		{
			while (getline(myfile, line))
			{

				++count;
			}
			myfile.close();
		}
		cout << "The program size is : "<< count<<endl ;


	}
/********************** /
/* The program section calculates the size of each part of the  program */

/******************************************************************/
/**/	void part_size()
	{
		string::size_type n, l;
		string line;
		ifstream myfile("loc.cpp");
		if (!myfile.is_open())
		{
			cout << "Cannot open that file, try again." << endl;
		}

		else
		{
						
			while (getline(myfile, line))
			{
				int pos;
				int pos2;
				if (pos = line.find("class")  != line.npos)
				{
					cout << "Part name: " << line<<endl;
					while (getline(myfile, line))
					{
						++counter;
						
					}
				}
			}	
			
			cout << "size: " << counter << endl;
			

			
		
			myfile.close();
			
		}

	}
/********************** /
/* The program sectioncalculates th- */

/******************************************************************/
/**/	void part_count()
	{
		string::size_type n, l;
		string line;
		ifstream myfile("loc.cpp");
		if (!myfile.is_open())
		{
			cout << "Cannot open that file, try again." << endl;
		}

		else
		{



			while (getline(myfile, line))
			{
				int pos;
				int pos2;
			
						if (pos2 = line.find("/**/") !=line.npos)
						{
														
								++counter3;
						}
					


				
			}

			
			cout << "members count: " << counter3-1<<endl;

		exit:
			myfile.close();

		}
	}
	
private:
	int count;
	int counter;
	int counter2;
	int counter3;
};
/*stop*/

int main()
{
	loc l;

	l.program_size();
	l.part_size();
	l.part_count();
		


	system("pause");
	return 0;
}




