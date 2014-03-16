#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;

class BinaryNode{
public:
    int element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode( int theElement, BinaryNode *lt, BinaryNode *rt ): element(theElement), left(lt), right(rt) { }
};

class BinarySearchTree
{
private:
    BinaryNode* root;

public:
    BinarySearchTree( ) : root( NULL ){}
    ~BinarySearchTree( ){ makeEmpty( ); }

    bool contains( int x ) const{
        return contains( x, root );
    }

    bool isEmpty( ) const{
        return root == NULL;
    }
    BinaryNode* thisone(){
        return root;
    }

    void printTree( ostream & out = cout ) const{
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    void makeEmpty( ){
        makeEmpty( root );
    }

    void insert( int x ){
        insert( x, root );
    }

    void remove( int x ){
        remove( x, root );
    }

    void insert( int x, BinaryNode * & t ){
        if( t == NULL )
            t = new BinaryNode(x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }

    void remove( int x, BinaryNode * & t ){
        if( t == NULL )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

    BinaryNode * findMin( BinaryNode *t ) const{
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    BinaryNode * findMax( BinaryNode *t ) const{
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }


    bool contains( int x, BinaryNode *t ) const{
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }

    void makeEmpty( BinaryNode * & t ){
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != NULL )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
    }
};



int main(int argc, char **argv)
{
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(34);
    bst.insert(9);
    bst.insert(54);
    bst.insert(134);
    bst.insert(4);
    bst.insert(19);
    bst.insert(5);


    bst.printTree();

    cout << "-------------------------" << endl;
    cout<< bst.findMin(bst.thisone())->element << endl;
    cout<< bst.findMax(bst.thisone())->element << endl;

	return 0;
}
