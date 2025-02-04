#ifndef BOX_H
#define BOX_H

#include <iostream>
using namespace std;

class Box
{
private:
	double length, width, height;
public:
	double getVolume(){
		return length*width*height;
	}
	void setLength(double l){
		length = l;
	}
	void setWidth(double w){
		width = w;
	}
	void setHeight(double h){
		height = h;
	}


	//overloaded + operator to add two boxes
	Box operator+( const Box& b){
		Box box;
		box.length = this->length + b.length;
	//	cout << "\nb2 length: " << b.length;
	//	cout << endl << "length of calling box should be of b1 5: "<<this->length;
	//	cout << endl << "width should be 7.9: " << this->width<<endl;
		box.width = this->width + b.width;
		box.height = this->height + b.height;
		return box;
	}


};
#endif