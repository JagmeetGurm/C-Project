// binarytree.cpp : Defines the entry point for the console application.
//This assignment is done by Jagmeet Singh Gurm as part of Assignment1 for CSCI 117 assigned by Dr. Yeung.
//there are two binary trees : binarytree and binary. For binary tree the data is:DXAY 
//and for binary the data is :entered by the user different each time.




#include "stdafx.h"
#include "node.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

node *root;

class binarytree
{//binary tree is created by recursive calls 
public:
binarytree()//constructor
	{
		root = NULL;
		count = 0;
		t = root;
	}
	~binarytree()//destructor
	{

	}
	void create(char item)
	{ //create function to create nodes for the bianry tree
		node *nn;
		nn = new node; //new nodes being created
		nn->value = item;
		nn->left = NULL; //
		nn->right = NULL;

		if (count == 0) //root being created
		{
			root = nn;
			root->parent = NULL;
			count++;
			create('X');
		}
		if (count == 1)
		{
			root->left = nn; //roots left node
			
			t = nn;
			nn->parent = root;
			count++;
			create('D');

		}
		if (count == 2)
		{
			t->left = nn; 
			nn->parent = t;
			count++;
			create('Y');
		}
		if (count == 3)
		{
			root->right = nn; //roots right pointer
			nn->parent = root;
			count++;
		}

	}
		void Traverse(node *temp) //traversal recursive function
		{
			if (temp!=NULL)
			{
				Traverse(temp->left);
				Traverse(temp->right);
				cout<< temp->value;
				if ((temp->left)!=NULL)
					Traverse(temp->right);
			}
			else
				cout<<" et ";
		}

	
		
	
		

		void non_recursive(node *temp)//equivalent non-recursive function
		{
			if (!temp)
			{
				cout << "et";
				return;
			}

				stack<node*> s; //using stack
				s.push(temp);
				node *prev = NULL;
				while (!s.empty())
				{
					node *curr = s.top();
					if (!prev || prev->left == curr || prev->right == curr)
					{
						if (curr->left)
							s.push(curr->left);
						else if (curr->right)
							s.push(curr->right);
					}
					else if (curr->left == prev)
					{
						if (curr->right)
							s.push(curr->right);
					}
					

					else if (true)
					{
						cout << curr->value << " ";
						s.pop();
						goto exit; //using goto to direct control
					}

					else if (curr->left != NULL)
						{
							s.push(curr->right);
						}
					cout << " et ";
					exit:
					prev = curr;
				}
			
			
		}
		


		


public:
	int count;
	node *t;
};
node *rt;

class  binary// 2nd binary tree here data is input by the user
{
public:
	binary() 
	{ //constructor
		rt = NULL; 

	}
	~binary() //destructor
	{}

	void create(char item) //create function to create nodes of binary tree
	{
		node *nn, *p;
		nn = new node;
		nn->value = item;
		nn->left = NULL;
		nn->right = NULL;
		p = NULL; //will act as parent node
		if (rt == NULL)
			rt = nn;
		else
		{
			//  insertions are as leaf nodes
			node* curr;
			curr = rt;
			// Finding the Node's parent
			while (curr)
			{
				p = curr;
				if (nn->value > curr->value) 
					curr = curr->right;
				else curr = curr->left;
			}

			if (nn->value < p->value)
				p->left = nn;
			else
				p->right = nn;
		}

	}
		

		void Traverse(node *temp) //traversal recursive function
		{
			if (temp != NULL)
			{
				Traverse(temp->left);
				Traverse(temp->right);
				cout << temp->value<<" ";
				if ((temp->left) != NULL)
					Traverse(temp->right);
			}
			else
				cout << "et ";
			
		}

		void non_recursive(node *temp)  //equivalent non-recursive function
		{
			if (!temp)
			{

				cout << "et";
				return;
			}	stack<node*> st; //using stack
			st.push(temp);
			node *prev = NULL;
			while (!st.empty()) {
				node *curr = st.top();
				if (!prev || prev->left == curr || prev->right == curr)
				{
					if (curr->left)
						st.push(curr->left);
					else if (curr->right)
						st.push(curr->right);
				}
				else if (curr->left == prev)
				{
					if (curr->right)
						st.push(curr->right);
				}
				else if (true)
				{
					cout << curr->value << " ";
					st.pop();
					goto done; //using goto to direct control
				}

				else if (curr->left != NULL)
				{
					st.push(curr->right);
				}
				cout << " et ";
				done:
				prev = curr;
				
			}

			
			
			
		}

	
public:
	node *l, *r;
};

int main()
{
	
	
	string val;
	binarytree bt ;
	binary b;
	int i = 0;
	bt.create('A');  //1st binary tree
	cout << "traversing the 1st tree : " << endl; 
	cout << "with recursion: ";
	bt.Traverse(root);
	cout << endl;
	

	cout << endl << "without recursion: ";
	bt.non_recursive(root); cout << endl;
	cout << "non: ";
	bt.non(root);
	cout << endl;
	cout << "enter the value for the second tree in (L N R) format: "; //2nd binary tree
	getline(cin, val); //reading the string 
	
	while (i<val.size()) //extracting each character fo the string
	{
		if (val[i] == '(' || val[i] == ')' || val[i]==' ')
		{
			i++;
			continue;
		}
		b.create(val[i]);
		i++;
	}
	cout  << "traversing the 2nd tree : "<<endl;
	cout << "with recursion : ";
	b.Traverse(rt);
	cout << endl;
	cout << "without recursion: ";
	b.non_recursive(rt); cout << endl;

	
	system("pause");
	return 0;
}