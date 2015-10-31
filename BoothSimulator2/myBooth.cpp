#include <iostream>
#include <bitset>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// just for simularion of 1-bit Alu but not needed for this program
//function to do and operation
//it receieves two inputs a and b
/*AND gate is called by ALU procedure. It receives two inputs(1-bit each)
;and accordingly gives the output. If input bits(ai,bi) are (1,0),(0,1) or (0,0)
;output is 0 else if input is (1,1) output is 1. The output serves as the 
;input for MU */

int carryOut=0b0;
int andGate(int a, int b){
	int sum2;
	if(a==1 && b==1)
	sum2=1;
	else sum2=0;
	return sum2;
}

/*

;OR gate is called by ALU procedure. It receives two inputs(1-bit each)
;and accordingly gives the output. If input bits(ai,bi) are (1,0),(0,1) or (1,1)
;output is 1 else if input is (0,0) output is 0. The output serves as the 
;input for MUX.
*/
int orGate(int a, int b){
	int sum3;
	if(a==0 && b==0)
	 sum3=0;
	else sum3=1;
	return sum3;
}




//funciton to add two var and return their sum in binary
//it receives 3 inputs no 1 no 2 and carryin ?
bitset<1> adder(int a, int b, int c){
//	int con=(int)c;
	int sum1=a+b+c;

	bitset<1> result(sum1);
	if((a==1 && b==0 &&c==0) ||(a==0 && b==1 && c==0) ||(a==0 && b==0 && (c==0 || c==1)))
	carryOut=0;
	else carryOut=1;
	//cout<<result;
return result;	
}
int main(int argc, char** argv) {
	int ai,bi,ci;
cout<<"enter ai: ";
cin>>ai;
cout<<"enter bi: ";
cin>>bi;
cout<<"enter cin: ";
cin>>ci;
cout<<andGate(ai,bi)<<endl;
cout<<orGate(ai,bi)<<endl;
cout<<"sum: "<<adder(ai,bi,ci);
cout<<"carryout: "<<carryOut;
	return 0;
}
