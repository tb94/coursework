#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

void genRndNums( vector<int>& v, int vec_size, int seed ) {
	srand(seed);
	for(int i = 0; i < vec_size; i++)
	{
		v.push_back(rand() % 10000 + 1);
	}
}

void printVec( const vector<int>& v, int vec_size ){
	for(int i = 0; i < vec_size; i++)
	{
		cout << setw(5) << v.at(i);

		if ((i + 1) % 12 == 0)
			cout << endl;
	}
}

int main() {

    vector<int> v;
    genRndNums( v, 100, 9 );
    sort(v.begin(), v.end());
    printVec(v, 100);

    return 0;
}
