//BubbleSort.h
//Bubble sort template class

#pragma once

#define SORT_ASC   0  //Default.In ascending order(A - Z).
#define SORT_DESC  1  //In descending order(Z - A).

class BubbleSort
{
public:
	BubbleSort();
	~BubbleSort();

protected:
	 template <class T> void swap(T &a, T &b);   //The position where two values are exchanged 

public:
	template <class T> void bubble_sort(T arr[], int size, int order =0);  //bubble sort ,default: From low to high (A-Z)
};


//The template class implementation
//Notice: The implementation of template classes needs to be put together with header files

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

//swap int value
//[in/out]  a  -- Front value
//[in/out]  b  -- Back value
template < class T>
void BubbleSort::swap( T &a,  T &b)
{
	T temp;
	temp = a;
	a    = b;
	b    = temp;
}

//Bubble sort,it can sort the values for int, double, string.
//[in/out]  arr    -- Array to be sorted
//[in]      size   -- Array size
//[in]      order  -- Order type, SORT_ASC  : From low to high (A-Z), SORT_DESC : From high to low ((A-Z))
template < class T>
void BubbleSort::bubble_sort(T arr[], int size, int order) {
	int i = 0;
	int j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++)
		{
			int orderSwap = 0;
			if (order == 0) {
				if (arr[j] > arr[j + 1]) { //ASC SORT
					swap(arr[j], arr[j + 1]);
				}
			}
			else if (order == 1) {
				if (arr[j] < arr[j + 1]) { //DESC SORT
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
}
