#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void build_heap(vector<int>&, int, bool (*)(int, int));
void heapify(vector<int>&, int, int, bool (*)(int, int));
bool less_than(int, int);
bool greater_than(int, int);
void heap_sort( vector<int>& v, int heap_size, bool (*compar)(int, int) );
int extract_heap( vector<int>& v, int& heap_size, bool (*compar)(int, int) );
void print_vector( vector<int>& v, int pos, int size );

void build_heap( vector<int>& v, int heap_size, bool (*compar)(int, int) )
{
    for (int i = heap_size; i >= 1; i--)
        heapify(v, heap_size, i, compar);
}

void heapify( vector<int>& v, int heap_size, int r, bool (*compar)(int, int) )
{
    int L = (2 * r),
        R = (2 * r) + 1,
        i;

    if ((compar(L, heap_size) || L == heap_size) && compar(v[i], v[L]))
        i = L;
    else
        i = r;

    if ((compar(R, heap_size) || R == heap_size) && compar(v[i], v[R]))
        i = R;

    if (i != r)
    {
        int temp = v[r];
        v[r] = v[i];
        v[i] = temp;

        heapify(v, i, heap_size, compar);
    }
}

bool less_than( int e1, int e2 )
{
    if (e1 < e2)
        return true;
    else
        return false;
}

bool greater_than( int e1, int e2 )
{
    if (e1 < e2)
        return true;
    else
        return false;
}

void heap_sort( vector<int>& v, int heap_size, bool (*compar)(int, int) )
{
    build_heap(v, heap_size, compar);
    
    for(int j = heap_size; j >= 2; j--)
    {
        int temp = v[1];
        v[1] = v[j];
        v[j] = temp;
        heap_size -=  1;

        heapify(v, 1, j, compar);
    }
}

int extract_heap( vector<int>& v, int& heap_size, bool (*compar)(int, int) )
{
    if (compar(heap_size, 1))
        cout << "Error: heap underflow";

    int temp = v[1];
    v[1] = v[heap_size];
    heap_size -= 1;

    heapify(v, heap_size, 1, compar);

    return temp;
}

void print_vector( vector<int>& v, int pos, int size )
{
    for (int i = pos; i < size; i++)
    {
        cout << setw(5) << v[i];
        if (i > 0 && i % 10 == 0)
            cout << endl;
    }

    cout << endl;
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake    
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );
    
    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );
                        
    return 0;
}
