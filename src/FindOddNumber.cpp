/**
 * @file
 * @brief	This exercise resolved this problem:
 *			An int array which has all its elements appeared even time except one. Find this number
 * @author	Peng Xia
 * @date	8/1/2011	
 * @version	0.1
 *
 */

#include <iostream>

using namespace std;

/**
 * This function used to find the number which appeared in array for odd times while others appeared even times.
 * @param array		The input array which has only one number appeared odd times.
 * @param length	The length of the input array
 */
int FindNumber_1(int *array, int length)
{
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		result ^= array[i];
	}
	return result;
}

int FindNumber_2(int *array, int length)
{
	int count0 = 0;
	int count1 = 0;
	int bitPos = 0;
	int result = 0;

	for (bitPos = 0; bitPos < 32; ++bitPos)
	{
		unsigned int mask = 1 << bitPos;
		count0 = 0;
		count1 = 0;
		for (int i = 0; i < length; i++)
		{
			if (array[i] & mask)
				count1++;
			else
				count0++;
		}
		if (count1 & 0x1)
			result |= mask;
	}
	return result;
}

/**
 * This is the main function which contains a test array
 */
int main()
{
	int result;
	int testArray[] = {2, 4, 8, 9, 134, 567, 89, 9, 2, 4, 134, 8, 567};

	result = FindNumber_1(testArray, sizeof(testArray)/sizeof(int));
	cout << "The number " << result << " appeared with odd times" << endl;

	result = FindNumber_2(testArray, sizeof(testArray)/sizeof(int));
	cout << "The number " << result << " appeared with odd times" << endl;

}
