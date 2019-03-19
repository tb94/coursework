/****************************************************************
        FILE:           sorts.h
        AUTHOR:         Tim Bretz
        LOGON ID:       Z1697841
        DUE DATE:       4/25/15

        PURPOSE:	Sort the list using the quick sort
			algorithm.
****************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/*	prototypes	*/
template <class T>
void quickSort(vector<T> &set, bool (*compare)(const T &, const T &));

template <class T>
void quickSort(vector<T> &set, int start, int end, bool (*compare)(const T &, const T &));

template <class T>
int partition(vector<T> &set, int start, int end, bool (*compare)(const T &, const T &));

/*	definitions	*/
template <class T>
void quickSort(vector<T> &set, bool (*compare)(const T &obj1, const T &obj2))
{
	quickSort(set, 0, set.size() - 1, compare);
}

template <class T>
void quickSort(vector<T> &set, int start, int end, bool (*compare)(const T &obj1, const T &obj2))
{
	int	pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);
		quickSort(set, start, pivotPoint - 1, compare);
		quickSort(set, pivotPoint + 1, end, compare);
	}
}

template <class T>
int partition(vector<T> &set, int start, int end, bool (*compare)(const T &obj1, const T &obj2))
{
	int 	pIndex, mid;
	T 	pValue, temp;

	mid = (start + end) / 2;

	temp = set[start];
	set[start] = set[mid];
	set[mid] = temp;

	pIndex = start;
	pValue = set[start];

	for (int scan = start + 1; scan <= end; scan ++)
	{
		if (compare(set[scan], pValue))
		{
			pIndex++;

			temp = set[pIndex];
			set[pIndex] = set[scan];
			set[scan] = temp;
		}
	}

	temp = set[start];
	set[start] = set[pIndex];
	set[pIndex] = temp;

	return pIndex;
}

#endif
