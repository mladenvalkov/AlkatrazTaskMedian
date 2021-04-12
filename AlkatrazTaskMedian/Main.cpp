#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "ArraySolution.h"
#include "MedianAVL.h"
#include <chrono>

using namespace std;

// This function tests the elapsed time of a vector implementation against 
// that of the AVL implementation.
// [in] numbercnt - the count of the numbers
void testElapsedTime(int numbercnt)
{
	MedianArray emptyArray;
	MedianAVLTree emptyTree;
	std::vector<double> vectorfortest;
	int sizearr = numbercnt;
	srand( (unsigned int)time(0) );
	for (int i = 0; i < sizearr; i++)
	{
		double elem = (double)(rand() % 100000) + 1.0;
		vectorfortest.emplace_back(elem);
	}

	std::chrono::steady_clock::time_point begin_vector_time = std::chrono::steady_clock::now();
	for (int i = 0; i < sizearr; i++)
	{
		emptyArray.includeElem(vectorfortest[i]);
		//emptyArray.printMedianArray();
	}
	cout << emptyArray.GetMedian() << '\n';
	std::chrono::steady_clock::time_point end_vector_time = std::chrono::steady_clock::now();

	std::chrono::steady_clock::time_point begin_tree_time = std::chrono::steady_clock::now();
	for (int i = 0; i < sizearr; i++)
	{
		emptyTree.IncludeElem(vectorfortest[i]);
	}
	//emptyTree.PrintMedianTree();
	cout << emptyTree.FindTreeMedian() << '\n';
	std::chrono::steady_clock::time_point end_tree_time = std::chrono::steady_clock::now();

	cout << "Time elapsed for vector implementation: " << std::setprecision(5) <<
		double(std::chrono::duration_cast<std::chrono::nanoseconds>(end_vector_time - begin_vector_time).count() ) * 1e-9 << " seconds. \n";
	cout << "Time elapsed for tree implementation: " << std::setprecision(5) <<
		double (std::chrono::duration_cast<std::chrono::nanoseconds>(end_tree_time - begin_tree_time).count()) * 1e-9 << " seconds. \n";
}

// Tests the returned median values for MedianAVL tree
// [in] test_iterations - number of iterations
void testAccuracy(int test_iterrations)
{
	MedianArray emptyArray;
	MedianAVLTree emptyTree;
	std::vector<double> vectorfortest;
	srand((unsigned int)time(0));
	for (int i = 0; i < test_iterrations; i++)
	{
		int sizearr = rand() % 100000 + 100000;

		for (int i = 0; i < sizearr; i++)
		{
			double elem = (double)(rand() % 10000) + 1.0;
			vectorfortest.emplace_back(elem);
		}

		for (int i = 0; i < sizearr; i++)
		{
			emptyArray.includeElem(vectorfortest[i]);
		}

		for (int i = 0; i < sizearr; i++)
		{
			emptyTree.IncludeElem(vectorfortest[i]);
		}
		double medianArray = emptyArray.GetMedian();
		double medianTree = emptyTree.FindTreeMedian();
		if (medianArray == medianTree)
			cout << "Test " << i << ". passed. The median is "<< medianTree << "\n";
		else
			cout << "Test " << i << ". failed! The result median: " << 
			medianTree << 
			" is different than the expected " << medianArray << "\n";
		vectorfortest.clear();
		emptyArray.ClearArray();
		emptyTree.DeleteTree();
	}
}

int main()
{
	testElapsedTime(100000);
	testAccuracy(10);
}