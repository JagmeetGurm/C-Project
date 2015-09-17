// BayBridges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;
// need an algo for finding intersection of two lines

//reading file 

//structure for coordinate values
//structure for points
class point{
public:
	point();
	point(double a, double b){
		x = a;
		y = b;
	}
	double X(){
		return x;
	}
	double Y(){
		return y;
	}
private:
	double x, y;
};


class lineSegment {
public:
	
	lineSegment(point a, point b){
		z1 = new point(a.X(), a.Y()); //creating a new point to which z1 points
		z2 = new point(b.X(), b.Y());
	
	}
	void aX(point a){
		//z1 = a;
		cout<< a.X();
	}
	//void a(double a)
	void aY(point a){
		cout<<a.Y();
	}
	point* ptA(){  //accessint the point A of line segment
		return z1;
	}
	point* ptB(){ //accessing the point B of line segment
		return z2;
	}

private:
	point* z1;
	point* z2;

};

int main(int argc, _TCHAR* argv[])

{
	//now reading from file
	ifstream infile("inputCoordinate.txt");
	string s;
	double x1, y1, x2, y2;
	vector<lineSegment> line;

//	int m=0;

	while (getline(infile, s)){ //reading from file line by line
		int k = 0;
		//cout << s << endl;
	for (int i = 3; i < s.length(); i++){ //starting the loop from 3
		//checking if char is a digit
		
		if ((s[i]=='-')||(s[i]=='0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') || (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9'))
		{
			int j = i + 1; //if it is then moving to next char
			while ((s[j] != ',')&& s[j] != ']'){ //traversing till the number ends
				j++;
			}
			
			string s2 = s.substr(i, (j - i)); //extracting out the double number from string
			i = j;
			
			double num = stod(s2);  //converting the string to double 
			k++;
			if (k == 1)
				x1 = num;
			if (k == 2)
				y1 = num;
			if (k == 3)
				x2 = num;
			if (k == 4)
				y2 = num;

			
		}
	}
	
	point A(x1, y1);
	point B(x2, y2);
	lineSegment l( A,  B);
	line.push_back(l);
	
	cout << l.ptA()->X() << endl; //this should return x1 of pt A. 
		}
		
		
		
	/*
	point A(3.4, 5);
	point B(8, 9);
	
	//testing points 
	cout << A.X()<<endl; //this should print x coordinate of x.
	cout << A.Y()<<endl;
	lineSegment l1(A, B);
	cout << "lets see: ";
	 l1.aX(A); //this should print the x coordinate of point passed to line segment
	 cout << "now this should print y coordinate of point A: ";
	 cout<< l1.ptA()->Y();
	 cout << "print y coordinate of b: ";
	 cout << l1.ptB()->Y();
	//cout<< p.Y();
//	cout<< p.Y();
	 */
	system("pause");
	return 0;
}

