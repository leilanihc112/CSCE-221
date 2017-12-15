//============================================================================
// Name        : bubble-sort.cpp
// Author      : Leilani Horlander-Cruz
// Date        : 02/19/17
// Copyright   : 2017
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

using namespace std;

void BubbleSort::sort(int A[], int size)			// main entry point
{
    for(int k = 1; k < size; k++) 
	{
		bool contin = false;
		for(int j = 0; j < size-k; j++) 
		{
			if(A[j+1] < A[j]) 
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				num_cmps++;
				contin = true;
			}
		}
		if(!contin) break;
	}
}
