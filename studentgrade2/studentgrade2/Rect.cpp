#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
#include "Rect.h"

void Rect::SetSides(double l, double w){
	a = l;				//length
	b = w;				//width
	area = a * b;		//calculate and set area

	return;
}

void Rect::CheckValidity(vector<Rect>& vt){
	double l, w;
	Rect rectn;

	ifstream inFS; // input file


	inFS.open("Rsides.txt");
	if (!inFS.is_open()) {
		cout << "ERROR: Could not open file." << endl;
		return;
	}

	while (inFS >> l) {			//condition: while program can intake a value for length
		inFS >> w;				//intake a value for width
		while (l <= 0 || w <= 0) {	//test for valid Rectangle side lengths
			cout << "Sides taken from document after last given Rectangle line do not make a valid Rectangle." << endl;
			return;
		}
		rectn.SetSides(l, w);	//take l and w, run through SetSides function
		vt.push_back(rectn);	//take completed object and place at the end of the vector
	}

	inFS.close();				//close file
	return;
}

double Rect::GetArea(vector<Rect>& vt){		//print all areas of rectangles in vector to Rareas.txt
	ofstream outFS;
	outFS.open("Rareas.txt", ios::app);
	if (!outFS.is_open()) {
		cout << "Could not open file." << endl;
		return 1;
	}
	for (int i = 0; i < vt.size(); i++) {
		//cout << "Area at Rectangle " << (i + 1) << ": ";
		//cout << vt.at(i).area << endl;
		outFS << "Area at Rectangle " << (i + 1) << ": ";
		outFS << vt.at(i).area << endl;
	}
	outFS.close();
	return area;
}
