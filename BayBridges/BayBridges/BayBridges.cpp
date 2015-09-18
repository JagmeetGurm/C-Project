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

class infrastructure{
public:
	infrastructure(){


	}
	BayBridge* front;
	BayBridge* back;
};
class BayBridge{
public:
	lineSegment lseg; //linesegment aka bridge 
	int id; //id of bridge
	int count; //
	BayBridge* next;

};

bool intersectPoint(point* A, point* B, point* C){
	return (C->Y() - A->Y())* (B->X() - A->X()) > (B->Y() - A->Y())*(C->X() - A->X());
}

bool intersectLineSegment(lineSegment l1, lineSegment l2){
	return (((intersectPoint(l1.ptA(), l2.ptA(), l2.ptB())) != (intersectPoint(l1.ptB(), l2.ptA(), l2.ptB())) && 
		(intersectPoint(l1.ptA(), l1.ptB(), l2.ptA())) != (intersectPoint(l1.ptA(), l1.ptB(), l2.ptB()))));
}

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
	line.push_back(l); //the vector line contains all the 6 line segments with each of their 2 points
	

		}
	//lets check if line segments intersect
//	cout<<intersectLineSegment(line[0], line[1])<<endl;
	//cout << "next" << endl;
	//cout << intersectLineSegment(line[5], line[0]);
	/*
	int* count = new int[line.size()];
	for (int i = 0; i < line.size(); i++){
		count[i] = 0;
	}
	bool check = true;
	int size = line.size();
	while (check){
	
		for (int i = 0; i < size- 1; i++){
			check = false;
			for (int j = i + 1; j < size; j++){
				if (intersectLineSegment(line[i], line[j])){
					count[i]++;
					count[j]++;
					check = true;
				}
			}

		}
		if (check){
		//lets find max count and delete the corresponding linesegment
		for (int i = 0; i < 1; i++){
		//	cout << count[i] << endl;
			int max = i;
			for (int j = i+1; j<size; j++){
				if (count[j] > count[max]){
					max = j;

				}
			}
			//deleting corresponding line segment
			for (int k = max; k < size-1; k++){
				line[k] = line[k + 1];
			}
		}

	//	line.resize(size-1);
			size--;
		}
	}
	



	 */
	system("pause");
	return 0;
}

