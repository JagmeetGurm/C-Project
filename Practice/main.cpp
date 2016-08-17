#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
/*
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
//function to reverse a string
string reverseString(string& s){
	int size =s.length();
	char temp;
	for(int i=0; i<size/2; i++){
		temp=s[i];
		s[i]=s[size-1-i];
		s[size-1-i]=temp;
		
	}
//	cout<<"s: "<<s<<endl;
	return s;
}

//function to find a string inside another string
void findString(string orignal, string search){
int pos=orignal.find(search);
int count=0;
cout<<"pos:"<<pos<<endl;
vector<string>stringVector;
char temp='a';
while(temp!='\0'){
	if(stringVector)
	stringVector.push_back()
}

if(orignal.find(search)!=std::string::npos){
cout<<"find";	
}
cout<<"first instance: "<<pos<<endl;
cout<<"no of times: "<<count<<endl;
	
}

int main(int argc, char** argv) {
	string original, search;
	cout<<"enter the stirng to reverse: ";
	getline(cin, original);
	cout<<"enter the string to be searched: ";
	getline(cin, search);
//	reverseString(original);
findString(original, search);
	cout<<original;
	return 0;
}

*/

class rectangle{
	public:
		rectangle(int l=0, int b=0){
		length=l;
		breadth=b;	
		}
		int area(){
		return 89;	
		}
		int retLength(){
			return length;
		}
		int retBreadth(){
			return breadth;
		}
		
		private:
			int length;
			int breadth;
	
};
class test{
	public: 
	test();
};
int main(){
	rectangle rect1;
//	rectangle rect2(3,4);
	test t1;
	//cout<<t1.area();
		vector<rectangle>vect;
	vect.push_back(rect1);
	cout<<vect.at(0).area()<<endl;
	cout<<rect1.area()<<endl;
	cout<<pow(2, 12)<<endl;
	cout<<pow(2, (10*(12/10)))*pow(2, 12%10);
	
}

