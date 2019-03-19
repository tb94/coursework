#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
using namespace std;

void graph::depth_first(int v) const
{
   static int fVert = -1;
   static bool* been = NULL;

   if(fVert == -1)
   {
        fVert = v;
        been = new bool(size);

        for(int i = 0; i < size; i++)
	            been[i] = false;
   }

   cout << label[v];
   been[v] = true;

   for(int x = 0; x != size; x++)
   {
        if(adj_matrix[v][x] != 0 && been[x] != true)
        {
            cout << "->";
            depth_first(x);
        }
   }

   if(v == fVert)
   {
        cout << "\n\n";
        fVert = -1;
        delete[] been;
        been = NULL;
   }
}

void graph::print() const
{
    cout << "No. of Nodes = " << size << "\n\n";
    cout << "Adjacency Matrix:" << "\n\n";
    cout << "  |";

    for(int i = 0; i < (int) label.size(); i++)
        cout << "  " << label[i];

    cout << "\n--|";

    for(int i = 0; i < (int) label.size(); i++)
        cout << "---";

    cout << "\n";

    for(int i = 0; i < (int) label.size(); i++)
    {
        cout << label[i] << " |";

        for(int x = 0; x < (int) label.size(); x++)
        {
            if(adj_matrix[i][x] != 0)
                cout << setw(3) << adj_matrix[i][x];
            else
                cout << setw(3) << "-";
       }
        if(i < (int) label.size() -1)
            cout << "\n |\n";
	}
}

#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();

    return 0;
}

#endif
