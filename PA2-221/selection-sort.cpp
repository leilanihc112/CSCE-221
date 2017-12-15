//============================================================================
// Name        : selection-sort.cpp
// Author      : August McBride
// Date        : 2/19/17
// Copyright   : 2017
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void
SelectionSort::sort(int A[], int size)        // main entry point
{
  /* Complete this function with the implementation of selection sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */

  for (int nextIndex = 0; nextIndex < size; ++nextIndex) {
    int smallestValue = A[nextIndex];
    int smallestIndex = nextIndex;

    for (int chkIndex = nextIndex; chkIndex < size; ++chkIndex) {

      if (A[chkIndex] < smallestValue) {

        smallestValue = A[chkIndex];
        smallestIndex = chkIndex;

        ++num_cmps;
      }

    }

    A[smallestIndex] = A[nextIndex];
    A[nextIndex] = smallestValue;
  }
  
}
