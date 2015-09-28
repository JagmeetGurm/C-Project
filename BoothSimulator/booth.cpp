#include <iostream>
#include <bitset>

using namespace std;

//global variables result and carryOut, sum, carryIn, op;
bitset<1> result=0b0, carryOut=0b0;
int sum=0b0;
int carryIn=0b0;
int op=0b0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bitset<1> adder(int a, int b){
	int sum1=a+b;
	bitset<1> result(sum1);
	if(a==1 && b==1)
	carryOut=1;
	//cout<<result;
return result;	
}

int andGate(int a, int b){
	int sum2;
	if(a==1 && b==1)
	sum2=1;
	else sum2=0;
	return sum2;
}

int orGate(int a, int b){
	int sum3;
	if(a==0 && b==0)
	 sum3=0;
	else sum3=1;
	return sum3;
}
bitset<1> mux(int andResult, int orResult, bitset<1> addResult, int opSignal){
	if(opSignal==0)
	return addResult;
	if(opSignal==01)
	return orResult;
	if(opSignal==10)
	return addResult;
	 
	
}
bitset<1> alu(int a, int b, int c, int d){
	int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	bitset<1> addResult=adder(a, b);
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
//orGate(ai, bi);
//bitset<1>result(sum);
if(op==11)
{if(bi==0)
bi=1;
else bi=0;
}
cout<<"result: "<<alu(ai, bi, carryIn, op);
cout<<endl;
if(op==10)
cout<<"carryout: "<<carryOut<<endl;
else cout<<"carryout: "<<0<<endl;
//bitset<2> x(c);
//cout<<x;
	return 0;
}
