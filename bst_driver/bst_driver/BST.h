#ifndef BST_H
#define BST_H

class node{
public:
	node(int k, node* l, node* r)
	{
		key = k; lc = l; rc = r;
	}


	int key;
//	node* parent;
	node* lc;
	node* rc;
	int lsubtreecount;
};

class bst{
public:
	bst();//cosntructor
	~bst();//destructor
	void insert(node* &r, node* nn);
	int findkthsmallest(node* root, int k);
	int print(node* t, int n1, int n2);
	node* root;
	node* getroot();

	node* rr;
	int count;

	

};
#endif