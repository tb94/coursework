/****************************************************************
	FILE:		mergesort.h
	AUTHOR:		Tim Bretz
	LOGON ID:	Z1697841
	DUE DATE:	4/25/15

	PURPOSE:	Use the merge sort algorithm for the
			given set.
****************************************************************/
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/*	prototypes	*/
template <class T>
void mergeSort(vector<T> &set, bool (*compare)(const T &, const T &));

template <class T>
void mergeSort(vector<T> &set, int low, int high, bool (*compare)(const T &, const T &));

template <class T>
void merge(vector<T> &set, int low, int mid, int high, bool (*compare)(const T &, const T &));

/*	definitions	*/
template <class T>
void mergeSort(vector<T> &set, bool (*compare)(const T &obj1, const T &obj2))
{
	mergeSort(set, 0, set.size() - 1, compare);
}

template <class T>
void mergeSort(vector<T> &set, int low, int high, bool (*compare)(const T &obj1, const T &obj2))
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		mergeSort(set, low, mid, compare);
		mergeSort(set, mid + 1, high, compare);

		merge(set, low, mid, high, compare);
	}
}

template <class T>
void merge(vector<T> &set, int low, int mid, int high, bool (*compare)(const T &obj1, const T &obj2))
{
	vector<T> temp(high - low + 1);

	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
			temp[k++] = set[j++];

		else
			temp[k++] = set[i++];
	}

	while (i <= mid)
		temp[k++] = set[i++];

	while (j <= high)
		temp[k++] = set[j++];

	for (i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i];
}

#endif
