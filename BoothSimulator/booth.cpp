#include <iostream>
#include <bitset>
#include <string>

using namespace std;

//global variables result and carryOut, sum, carryIn, op;
bitset<1> result=0b0; 
int carryOut=0b0;
int sum=0b0;
int carryIn=0b0;
int op=0b0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
//funciton to add two var and return their sum in binary
//it receives two inputs a and b
bitset<1> adder(int a, int b, int c){
//	int con=(int)c;
	int sum1=a+b+c;

	bitset<1> result(sum1);
	if((a==1 && b==0 &&c==0) ||(a==0 && b==1 && c==0) ||(a==0 && b==0 && c==0))
	carryOut=0;
	else carryOut=1;
	//cout<<result;
return result;	
}


//function to do and operation
//it receieves two inputs a and b
int andGate(int a, int b){
	int sum2;
	if(a==1 && b==1)
	sum2=1;
	else sum2=0;
	return sum2;
}

//function to do or operation
//it receives two inputs a and b

int orGate(int a, int b){
	int sum3;
	if(a==0 && b==0)
	 sum3=0;
	else sum3=1;
	return sum3;
}


//function mux reacting to op signal and returning binary output to alu
bitset<1> muxZero(int andResult, int orResult, bitset<1> addResult, int opSignal){
	if(opSignal==0)
	return andResult;
	if(opSignal==01)
	return orResult;
	if(opSignal==10)
	return addResult;
	 
	
}
bitset<1> aluOne(int a, int b, int c, int d, int binv){
	bitset<1> addResult=adder(a,b, c);
		int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	result=muxZero(andResult, orResult, addResult, d);
	return result;
	
}

//alu function returning output received from mux
bitset<1> aluZero(int a, int b, int c, int d, int binv){
	int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	bitset<1> addResult=adder(a, b, c);
result=	muxZero(andResult, orResult, addResult, d);
//cout<<"here: "<<result;
return result;
}

int main(int argc, char** argv) {
string ai;//=0b1;
string bi; //=0b1;
int binv=0b0;
int carryInOne=0b0;
int carryIn=0;

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
int a=(ai[ai.length()-1])- '0';
int b=(bi[bi.length()-1])- '0';
if(op==11)
{if(b==0)
b=1;
else b=0;
}
//cout<<"result: "<<aluZero(ai, bi, carryIn, op, binv);
cout<<endl;

//int carryInOne=carryOut;
cout<<"ist: ";
bitset<1> res=aluZero(a, b, carryIn, op, binv);
cout<<"carryout ist: "<<carryOut;
a=ai[ai.length()-2]- '0';
b=bi[bi.length()-2]- '0';

cout<<"Result: "<<aluOne(a, b, carryOut, op, binv)<<res<<endl;
cout<<"carryOut: "<<carryOut<<endl;
//bitset<2> x(c);
//cout<<x;


	return 0;
}
