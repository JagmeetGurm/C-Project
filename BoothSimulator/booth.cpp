#include <iostream>
#include <bitset>

using namespace std;

//global variables result and carryOut, sum, carryIn, op;
int result=0b0, carryOut=0b0;
int sum=0b0;
int carryIn=0b0;
int op=0b0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void adder(int a, int b){
	 sum=a+b;
	bitset<1> result(sum);
	
	cout<<result;
	
}

void
int main(int argc, char** argv) {
int ai=0b1;
int bi=0b1;
//int c=a+b;

//entering the four inputs
cout<<"Enter the ai: ";
cin>>ai;
cout<<"Enter the bi: ";
cin>>bi;
cout<<"Enter the carryin: ";
cin>>carryIn;
cout<<"Enter the op signal: ";
cin>>op;
adder(ai, bi);
bitset<1>result(sum);
cout<<"result: "<<result<<endl;
cout<<"carryout: "<<carryOut<<endl;
//bitset<2> x(c);
//cout<<x;
	return 0;
}
