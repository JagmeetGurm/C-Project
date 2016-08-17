// binary_tree.cpp : Defines the entry point for the console application.
//This assignment is Done by Jagmeet Singh Gurm for the Course CSCI 117 as assigned by Dr. Yeung.
//It is binary tree which reads the expression: a+b-c*d in inorder.
// There are 7 functions in this binary_tree project, each of which is explained briefly below.


#include "stdafx.h"
#include "node.h"
#include <iostream>
#include <ctype.h>

using namespace std;
node *root;  //root pointer to point always to the root of the tree.

class binary_tree
{public:
	binary_tree() //constructor, is called when a binary tree is created in the main function.
	{
		root = NULL;   //root pointer at this time points to nothing, is null.
		t = root;    //'t' pointer which is used to keep track of the current location of the binary tree is assigned to root here.
		count=0;     //counts the no. of nodes of the binary tree, here it is initialized.

	}
	~binary_tree()//destructor
	{
		
	}
	void create(char input)  //create function to create the binary_tree, it takes a char input
	{      
		node *nn;
		nn = new node;  // new node is being created. this will serve the purpose every time the funtion is called recursively to create a new node.
		nn->left = NULL; // left pointer of nn(new node) points to null.
		nn->right = NULL; //right pointer of nn points to null.
		
		nn->value = input;   //input of char type is assigned to value of nn.
		
		if (count == 0)
		{                   //root of binary_tree is being  created.
			root = nn;     //new node created becomes the root.
			t = nn;      //t a pointer to trace the currrent locatiion.
			nn->parent = NULL;
			count++;    //incrementing the count as a node is being created.
			 create('+');

			 // the left child of the root node is being created.
		}
		else if (count == 1)
		{
			root->left = nn;  //left pointer of the root node being assigned to the new node creatd.
			t=nn;
			nn->parent = root;  //new node's parent pointer will point to the root.

			count++;
			 create('a');

			 //3rd pointer, or the left child of 2nd node is created.
		}
		else if (count == 2)
		{
			t->left = nn;
			nn->parent = t;
			count++;
			 create('b');
			 //right child fo the 2nd node is being created.
		}
		else if (count == 3)
		{
			t->right = nn;
			nn->parent = t;
			count++;
			 create('*');
			 //right child of the root node is created.
		}
		else if (count == 4)
		{
			root->right = nn;
			nn->parent = root;
			t = nn;
			count++;
			 create('c');
			 //left child of the right node of root is being created.

		}
		else if (count == 5)
		{
			t->left = nn;
			nn->parent = t;
			count++;
			 create('d');
			 //right child of the right node of the root node is beeing created.

		}
		else
		{
			t->right = nn;
			nn->parent = t;
			count++;
		} 

	}
	void traversal_inorder(node *temp) //function for traversing the binary tree in inorder.
	{
		if (temp != NULL)
		{
			traversal_inorder(temp->left);
			cout << temp->value;
			traversal_inorder(temp->right);
		}

	}


	// functiion for traversing the binary tree in postorder.
		void traversal_postorder(node *temp)
		{
			if (temp != NULL)
			{
				traversal_postorder(temp->left);
				traversal_postorder(temp->right);
				cout << temp->value;
			}
		}

		// function which tells the level of each node when its value is entered.
		int tell_level(node *t, char a, int &level_node) //it receives three inputs: the root pointer, node value, int value intialized to 0. 
		{ //root is at level 0.
			
			if (t!= NULL)
			{

				tell_level(t->left, a, level_node); //calling the left subtree recursively
				tell_level(t->right, a, level_node); //calling the right subtree recursively
				if (t->value == a) //when node value is found from there, we count upwards till root to know the level of a node.
				{
					while (t->parent != NULL) // going back till root to count the level of the particular node.
					{
						level_node++;
						t = t->parent;
					}
				}
			}
			if (t == NULL)
				return -1;



			return level_node;
		}


		//function to recursively remove all nodes from the binary tree.
		void recursive_removal(node *temp)
		{
			if (temp != NULL)
			{
				recursive_removal(temp->left);
				recursive_removal(temp->right);
				t = temp;
				delete t;
			}
		}
public:
	int count;
	node *t;

};

int main()
{
	int level = 0;
	char node_val;

	binary_tree bt; //binary tree created.
	 bt.create('-');
	 cout << "inorder traversal of the binary tree created: ";
	 bt.traversal_inorder(root); //traversal_inorder function
	 cout << endl;
	 cout << "post order traversal of the binary tree created: ";

	 bt.traversal_postorder(root);  //traversal_postorder function
	 cout << "\n please enter the value of the node whose level you want to know: ";
	 cin >> node_val;  //varible to store value entered of node whose level has to be found.
	cout<< bt.tell_level(root, node_val, level);  //tell_level function
	cout << endl;

	cout << " Recursively deleting the whole binary tree" << endl;
	bt.recursive_removal(root); //recursive_removal function
	system("pause");
	return 0;
}

