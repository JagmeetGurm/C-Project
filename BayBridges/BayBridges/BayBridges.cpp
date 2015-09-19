// BayBridges.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;


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
//	lineSegment();
	lineSegment(point a, point b){
		z1 = new point(a.X(), a.Y()); //creating a new point to which z1 points
		z2 = new point(b.X(), b.Y());
	
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

class BayBridge{
public:

	lineSegment* lseg; //linesegment aka bridge 
	int id; //id of bridge
	int count; //
	BayBridge* next;

};

//referenced from: http://bryceboe.com/2006/10/23/line-segment-intersection-algorithm/ 
//checking if points are in counterclockwise ordrer
bool intersectPoint(point* A, point* B, point* C){
	return (C->Y() - A->Y())* (B->X() - A->X()) > (B->Y() - A->Y())*(C->X() - A->X());
}


//chekcing if linesegments intersect
bool intersectLineSegment(lineSegment* l1, lineSegment* l2){
	return (intersectPoint(l1->ptA(), l2->ptA(), l2->ptB())) != (intersectPoint(l1->ptB(), l2->ptA(), l2->ptB())) &&
		(intersectPoint(l1->ptA(), l1->ptB(), l2->ptA())) != (intersectPoint(l1->ptA(), l1->ptB(), l2->ptB()));
}

//int total;

class infrastructure{
public:
	infrastructure(){
		//total = 0;
		front = NULL;

	} 
	void	create(BayBridge* b){

		BayBridge* temp;
		temp = b;
		if (front==NULL){
			back = temp;
			front = temp;
		
		//	total++;
		}
		else{
			back->next = temp;
			back=temp;
			//total++;
		}
	}
	void print(){
		BayBridge* temp;
		temp = front;
		for (temp = front; temp != back->next; temp=temp->next){
			cout << temp->id<<endl;
		//	temp = temp->next;
		}

	}
	int max(){
		BayBridge* temp = front;
		int m = temp->count;
		//finding the max
		for (temp = front; temp != back->next; temp = temp->next){
			if (m < temp->count){
				m = temp->count;
			}
			//temp = temp->next;

		}
		
		
		return m;
	}
	void maxDelete(){
	//	BayBridge* a;
		BayBridge* temp4; //= front;
		BayBridge* temp5 = front;
		BayBridge* temp3;// = front->next;
	//cout << m << endl;
	if (max() == front->count){
		temp4 = front;
		front = front->next;
		delete temp4;
	}
	if (max() == back->count){
		BayBridge* temp9 = front;
		BayBridge* temp10 = front->next;
		for (temp9 = front; temp9->next != back; temp9 = temp9->next){
			temp10 = temp10->next;
		}
		delete temp10;
		back = temp9;
		back->next = NULL;
	}
	else{
		
		for (temp3 = front->next; temp3 != back->next; temp3 = temp3->next){
			if (temp3->count == max()){
				temp5->next = temp3->next;
			//	BayBridge* temp3 = temp->next;
				delete temp3;
				break;
			}
			temp5 = temp5->next;
		}
	}


	}



	bool inter(){
		bool yes = false;
		BayBridge* temp = front;
		BayBridge* temp2 = front->next;
		for ( temp=front; temp !=back; temp=temp->next){
			for (temp2 = temp->next; temp2!=back->next; temp2=temp2->next){
				if (intersectLineSegment(temp->lseg, temp2->lseg)){
					temp->count++;
					temp2->count++;
					yes = true;
				}
			}
		}
		return yes;
	}

	//int total=0;
	BayBridge* front;
	BayBridge* back;
};




int main(int argc, char* argv[])

{
	//now reading from file
	ifstream infile;
	//infile.open(argv[1]);
	infile.open("inputCoordinate.txt");
	string s;
	double x1, y1, x2, y2;
	vector<lineSegment> line;

//	int m=0;
	vector<int> id;
	while (getline(infile, s)){ //reading from file line by line
		int k = 0;
		//cout << s << endl;
		//a loop to collect ids of each bridge by accessing ist char of each line
		int myId = s[0] - '0';
	//	cout << myId << endl;
		id.push_back(myId); ///);
	
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
	
	//lest built the infrastructure
	infrastructure infra;
	BayBridge* bb;
	for (int i = 0; i < line.size(); i++){
		// (line[i], id[i], 0);
		
		bb = new BayBridge();

		bb->lseg = &line[i];
		bb->id = id[i];
		bb->count = 0;
		bb->next = NULL;
		infra.create(bb);
		//cout << total;
	//	infra.print();
	//	cout<<bb->lseg->ptA()->Y()<<endl; //this shd print all the y coordinates of A pt.
	}
	while (infra.inter()){

		infra.maxDelete();
	
		//
	}
	infra.print();
	
	 
	system("pause");
	return 0;
}
































