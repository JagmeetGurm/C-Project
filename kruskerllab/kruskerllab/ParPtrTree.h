class ParPtrTree {
private:
	int* array; // Node array
	int* weights;//weight array
	int size; // Size of node array
	int FIND(int) const; // Find root
public:
	ParPtrTree(int); // Constructor
	~ParPtrTree() ; // Destructor
	void UNION(int, int); // Merge equivalences
	bool differ(int, int); // True if not in same tree
	int give_root(int);
};
