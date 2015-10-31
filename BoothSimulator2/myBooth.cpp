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
bitset<1> result=0b0; 
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



//function mux reacting to op signal and returning binary output to alu
bitset<1> muxZero(int andResult, int orResult, bitset<1> addResult, int opSignal){
	if(opSignal==0)
	return andResult;
	if(opSignal==01)
	return orResult;
	if(opSignal==10)
	return addResult;
	 
	
}//this alu represents the repeatedly calles n-2 alus



bitset<1> aluFinal(int a, int b, int ci, int op, int binv){
	bitset<1> addResult=adder(a,b, ci);
		int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	result=muxZero(andResult, orResult, addResult, op);
	return result;
	
}

bitset<1> aluOne(int a, int b, int c, int d, int binv){
	bitset<1> addResult=adder(a,b, c);
		int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	result=muxZero(andResult, orResult, addResult, d);
	return result;
	
}

//alu function returning output received from mux
bitset<1> aluZero(int a, int b, int ci, int op, int binv){
	int andResult=andGate(a, b);
	int orResult=orGate(a, b);
	bitset<1> addResult=adder(a, b, ci);
result=	muxZero(andResult, orResult, addResult, op);
//cout<<"here: "<<result;
return result;
}

int main(int argc, char** argv) {
	string ai,bi;
	int ci,op,binv;
	int res[16];
cout<<"enter ai: ";
cin>>ai;
cout<<"enter bi: ";
cin>>bi;
cout<<"enter cin: ";
cin>>ci;
cout<<"enter op: ";
cin>>op;
cout<<"enter binv: ";
cin>>binv;

if(binv==1){
	for(int i=0; i<bi.length(); i++)
	{
		if(bi[i]=='1')
		bi[i]='0';
		else bi[i]='1';
		
	}
}
//cout<<andGate(ai,bi)<<endl;
//cout<<orGate(ai,bi)<<endl;
//cout<<"sum: "<<adder(ai,bi,ci);
//cout<<"carryout: "<<carryOut;
int aiLength=ai.length();
int biLength=bi.length();
cout<<"first alu: "<<endl;
if(aluZero(ai[aiLength-1]-'0',bi[biLength-1]-'0',ci,op,binv)==1)
	res[15]=1;
	else res[15]=0;

cout<<"result15: "<<res[15]<<endl;

cout<<"carryout: "<<carryOut<<endl<<endl;
for(int i=aiLength-2;i>0;i--){
	ci=carryOut;
if(aluOne(ai[i]-'0',bi[i]-'0',ci,op,binv)==1)
res[i]=1;
else res[i]=0;
	
}
ci=carryOut;

if(aluFinal(ai[0]-'0',bi[0]-'0',ci,op,binv)==1)
	res[0]=1;
	else res[0]=0;


cout<<"finalresult:"<<endl;
for(int i=0;i<16;i++){
cout<<	res[i];
}
cout<<endl<<carryOut<<endl;
	return 0;
}
