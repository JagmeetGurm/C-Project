#ifndef BOX_H
#define BOX_H
#include <iostream>
using namespace std;

class Box{
public:
	Box(){
		cout << "constructor called!"<<endl;
	}
	~Box(){
		cout << "destructor called!"<<endl;
	}
};
#endif