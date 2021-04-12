// ArraySolution.cpp - holds the implementation of methods in class MedianArray

#include "ArraySolution.h"
#include <iostream>
using namespace std;

// Includes an element in the vector
//  [in] elem - included element
void MedianArray::includeElem(const double& elem)
{
	if ( vecsize == 0 )
	{
		sortedVec.emplace_back(elem);
		vecsize++;
	}
	else
	{
		if ( elem < sortedVec[0] )
		{
		    sortedVec.insert(sortedVec.begin(), elem);
			vecsize++;
		}
		else if (elem > sortedVec[(size_t)vecsize - 1])
		{
			sortedVec.emplace_back(elem);
			vecsize++;
		}
		else
		{
			int current_left = 0;
			int current_right = vecsize - 1;

			while (current_right - current_left > 1)
			{
				int middle = current_left + (current_right - current_left) / 2;
				if (sortedVec[(size_t)middle] > elem)
				{
					current_right = middle;
				}
				else
				{
					current_left = middle;
				}
			}

			sortedVec.insert(sortedVec.begin() + current_left + 1, elem);
			vecsize++;
		}
	}
}

// Returns the median value
double MedianArray::GetMedian()
{
	if (vecsize == 0)
		return 0.0;
	else if (vecsize % 2 == 0)
	{
		return (sortedVec[(size_t)vecsize / 2 - 1] + sortedVec[(size_t)vecsize / 2] ) / 2.0;
	}
	else
	{
		return sortedVec[vecsize / 2];
	}
}

// Prints the values in the array
void MedianArray::printMedianArray()
{
	for (size_t i = 0; i < (size_t)vecsize; i++)
	{
		cout << sortedVec[i] << " ";
	}
	cout << '\n';
}