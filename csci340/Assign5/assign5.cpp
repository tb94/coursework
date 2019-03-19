#include "assign5.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------
// Do not modify this section of code
//------------------------------------------------
const int MAX_SIZE = 1000;
const int MAX_COUNT = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;
int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//--------------------------------------------
// End
//--------------------------------------------

binTree::binTree()
{ root = NULL; }

unsigned binTree::height() const
{	return height(root);	}

unsigned binTree::height(Node* n) const
{
    if (n == NULL)
        return 0;
    else
        return max(height(n->left), height(n->right) + 1);
}

unsigned binTree::size() const
{	return size(root);	}

unsigned binTree::size(Node* n) const
{
	if (n == NULL)
		return 0;
	else
		return (size(n->left) + size(n->right) + 1);
}

void binTree::inorder(void(*a)(int))
{	inorder(root, a);	}

void binTree::inorder(Node *p, void(*a)(int))
{
    if (p != NULL)
    {
        inorder(p->left, a);
        a(p->data);
        inorder(p->right, a);
    }
}

void binTree::preorder(void(*a)(int))
{ preorder(root, a); }

void binTree::preorder(Node *p, void(*a)(int))
{
    if (p != NULL)
    {
        a(p->data);
        preorder(p->left, a);
        preorder(p->right, a);
    }
}

void binTree::postorder(void(*a)(int))
{ preorder(root, a); }

void binTree::postorder(Node *p, void(*a)(int))
{
    if (p != NULL)
    {
        postorder(p->left, a);
        postorder(p->right, a);
        a(p->data);
    }
}

void binTree::insert(int val)
{ insert(root, val); }

void binTree::insert (Node *&ptr, int x)
{
    if (ptr == NULL)
        ptr = new Node(x);
    else
    {
        if (x < ptr->data)
            insert(ptr->left, x);
        else
            insert(ptr->right, x);
    }
}

//-------------------------------------------
// Do not modify this section of code
//-------------------------------------------
#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );
    mcount = rcount = 0;
    for_each( v.begin(), v.end(), display );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
//---------------------------------
// End
//--------------------------------                                             
                                              
