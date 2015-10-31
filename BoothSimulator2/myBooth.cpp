#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// just for simularion of 1-bit Alu but not needed for this program
//function to do and operation
//it receieves two inputs a and b
/*AND gate is called by ALU procedure. It receives two inputs(1-bit each)
;and accordingly gives the output. If input bits(ai,bi) are (1,0),(0,1) or (0,0)
;output is 0 else if input is (1,1) output is 1. The output serves as the 
;input for MU */
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

int main(int argc, char** argv) {
	int ai,bi;
cout<<"enter ai: ";
cin>>ai;
cout<<"enter bi: ";
cin>>bi;
cout<<andGate(ai,bi)<<endl;
cout<<orGate(ai,bi);
	return 0;
}
