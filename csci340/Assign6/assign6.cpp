#include <iostream>
#include "assign5.h"
#include "assign6.h"
using namespace std;

void BST::insert(int val)
{ insert(root, val); }

void BST::insert (Node *&ptr, int x)
{
    if (ptr == NULL)
        ptr = new Node(x);
    else if (x < ptr->data)
    {
        if (ptr->left == NULL)
            ptr->left = new Node(x);
        else
            insert(ptr->left, x);
    }
    else if (x > ptr->data)
    {
        if (ptr->right == NULL)
            ptr->right = new Node(x);
        else
            insert(ptr->right, x);
    }
}

bool BST::search(int val)
{
    if(root == NULL)
        return false;
    else
        return search(root, val);
}

bool BST::search(Node *&ptr, int y)
{
    if (y == ptr->data)
        return true;
    else if (y < ptr->data)
    {
        if (ptr->left == NULL)
            return false;
        else
            return search(ptr->left, y);
    }
    else if (y > ptr->data)
    {
        if (ptr->right == NULL)
            return false;
        else
            return search(ptr->right, y);
    }
    else
        return false;
}

bool BST::remove(int val)
{ return remove(root, val); }

bool BST::remove(Node *&ptr, int z)
{
    if (ptr == NULL)
        return false;
    else if (ptr->data > z)
        return remove(ptr->left, z);
    else if (ptr->data < z)
        return remove(ptr->right, z);
    
    if (ptr->right != NULL && ptr->left != NULL)
    {
        Node* pred = ptr->left;
        ptr = pred;
        return remove(ptr->left, pred->data);
    }
    else if (ptr->right == NULL && ptr->left == NULL)
    {
        delete ptr;
     
        return true;
    }
    else
    {
        Node* temp = ptr;
        if (ptr->right != NULL)
            ptr = ptr->right;
        else
            ptr = ptr->left;
        
        delete temp;

        return true;
    }
}

void BST::printLeftLeaves()
{ printLeftLeaves(root->left); }

void BST::printLeftLeaves(Node* r)
{
    if (r == NULL)
        return;

    if (r->left == NULL && r->right == NULL)
        cout << r->data << " ";

    printLeftLeaves(r->left);
    printLeftLeaves(r->right);
}

void BST::sumAncestors(int t, int &s)
{ sumAncestors(root, t, s); }

bool BST::sumAncestors(Node *node, int target, int &asum)
{
    if (node == NULL)
        return false;
    if (node->data == target)
        return true;
 
    if (sumAncestors(node->left, target, asum) || sumAncestors(node->right, target, asum))
    {
        asum += node->data;
        return true;
    }
    else
        return false;
}
