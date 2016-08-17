#include<iostream>
#include<cstring>
#include<cstdlib>
#include <fstream>
#include <sstream>
using namespace std;
 
/*
void lcs( string one,  string two, int len1, int len2 )
{
   int temp[len1+1][len2+1];
 
   for (int i=0; i<=len1; i++)
   {
     for (int j=0; j<=len2; j++)
     {
       if (i == 0 || j == 0)
         temp[i][j] = 0;
       else if (one[i-1] == two[j-1])
         temp[i][j] = temp[i-1][j-1] + 1;
       else
         {
		 if(temp[i-1][j]> temp[i][j-1])
		 temp[i][j]=temp[i-1][j];
		 else temp[i][j]=temp[i][j-1];
     }
	 }
   }
 
   
   int size = temp[len1][len2];
 
   
   char lcs[size+1];
   lcs[size] = '\0'; // Set the terminating character
 int i = len1, j =len2;
while (i > 0 && j > 0)
{
	
	if (one[i-1] == two[j-1])
	{
		lcs[size-1] = one[i-1]; 
		i--; j--; size--;	 
	}

	
	else if (temp[i-1][j] > temp[i][j-1])
		i--;
	else
		j--;
}
cout<<lcs;
/* int k=1;
for (int i=1; i<=len2; i++) {
if(temp[len1][i]==k){
cout<<two[i-1];
k++;
}
}
   
}
 
/* Driver program to test above function 
int main(int argc, char *argv[])
{ ifstream infile;
string s;
infile.open("C:\\Users\\Jagmeet\\Documents\\Visual Studio 2013\\Projects\\LCS\\input.txt");
//infile.open(argv[1]);
while(getline(infile,s )){
//	cout<<s;
	string one="";
	  string two="";
  for(int i=0; i<s.length(); i++){
  	
  	while(s[i]!=';'){
  		one=one+s[i];
  		i++;
	  }
	 while(i<s.length()){
	 	
	 two=two+s[i];
	 i++;
  }
}
  int len1 = one.length();
  int len2 = two.length();
  lcs(one, two, len1, len2);
  cout<<endl;
}
	

  
  return 0;
}
*/


    void swap(int array[], int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
void quicksort(int array[], int lo, int hi)
    {
        int i,j,pivot;
        i=lo;
        j=hi;
        pivot=array[lo];
        
        while (i<=j){
        	while(array[i]<pivot)
        		++i;
        	while(array[j]>pivot)
				--j;
		if (i<=j){
			swap(array, i,j);
			++i;
			--j;
		}
		}
		if(lo<j)
			quicksort(array, lo,j);
		if(i<hi)
			quicksort(array, i,hi);
			
			for(int i=0; i<5; i++){
				cout<<array[i]<<" ";
			}
    }

    int main(){
    	int a[5]={6,3,2,1,4};
    //	quicksort(a, 0, 4);
    int i=1; 
    while(i<=10){
	cout<<i<<endl;
	i+=1;
	}
    	return 0;
	}
    
