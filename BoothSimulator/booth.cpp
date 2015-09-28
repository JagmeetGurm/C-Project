#include <iostream>
#include <bitset>

using namespace std;

//global variables result and carryOut, sum, carryIn, op;
int result=0b0, carryOut=0b0;
int sum=0b0;
int carryIn=0b0;
int op=0b0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int adder(int a, int b){
	int sum1=a+b;
	bitset<1> result(sum1);
	if(a==1 && b==1)
	carryOut=1;
	//cout<<result;
return sum1;	
}

int andGate(int a, int b){
	if(a==1 && b==1)
	int sum2=1;
	else sum2=0;
	return sum2;
}

int orGate(int a, int b){
	if(a==0 && b==0)
	int sum3=0;
	else sum3=1;
	return sum3;
}
void mux(int andResult, int orResult, int addResult, int opSignal){
	if(opSignal==0)
	return addResult;
	if(opSignal==01)
	return orResult;
	if(opSignal==10)
	return addResult;
	 
	
}
int alu(int a, int b, int c, int d){
	int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	int addResult=adder(a, b);
result=	mux(andResult, orResult, addResult, d);
return result;
}

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
//adder(ai, bi);
//andGate(ai, bi);
orGate(ai, bi);
bitset<1>result(sum);
cout<<"result: "<<result<<endl;
cout<<"carryout: "<<carryOut<<endl;
//bitset<2> x(c);
//cout<<x;
	return 0;
}
