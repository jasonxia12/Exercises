/**
 * @file FindMissingNumber.cpp
 * @brief Find a missing number from an array wich should contains 0..99
 *
 * We have an array which contains number from 0..99. But one number is
 * missed wihle the other number appeared twice. Our goal of this program
 * is simulate this case and give a solution to find the missing numbver.
 *
 * @author Peng Xia
 * @version 0.1
 * @date 2011-08-05
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Find the missing number by counting it's appearience	
 *
 * @param array		This is the input array which contains the numbers
 * @param length	The array length
 *
 * @return			Return the missed number or -1 if not found
 */
int FindMissingNumber_1(int *array, int length)
{
	// Validate the input parameters
	if (array == NULL || length <= 0)
		return -1;

	// If we want to decrease the space, using bit map
	// malloc((length+sizeof(int)-1)/(sizeof(int)));
	int *countArray = (int*)malloc(sizeof(int)*length);

	// initialize countArray
	memset(countArray, 0, sizeof(int)*length); 

	int i;
	// first round, counting the appearience of numbers.
	for (i = 0; i < length; ++i)
	{
		// protection code
		if (array[i] < 0 || array[i] >= length)
		{
			free(countArray);
			return -1;
		}
		countArray[array[i]] += 1;
	}

	// second round, find the number never appeared.
	for (i = 0; i < length; ++i)
	{
		// We found it.
		if (countArray[i] ==0)
			return i;
	}

	// release the aux array.
	free(countArray);

	// If we reach here, something is wrong. just return -1
	return -1;
}

/**
 * @brief This fucntion is used to compare two int less than 100
 *
 * @param p0	Point to the first integer
 * @param p1	Point to the second integer
 *
 * @return		negative, 0, positive for less than, equal, greater than
 */
int compare(const void *p0, const void *p1)
{
	return (*(int*)p0 - *(int*)p1);
}

/**
 * @brief Find the missing number after sort the array
 *
 * We sort the array first then go through the sorted array to find it:
 * \n 1. Sort the array
 * \n 2. According to following table to find the missing numberc
 * @verbatim
 * +-----------+----------------------+-----------------------------------
 * | fFoundDup |index and array[index]| Description
 * +-----------+----------------------+-----------------------------------
 * |  false    | index < array[index] | index is the missing number
 * +-----------+----------------------+-----------------------------------
 * |  false    | index = array[index] | this value is correct
 * +-----------+----------------------+-----------------------------------
 * |  false    | index > array[index] | array[index] is duplicated
 * +-----------+----------------------+-----------------------------------
 * |  true     |index-1 < array[index]| index-1 is the missing number
 * +-----------+----------------------+-----------------------------------
 * |  true     |index-1 = array[index]| this value is correct
 * +-----------+----------------------+-----------------------------------
 * |  true     |index-1 > array[index]| N/A
 * +-----------+----------------------+-----------------------------------
 * @endverbatim
 * @warning This function has side effects, the input array will be changed.
 *
 * @param array		This is the input array which contains the numbers
 * @param length	The array length
 *
 * @return			Return the missed number or -1 if not found
 */
int FindMissingNumber_2(int *array, int length)
{
	// Validate the input parameters
	if (array == NULL || length <= 0)
		return -1;

	// I guess sorting is not the key point of this quiz, is that right?
	// Let's using qsort to avoid reinvent wheel.
	qsort(array, length, sizeof(int), compare);


	// This flag is used to indicate if we fond a dup number
	int fFoundDup = 0;	

	int index;
	for (index = 0; index < length; ++index)
	{
		if (index-fFoundDup == array[index])
		{
			// This number is correct, process next.
			continue;
		}
		else if (index-fFoundDup < array[index])
		{
			// We fond it.
			return (index-fFoundDup);
		}
		else
		{
			// We fond the duplicate one.
			fFoundDup = 1;
			//cout << "We found the duplicate number is: " << array[index] << endl;
		}
	}
	// If we reach here, something is wrong.
	// Mybe this array does not contains missing number
	// or it contains many duplicated/missing numbers?
	cout << "Are you kidding?" << endl; 
	cout << "This arrary is not the one we talked about:)" << endl;
	return -1;
}

/**
 * @brief Generate a testing array
 *
 * @param array			This is the input array to fill
 * @param length		The array length
 * @param number_mis	The missing number
 * @param number_dup	The duplicate number
 */
void GenerateTestCase(int *array, int length, int &number_mis, int &number_dup)
{
	// Initialize the array with 0..99
	for (int i = 0; i < length; i++)
		array[i] = i;
	
	// We will randomly remove a number
	srand(time(NULL));
	number_mis = rand() % length;
	do
	{
		number_dup = rand() % length;
	} while (number_dup == number_mis);

	// Replace the missed number with the duplicated one.
	array[number_mis] = number_dup;

	// shuffle the array.
	for (int i = 0; i < length; i++)
	{
		int newIndex = rand() % length;
		// exchange these two numbers
		int temp = array[i];
		array[i] = array[newIndex];
		array[newIndex] = temp;
	}
}

int main()
{
	const int NUM_COUNT = 100;
	int array[NUM_COUNT];

	int number_mis;
	int number_dup;

	/* A simple test for these two functions.
	for (int i = 0; i < 100; ++i)
	{
		GenerateTestCase(array, NUM_COUNT, number_mis, number_dup);
		if (number_mis == FindMissingNumber_1(array, NUM_COUNT) &&
			number_mis == FindMissingNumber_2(array, NUM_COUNT))
			continue;
		else
			cout << "Something wrong" << endl;
	}
	*/

	// Generate test array
	GenerateTestCase(array, NUM_COUNT, number_mis, number_dup);
	cout << "We set the missing number to: " << number_mis << endl;
	cout << "We set the duplicate number to: " << number_dup << endl;
	int result;
	// Test our first solution
	result = FindMissingNumber_1(array, NUM_COUNT);
	cout << "FindMissingNumber_1 found the missing number is: " << result << endl;
	
	// Test our second solution
	result = FindMissingNumber_2(array, NUM_COUNT);
	cout << "FindMissingNumber_2 found the missing number is: " << result << endl;
}
