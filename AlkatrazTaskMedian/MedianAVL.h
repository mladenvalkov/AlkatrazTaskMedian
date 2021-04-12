// MedianAVL.h contains the class MedianAVLTree 

//Structure that implements the node of an AVL Tree
struct node
{
	double inf;           // information field
	int balance;          // difference between the heigth of right and left tree
	int left_size;        // number of elements in left subtree
	int right_size;       // number of elements in right subtree
	node* left_tree;      // pointer to the root of the left subtree
	node* right_tree;     // pointer to the root of the right subtree
};

class MedianAVLTree
{
public:
	MedianAVLTree()
	{
		root = nullptr;
	}
	~MedianAVLTree()
	{
		DeleteMedianTree(root);
	}
	// Deletes the tree
	void DeleteTree()
	{
		DeleteMedianTree(root);
	}

	// Includes a element in the tree
	// [in] x - added element
	void IncludeElem(const double& x)
	{
		InsertElem(root, x);
	}

	// Prints the tree
	void PrintTree()
	{
		PrintMedianSubTree(root);
	}

	// Finds the median value of the current tree
	double FindTreeMedian()
	{
		if (root == nullptr)
			return 0.0;
		int treesize = 1 + root->left_size + root->right_size;
		if (treesize % 2 == 0)
			return (FindElementWithIndex(root, treesize / 2 - 1) + FindElementWithIndex(root, treesize / 2)) / 2.0;
		else
			return FindElementWithIndex(root, treesize / 2);
	}

private:
	// If P has left subtree A, and right child R with subtrees B and C
	// then P becomes the left child of R with P having subtrees A and B
	// and R has right subtree C - left AVL rotation.
	// [in] r - upper node of rotation - P
	void LeftRotate(node*& r);

	// If P has left child R with subtrees A and B and right subtree C
	// then P becomes right child of R with subtrees B and C and R has
	// left subtree A - right AVL rotation.
	// [in] r - upper node of rotation - P
	void RightRotate(node*& r);
	
	// Insterts an element in the tree.
	// Returns the change in the tree.
	// [in] r - the node from which we start to search where to place x
	// [in] x - inserted element
	int InsertElem(node*& r, const double& x);

	// Prints the tree with a given root.
	// [in] r - print the tree with root r
	void PrintMedianSubTree(const node* r);

	// Deletes a tree with given root
	// [in] r - deletes the tree with a given root
	void DeleteMedianTree(node*& r);

	// Finds the element which corresponds to the one
	// with a given index of a sorted array with the tree numbers.
	// [in] r - root of the tree
	// [in] idx - index of the element
	double FindElementWithIndex(node*& r, int idx);

private:
	node* root;
};