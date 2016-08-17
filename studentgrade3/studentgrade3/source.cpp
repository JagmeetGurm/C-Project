/*
John Colburn
2-13-15
CSCI 41
Project 1
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.h"
#include "Triangle.h"
#include "Rect.h"


using namespace std;

void saveRArea(vector <Rect> vRect);
void saveTArea(vector <Triangle> vTriangle);

ifstream inFS;
ofstream outFS;

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	vector <Rect> vRect;
	vector <Triangle> vTriangle;

	Rect Rect;
	Triangle Tri;

	inFS.open("Rsides.txt");
	if (!inFS.is_open())
	{
		cout << "Could not open rSides.txt." << endl;
		return 1;
	}

	while (inFS.good())
	{
		//cout << "Reading two numbers from rSides.txt" << endl;
		inFS >> a >> b;
		Rect.setHeight(a);
		Rect.setWidth(b);

		if (Rect.checkValidity() == true)
			vRect.push_back(Rect);
		//else
		//cout << "Invalid Input" << endl;
	}

	inFS.close();//Closes rSides.
	saveRArea(vRect);

	inFS.open("Tsides.txt");
	if (!inFS.is_open())
	{
		cout << "Could not open tSides.txt." << endl;
		return 1;
	}

	while (inFS.good())
	{
		//cout << "Reading two numbers from tSides.txt" << endl;
		inFS >> a >> b >> c;
		Tri.setSideA(a);
		Tri.setSideB(b);
		Tri.setSideC(c);
		if (Tri.checkValidity() == true)
			vTriangle.push_back(Tri);
		//else
		//cout << "Invalid Input" << endl;
	}
	inFS.close();
	saveTArea(vTriangle);
}

void saveRArea(vector <Rect> vRect)
{
	outFS.open("rAreas.txt");
	cout << "Opening rAreas.txt" << endl;
	if (!outFS.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;
	}
	else
	for (int i = 0; i<vRect.size(); i++) //Tests that the areas are working correctly.
	{
		outFS << vRect[i].getArea() << endl;
	}
	outFS.close();
}

void saveTArea(vector <Triangle> vTriangle)
{
	outFS.open("tAreas.txt");
	cout << "Opening tAreas.txt";
	if (!outFS.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;
	}
	else
	for (int j = 0; j<vTriangle.size(); j++)
	{
		outFS << vTriangle[j].getArea() << endl;
	}
	outFS.close();
}