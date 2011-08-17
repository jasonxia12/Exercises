/**
 * @file Exec_005.cpp
 * @brief Find k minimum numbers from n numbers
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-18
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;



/**
 * @brief Find the minimum k numbers of the array
 *
 * @param array		The input array
 * @param k			K minimum numbers 
 *
 * @return			The return vector contains k minimum number
 */
vector<int> FindMin(vector<int>& array, int k)
{
	int size = array.size();

	if (size <= k)
		return array;

	vector<int> result(array.begin(), array.begin()+k);
	make_heap(result.begin(), result.end());

	vector<int>::iterator it;
	for (it = array.begin()+k; it < array.end(); ++it)
	{
		if (*it < result.front())
		{
			pop_heap(result.begin(), result.end());
			result.pop_back();
			result.push_back(*it);
			push_heap(result.begin(), result.end());
		}
	}
	return result;
}


/**
 * @brief This is a helper function to dump an array
 *
 * @param array		The array to be dumped 
 */
void DumpArray(vector<int>& array)
{
	int size = array.size();

	for (int i = 0; i < size; i++)
	{
		if (i%10 == 0) 
			cout << endl;
		cout << setw(3) << array[i] << ", ";
	}
}


/**
 * @brief Main() used to test our code
 *
 * @return 
 */
int main()
{
	int TestCaseSize = 10;
	int TestCaseMin = 0;
	int TestCaseMax = 100;
	int TestCaseK = 3;

	vector<int> array;
	
	// Initialize the test array
	srand(time(NULL));
	for (int i = 0; i < TestCaseSize; i++)
	{
		int value = rand()%(TestCaseMax-TestCaseMin)+TestCaseMin;
		array.push_back(value);
	}
	cout << "The original array is:";
	DumpArray(array);
	cout << endl;

	vector<int> result = FindMin(array, TestCaseK);
	cout << "The minium " << TestCaseK << " number is:";
	DumpArray(result);
	cout << endl;
}
