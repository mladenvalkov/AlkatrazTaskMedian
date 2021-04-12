// MedianAVL.cpp holds the implementation of methods in class MedianAVLTree

#include<iostream>
#include "MedianAVL.h"

using namespace std;

// If P has left subtree A, and right child R with subtrees B and C
// then P becomes the left child of R with P having subtrees A and B
// and R has right subtree C - left AVL rotation.
// [in] r - upper node of rotation - P
void MedianAVLTree::LeftRotate(node*& r)
{
	node* p = r;
	r = r->right_tree;
	int size_1 = p->left_size;
	int size_2 = r->left_size;
	//int size_3 = r->right_size;

	p->right_tree = r->left_tree;
	r->left_tree = p;

	p->balance -= 1;
	if (r->balance > 0)
	{
		p->balance -= r->balance;
	}

	r->balance -= 1;
	if (p->balance < 0)
	{
		r->balance += p->balance;
	}

	p->right_size = size_2;
	r->left_size = size_1 + size_2 + 1;
	//r->right_size = size_3;
}

// If P has left child R with subtrees A and B and right subtree C
// then P becomes right child of R with subtrees B and C and R has
// left subtree A - right AVL rotation.
// [in] r - upper node of rotation - P
void MedianAVLTree::RightRotate(node*& r)
{
	node* p = r;
	r = r->left_tree;
	//int size_1 = r->left_size;
	int size_2 = r->right_size;
	int size_3 = p->right_size;

	p->left_tree = r->right_tree;
	r->right_tree = p;

	p->balance += 1;
	if (r->balance < 0)
	{
		p->balance -= r->balance;
	}

	r->balance += 1;
	if (p->balance > 0)
	{
		r->balance += p->balance;
	}

	r->right_size = 1 + size_2 + size_3;
	p->left_size = size_2;
}

// Insterts an element in the tree.
// Returns the change in the tree.
// [in] r - the node from which we start to search where to place x
// [in] x - inserted element
int MedianAVLTree::InsertElem(node*& r, const double& x)
{
	int ret_h = 0;
	if (r == nullptr)
	{
		r = new node;
		r->inf = x;
		r->balance = 0;
		r->left_size = 0;
		r->right_size = 0;
		r->left_tree = nullptr;
		r->right_tree = nullptr;
		ret_h = 1;
	}
	else if (x >= r->inf)
	{
		r->right_size++;
		if (InsertElem(r->right_tree, x))
		{
			r->balance++;
			if (r->balance == 1)
				ret_h = 1;
			else if (r->balance == 2)
			{
				if (r->right_tree->balance == -1)
					RightRotate(r->right_tree);
				LeftRotate(r);
			}
		}
	}
	else if (x < r->inf)
	{
		r->left_size++;
		if (InsertElem(r->left_tree, x))
		{
			r->balance--;
			if (r->balance == -1)
				ret_h = 1;
			else if (r->balance == -2)
			{
				if (r->left_tree->balance == 1)
					LeftRotate(r->left_tree);
				RightRotate(r);
			}
		}
	}
	return ret_h;
}

// Prints the tree with a given root.
// [in] r - print the tree with root r
void MedianAVLTree::PrintMedianSubTree(const node* r)
{
	if (r != nullptr)
	{
		cout << r->inf << " ( ";

		if (r->left_tree == nullptr)
			cout << " () ";
		else
			PrintMedianSubTree(r->left_tree);

		cout << " ) ( ";

		if (r->right_tree == nullptr)
			cout << " () ";
		else
			PrintMedianSubTree(r->right_tree);

		cout << " ) \n";
	}
}

// Deletes a tree with given root
// [in] r - deletes the tree with a given root
void MedianAVLTree::DeleteMedianTree(node*& r)
{
	if (r)
	{
		DeleteMedianTree(r->left_tree);
		DeleteMedianTree(r->right_tree);
		delete(r);
		r = nullptr;
	}
}

// Finds the element which corresponds to the one
// with a given index of a sorted array with the tree numbers.
// [in] r - root of the tree
// [in] idx - index of the element
double MedianAVLTree::FindElementWithIndex(node*& r, int idx)
{
	if (r != nullptr)
	{
		if (idx < r->left_size)
			return FindElementWithIndex(r->left_tree, idx);
		if (idx > r->left_size)
			return FindElementWithIndex(r->right_tree, idx - r->left_size - 1);
		return r->inf;
	}
	else
		return 0.0;
}