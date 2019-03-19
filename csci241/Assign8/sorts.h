/****************************************************************
	FILE:		sorts.h
	AUTHOR:		Tim Bretz
	LOGON ID:	Z1697841
	DUE DATE:	4/25/15

	PURPOSE:	Build the list and create methods to
			compare items in the list.
****************************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

/*	prototypes	*/
template <class T>
void buildList(vector<T> &set, const char* fileName);

template <class T>
void printList(const vector<T> &set, int itemWidth, int numPerLine);

template <class T>
bool lessThan(const T &item1, const T &item2);

template <class T>
bool greaterThan(const T &item1, const T &item2);

/*	definitions	*/
template <class T>
void buildList(vector<T> &set, const char* fileName)
{
	T		item;
	ifstream	inFile;

	inFile.open(fileName);
	if (inFile.fail())
	{
		cout << "Error opening file\n";
		exit(-1);
	}

	inFile >> item;

	while(inFile)
	{
		set.push_back(item);
		inFile >> item;
	};

	inFile.close();
}

template <class T>
void printList(const vector<T> &set, int itemWidth, int numPerLine)
{
	for(int i = 0; i < (int)set.size(); i++)
	{
		if (i % numPerLine == 0)
			cout << endl;

		cout << setw(itemWidth) << set[i] << ' ';
	}

	cout << endl;
}

template <class T>
bool lessThan(const T &item1, const T &item2)
{
	if (item1 < item2)
		return true;
	else
		return false;
}

template <class T>
bool greaterThan(const T &item1, const T &item2)
{
	if (item1 > item2)
		return true;
	else
		return false;
}

#endif
