/**
 * @file Exec_003.cpp
 * @brief Find the maximum sum of a sub array from an array.
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-18
 */
#include <iostream>
#include <vector>

using namespace std;

bool FindMaxSum(const vector<int>& array, int& maxSum)
{
	int size = array.size();
	if (size == 0) 
		return false;

	int curSum = maxSum = array[0];

	cout << "curSum = " << curSum << ", maxSum = " << maxSum << endl;
	for (int i = 1; i < size; i++)
	{
		curSum += array[i];
		if (maxSum < curSum)
			maxSum = curSum;
		cout << "curSum = " << curSum << ", maxSum = " << maxSum << endl;
		if (curSum < 0)
			curSum = 0;
	}
}

int main()
{
	int testCaseSize = 20;
	int testCaseMin = -100;
	int testCaseMax = 100;

	int value;
	vector<int> testArray;

	srand(time(NULL));
	for (int i = 0; i < testCaseSize; i++)
	{
		value = rand()%(testCaseMax-testCaseMin)+testCaseMin;
		testArray.push_back(value);
		cout << value << ", ";
	}
	cout << endl;
	/*
	testArray.push_back(1);
	testArray.push_back(-2);
	testArray.push_back(3);
	testArray.push_back(10);
	testArray.push_back(-4);
	testArray.push_back(7);
	testArray.push_back(2);
	testArray.push_back(-5);
	*/
	
	FindMaxSum(testArray, value);
	cout << "Max Sum : " << value << endl;
}

