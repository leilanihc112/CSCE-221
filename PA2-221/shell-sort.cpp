//============================================================================
// Name        : shell-sort.cpp
// Author      : August McBride
// Date        :2/19/17
// Copyright   : 2017
// Description : Implementation of shell sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void
ShellSort::sort(int A[], int size)
{
  int temp;
	
  for(int mid = size/2; mid>0; mid/=2)  
  {
	  for(int i=mid; i<size; i++ ){
		for(int j=i-mid; j>=0 && A[j]>A[j+mid]; j-=mid)
		{
			temp = A[j];
			A[j]=A[j+mid];
			A[j+mid]=temp;
			++num_cmps;
		}
	  }  
  }
}
