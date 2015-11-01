#include <iostream>
#include <bitset>
using namespace std;


/*This project is done by Jagmeet S. Gurm as a part of HomeWork 
Assignment given by Dr. Park. 

The Project simulates the Booth's 2's compliment multiplier Algorithm,
in which we make use of  16-bit 2 operands-16-bit multiplicand and 
16-bit mutliplier, to get a 32-bit product.
The multiplier basically performs multiplication by repeated 
addition and subtraction which is performed by 16-bit AlU
which in turn makes use of 1-bit AlU. The 16-bit ALU consists of 
16 1-bit ALU simulators each consisting of the sub-components:
AND gate, OR gate, 1-bit full adder, and 4X1 mulitplexor and an
in-built binv mulitplexor for handling subtraction. The 
carry-out of each ALU  serves as the carry-in for the next ALU.
we call  1st ALU procedure(alu) and then 2nd ALU 15 times in order 
to simulate 16 simulators and every time the the above procedures are
called and depending on the op signal, 
the MUX outputs the result which is then returned to ALU procedure.
Each ALU procedures, receives 5 parameters-ai, bi, cin, binv and op signal
and outputs two values- the result(result) and the carryout(cout). 
The last one outputs overflow instead of cout. It calls all the  above
functions- AND(andGate), OR(orGate), ADDER(adder),  in-bulit binv
mulitplexor, MUX, and MUX outputs the result depending on the op signal 
which is then returned to ALU function.The final ALU finally outputs 
result & overflow.
cin and binv are entered 0 in all cases except subtraction. For subtraction,
we enter both of them 1. op signal is 00 for AND, 01 for OR, 10 for ADD, SUB.

The main driver accepts two 16-bit numbers in two compliments 
and calls the booth's mulitplier passing the 2 numbers.
The multiplier function have Register components MD,
AC, MQ and calls the 16-bit ALU to perform addition and subtraction
for performing the multiplication according to Booth's Algorithm.
*/
 
//globoal variables result holding result of addition/subtraction
//of each ALU and carryOut holding the carryOut of each ALU. 
bitset<1> result=0b0; 
int carryOut=0b0;
string finalResult; //will hold the final result value
// just for simularion of 1-bit Alu but not needed for this program
//function to do and operation
/*AND gate is called by ALU procedure. It receives two inputs(1-bit each)
and accordingly gives the output. If input bits(ai,bi) are (1,0),(0,1) or (0,0)
output is 0 else if input is (1,1) output is 1. The output serves as the 
input for MUX */
int andGate(int a, int b){
	int sum2;
	if(a==1 && b==1)
	sum2=1;
	else sum2=0;
	return sum2;
}

/*
OR gate is called by ALU procedure. It receives two inputs(1-bit each)
and accordingly gives the output. If input bits(ai,bi) are (1,0),(0,1) or (1,1)
output is 1 else if input is (0,0) output is 0. The output serves as the 
input for MUX.
*/
int orGate(int a, int b){
	int sum3;
	if(a==0 && b==0)
	 sum3=0;
	else sum3=1;
	return sum3;
}


/*
1-bit full ADDER is called by ALU procedure and receives 
3 inputs(ai,bi,cin) and outputs two values(sum, cout). 
The output sum serves as the input to MUX. The cout
of each case serves as the cin for the next one.
*/
bitset<1> adder(int a, int b, int c){

	int sum1=a+b+c;

	bitset<1> result(sum1);
	if((a==1 && b==0 &&c==0) ||(a==0 && b==1 && c==0) ||(a==0 && b==0 && (c==0 || c==1)))
	carryOut=0;
	else carryOut=1;
	
return result;	
}



/*
The MUX(mux) procedure is called by ALU procedure. It receives four
inputs-output of andGate, output of orGate, sum of adder and
op signal. That is the output of the AND(andGate),OR(orGate),ADD(adder)
acts as the input for the MUX. Depending on the op signal, it outputs
the result which is then returned to ALU procedure.
*/
bitset<1> muxZero(int andResult, int orResult, bitset<1> addResult, int opSignal){
	if(opSignal==0)
	return andResult;
	if(opSignal==01)
	return orResult;
	if(opSignal==10)
	return addResult;
	 
	
}


/*
bitset<1> aluFinal(int a, int b, int ci, int op, int binv){
	bitset<1> addResult=adder(a,b, ci);
		int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	result=muxZero(andResult, orResult, addResult, op);
	return result;
	
}
*/


