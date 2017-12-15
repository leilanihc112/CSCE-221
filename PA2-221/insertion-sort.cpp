//============================================================================
// Name        : insertion-sort.cpp
// Author      : August McBride
// Date        : 2/19/17
// Copyright   : 2017
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void InsertionSort::sort(int A[], int size)				// main entry point
{
  /* Complete this function with the implementation of insertion sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */

  for (int i = 1; i < size; ++i) {
  	int j = i;

  	while (j > 0 && A[j - 1] > A[j]) {

  		int swap = A[j - 1];
  		A[j - 1] = A[j];
  		A[j] = swap;
  		--j;
  		++num_cmps;
  	}
  }
}
