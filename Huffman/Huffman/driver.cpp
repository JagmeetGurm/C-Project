#include "stdafx.h"
#include "heap.h"
#include "heap.cpp"
#include "Huffman.h"
#include<string>
#define MaxSize 100
//MY HEAP RUNS PERFECTLY . HAS CHECKED THAT BEFORE PROCEEDING FURTHER
#include <iostream>
using namespace std;
//char a = 'a';
LeafNode<char>hn[MaxSize];
//HuffTree<char>*hn[100];



void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << "(" << hn.getheapread() << "," << hn.getheapwrite() << endl;

}

void binarySearch(LeafNode<char> hn, int lowerbound, int upperbound, char key)
{
	int position;
	int comparisonCount = 1;    //count the number of comparisons (optional)

	// To start, find the subscript of the middle position.
	position = (lowerbound + upperbound) / 2;

	while ((hn[position].it != key) && (lowerbound <= upperbound))
	{
		comparisonCount++;
		if (hn[position].it > key)               // If the number is > key, ..
		{
			int arr[];                                            // decrease position by one.
			upperbound = position - 1;
			printCode(hn.root(),  arr[],  position);
		}
		else
		{                                                        // Else, increase position by one.
			lowerbound = position + 1;
			int arr[];                                            // decrease position by one.
			//
			printCode(hn.root(), arr[], position);
		}
		position = (lowerbound + upperbound) / 2;
	}
	if (lowerbound < = upperbound)
	{
		cout << "The number was found in array subscript " << position << endl << endl;
	//	cout << "The binary search found the number after " << comparisonCount
		//	<< " comparisons.\n";
		// printing the number of comparisons is optional
	}
	
	return;  // you may also consider returning the subscript
}

void printCode(HuffTree<E>* root, int arr[], int top)
{
	// Assign 0 to left edge and recur
	if (root->left)
	{
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// Assign 1 to right edge and recur
	if (root->right)
	{
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// If this is a leaf node, then it contains one of the input
	// characters, print the character and its code from arr[]
	if (isLeaf(root))
	{
		cout << root->data;
		printArr(arr, top);
	}
}
//1. buidtree

//2.encode

//3.decode
int main()
{
	string car[100];
	int fr[100];
	string input;
//	hn[0] = LeafNode<char>('A',30);
	//hn[1] = LeafNode<char>('B', 40);
//	buildHuff(hn, 2);
//	minTreeComp<int> mt;
//	HuffTree<char>*hf;
//	char a = 'a';
//	char b = 'b';
//	char c = 'c';
//	char d = 'd';
//	char e = 'e';
//	hn[0]=new HuffTree<char>(a, 30);
//	hn[1]=new HuffTree<char>(b, 50);
//	hn[2]=new HuffTree<char>(c, 50);
//	 hn[3]=new HuffTree<char>(d, 50);
//	hn[4]=new HuffTree<char>(e, 50);
//buildHuff(hn, 5);
	cout<<endl;
	
//	cout<<endl<<hn[1]->weight();
/*	heap<int,int> h(new int[50], 0,50) ;
	h.buildHeap();
cout<<h.size();
	h.insert(5);
	h.insert(10);
	h.insert(2);
	h.insert(6);
	h.insert(4);
	cout<<h.isLeaf(1);
	cout<<endl<<h.getheapread();
	cout << endl << h.getheapwrite()<<endl;
	h.buildHeap();
	h.print();
*/	
//	HuffTree<char>hf('A', 20);


	cout << "enter the stirng :" ;
	getline(cin, input);
	//cout << input;
	if (input[0] == '1')
	{//1.buildtree
		int i = 0;
		while (i < input.length()){
			i++;
			for (char a = 'A'; a < 'Z'; a++)
			{
				
				if (input[i] == a)
				{
					string:: size_type sz;
					char c = input.find(a);
					string temp = input.substr(c);
					fr[i] = stoi(temp, &sz);
					car[i] = temp.substr(sz);
						
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cout << fr[i] << endl;
		}

		//loading heap
		//check condition

		if (car.length() <= MaxSize)
		{
			//sortling heap
			string min="z";
			for (int i = 0; i < car.length(); i++)
			{
				for (int j = 0; j < car.length(); j++)
				{

					if (min > car[i])
					{
						min = car[i];
					}

				}
				car[i] = min;
			}

			//building hufftree
			for (int i = 0; i < car.length(); i++)
			{

				hn[i] = LeafNode(car[i], fr[i]);
			}
			buildhuff(hn, car.length());

			//output

			 printCode(hn.root(),  arr[],  top);//referenced from geekforgeeks.org
			
		}
		else{
			cout << "sorry full";
		}
	}
	
	
	else if (input[0] == '2')
	{//2.encode
		for (int i = 0; i < input.length(); i++)
		{//BINARY SEARCH
			
			binarySearch(hn, lowerbound,  upperbound,input[i+1] );
		}
	}
	else
	{//3.decode
		
		for (int i = 0; i < input.length();i++)
		{
			if (stoi(input[i]) == 0)
			{//traverse left
				i=2 * i + 1;
			}
			if (input[i] == 1)
			{//traverse right
				 i=2 * i + 2;
			}
			if (isLeaf())
			{
				cout << hn[i].val;
			}
	}


		system("pause");
	return 0;
}

	