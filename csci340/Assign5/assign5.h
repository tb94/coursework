#ifndef ASSIGNMENT5
#define ASSIGNMENT5
#include <cstddef>

//--------------------------
// You need to add definition of the Node class
//--------------------------
class Node
{
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    friend class binTree;
    friend class BST;

    private:
        int data;
        Node *left;
        Node *right;
};


class binTree {
	friend class BST;

    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );
    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};

#endif
