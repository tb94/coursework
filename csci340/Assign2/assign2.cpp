/*********************/
/*		Tim Bretz		*/
/*		z1697841			*/
/*		CSCI 340			*/
/*		Assignment 2	*/
/*		9/11/15			*/
/*********************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int TOBE_SEARCHED = 5000;

/*		Insert random numbers into vector v of size vec_size	*/
void genRndNums( vector<int>& v, int vec_size, int seed )
{
   srand(seed);
   for(int i = 0; i < vec_size; i++)
   {
      v.push_back(rand() % 10000 + 1);
   }

}

/*		if find reaches the end of the vector return false
		otherwise return true										*/
bool linearSearch( const vector<int>& v, int x)
{
	// returns an iterator of the found element or
	// an iterator of the end of the vector if the search fails
	if (find(v.begin(), v.end(), x) == v.end())
		return false;
	else
		return true;
}

/*		return the value of the binary search	*/
bool binarySearch( const vector<int>& v, int x)
{
	// returns true if the search succeeds or false if it fails
	return binary_search(v.begin(), v.end(), x);
}

/*		searches through container using the search function, p,
		and returns the number of matching elements in searchNums	*/
int search( const vector<int>& container, const vector<int>& searchNums,
            bool (*p)( const vector<int>&, int) )
{
	int count = 0;
	vector<int>::const_iterator it;
	// iterates through searchNums from beginning to end
	for (it = searchNums.begin(); it != searchNums.end(); ++it)
	{
		// checks if the current element is in container
		if (p(container, *it))
			count++;
	}

	return count;
}

/*		sorts vector v using std::sort	*/
void sortVec (vector<int>& v)
{
	sort(v.begin(), v.end());
}

/*		prints the percent of successful matches in a vector	*/
void printStat (int totalSucCnt, int vec_size)
{
	cout << ((float)totalSucCnt / (float)vec_size) * 100 << '%' << endl;
}

/* 	the provided main funtion	*/
int main() {
    vector<int> container, tobeSearched;
    genRndNums(container, 10000, 9);
    genRndNums(tobeSearched, TOBE_SEARCHED, 3);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVec( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    return 0;
}
