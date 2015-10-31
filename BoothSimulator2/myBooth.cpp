#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// just for simularion of 1-bit Alu but not needed for this program
//function to do and operation
//it receieves two inputs a and b
int andGate(int a, int b){
	int sum2;
	if(a==1 && b==1)
	sum2=1;
	else sum2=0;
	return sum2;
}

int main(int argc, char** argv) {
	int ai,bi;
cout<<"enter ai: ";
cin>>ai;
cout<<"enter bi: ";
cin>>bi;
cout<<andGate(ai,bi);
	return 0;
}
