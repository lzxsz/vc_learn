// BubbleSortDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is a bubble sort demo.

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "BubbleSort.h"

using namespace std;

//swap int value
//[in/out]  a  -- Front value
//[in/out]  b  -- Back value
void swap_int(int *a, int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}

//bubble sort  for int
//[in/out]  arr    -- Array to be sorted
//[in]      size   -- Array size
//[in]      order  -- Order type, SORT_ASC  : From low to high (A-Z), SORT_DESC : From high to low ((A-Z))
void bubble_sort_int(int arr[], int size, int order) {
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++)
		{
			int orderSwap = 0;
			if (order == 0) {
				if (arr[j] > arr[j + 1]) { //ASC SORT
					swap_int(&arr[j], &arr[j + 1]);
				}
			}
			else if (order == 1) {
				if (arr[j] < arr[j + 1]) { //DESC SORT
					swap_int(&arr[j], &arr[j + 1]);
				}
			}
		}

		for (int n = 0; n < size; n++) {
			printf("%d ", arr[n]);
		}

		printf("\n");
	}

}

//main 
int main()
{
    //std::cout << "Hello World!\n"; 

    int    nArray[] = {3, 6, 9, 2, 7, 0, 4, 1, 5, 8};
    double dArray[] = {3.3, 6.6, 9.9, 2.2, 7.7, 0.0, 4.4, 1.1, 5.5, 8.8 };

	string sArray[]  = { "DDD-3", "GGG-6", "JJJ-9", "CCC-2", "HHH-7", "AAA-0", "EEE-4", "BBB-1", "FFF-5", "III-8" };

	int size = sizeof nArray / sizeof nArray[0];

	printf("1.Bubble sort for int values:\n");
	printf("Before sorting:\n");
    //SORT_ASC  : From low to high
	//SORT_DESC : From high to low
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nArray[i]);
	}
	printf("\n");

	printf("------------------------------\n");

	printf("From low to high (SORT_ASC):\n");

	bubble_sort_int(nArray, size, SORT_ASC);

	printf("Result:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nArray[i]);
	}
	
	cout << endl;

	printf("------------------------------\n");
	printf("From high to low (SORT_DESC):\n");
	bubble_sort_int(nArray, size , SORT_DESC); 

	printf("Result:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nArray[i]);
	}

	cout << endl<< endl;
	// ---------------------------------------------------------

	BubbleSort sortdata;
	
	//bubble sort for double value
	printf("------------------------------\n");
	printf("2.Bubble sort for double values:\n");
	printf("Before sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%g ", dArray[i]);
	}
	printf("\n");

	//Bubble sort double
	sortdata.bubble_sort(dArray, size);

	printf("After sorting : ");
	for (int i = 0; i < size; i++)
	{
		printf("%g ", dArray[i]);
	}

	cout << endl << endl;

	// ---------------------------------------------------------

	printf("3.Bubble sort for string values:\n");
	printf("Before sorting: ");
	for (int i = 0; i < size; i++)
	{
		printf("%s ", sArray[i].c_str());
	}

	cout << endl;

	//Bubble sort string
	sortdata.bubble_sort(sArray, size);

	printf("After sorting : ");
	for (int i = 0; i < size; i++)
	{
		printf("%s ", sArray[i].c_str());
	}

	cout << endl;
}


