// ArraySolution.h holds the declaration of class MedianArray
#include<vector>

class MedianArray
{
public:
	MedianArray()
	{
		vecsize = 0;
	}
	~MedianArray()
	{
	}
	// Includes an element in the vector
	//  [in] elem - included element
	void includeElem(const double& elem);

	// Returns the median value
	double GetMedian();

	// Prints the values in the array
	void printMedianArray();

	// Clears the values in the array
	void ClearArray()
	{
		sortedVec.clear();
		vecsize = 0;
	}
private:
	int vecsize;
	std::vector<double> sortedVec;
};