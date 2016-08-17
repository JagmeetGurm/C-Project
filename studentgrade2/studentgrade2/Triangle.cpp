#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<vector>
#include <fstream>
using namespace std;

#include "Triangle.h"
void Triangle::SetSides(double a, double b, double c){
	a = a;				//side 1
	b = b;				//side 2
	c = c;				//side 3
	tperim = (a + b + c) / 2;		//calculate perimeter to use in area calculation
	area = sqrt(tperim * (tperim - a) * (tperim - b) * (tperim - c));	//calculate area and set

	return;
}

void Triangle::CheckValidity(vector<Triangle>& vt){		//check validity of given sides for a triangle
	double a, b, c;
	Triangle tri;

	ifstream inFS; // input file


	inFS.open("Tsides.txt");
	if (!inFS.is_open()) {
		cout << "ERROR: Could not open file." << endl;
		return;
	}

	while (inFS >> a) {			//while program can intake a value for a (side 1)
		inFS >> b >> c;			//intake values for b and c

		double ttest1 = a + b;	//tests to use in validity check
		double ttest2 = b + c;
		double ttest3 = a + c;
		while (a <= 0 || b <= 0 || c <= 0 || ttest1 <= c || ttest2 <= a || ttest3 <= b) {	//test for valid Triangle side lengths
			cout << "Sides taken from document after last given Rectangle line do not make a valid Rectangle." << endl;
			return;
		}
		tri.SetSides(a, b, c);	//if valid, set these three sides to a Triangle object
		vt.push_back(tri);		//place new triangle at the back of the vector
	}

	inFS.close();	//close file
	return;

}

double Triangle::GetArea(vector<Triangle>& vt) {		//print area of all triangles in vector to Tareas.txt
	ofstream outFS;
	outFS.open("Tareas.txt", ios::app);
	if (!outFS.is_open()) {
		cout << "Could not open file." << endl;
		return 1;
	}
	for (int i = 0; i < vt.size(); i++) {
		//cout << "Area at Triangle " << (i + 1) << ": ";
		//cout << vt.at(i).area << endl;
		outFS << "Area at Triangle " << (i + 1) << ": ";
		outFS << vt.at(i).area << endl;
	}
	outFS.close();
	return area;
}
