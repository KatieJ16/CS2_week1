/**
 * @file arrays1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An array example.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_SIZE 60

using namespace std;

//
// TODO: put user functions here
//

void arrayPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int arrayFindMax(int arr[], int n)
{
	//finds the max of an array
	int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max){
			max = arr[i];
		}
    }
    return max;
}

int arrayFindMean(int arr[], int n)
{
	//finds the arithmetic mean of an array
	int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

int * arrayAscending(int arr[], int n)
{
	//Puts in Ascending order
    for (int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j ++){
			if (arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
    }
    return arr;
}

/**
 * @brief Sets up and runs an array example.
 */
int main(int argc, char ** argv)
{

    /*-------- CHANGE NOTHING BELOW THIS LINE FOR PART 1 --------*/
    int * test_values = new int[TEST_SIZE];
    int real_size;

    // seed the PRNG
    srand(time(nullptr));

    // initialize the test array to garbage
    for (int i = 0; i < TEST_SIZE; i++)
    {
        test_values[i] = rand();
    }

    // determine a real size
    real_size = TEST_SIZE - (rand() % 20);

    // initialize the meaningful part of the test array to random numbers
    // all of which are less than one million
    for (int i = 0; i < real_size; i++)
    {
        test_values[i] = rand() % 1000000;
    }
    /*-------- CHANGE NOTHING ABOVE THIS LINE FOR PART 1 --------*/

    //
    // TODO: do your stuff here with the array `test_values`
    // of dynamic size `real_size`
    //
    cout << "Array = ";
    arrayPrint(test_values, real_size);
    cout << endl;
    cout << "Maximum = " << arrayFindMax(test_values, real_size) << endl;
    cout << "Mean = " << arrayFindMean(test_values, real_size) << endl;
    cout << "Ascending = ";
    arrayPrint(arrayAscending(test_values, real_size), real_size);
    cout << endl;
    
    delete[] test_values;
}
