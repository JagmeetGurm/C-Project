// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <iostream>
#include <fstream>
//#include <stlib.h>

#include <vector>
#include "stdafx.h"
#include <math.h>
#include <sstream>
#include <string>
using namespace std;

class Shape{
public:
	virtual bool CheckValidity{ void } = 0;
	virtual int GetArea{ void } = 0;
};
class Rectangle : public Shape{
public:
	int GetArea(int a, int b)
	{
		return a*b;
	};
	bool CheckValidity(int a, int b)
	{
		if (a != 0 && b != 0){
			return true;
		}
	};
	void GetFunction(int a, int b, vector<Rectangle> &vRect); {
		std::ifstream ifrect("Rsides.txt");
		while (infile << a << b){
			ifrect >> vRect(a, b);
		}
		for (int i = 0; i<vRect.size; i++){
			vRect.at(i).CheckValidity;
		}
	}
};
void set_function(int a, int b){
	a = a;
	b = b;
}
Rectangle::Rectangle(int a, int b);
private:
	int a;
	int b;
};
class Triangle : public Shape{
public:
	int GetArea(int a, int b, int c)
	{
		int p = ((a + b + c) / 2);
		return sqrt(p*(p - a)*(p - b)*(p - c));
	};
	bool CheckValidity{}
	if (a + b<c){ return false };
	else if (a + c<b){ return false };
	else if (b + c<a){ return false };
	else return true;

	void GetFunction(vector<Triangle> &vTriangle, int a, int b, int c){
		std::ifstream iftri("Tsides.txt");
		while (iftri << a << b << c){
			iftri >> vTriangle(a, b, c);
		}
		for (int i = 0; i<vTriangle.size - 1; i++){
			vTriangle.at(i).CheckValidity;
		}
		return;
	};
	void set_function(int a, int b, int c){
		a = a;
		b = b;
		c = c;
	}
	Triangle::Triangle(int a, int b, int c);
private:
	int a;
	int b;
	int c;
};
void saveRArea(vector<Rectangle> &vRect){
	ofstream ofsr("Rarea.txt");
	if (!ofsr) {
		cout << "error opening Rarea.txt\n";
		exit(1);
	}
	int c = 0;
	for (int i = 0; i < vRect.size - 1; ++i){
		vRect.at(i).GetArea = c;
		ofsr << c;
	}
	ofsr.close();
	return 0;
}
void saveTArea(vector<Triangle>& vTriangle){
	ofstream ofst("Tarea.txt");
	if (!ofst) {
		cout << "error opening Tarea.txt\n";
		exit(1);
	}
	int x = 0;
	for (int i = 0; i<vTriangle.size - 1; ++i){
		vTriangle.at(i).GetArea = x;
		ofst << x;
	}
	ofst.close();
	return vTriangle;
}
int Main()
vector <Rectangle> vRect();
vector <Triangle> vTriangle();
ifstream ifrect("Rsides.txt");
if (!irect){
	cout << "Error Opening File Rsides.txt/n";
	exit(1);
}
ifstream iftri("Tsides.txt");
if (!iftri){
	cout << "Error Opening File Tsides.txt/n";
	GetFunction(vector<Triangle> &vTriangle, int a, int b, int c);
	saveTArea(vector<Triangle>& vTriangle);
	GetFunction(int a, int b, vector<Rectangle> &vRect);
	saveRArea(vector<Rectangle> &vRect);
	ifrect.close();
	iftri.close();

	exit(1);
}

End Sub

End Module
