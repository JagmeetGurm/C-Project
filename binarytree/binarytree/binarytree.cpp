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

	
		
	
		


		

		void visitNode(node *temp)
		{
			cout << temp->value << endl;
		}

		void nonrecursive(node *tp)
		{
			
			node * temp = NULL;
			stack<node*> st; //using stack
			f5:
			if (!tp)
			{

				cout << "et";
				return;
			} 

		

			if (tp->left != NULL)
			{
				temp = tp;
				tp = tp->left;
				st.push(temp);
				goto f5;

			}

		CN:

		

			if (tp->right != NULL)
			{
				temp = tp;
				tp = tp->right;
				st.push(temp);
				goto f5;

			}
			
			else
			{
				visitNode(tp);
			PT:
				switch (true)

				if (st.empty())
				{
					
					break;
				}

				temp = st.top();
				st.pop();
				if (temp->left == tp)
				{
					tp= temp;
					goto CN;
				}
				else
				{
					tp = temp;
					goto PT;
				}
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
		
		void visitNode(node *temp)
		{
			cout << temp->value << endl;
		}
		
		void non_recursive(node *tp)
		{

			node * temp = NULL;
			stack<node*> st; //using stack
		f6:
			if (!tp)
			{

				cout << "et";
				return;
			}

		

			if (tp->left != NULL)
			{
				temp = tp;
				tp = tp->left;
				st.push(temp);
				goto f6;

			}

		CurrN:



			if (tp->right != NULL)
			{
				temp = tp;
				tp = tp->right;
				st.push(temp);
				goto f6;

			}

			else
			{
				visitNode(tp);
			PopT:
				switch (true)

				if (st.empty())
				{

					break;
				}

				temp = st.top();
				st.pop();
				if (temp->left == tp)
				{
					tp = temp;
					goto CurrN;
				}
				else
				{
					tp = temp;
					goto PopT;
				}
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
	


	cout << "non- recursive: "; //this is the one to be implemented
	bt.nonrecursive(root);
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