/*The ALU function(alu) takes 5 parameters(ai,bi,cin,op, binv) and outputs
two values- result and cout(carry-out). It calls all the  procedures
andGate, orGate, adder, and mux.  And then it output the result received
from mux & cout from adder. The carry-out serves as the cin for next ALU.
the binv mulitplexor is in-built.This will be called 15-times.
*/
bitset<1> aluOne(int a, int b, int c, int d, int binv){
	bitset<1> addResult=adder(a,b, c);
		int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	result=muxZero(andResult, orResult, addResult, d);
	return result;
	
}
//This will be called one time taking 5 parameters(ai,bi,cin,op, binv)
// and outputs two values- result and cout(carry-out). The carryout 
//serves as the cin for aluOne.
bitset<1> aluZero(int a, int b, int ci, int op, int binv){
	int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	bitset<1> addResult=adder(a, b, ci);
result=	muxZero(andResult, orResult, addResult, op);

return result;
}


/*The mutiplier function performs receives two operands
and sets MD and MQ register with their values.
A clockcounter is initialized to the lenghth of the 
operand which is 16 in this case.
BAsed on the value of MQ0 and MQ-1(dummy bit),
the following operations are performed by using
16-bit AlU.
If
MQ0(dj1)==0, MQ-1(dj)==1: Do AC=AC+MD
MQ0(dj1)==1, MQ-1(dj)==0: Do AC=AC-MD
else do nothing when dj1 and dj 
are equal to 00 or 11.

For performing addition and subtraction,
16-bit ALUs are used. In case of subtraction
MD is inversed(1's compliment) and cin=1, binv=1.
In case of addition, cin=0, binv=0.
And op signal is set to 10 for both the cases.
*/

void multiplier(string a, string b){
cout<<"cycle-counter        MD               AC            MQ              MQ-1";
cout<<endl;
//MD and MQ registers assigned the 2 16-bit operands.
string MD=a;
string MQ=b;
char dj1=MQ[MQ.length()-1]; //dj1 or MQ0
char dj='0'; //dj or MQ-1, the dummy bit
string AC="0000000000000000"; //AC register being initialized
int clockCounter=0b10000; //the clockCounter set to 16 initialized
while(clockCounter!=0){
//MD register reinitialized with original value each time
cout<<(bitset<16>)clockCounter<<" ";
cout<<MD;
cout<<" "<<AC<<"  ";
cout<<MQ<< "  "<< dj<<endl;
		MD=a;
		carryOut=0;
		int	ci=0, binv=0, op=10;
		//for addition case when MQ0==0 and MQ-1==1
		if((dj1=='0') && dj=='1'){
		

if(aluZero(AC[15]-'0', MD[15]-'0',ci,op,binv)==1)
AC[15]='1';
else AC[15]='0';

for(int i=MD.length()-2;i>=0;i--){	
	ci=carryOut;
if(aluOne(AC[i]-'0',MD[i]-'0',ci,op,binv)==1)
AC[i]='1';
else AC[i]='0';


		}
	}
	
//for subtraction case when MQ0==1 and MQ-1==0
	if((dj1=='1') && (dj=='0')){
		binv=1;
		for(int i=0; i<MD.length(); i++)
		
	{
		if(MD[i]=='1')
		MD[i]='0';
		else MD[i]='1';
		
	}
	ci=1, op=10;
	if(aluZero(AC[15]-'0', MD[15]-'0',ci,op,binv)==1)
AC[15]='1';
else AC[15]='0';
for(int i=MD.length()-2;i>=0;i--){	
	ci=carryOut;
if(aluOne(AC[i]-'0',MD[i]-'0',ci,op,binv)==1)
AC[i]='1';
else AC[i]='0';
	}
}

//when MQ0 is 0 and MQ-1 is 0
if(dj1==0 && dj==0){
	//do nothing
}

//when MQ0 is 1 and MQ-1 is 1
if(dj1==1 && dj==1){
	//do nothing
}
//Performing the Arithmetic shift
dj=dj1;
char temp=AC[15];
for(int i=AC.length()-1;i>0; i--){
	MQ[i]=MQ[i-1];
	AC[i]=AC[i-1];
	
}
AC[0]=AC[1];
MQ[0]=temp;
dj1=MQ[15];

//printing the output
//cout<<(bitset<16>)clockCounter<<" ";
clockCounter=clockCounter-1;
//cout<<" "<<AC<<"  ";
//cout<<MQ<< "  "<< dj<<endl;
}
finalResult=AC+MQ;
}

//main driver
int main(int argc, char** argv) {
string ai,bi; //strings to accept the 2 16-bit 2's compliment operands

cout<<"enter ai: ";
cin>>ai;
cout<<"enter bi: ";
cin>>bi;
//calling the multiplier function
multiplier(ai,bi);
cout<<endl;
cout<<"final Result: "<<finalResult<<endl;
	return 0;
}
