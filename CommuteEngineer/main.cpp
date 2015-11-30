#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib >
using namespace std ;

//point class reflecting the coordinate position of each startup
class point{
public:
	point();
	point(double a, double b){
		x = a; //the x coordinate of point
		y = b; // the y coordinate of point
	}
	double X(){
		return x;
	}
	double Y(){
		return y;
	}
private:
	double x, y; 
};


int main() {
	ifstream infile;
	infile.open("C:\\Users\\Jagmeet\\Documents\\Visual Studio 2013\\Projects\\CommuteEngineer\\inputFile.txt");
	string s, x, y;
	while(getline(infile, s))
{
	
	for(int i=0; i<s.length(); i++){
		if(s[i]=='('){
			int first=++i;
			int k=0;
			while(s[i]!=','){
			k++;
			i++;
			}
			 x=s.substr(first, k);
			
			 std::string::size_type sz;     // alias of size_t

  double xPoint = stod(x, &sz);
   cout<<"x: "<<xPoint+100;
			k=0;
			first=++i;
			while(s[i]!=')'){
				k++;
				i++;
			}
			 y=s.substr(first, k);
			 cout<<" y: "<<y<<endl;
			 //std::string::size_type sz;     // alias of size_t

  double yPoint = std::stod (y,&sz);
		}
		//cout<<"x: "<<x<<endl;
	}
	}
	
		point p(4,5);
//	cout<<p.X();
	return 0;
}
