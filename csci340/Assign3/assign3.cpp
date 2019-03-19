/*********************/
/*    Tim Bretz      */
/*    z1697841       */
/*    CSCI 340       */
/*    Assignment 3   */
/*    9/21/15        */
/*********************/
#include <set>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void sieve( set<int>& s, int n)
{
    bool *ar = new bool[n + 1];
    memset(ar, 0, sizeof(bool) * (n + 1));
    
    for (int m = 2; m < n; m++)
    {
        if (!ar[m])
        {
            s.insert(m);
            
            for (int k = m * m; k < n; k += m)
                ar[k] = true;
        }
    }

    cout << endl;

    delete [] ar;

}

void print_primes( const set<int>& s)
{
    int i = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        if (i % 10 == 0)
            cout << endl;

        cout << setw(4) << *it;
        i++;
    }

    cout << endl;
}

int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}
