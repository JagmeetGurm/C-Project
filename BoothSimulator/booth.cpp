#include <iostream>
#include <bitset>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
int a=0b1;
int b=0b1;
int c=a+b;
bitset<2> x(c);
cout<<x;
	return 0;
}
