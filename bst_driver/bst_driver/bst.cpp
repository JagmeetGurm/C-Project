#include "stdafx.h"
#include <iostream>
#include "BST.h"

using namespace std;

bst::bst()
{
	root = NULL;
	count = 0;
}
bst::~bst()
{}


//did insertion in two ways: iterative and recursion. The recursion one has been commented. But both works.
// lsubtreecount keeps the count of no. of nodes in left subtree of each node. This is 0 when tree is null and gets incremented with new nodes created
//Assume the root has N nodes in its left subtree. If K = N + 1, root is K-th node. If K < N, we recursively search for the Kth smallest element in the left subtree of root.If K > N + 1, we  search in the right subtree for the(K – N – 1) - th smallest element.
//INVARIANT-Leaf nodes have 0 lsubtreecount before tree built and even after the tree is built
//when there is only one node(one leaf), the lsubtreecount==0, because if(nn->key<temp->key) doesnt get executed 
//If there is one node with one leftchild, so if lsubtreecount=1, as if(nn->key <temp->key) gets executed once 
//and it remains same for any number of leaf nodes.

void bst::insert(node* &root, node* nn)
{//The insert function maintains the invariant because as it maintains the structure of BST according to which leaf nodes have no children.
	node* temp = root;
	
	node *parent = root;

	// Traverse 
	while (temp!=NULL)
	{     //has looked up internet to get "idea only" for this part

		parent = temp;

		if (nn->key < temp->key)
		{
			//going to left subtree,	increment node count 
			temp->lsubtreecount++; 
			// left subtree 
			temp = temp->lc;
		}
		else
		{
			// right subtree 
			temp = temp->rc;
		}
	}
	//iterative version of insertion
	if (root==NULL)
	{
		root = nn;
	}
	else if (nn->key < parent->key)
	{
		// Insert on left subtree 
		parent->lc = nn;
	}
	else
	{
		// Insert on right subtree 
		parent->rc = nn;
	} 

//Recursive version	

/*	if (root == NULL)
	{
		root = nn;
		
	}
	else if (nn->key < parent->key)
	{
		insert(parent->lc, nn);
	}
	else (insert(parent->rc, nn)); */
}
int bst::print(node* t, int n1, int n2)
{
	count++;
	if (t == NULL)
	{
		count--;	
		return 0;
	}
	if (n1<t->key)
	{
	//	count++;
		print(t->lc, n1, n2);
		
	}
		if (n1 <= t->key&&t->key <= n2)

			cout << t->key << " ";
		if (n2>t->key){
		//	count++;	
			print(t->rc, n1, n2);
		 }
	return count;
}
node* bst::getroot()
{
	return root;
}

int bst::findkthsmallest(node* root, int k)
{
	int ksmallestkey = -1;

	if (root!=NULL)
	{
		//temp pointer for traversing the tree
		node *temp = root;

		// go to kth smallest 
		while (temp!=NULL)
		{
			if (k==(temp->lsubtreecount + 1))
			{
				ksmallestkey = temp->key;
				break;
			}
			else if (k > temp->lsubtreecount)
			{
				
				//go to right subtree 
				k = k - (temp->lsubtreecount + 1);
				temp = temp->rc;
			}
			else
			{
				// The node is on left subtree 
				temp = temp->lc;
			}
		}
	}

	return ksmallestkey;
}