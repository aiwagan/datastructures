#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
class avlnode{
public:
        int element;
        avlnode *left;
        avlnode *right;
        int  height;

        avlnode( int ele, avlnode *lt, avlnode *rt, int h = 0 ): element(ele), left(lt), right(rt),height(h) { }
};

class avltree{
public:
    avlnode *root;
    static const int ALLOWED_IMBALANCE = 1;

    avltree( ) : root(NULL){ }

    ~avltree( ) {
        makeEmpty( );
    }

     int findMin( ) const {
       return findMin( root )->element;
    }

    int findMax( ) const {
        return findMax( root )->element;
    }

    bool contains( int x ) const{
        return contains( x, root );
    }

    bool isEmpty( ) const {
        return root == NULL;
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( ) {
        makeEmpty( root );
    }

    void insert( int x ){
        insert( x, root );
    }

    void remove( int x ){
        remove( x, root );
    }

    int height(avlnode*  t)const{
        return t == NULL ? -1 : t->height;
    }


    void insert( int x, avlnode * & t)
    {
        if( t == NULL )
            t = new avlnode( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );

        balance( t );
    }

    void remove( int x, avlnode * & t )
    {
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
            avlnode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }

        balance( t );
    }

    void balance( avlnode * & t )
    {
        if( t == NULL )
            return;

        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ){
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );}

        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    avlnode * findMin( avlnode *t ) const{
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    avlnode * findMax( avlnode *t ) const{
        if( t != NULL )
            while( t->right != NULL )
                t = t->right;
        return t;
    }

    bool contains( int x, avlnode *t ) const {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }

    void makeEmpty( avlnode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    void printTree( avlnode *t ) const {
        if( t != NULL )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

     void rotateWithLeftChild( avlnode * & k2 )
    {
        avlnode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }


    void rotateWithRightChild( avlnode * & k1 )
    {
        avlnode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }


    void doubleWithLeftChild( avlnode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }


    void doubleWithRightChild( avlnode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }

};

int main()
{
    avltree t;
    srand(time(NULL));
    for(int i=0; i<10; i++)
        t.insert( rand()%1000);
    t.printTree( );



    return 0;
}
