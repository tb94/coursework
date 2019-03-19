#ifndef ASSIGNMENT5
#define ASSIGNMENT5

//--------------------------
// You need to add definition of the Node class
//--------------------------



class binTree {
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
